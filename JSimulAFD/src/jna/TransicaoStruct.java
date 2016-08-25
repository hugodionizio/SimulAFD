/**
 * Projeto: Tutorial
 * Pacote: jna
 * Classe: TransicaoStruct.java
 * Funcão: TODO
 * @author hugo
 * Data: 24/08/2016 18:26:30
 */
package jna;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

public class TransicaoStruct extends Structure {
	public static class ByReference extends TransicaoStruct implements Structure.ByReference {}

	public int numSimbolos;
	public int numEstados;
	
	public Pointer funcoes; // char**
}