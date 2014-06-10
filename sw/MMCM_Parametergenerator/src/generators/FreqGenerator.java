package generators;

import java.io.File;
import java.io.PrintStream;
import java.text.DecimalFormat;

public class FreqGenerator {
	
  public static void main (String[] args) throws Exception {
	System.out.println("Starting MMCM parameter search...");
	System.setOut(new PrintStream(new File("freq.csv")));
	    
    int fin = 1250; 
    
    for(int d = 1; d <= 80 ; d++) {
    	for(int m = 1; m <= 64; m++) {
    		for(int o = 1; o <= 128 ; o++) {
    			double x = calc(fin, m, d, o);
    			DecimalFormat df = new DecimalFormat(",##0.000" );
    			if(x >= 360 && x < 400 && (fin * (m / d)) < 1200) {
    				System.out.println(fin + ";" + m + ";" + d +";" + o + ";" + df.format(x));
    			}
    		}
    	}
    }
	
  }
  
  public static double calc(int fin, int m, int d, int o) {
	  if(d <= 0 || o <= 0) return 1;
	  return (double)fin * m / (d * o);
  }
  
  public static double calc(int fin, int m, int d) {
	  if(d <= 0) return 1;
	  return (double)fin * m / d;
  }
  
  public static double min(double d, double e) {
	  return d < e ? d : e;
  }
}