/**
 * Projeto: Tutorial
 * Pacote: jna
 * Classe: AutomatoStruct.java
 * Funcão: TODO
 * @author hugo
 * Data: 24/08/2016 18:26:42
 */
package jna;

import com.sun.jna.Structure;

public class AutomatoStruct extends Structure {
	public static class ByReference extends AutomatoStruct implements Structure.ByReference {}

	public AlfabetoStruct a;
	public EstadosStruct e; // Conjunto de Estados, Estado Inicial e Estados Finais
	public TransicaoStruct t;
}