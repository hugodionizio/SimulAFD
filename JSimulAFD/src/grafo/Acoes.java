package grafo;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
//import java.awt.event.MouseListener;
import java.util.HashMap;
import java.util.Hashtable;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import com.mxgraph.analysis.mxAnalysisGraph;
import com.mxgraph.layout.mxCircleLayout;
import com.mxgraph.swing.mxGraphComponent;
import com.mxgraph.util.mxConstants;
import com.mxgraph.view.mxGraph;
import com.mxgraph.view.mxStylesheet;

public class Acoes extends JFrame {
	protected static mxGraph graph = new mxGraph();
	protected mxAnalysisGraph aGraph;
	protected static HashMap m = new HashMap();
	private mxGraphComponent graphComponent;
	private JTextField texto;
	private JTextField sequencia;
	private JButton botaoAdd;
	private JButton botaoDel;
	private JButton botaoLigar;
	private JButton botaoInicial;
	private JButton botaoFinal;
	private JButton botaoSequencia;
	private JButton botaoLimpar;
	private Object cell;
	private JLabel lblauthor;

	public static HashMap getM() {
		return m;
	}

	public static mxGraph getGraph() {
		return graph;
	}

	public Acoes() {
		super("JSimulAFD - Simulador de AFD em JNA");
		initGUI();
	}

	private void initGUI() {
		setSize(800, 600);
		//setSize(700, 500);
		setLocationRelativeTo(null);
		mxCircleLayout layout;
		getContentPane().setLayout(null);
		getContentPane().setLayout(null);

		// graph = new mxGraph();
		graphComponent = new mxGraphComponent(graph);
		graphComponent.setBounds(64, 5, 670, 380);
		// graphComponent.setPreferredSize(new Dimension(770, 480));
		graphComponent.setPreferredSize(new Dimension(670, 380));
		getContentPane().add(graphComponent);

		texto = new JTextField();
		texto.setBounds(28, 392, 210, 20);
		getContentPane().add(texto);
		// texto.setPreferredSize(new Dimension(520, 21));
		texto.setPreferredSize(new Dimension(210, 20));
		
		// layout = new mxCircleLayout(graph, 1);
		// layout.execute(graph.getDefaultParent());

		// Adds cells to the model in a single step

/*		Object parent = this.getGraph().getDefaultParent();
		graph.getModel().beginUpdate();
		try {
			mxStylesheet stylesheet = graph.getStylesheet();
			Hashtable<String, Object> style = new Hashtable<String, Object>();
			style.put(mxConstants.STYLE_SHAPE, mxConstants.SHAPE_DOUBLE_ELLIPSE);
			style.put(mxConstants.STYLE_OPACITY, 50);
			style.put(mxConstants.STYLE_FONTCOLOR, "#774400");
			stylesheet.putCellStyle("ROUNDED", style);
			
			String nome = "Inicio";			
			Object v0 = graph.insertVertex(parent, null, nome, 20, 20, 30,
					30, ";strokeColor=red;fillColor=green");
			this.getM().put(nome, v0);
			
			nome = "Hello,";
			Object v1 = graph.insertVertex(parent, null, nome, 60, 60, 40,
					40, "ROUNDED;strokeColor=red;fillColor=green");
			this.getM().put(nome, v1);
			
			nome = "World!";
			Object v2 = graph.insertVertex(parent, null, "World!", 200, 150,
					80, 30, "defaultVertex;fillColor=blue");
			this.getM().put(nome, v2);
			
			Object inicio = graph.insertEdge(parent, null, "", v0, v1);
			Object e1 = graph.insertEdge(parent, null, "a", v1, v1);
			
		} finally {
			// Updates the display
			graph.getModel().endUpdate();
		}
*/
		JButton botaoAdd = new JButton("Adicionar");
		botaoAdd.setBounds(243, 390, 100, 25);
		getContentPane().add(botaoAdd);
		botaoAdd.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				AdicionarEstado add = new AdicionarEstado(texto.getText());

				texto.setText("");
			}
		});

		JButton botaoDel = new JButton("Deletar");
		botaoDel.setBounds(348, 390, 87, 25);
		getContentPane().add(botaoDel);
		botaoDel.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				graph.getModel().remove(cell);
				// DeletarEstado del = new DeletarEstado(texto.getText());
			}
		});

		JButton botaoLigar = new JButton("Ligar");
		botaoLigar.setBounds(440, 390, 70, 25);
		getContentPane().add(botaoLigar);
		botaoLigar.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				AdicionarArco linha = new AdicionarArco();
				// TODO Auto-generated method stub

			}
		});
		
		JButton botaoInicial = new JButton("Estado Inicial");
		botaoInicial.setBounds(515, 390, 128, 25);
		getContentPane().add(botaoInicial);
		botaoInicial.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				boolean existe = false;
				
				Object parent = getGraph().getDefaultParent();
				
				for (Object estado : graph.getChildVertices(parent)) {
					
					com.mxgraph.model.mxCell este;
					este = (com.mxgraph.model.mxCell)estado;
					
					if (este.getValue().toString().equalsIgnoreCase("Inicio")) {
						JOptionPane.showMessageDialog(null, "Estado inicial já existe");
//						System.out.println("Não é para gerar!!!");
						existe = true;
						break;
					}
//					else break;
				}

				if (!existe) {
					AdicionarEstado add = new AdicionarEstado("Inicio", true);
					
					graph.getModel().beginUpdate();
						Object v0 = getM().get("Inicio");
						Object e1 = graph.insertEdge(parent, null, "", v0, cell);
					graph.getModel().endUpdate();
				}				
			}
		});

		JButton botaoFinal = new JButton("Estado Final");
		botaoFinal.setBounds(648, 390, 121, 25);
		getContentPane().add(botaoFinal);
		botaoFinal.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				mxStylesheet estado = graph.getStylesheet();
				Hashtable<String, Object> style = new Hashtable<String, Object>();
				style.put(mxConstants.STYLE_SHAPE, mxConstants.SHAPE_DOUBLE_ELLIPSE);
				estado.putCellStyle("ESTADOFINAL", style);

				graph.getModel().setStyle(cell,"ESTADOFINAL");				
			}
		});

		JTextField sequencia = new JTextField();
		sequencia.setBounds(28, 458, 210, 20);
		getContentPane().add(sequencia);
		sequencia.setPreferredSize(new Dimension(210, 20));

		JButton botaoSequencia = new JButton("Verificar sequência");
		botaoSequencia.setBounds(255, 455, 170, 25);
		getContentPane().add(botaoSequencia);
		botaoSequencia.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				System.out.println("Verificando sequência: "+sequencia.getText());

				Object parent = getGraph().getDefaultParent();
				int numEstados = graph.getChildVertices(parent).length;
				
				for (Object estado : graph.getChildVertices(parent)) {
					
					com.mxgraph.model.mxCell este;
					este = (com.mxgraph.model.mxCell)estado;
					
					System.out.println("Estado ["+este.getId()+"] "+este.getValue().toString());
					if (este.getValue().toString().equalsIgnoreCase("Inicio"))
						numEstados--;
				}
				System.out.println("Número de estados: "+numEstados);
			}
		});
		
		JButton botaoLimpar = new JButton("Limpar");
		botaoLimpar.setBounds(440, 455, 82, 25);
		getContentPane().add(botaoLimpar);
		botaoLimpar.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				Object parent = getGraph().getDefaultParent();
				for (Object estado : graph.getChildVertices(parent)) {
					
					com.mxgraph.model.mxCell este;
					este = (com.mxgraph.model.mxCell)estado;					
								
					Object trash = getM().get(este.getValue().toString());
					graph.removeCells(new Object[]{trash});
				}				
			}
		});

		graphComponent.getGraphControl().addMouseListener(new MouseAdapter() {

			@Override
			public void mouseReleased(MouseEvent e) {
				cell = graphComponent.getCellAt(e.getX(), e.getY());
			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub

			}

			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub

			}
		});

		/*
		 * graph.getModel().beginUpdate(); Object parent =
		 * graph.getDefaultParent(); graph.insertVertex(parent, null, "TESTE",
		 * 30, 80, 100, 50); graph.getModel().endUpdate();
		 */
		
		lblauthor = new JLabel("by Hugo Dionizio Santos");
		lblauthor.setFont(new Font("Dialog", Font.BOLD, 9));
		lblauthor.setBounds(630, 544, 139, 15);
		getContentPane().add(lblauthor);
	}
}