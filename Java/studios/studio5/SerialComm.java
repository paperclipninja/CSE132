package studio5;

import java.io.*;

import gnu.io.*;

public class SerialComm {
	
	SerialPort serialPort;
	InputStream in;
	OutputStream out;
	
    public SerialComm()
    {
        super();
    }
    boolean connect ( String portName ) throws Exception
    {
    	boolean success;
    	
        CommPortIdentifier portIdentifier = CommPortIdentifier.getPortIdentifier(portName);
        if ( portIdentifier.isCurrentlyOwned() )
        {
            System.out.println("Error: Port is currently in use");
            success = false;
        }
        else
        {
            CommPort commPort = portIdentifier.open(this.getClass().getName(),2000);
            
            if ( commPort instanceof SerialPort )
            {
                serialPort = (SerialPort) commPort;
                serialPort.setSerialPortParams(9600,SerialPort.DATABITS_8,SerialPort.STOPBITS_1,SerialPort.PARITY_NONE); // First parameter is baud rate for the port
                
                in = serialPort.getInputStream();
                out = serialPort.getOutputStream();
                success = true;
            }
            else
            {
                System.out.println("Error: Only serial ports are handled by this example.");
                success = false;
            }
        }
        return(success);
    }
    
    void disconnect() {
    	serialPort.close();
    	try {
			in.close();
			out.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    }
    
    InputStream getInputStream() {
    	return(in);
    }
    
    OutputStream getOutputStream() {
    	return(out);
    }
    
    // Example use
    public static void main ( String[] args )
    {
        try
        {
            SerialComm s = new SerialComm();
            s.connect("COM4"); // Adjust this to be the right port for your machine
            InputStream in = s.getInputStream();
            OutputStream out = s.getOutputStream();
            // InputStream and OutputStream are now avaiable for use
            // insert code below to use them
            
            
        }
        catch ( Exception e )
        {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}

