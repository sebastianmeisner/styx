package generators;

import java.io.PrintWriter;
import java.util.*;



public class FreqGenerator {
	
	// Frequency range for which we want to find all possible frequencies
	public static final double f_min = 360; // MHz
	public static final double f_max = 700; // MHz

	private static void dedubFromSorted(Vector<MMCMParameters> v){
		Iterator<MMCMParameters> i = v.iterator();
		if (i.hasNext()) { 
			MMCMParameters m_last = (MMCMParameters) i.next(); 
			while (i.hasNext()){
				MMCMParameters m_current = (MMCMParameters) i.next();
			    if ( m_last.getFrequency() == m_current.getFrequency() ){
			    	i.remove();
			    } else {
			    	m_last = m_current;
			    }
			}
		}
	}
	
	private static String toCArray(Vector<MMCMParameters> v){
	/* Example output:
		// 1.2 to ~1.326, 106 different frequencies
		// 350MHz Base: 420MHz to 464.088 MHz Range
		// 300MHz Base: 360MHz to 397.826 MHz Range
		volatile int m_values[] = {6,59,53,47,41,35,64,29,52,23,63,40,57,17,62,45,28,39,50,61,11,60,49,38,27,43,59,16,53,37,58,21,47,26,57,31,36,41,46,51,56,61,5,64,59,54,49,44,39,34,63,29,53,24,43,62,19,52,33,47,61,14,51,37,60,23,55,32,41,50,59,9,58,49,40,31,53,22,57,35,48,61,13,56,43,30,47,64,17,55,38,59,21,46,25,54,29,62,33,37,41,45,49,53,57,61};
		volatile int d_values[] = {5,49,44,39,34,29,53,24,43,19,52,33,47,14,51,37,23,32,41,50,9,49,40,31,22,35,48,13,43,30,47,17,38,21,46,25,29,33,37,41,45,49,4,51,47,43,39,35,31,27,50,23,42,19,34,49,15,41,26,37,48,11,40,29,47,18,43,25,32,39,46,7,45,38,31,24,41,17,44,27,37,47,10,43,33,23,36,49,13,42,29,45,16,35,19,41,22,47,25,28,31,34,37,40,43,46};
		volatile int o_values[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	*/	
		if (!v.isEmpty()){
			String comments_l1 = "// " + v.firstElement().getFactor() + " to "+ v.lastElement().getFactor() + ", " + v.size()+ " different frequencies";
			String comments_l2 = "// " + v.firstElement().f_in + " MHz Base: "+ v.firstElement().getFrequency()+ " MHz to " + v.lastElement().getFrequency() + " MHz Range"; 
			String m_values = "volatile int m_values[] = {";
			String d_values = "volatile int d_values[] = {";
			String o_values = "volatile int o_values[] = {";
			for (MMCMParameters p : v){
				m_values += p.m+",";
				d_values += p.d+",";
				o_values += p.o+",";
			}
			// remove last comma and add closing parenthesis
			m_values =  m_values.substring(0, m_values.length()-1)+"};";
			d_values =  d_values.substring(0, d_values.length()-1)+"};";
			o_values =  o_values.substring(0, o_values.length()-1)+"};";
			
			return comments_l1 + "\n" + comments_l2 + "\n" + m_values + "\n" + d_values + "\n" + o_values + "\n\n";
		} else {
			return "// no valid parameters for given base frequency (f_in).\n\n";
		}
	}
	
  public static void main (String[] args) throws Exception {
	System.out.println("Starting MMCM parameter search...");
	PrintWriter mmcm_params_writer = new PrintWriter("mmcm_params.h", "UTF-8");    
	
	double[] f_ins = {50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700};
	for (double f_in : f_ins){
		Vector<MMCMParameters> validParams = new Vector<MMCMParameters>();	 
		
	    for(int d = 1; d <= 80 ; d++) {
	    	for(int m = 1; m <= 64; m++) {
	    		for(int o = 1; o <= 128 ; o++) {
	    			MMCMParameters p = new MMCMParameters(f_in, m, d, o);
	    			if(p.valid() && p.withinLimitsOf(f_min, f_max)) {
	    				validParams.add(p);
	    			}
	    		}
	    	}
	    }
	    Collections.sort(validParams);
	    dedubFromSorted(validParams);
	    System.out.println("With f_in= "+f_in+" MHz we have "+validParams.size()+" valid frequencies.");
	    PrintWriter writer = new PrintWriter("freq"+f_in+".csv", "UTF-8");
	    Iterator<MMCMParameters> i = validParams.iterator();
	    while (i.hasNext()){
	    	writer.println(i.next().toString());	
	    }
	    writer.close();
	    
	    mmcm_params_writer.println(toCArray(validParams));
	    
	}
	mmcm_params_writer.close();
	System.out.println("Finished MMCM parameter search!");
  }
}