package lab4;

import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;
 
public class Graphing extends JPanel {
	int[] input;
	int[] output;
	
	public Graphing(int[] in, int[] out){
		input=in;
		output=out;
	}

    final int PAD = 20;
 
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                            RenderingHints.VALUE_ANTIALIAS_ON);
        int w = getWidth();
        int h = getHeight();
        int range=(getMax()-getMin());
        
        // Draw ordinate.
        g2.draw(new Line2D.Double(PAD, PAD, PAD, h-PAD));
        // Draw abcissa.
        g2.draw(new Line2D.Double(PAD, PAD+range, w-PAD, PAD+range));
        
        double xInc = (double)(w - 2*PAD)/(input.length-1);
        double scale = (double)(h - 2*PAD);
        
        // Mark data points.
        
        g2.setPaint(Color.red);
        for(int i = 0; i < input.length; i++) {
            double x = PAD + i*xInc;
            double y = h - PAD - scale*input[i] -scale*range;
            g2.fill(new Ellipse2D.Double(x-2, y-2, 4, 4));
        }
        
        g2.setPaint(Color.blue);
        for(int i = 0; i < input.length; i++) {
            double x = PAD + i*xInc;
            double y = h - PAD - scale*output[i]-scale*range;
            g2.fill(new Ellipse2D.Double(x-2, y-2, 4, 4));
        }
        
    }
 
    private int getMax() {
        int max = -Integer.MAX_VALUE;
        for(int i = 0; i < output.length; i++) {
            if(output[i] > max)
                max = output[i];
        }
        for(int i = 0; i < input.length; i++) {
            if(input[i] > max)
                max = input[i];
        }
        return max;
    }
    
    private int getMin(){
    	int min=50000;
    	for(int i=0; i<input.length; i++){
    		if(input[i]<min) min=input[i];
    	}
    	for(int i=0; i<output.length; i++){
    		if(output[i]<min) min=output[i];
    	}
    	return min;
    }
 
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        int[] a={1,2,3,4,5,6,7};
        int[] b={6,7,8,9,0,1,-10};
        f.add(new Graphing(a,b));
        f.setSize(1000,800);
        f.setLocation(200,200);
        f.setVisible(true);
    }
}