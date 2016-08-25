// Projeto : JNA Example #15
// Classe: Example15.java
// Função : : Send a Struct Containing an Array of Structs to C
// Autor(es) : Hugo Dionizio Santos
// Data : Sáb Mai 16 16:27:45 BRT 2015

package jna;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Structure;

public class Example15 {
	public interface CLibrary extends Library {
		public static class Example15StructA extends Structure {
			public static class ByReference extends Example15StructA implements Structure.ByReference {}
		
			public int val;
		}
	
		public static class Example15StructB extends Structure {
			public static class ByReference extends Example15StructB implements Structure.ByReference {}
		
			public int numAs;
			public Example15StructA.ByReference as;
		}

//		public Example15Struct.ByValue example15_getStrings();
//		public void example15_cleanup(Example15Struct.ByValue sVal);
		public void example15_send(Example15StructB.ByReference sVal);
}

	static public void example15(String argv[]) {
		CLibrary clib;
		CLibrary.Example15StructB.ByReference ex15ref;
		
		System.out.println("Testando passagem de estrutura contendo arranjo de estruturas...");

		try {
			clib = (CLibrary)Native.loadLibrary("./libexample15.so", CLibrary.class);
			// generate data to send
			ex15ref = new CLibrary.Example15StructB.ByReference();
		}
		catch (UnsatisfiedLinkError e) {
			clib = (CLibrary)Native.loadLibrary("./bin/libexample15.so", CLibrary.class);
			// generate data to send
			ex15ref = new CLibrary.Example15StructB.ByReference();
		}

		ex15ref.numAs = 5;
		ex15ref.as = new CLibrary.Example15StructA.ByReference();

		// toArray generates a block of Example15StructA's that are suitable for passing to C
		CLibrary.Example15StructA[] ex15as = (CLibrary.Example15StructA[])ex15ref.as.toArray(ex15ref.numAs);

		// Note: do NOT allocate a new object for each struct in the array -
		//			toArray() has already allocated each array item
		for (int ex15loop=0; ex15loop<ex15ref.numAs; ex15loop++) {
			ex15as[ex15loop].val = ex15loop;
		}

		// call the C function to pass the data to C
		clib.example15_send(ex15ref);
	}
}

// Fim da classe
