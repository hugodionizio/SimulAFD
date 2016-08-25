package grafo;
import javax.swing.JOptionPane;

public class AdicionarArco extends Acoes {
	public AdicionarArco() {
		Object parent = this.getGraph().getDefaultParent();
		Object v1 = this.getM().get(JOptionPane.showInputDialog("Digite o estado x"));
		Object v2 = this.getM().get(JOptionPane.showInputDialog("Digite o estado y"));
		String nome = JOptionPane.showInputDialog("Digite a função do arco:");
		this.getGraph().insertEdge(parent, null, nome, v1, v2);
	}
}
