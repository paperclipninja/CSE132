package studio6;
import java.io.*;
import java.util.Scanner;

import gnu.io.SerialPort;

public class ViewInputStream extends FilterInputStream {
	   static SerialPort serialPort;
	   SerialComm s=new SerialComm();
	   InputStream in;

    	public int read() throws IOException{
    		while(in.available()<1)
    		{
    			//System.out.println("waiting");
    		}
    		if(in.available() >= 1 ){

				
    		    int next =  in.read();
				//System.out.println((char)next);
				return next;
    		}
    		else{
    			
    			return -1;//read();
    		}
    	
    	}
    	

    	
	public ViewInputStream(InputStream i) {
		super(i);
		in=i;
		// FIXME Auto-generated constructor stub
	}
	
	public static void main(String[] args){
		System.out.println("working?");
		try
	      {
	      
	         SerialComm s = new SerialComm();
	      
	         s.connect("COM8"); // Adjust this to be the right port for your machine
	      
	         ViewInputStream in = new ViewInputStream( s.getInputStream());
	      
	         OutputStream out = s.getOutputStream();

	         	while(true){            
	            			if(in.available() >= 1 ){
	                			int next =  in.read();
	                			
	            				System.out.println((char)next);
	            				System.out.println("NEXT CHARACTER");
	            			}
	         	}
	      }
	      	
	      catch ( Exception e )
	      {
	      
	      		// TODO Auto-generated catch block
	      
	         e.printStackTrace();
	      
	      }
	   
	   }
}
