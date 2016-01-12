package studio6;

import java.io.InputStream;
import java.io.OutputStream;

import gnu.io.SerialPort;

public class ViewOutputStream extends OutputStream {
	static SerialPort serialPort;
	   SerialComm s=new SerialComm();
	   OutputStream out;
	public ViewOutputStream() {
		//super(o);
		//out=o;
		// FIXME Auto-generated constructor stub
	}
	public void write(int a){
		
	}
}
