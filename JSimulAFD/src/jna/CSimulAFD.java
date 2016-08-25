
// Example #1: Send and Receive an Integer

package jna;

import com.sun.jna.Library;
import com.sun.jna.Native;

public class CSimulAFD {
	public interface CLibrary extends Library {
		public int mainCSimulAFD(int argc, String[] argv);
	}

	static public void SimulAFD(String argv[]) {
		int status;
		CLibrary clib;

		try {
			clib = (CLibrary)Native.loadLibrary("./CSimulAFD.so", CLibrary.class);
			status = clib.mainCSimulAFD(argv.length, argv);
		}
		catch (UnsatisfiedLinkError e) {
			clib = (CLibrary)Native.loadLibrary("./bin/CSimulAFD.so", CLibrary.class);
			status = clib.mainCSimulAFD(argv.length, argv);		
		}
		
		System.out.println("status: " + status);
	}
}




