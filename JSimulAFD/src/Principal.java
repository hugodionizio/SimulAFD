import grafo.Acoes;
import jnaf.CSimulAFD;
/*import jnaf.Example15;
import jnaf.ExampleStructInt;
import jnaf.Stdio;
*/
public class Principal {

	public Principal() {
		Acoes a = new Acoes();
		a.setVisible(true);
	}

	public static void main(String[] args) {
		System.out.println("Boas vindas ao "
				+ "Simulador de Autômatos Finitos Determinísticos"
				+ " em JNA (C/JGraph)!");
				
		new Principal();
		
/*		Stdio.exemploStdio();
		Example1.Example1(args);
		Example15.example15(args);
		ExampleStructInt.exampleStructInt(args);
*/		
		CSimulAFD.SimulAFD(args);
	}
}
