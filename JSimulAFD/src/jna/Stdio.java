package jna;

import com.sun.jna.Library;
import com.sun.jna.Native;

public class Stdio {
	public interface CLibrary extends Library {
	}
	
	public static void exemploStdio () {
		CLibrary clib;

		try {
			clib = (CLibrary) Native.loadLibrary("./libexample.so",
					CLibrary.class);
		} catch (UnsatisfiedLinkError e) {
			clib = (CLibrary) Native.loadLibrary("./bin/libexample.so",
					CLibrary.class);
		}		
	}
}
