package ucfgens;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;

public class UCFFloorplanning {
	
	int numberElements = 0;
	
	UCFFloorplanning(int pNumberElements) {
		numberElements = pNumberElements;
	}
	
	public String generateFloorplanningConstrains() {
		return generateFloorplanningConstrains(0);
	}
	
	public String generateFloorplanningConstrains(int sliceSteps) {
		int xlow = 14;
		int xhigh = 63;
		int ylow = 0;
		int yhigh = 5;
		int x = 14;
		int y = 0;
		
		boolean direction = true;

		//HashSet<String> set = new HashSet<String>();
		
		String ucf = "";
		String templateA = "INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q1\" BEL = A6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q_temp\" BEL = A5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateB = "INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q1\" BEL = B6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q_temp\" BEL = B5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateC = "INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q1\" BEL = C6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q_temp\" BEL = C5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateD = "INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q1\" BEL = D6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q_temp\" BEL = D5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_middle_p.InverterElem_middle_p/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		
		String templateA_begin = "INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q1\" BEL = A6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q_temp\" BEL = A5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateB_begin = "INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q1\" BEL = B6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q_temp\" BEL = B5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateC_begin = "INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q1\" BEL = C6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q_temp\" BEL = C5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateD_begin = "INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q1\" BEL = D6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q_temp\" BEL = D5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_begin.InverterElem_begin/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		
		String templateA_end = "INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q1\" BEL = A6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q_temp\" BEL = A5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateB_end = "INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q1\" BEL = B6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q_temp\" BEL = B5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateC_end = "INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q1\" BEL = C6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q_temp\" BEL = C5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		String templateD_end = "INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q1\" BEL = D6LUT;\n" + 
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q1\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n" +
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q_temp\" BEL = D5FF;\n" +
				"INST \"test_circuit/reg[###ID###].reg_end.InverterElem_end/q_temp\" LOC = SLICE_X###XSLICE###Y###YSLICE###;\n\n";
		
		
		
		int internSliceCounter = 0;
		
		// Generation
		for(int i = 1; i <= numberElements; i++) {
			if(sliceSteps <= xhigh) {
				internSliceCounter = internSliceCounter + 1;
				
				if (i == 1) {
					if (internSliceCounter % 8 == 0
							|| internSliceCounter % 8 == 1) {
						ucf += templateA_begin;
					}
					if (internSliceCounter % 8 == 2
							|| internSliceCounter % 8 == 3) {
						ucf += templateB_begin;
					}
					if (internSliceCounter % 8 == 4
							|| internSliceCounter % 8 == 5) {
						ucf += templateC_begin;
					}
					if (internSliceCounter % 8 == 6
							|| internSliceCounter % 8 == 7) {
						ucf += templateD_begin;
					}
				} else {
					if(i == numberElements) {
						if (internSliceCounter % 8 == 0
								|| internSliceCounter % 8 == 1) {
							ucf += templateA_end;
						}
						if (internSliceCounter % 8 == 2
								|| internSliceCounter % 8 == 3) {
							ucf += templateB_end;
						}
						if (internSliceCounter % 8 == 4
								|| internSliceCounter % 8 == 5) {
							ucf += templateC_end;
						}
						if (internSliceCounter % 8 == 6
								|| internSliceCounter % 8 == 7) {
							ucf += templateD_end;
						}
					} else {
						if (internSliceCounter % 8 == 0
								|| internSliceCounter % 8 == 1) {
							ucf += templateA;
						}
						if (internSliceCounter % 8 == 2
								|| internSliceCounter % 8 == 3) {
							ucf += templateB;
						}
						if (internSliceCounter % 8 == 4
								|| internSliceCounter % 8 == 5) {
							ucf += templateC;
						}
						if (internSliceCounter % 8 == 6
								|| internSliceCounter % 8 == 7) {
							ucf += templateD;
						}
					}
				}
				ucf = ucf.replaceAll("###ID###", new Integer(i).toString());
				if (i % 2 == 0) {
					ucf = ucf.replaceAll("###XSLICE###",
							new Integer(x).toString());
					ucf = ucf.replaceAll("###YSLICE###",
							new Integer(yhigh).toString());
				} else {
					ucf = ucf.replaceAll("###XSLICE###",
							new Integer(x).toString());
					ucf = ucf.replaceAll("###YSLICE###",
							new Integer(ylow).toString());
				}
				if (i % 8 == 0) { //&& internSliceCounter % 4 == 0) {
					if (direction) {
						x++;
					} else {
						x--;
					}
				}
				if(direction && x > xhigh) {
					direction = false;
					x = xhigh;
					if(ylow < yhigh) {
						ylow++;
						yhigh--;
					}
				}
				if(!direction && x <= xlow) {
					direction = true;
					if(ylow < yhigh) {
						ylow++;
						yhigh--;
					}
				}
				
			}
		}
		
		System.out.print(ucf);
		File f = new File("main_floorplanning.ucf");
		try {
			FileWriter fw = new FileWriter(f, false);
			fw.write(ucf);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return ucf;
	}
	
	public static void main(String[] args) {
		try {
			System.setOut(new PrintStream(new File("floorplanner_results.txt")));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		UCFFloorplanning u = new UCFFloorplanning(1024);
		u.generateFloorplanningConstrains();
		//System.out.println(u.generateFloorplanningConstrains());
		
		//System.out.println();
		
		/*for(int i = 0; i < 128; i = i + 2) {
			int x = 8*i;
			int y = 8*i + 1;
			int i2 = i+1;
			//System.out.println(x + " - " + y);
			
			System.out.println("out_value(" + i + ")\t<=\tintern(" + x + ");");
			System.out.println("out_value(" + i2 + ")\t<=\tintern(" + y + ");");
		}*/
		/*
		try {
			System.setOut(new PrintStream(new File("bla.txt")));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
		
		for(int i = 0; i < 128; i++) {
			System.out.print("intr_out(" + i + ") \t <= \t (");
			for(int j = 0; j < 8; j++) {
				System.out.print("intern(" + (i*8+j+1) + ")");
				if(j != 7) {
					System.out.print(" AND ");
				} else {
					System.out.print(") OR (");
				}
			}
			
			for(int j = 0; j < 8; j++) {
				System.out.print("(NOT intern(" + (i*8+j+1) + "))");
				if(j != 7) {
					System.out.print(" AND ");
				} else {
					System.out.println(");");
				}
			}
		}
		*/
		//calculateMinFrequencyStep();
	}
	
	public static void calculateMinFrequencyStep() {
		double fin = 100.00;
		int range_low = 100, range_high = 210;
		int i = 1;
		
		try {
			System.setOut(new PrintStream(new File("freq_50.csv")));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
		System.out.println("index;fin;m;o;d;erg");

		for(fin = 50.00; fin <= 50.00; fin++) {
			for(int m = 1; m <= 6; m++) {
				for(int o = 1; o <= 5; o++) {
					for(int d = 1; d <= 1; d++) {
						double erg = fin * m / (o * d);
						if(true) {//erg>= range_low && erg <= range_high) {
							DecimalFormatSymbols dfs = DecimalFormatSymbols.getInstance();
							dfs.setDecimalSeparator(',');
							DecimalFormat dFormat = new DecimalFormat("0.00000", dfs);
							String zahlString = dFormat.format(erg);
							System.out.print(i + ";" + fin + ";" + m + ";" + o + ";" + d + ";");
							System.out.println(zahlString);
							i++;
						}
					}
				}
			}
		}
	}
	
}
