import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.*;



public class lab3test{


   public static void main(String[] args) {
		int[] xArray={-1424,
				-3424,
				4352,
				6544,
				3152,
				11696,
				12080,
				7920,
				8480,
				6880,
				4208,
				5392,
				-896,
				6128,
				-3456,
				-4448,
				-2816,
				-7216,
				-8368,
				-10896,
				-6832,
				-11296,
				-3264,
				1376,
				-4304,
				2816,
				6144,
				-1280,
				880,
				8784,
				6480,
				10432,
				10720,
				9744,
				10544,
				7008,
				6912,
				-2912,
				-1088,
				-3536,
				-10064,
				-5472,
				-10880,
				-3408,
				-10816,
				-6064,
				-6192,
				-8624,
				-11056,
				-2224,
				-3312,
				4048,
				5616,
				11152,
				8848,
				5680,
				9424,
				4736,
				7344,
				6160,
				4816,
				1968,
				4608,
				-7168,
				-1616,
				-1888,
				-3920,
				-5520,
				-7920,
				-5952,
				-5920,
				-7760,
				-6848,
				-4912,
				-6864,
				-768,
				2432,
				4976,
				10336,
				5760,
				9840,
				10800,
				11136,
				4160,
				7008,
				5600,
				-288,
				-1408,
				2512,
				-3440,
				-3536,
				-6016,
				-9488,
				-9888,
				-6720,
				-10896,
				-4352,
				-3744,
				-6640,
				-2912,
				-3888,
				-5184,
				7184,
				3904,
				7984,
				8560,
				8240,
				4752,
				4304,
				5088,
				928,
				-448,
				5856,
				-848,
				-7008,
				-4944,
				-10016,
				-11840,
				-8896,
				-5056,
				-7376,
				-4768,
				-9440,
				-5456,
				-2896};
		int[] filter= {	234,
				-33,
				-188,
				-404,
				-600,
				-663,
				-476,
				43,
				904,
				2027,
				3248,
				4350,
				5117,
				5392,
				5117,
				4350,
				3248,
				2027,
				904,
				43,
				-476,
				-663,
				-600,
				-404,
				-188,
				-33,
				234};
		int[] storedThings=new int[27];
	 	int[] results=new int[xArray.length];

	 	int num=0;
        int[] testX={0,1,2,3,4,5,6,7,8,   9,10,11,12,13,14,15,16,17};
        int[] testFilter={  8,7,6,5,4,3,2,1,0};
        for(int i=26; i<xArray.length; i++){
        	for(int n=0; n<26; n++){
        		//System.out.println(Arrays.toString(storedThings));
        		shift(storedThings);
        		//System.out.println(Arrays.toString(storedThings));
        		//System.out.println(xArray[i-n]+" x "+testFilter[n]+" = "+testX[i-n]*testFilter[n]);
        		storedThings[26]+=xArray[i-n]*filter[n];
        	}
        	results[i-26]=summ(storedThings);
        	}
        print(results);
        	//results[i-26]=summ(storedThings);
   //}
       // print(results);     
   }
   public static void print(int[] array){
	   String s="";
   for(int x=26; x<array.length; x++)
   {
	   s=s+array[x]+" , ";
   }
   System.out.println(s);
   }
   public static void shift(int[] array){

	   for(int x=0; x<array.length-1; x++){
		 array[x]=array[x+1];
	   }
	   array[array.length-1]=0;
   }
   public static int summ(int[] array){
	   int sum=0;
	   for(int x=0; x<array.length; x++){
		   sum+=array[x];
	   }
	   return sum;
   }
}


