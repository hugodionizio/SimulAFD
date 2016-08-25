/**
 * Projeto: Tutorial
 * Pacote: jna
 * Classe: AlfabetoStruct.java
 * Funcão: Criar e gerenciar alfabetos
 * @author hugo
 * Data: 24/08/2016 18:06:59
 */
package jna;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

public class AlfabetoStruct extends Structure {
	public static class ByReference extends AlfabetoStruct implements Structure.ByReference {}

	public int numSimbolos;
	public Pointer simbolos; // char*
}