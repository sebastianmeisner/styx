package generators;

import java.text.DecimalFormat;

public class MMCMParameters implements Comparable<MMCMParameters> {
	
	// Parameter of the used FPGA. This values are from the "Virtex-6 FPGA Data Sheet"
	// FPGA: Virtex-6 Speedgrade: -1
	public static final double f_vcomin = 600; // MHz
	public static final double f_vcomax = 1200; // MHz
	public static final double f_pfdmin = 10; //135; // MHz
	public static final double f_pfdmax = 300; //450; // MHz
	public static final double f_inmax = 10; // MHz
	public static final double f_inmin = 700; // MHz
	
	// Input frequency to the MMCM, must be between f_inmin and f_inmax
	public double f_in = 350; //MHz 
	
	public int	  m;
	public int    d;
	public int    o;
	
	public MMCMParameters( double f_in, int m, int d, int o) {
		this.f_in = f_in;
		this.m = m;
		this.d = d;
		this.o = o;
	}
	
	public double getFactor(){
		return (double)this.m / (this.d * this.o);
	}
	
	public double getFrequency(){
		if(this.d <= 0 || this.o <= 0){ return 1;}
		return this.f_in * this.getFactor();
	}
	
	public boolean withinLimitsOf(double f_min, double f_max){
		 if (this.getFrequency()>= f_min && 
				 this.getFrequency() < f_max)
		 { return true;}
		 else {return false;}
	}
	
	  public boolean valid() {
		    // According to the "Virtex-6 FPGA Clocking Resources User Guide" certain 
		    // rules have to be followed to generate valid  MMCM parameters:
		    // see "MMCM Programming" -> "Determine the Input Frequency"
			boolean pass = false;
			if ( (this.f_in / this.d) < MMCMParameters.f_pfdmax 
				 &&(this.f_in / this.d) > MMCMParameters.f_pfdmin
				 &&(this.f_in * (this.m / this.d)) < MMCMParameters.f_vcomax
				 && (this.f_in * (this.m / this.d)) > MMCMParameters.f_vcomin
				 )
				{ pass = true;}		
			return pass;		
		}
	  
	  public String toString(){
		  DecimalFormat df = new DecimalFormat(",##0.000" );  
		  return this.f_in + ";" + this.m + ";" + this.d +";" + this.o + ";" + df.format(this.getFrequency());
	  }
	  
	  public int compareTo(MMCMParameters p){
		  if (p.getFrequency() < this.getFrequency()) return 1;
		  if (p.getFrequency() > this.getFrequency()) return -1;
		  else{ // Second order sort parameter:
			    // According to the "Virtex-6 FPGA Clocking Resources User Guide" lower d values 
			    //(and therefore higher vco frequencies) are better for frequency synthesis.
			    // see "MMCM Programming" -> "Determine the M and D Values"
			  if (p.d < this.d) return 1;
			  if (p.d > this.d) return -1;
			  else return 0;
		  }
	  }
}
