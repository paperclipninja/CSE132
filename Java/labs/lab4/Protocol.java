package lab4;

import java.io.IOException;

import studio6.ViewInputStream;

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
	
		int key= (a)//toInt((byte)a,(byte)b);
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
			synthTemp[index]=num;
			System.out.println("SYNTHTEMP "+synthTemp[index]);
			break;
		case 0x05: sFiltTemp[index]=toInt(firstBit,secondBit);
			System.out.println("SFILTTEMP "+sFiltTemp[index]);
			break;
		case 0x06: System.out.println("YA SCREWED");//ITS A STRING
			break;
		case 0x07: index=toInt(firstBit,secondBit);
			System.out.println("INDEX "+index);
			break;
		}		
			
		int end=in.read();
		System.out.println("END OF MESSAGE:"+end);
		//time[index]=t;
		System.out.println("WORKING??");
     	return "end";
	}
	public static void main(String args[]){
		SerialComm s=new SerialComm();
		Protocol p=new Protocol(); 
		try{
		s.connect("COM8");
		ViewInputStream in=new ViewInputStream( s.getInputStream());
			while(true){     
				if(in.available() >= 1 ){
					char next = (char) in.read();
					if(next=='@'){
						String message = p.getMessage(in);
						System.out.println(message);
					}
		      		}
			}
		}
		catch( Exception e){
		}
	}
}
