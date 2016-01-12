package lab4;

import java.io.IOException;

import javax.swing.JFrame;

import studio5.ViewInputStream;

import lab4.GraphDis;
import sedgewick.StdDraw;

public class Protocol {
	int index;
	int[] rawTemp;
	int[] temp;
	int[] filtTemp;
	int[] synthTemp;
	int[] sFiltTemp;
	long[] time;

	public Protocol() {
		index=0;
		rawTemp=new int[125];
		temp=new int[125];
		filtTemp=new int[125];
		synthTemp=new int[125];
		sFiltTemp=new int[125];
		time=new long[125];
		// FIXME Auto-generated constructor stub
	}

	public int toInt(byte b0,byte b1){
		return ((int)b0 << 8) | (b1 & 0xFF);
	}

	public long toLong(byte a,byte b,byte c,byte d){
		return ( ((long)a & 0xff) << 24) |((long)b & 0xff) << 16 |	((long)c & 0xff) << 8 | ((long)d & 0xff);
	}

	public String getMessage(ViewInputStream in) throws IOException{
		int a=in.read();
		//int b=in.read();

		int key= (a);//toInt((byte)a,(byte)b);
		System.out.println("KEY="+key);

		int c=in.read();
		int d=in.read();
		int e=in.read();
		int f=in.read();
		long t= toLong((byte)c,(byte)d,(byte)e,(byte)f);
		System.out.println("TIME="+t); 

		byte firstBit=(byte)in.read();
		byte secondBit=(byte)in.read();
		System.out.println("INDEX= "+index);

		switch(key){
		case 0x01: rawTemp[index]=toInt(firstBit,secondBit); 
		System.out.println("RAWTEMP "+rawTemp[index]);
		break;
		//temp
		case 0x02:temp[index]=toInt(firstBit,secondBit);
		System.out.println("TEMP "+temp[index]);
		break;
		//temp[index]=Integer.parseInt(value);
		case 0x03: filtTemp[index]=toInt(firstBit,secondBit);
		System.out.println("FILTTEMP "+filtTemp[index]);
		break;
		case 0x04: 
			System.out.println("CASE4");
			int num=toInt(firstBit,secondBit);
			System.out.println(num);
			synthTemp[index]=num;
			System.out.println("SYNTHTEMP "+synthTemp[index]);
			break;
		case 0x05: sFiltTemp[index]=toInt(firstBit,secondBit);
		System.out.println("SFILTTEMP "+sFiltTemp[index]);
		break;
		case 0x06: System.out.println("YA SCREWED");//ITS A STRING
		break;
		case 0x07: index=toInt(firstBit,secondBit);
		time[index]=t;
		System.out.println("INDEX "+index);
		break;
		}		


		int end=in.read();
		System.out.println("END OF MESSAGE:"+end);
		//time[index]=t;
		System.out.println("WORKING??");
		return "end";
	}
	public int getIndex(){
		return index;
	}
	public int getMax() {
		int max =0;
		for(int i = 0; i < sFiltTemp.length; i++) {
			if(Math.abs(sFiltTemp[i]) > max)
				max = Math.abs(sFiltTemp[i]);
		}
		for(int i = 0; i < synthTemp.length; i++) {
			if(Math.abs(synthTemp[i]) > max)
				max = Math.abs(synthTemp[i]);
		}
		System.out.println("max = "+max);
		return max;
	}
	public static void main(String args[]){
		StdDraw.setCanvasSize(1000, 1000);
		int max=32592; //this.getMax();
		int inc=((2*max)/125);
		StdDraw.setXscale(0,2*max);
		StdDraw.setYscale(max,-max);
		StdDraw.setPenColor(StdDraw.BLACK);
		StdDraw.setPenRadius(.01);
		StdDraw.line(0, 0, 2*max, 0);
		StdDraw.setPenRadius(.005);
		StdDraw.line(0,2*max,0,-2*max);
		SerialComm s=new SerialComm();
		Protocol p=new Protocol(); 
		try{
			s.connect("COM9");
			int switc=0;
			ViewInputStream in=new ViewInputStream( s.getInputStream());
			while(p.getIndex()!= 150){     
				if(in.available() >= 1 ){
					char next = (char) in.read();
					if(next=='@'){
						String message = p.getMessage(in);
						switch(switc){
						case 0://index

							switc++;
							break;
						case 1:
							if(p.synthTemp[p.getIndex()]>0){
								StdDraw.filledCircle((double) p.time[p.getIndex()], (double) -p.synthTemp[p.getIndex()],  2);
								StdDraw.point((double)p.time[p.getIndex()], (double) -p.synthTemp[p.getIndex()]);
								System.out.println("Draw"+ p.synthTemp[p.getIndex()]);
							}
							else{
								StdDraw.filledCircle((double) p.time[p.getIndex()], (double) -p.synthTemp[p.getIndex()],  2);
								System.out.println("Draw"+ p.synthTemp[p.getIndex()]);

							}
							//input
							switc++;
							break;
						case 2:
							if(p.sFiltTemp[p.getIndex()]>0){
								StdDraw.filledCircle((double) p.time[p.getIndex()], (double) -p.sFiltTemp[p.getIndex()],  2);
								System.out.println("Draw"+ p.sFiltTemp[p.getIndex()]);

							}
							else{
								StdDraw.filledCircle((double) p.time[p.getIndex()], (double) -p.sFiltTemp[p.getIndex()],  2);
								System.out.println("Draw"+ p.sFiltTemp[p.getIndex()]);


							}
							//output
							switc=0;
							break;

						}

						System.out.println(message);
					}

				}
			}
		}
		catch( Exception e){
			
					}
	}
}

			//StdDraw.filledCircle(max, -max, max);


			//Plot Inputs
			//		        StdDraw.setPenColor(StdDraw.RED);
			//		        for(int i=0;i<125;++i){
			//		        	if(synthTemp[i]>0){
			//		               StdDraw.filledCircle((double) (i*inc), (double) -synthTemp,  .2);
			//		              	System.out.println("input " +i +" = "+synthTemp);
			//		        	}
			//		        	else{
			//		                StdDraw.filledCircle((double) (i*inc), (double) -synthTemp,  .2);
			//		               	System.out.println("input " +i +" = "+synthTemp);
			//
			//		        	}
			//		        }
			//		        //Plot output
			//		        StdDraw.setPenColor(StdDraw.BLUE);
			//		        for(int i=0;i<sFiltTemp.length;++i){
			//		        	if(sFiltTemp[i]>0){
			//		               StdDraw.filledCircle((double) (i*inc), (double) -sFiltTemp[i],  .2);
			//		               	System.out.println("output " +i +" = "+sFiltTemp[i]);
			//		        	}
			//		        	else{
			//		                StdDraw.filledCircle((double) (i*inc), (double) -sFiltTemp[i],  .2);
			//		               	System.out.println("output " +i +" = "+sFiltTemp[i]);
			//
			//		        	}
			//		        }
			//			}
			//			
			//		
			//			GraphDis q = new GraphDis(p.synthTemp,p.sFiltTemp);
			//			//			System.out.println(q.getMax);
			////						int[] input = {1,2,3,4,5,-6};
			////						int[] output={6,7,8,8,-1,-10};
			//			//double[] input = {1042.944,1564.416,2085.888
			//			//	    			,2607.3599999999997
			//			//	    			,3128.832
			//			//	    			,3650.304
			//			//	    			,4171.776
			//			//	    			,4693.248
			//			//	    			,5214.719999999999
			//			//	    			,5736.192
			//			//	    			,6779.1359999999995
			//			//	    			,11993.856
			//			//	    			,13036.8
			//			//	    			,13558.271999999999
			//			//	    			,14601.216
			//			//	    			,15122.688
			//			//	    			,15644.16
			//			//	    			,16165.632
			//			//	    			,16687.104
			//			//	    			,17208.576
			//			//	    			,17730.048
			//			//	    			,18251.52
			//			//	    			,18772.992
			//			//	    			,26595.072
			//			//	    			,27116.543999999998
			//			//	    			,27638.016
			//			//	    			,28159.487999999998
			//			//	    			,28680.96
			//			//	    			,29202.432
			//			//	    			,29723.904
			//			//	    			,30245.376
			//			//	    			,30766.847999999998
			//			//	    			,31288.32
			//			//	    			,31809.791999999998
			//			//	    			,32331.264
			//			//	    			,39631.871999999996
			//			//	    			,40153.344
			//			//	    			,40674.816
			//			//	    			,41196.288
			//			//	    			,41717.759999999995
			//			//	    			,42239.231999999996
			//			//	    			,42760.704
			//			//	    			,43282.176
			//			//	    			,43803.648
			//			//	    			,44325.119999999995
			//			//	    			,45889.536
			//			//	    			,29280
			//			//	    			,-27616
			//			//	    			,-4864
			//			//	    			,-26896
			//			//	    			,-21904
			//			//	    			,22160
			//			//	    			,2640
			//			//	    			,-28752
			//			//	    			,1744
			//			//	    			,9216
			//			//	    			,-24976
			//			//	    			,22192
			//			//	    			,4080
			//			//	    			,24208
			//			//	    			,26256
			//			//	    			,30528
			//			//	    			,10528
			//			//	    			,-21872
			//			//	    			,-4096
			//			//	    			,10160
			//			//	    			,784
			//			//	    			,-23728
			//			//	    			,6672
			//			//	    			,25344
			//			//	    			,-24432
			//			//	    			,-18192
			//			//	    			,128
			//			//	    			,-12640
			//			//	    			,-2080};
			//			//	    		
			//			//	    	//GraphDis g = new GraphDis(p.synthTemp,p.sFiltTemp);
			////			GraphDis q = new GraphDis(input,output);
			//			q.graphing();
			//			//			GraphingData g = new GraphingData (p.synthTemp,p.sFiltTemp);
			//			//			  JFrame f = new JFrame();
			//			//		        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			//			//		        f.add(g);
			//			//		        f.setSize(400,400);
			//			//		        f.setLocation(200,200);
			//			//		        f.setVisible(true);
			//
			//		}
			//		catch( Exception e){
			//
			//		}
			//	}
			//}
