/**
 * Projeto: Tutorial
 * Pacote: jna
 * Classe: EstadosStruct.java
 * Funcão: TODO
 * @author hugo
 * Data: 24/08/2016 18:25:58
 */
package jna;

import com.sun.jna.Pointer;
import com.sun.jna.Structure;

public class EstadosStruct extends Structure {
	public static class ByReference extends EstadosStruct implements Structure.ByReference {}			
	public int numEstados;
	public Pointer estados; // int*

	public char representacao;
	public int estadoInicial;
	public int numEstadosFinais;
	public Pointer estadosFinais; // int*
}