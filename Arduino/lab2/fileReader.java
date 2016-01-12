import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.*;

class ReadCVS{
	public List temp=new ArrayList();
	public List time=new ArrayList();
	public List tempReadings=new ArrayList();
	public static void main(String[] args){
	//ReadCVS obj = new read CVS();
	obj.run();
	}

	public void run(){
	//input here=cvs file
		//will wirte later
      System.out.println("Is this working?");
		/*BufferedReader br=null;
		String line="";
		try{
			br=new BufferedReader(new FileReader(cvsFile));
			while((line=br.readLine())!=null){  
				tempReadings=line.split(COMMA_DELIMITER);   //stores stuff (rows?) in an array
				if(tokens.length>0){
					temp.add(Long.parseLong(tokens[0])); //this gets the values, parses the numbers, and stores it into an arraylist
					time.add(Long.parseLong(tokens[1]));
					tempReadings.add(Long.parseLong(tokens[2]));
					//Depening on how stuff is going to be stored, change numbers so correct value stored				
				}
			}
		}*/
	}
   final int PAD=20; //PAD=padding
	public void paintCOmponent(Graphics g){
		super.paintComponent(g);
		Graphics23 g2=(Graphics2D)g;
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		int w=temp.length(); //getWidth=#of pts in temp OR time
		int h=getmax(); //getHeight= getMax of Temp
		g2.draw(new Line2D.Double(20,20,20,h-20));//check to see why this works and adjust 20 val accordingly
		g2.draw(new Line2D.Double(20,h-20,w-20,h-20));

		Font font = g2.getFont();
        FontRenderContext frc = g2.getFontRenderContext();
        LineMetrics lm = font.getLineMetrics("0", frc);
        float sh = lm.getAscent() + lm.getDescent();
        // Ordinate label.
        String s = "data";
        float sy = PAD + ((h - 2*PAD) - s.length()*sh)/2 + lm.getAscent();
        for(int i = 0; i < s.length(); i++) {
            String letter = String.valueOf(s.charAt(i));
            float sw = (float)font.getStringBounds(letter, frc).getWidth();
            float sx = (PAD - sw)/2;
            g2.drawString(letter, sx, sy);
            sy += sh;
        }
        // Abcissa label.
        s = "x axis";
        sy = h - PAD + (PAD - sh)/2 + lm.getAscent();
        float sw = (float)font.getStringBounds(s, frc).getWidth();
        float sx = (w - sw)/2;
        g2.drawString(s, sx, sy);
        // Draw lines.
        double xInc = (double)(w - 2*PAD)/(temp.length-1);
        double scale = (double)(h - 2*PAD)/getMax();
        g2.setPaint(Color.green.darker());
        for(int i = 0; i < temp.length-1; i++) {
            double x1 = PAD + i*xInc;
            double y1 = h - PAD - scale*temp[i];
            double x2 = PAD + (i+1)*xInc;
            double y2 = h - PAD - scale*temp[i+1];
            g2.draw(new Line2D.Double(x1, y1, x2, y2));
        }
        // Mark data points.
        g2.setPaint(Color.red);
        for(int i = 0; i < temp.length; i++) {
            double x = PAD + i*xInc;
            double y = h - PAD - scale*data[i];
            g2.fill(new Ellipse2D.Double(x-2, y-2, 4, 4));
        }
    }
 
    private int getMax() {
        int max = -Integer.MAX_VALUE;
        for(int i = 0; i < temp.length; i++) {
            if(temp[i] > max)
                max = temp[i];
        }
        return max;
    }



	
		//canvas
		//get values from temp, time
		//cry lots of tears

		//**get graphing the thing later**//
public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.add(new GraphingData());
        f.setSize(400,400);
        f.setLocation(200,200);
        f.setVisible(true);
}
}
//keep a count
//keep length of thing

//count++, get next value.
//if count is EVEN, its the time
//if count is ODD, its the value
//only store and graph the last values
