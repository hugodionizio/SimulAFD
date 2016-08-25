package grafo;

import java.util.Hashtable;

import com.mxgraph.util.mxConstants;
import com.mxgraph.view.mxStylesheet;

public class AdicionarEstado extends Acoes {

	public AdicionarEstado(String nome) {
		gerarGrafo(nome, "Normal");
	}
	
	public AdicionarEstado(String nome, boolean inicial) {
		gerarGrafo(nome, "Inicial");
	}
	
	public void gerarGrafo(String nome, String tipo) {
		this.getGraph().getModel().beginUpdate();
		Object parent = this.getGraph().getDefaultParent();

		mxStylesheet estado = graph.getStylesheet();
		Hashtable<String, Object> style = new Hashtable<String, Object>();
		style.put(mxConstants.STYLE_SHAPE, mxConstants.SHAPE_ELLIPSE);
		estado.putCellStyle("ESTADO", style);

		Object v1;
		if (tipo.equalsIgnoreCase("Normal")) {
			v1 = this.getGraph().insertVertex(parent, null, nome, 330, 30,
					50, 50, "ESTADO");			
		}
		else {
			nome = "Inicio";
			v1 = this.getGraph().insertVertex(parent, null, nome, 240, 30,
					50, 50, ";");
		}

		this.getM().put(nome, v1);
		this.getGraph().getModel().endUpdate();		
	}

}
