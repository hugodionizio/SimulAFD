// Projeto : JNA Example #15
// Classe: Example15.java
// Função : : Send a Struct Containing an Array of Structs to C
// Autor(es) : Hugo Dionizio Santos
// Data : Sáb Mai 16 16:27:45 BRT 2015

package jna;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Structure;

public class ExampleStructInt {
	public interface CLibrary extends Library {
		public static class ExampleStructIntA extends Structure {
			public static class ByReference extends ExampleStructIntA implements Structure.ByReference {}
		
			public int val;
		}
	
		public static class ExampleStructIntB extends Structure {
			public static class ByReference extends ExampleStructIntB implements Structure.ByReference {}
		
			public int numAs;
			public ExampleStructIntA.ByReference as;
		}
		
		//		public ExampleStructInt.ByValue exampleStructInt_getStrings();
//		public void exampleStructInt_cleanup(ExampleStructInt.ByValue sVal);
		public int exampleStructInt_send(ExampleStructIntB.ByReference sVal);
}

	static public void exampleStructInt(String argv[]) {
		CLibrary clib;
		CLibrary.ExampleStructIntB.ByReference exStructIntref;
		int finalValue = 0;
		
		try {
			clib = (CLibrary)Native.loadLibrary("./libexampleStructInt.so", CLibrary.class);
			// generate data to send
			exStructIntref = new CLibrary.ExampleStructIntB.ByReference();
		}
		catch (UnsatisfiedLinkError e) {
			clib = (CLibrary)Native.loadLibrary("./bin/libexampleStructInt.so", CLibrary.class);
			// generate data to send
			exStructIntref = new CLibrary.ExampleStructIntB.ByReference();
		}

		exStructIntref.numAs = 6;
		exStructIntref.as = new CLibrary.ExampleStructIntA.ByReference();

		// toArray generates a block of ExampleStructIntA's that are suitable for passing to C
		CLibrary.ExampleStructIntA[] exStructIntas = (CLibrary.ExampleStructIntA[])exStructIntref.as.toArray(exStructIntref.numAs);

		// Note: do NOT allocate a new object for each struct in the array -
		//			toArray() has already allocated each array item
		for (int exStructIntloop=0; exStructIntloop<exStructIntref.numAs; exStructIntloop++) {
			exStructIntas[exStructIntloop].val = exStructIntloop;
		}

		// call the C function to pass the data to C
		finalValue = clib.exampleStructInt_send(exStructIntref);
		
		System.out.println("Valor final = "+finalValue);
	}
}

// Fim da classe
