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

import jna.AlfabetoStruct;
import jna.AutomatoStruct;
import jna.EstadoStruct;
import jna.TransicaoStruct;

import com.mxgraph.analysis.mxAnalysisGraph;
import com.mxgraph.layout.mxCircleLayout;
import com.mxgraph.swing.mxGraphComponent;
import com.mxgraph.util.mxConstants;
import com.mxgraph.view.mxGraph;
import com.mxgraph.view.mxStylesheet;
import com.sun.jna.Library;
import com.sun.jna.Memory;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;

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

	public interface CLibrary extends Library {
		public static class EstadoStruct extends Structure {
			public static class ByReference extends EstadoStruct implements
					Structure.ByReference {
			}

			public int numEstados;
			public Pointer estados; // int*

			public char representacao;
			public int estadoInicial;
			public int numEstadosFinais;
			public Pointer estadosFinais; // int*
		}

		public static class Alfabeto extends Structure {
			public static class ByReference extends Alfabeto implements
					Structure.ByReference {
			}

			public int numSimbolos;
			public Pointer simbolos; // char*
		}

		public static class Transicao extends Structure {
			public static class ByReference extends Transicao implements
					Structure.ByReference {
			}

			public int numSimbolos;
			public int numEstados;

			public Pointer funcoes; // char**
		}

		public static class Automato extends Structure {
			public static class ByReference extends Automato implements
					Structure.ByReference {
			}

			public Alfabeto a;
			public EstadoStruct e; // Conjunto de Estados, Estado Inicial e
									// Estados Finais
			public Transicao t;
		}
		
		public int verificarAutomato(Automato aut); 
	}

	CLibrary clib;
	CLibrary.EstadoStruct.ByReference estAut;
	CLibrary.Alfabeto.ByReference alfAut;
	CLibrary.Transicao.ByReference traAut;
	CLibrary.Automato.ByReference aut;

	public static HashMap getM() {
		return m;
	}

	public static mxGraph getGraph() {
		return graph;
	}

	public Acoes() {
		super("JSimulAFD - Simulador de AFD em JNA");

		try {
			clib = (CLibrary) Native.loadLibrary("./CSimulAFD.so",
					CLibrary.class);
			// generate data to send
			estAut = new CLibrary.EstadoStruct.ByReference();
		} catch (UnsatisfiedLinkError e2) {
			clib = (CLibrary) Native.loadLibrary("./bin/CSimulAFD.so",
					CLibrary.class);
			// generate data to send
			estAut = new CLibrary.EstadoStruct.ByReference();
		}

		initGUI();
	}

	private void initGUI() {
		setSize(800, 600);
		// setSize(700, 500);
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

		/*
		 * Object parent = this.getGraph().getDefaultParent();
		 * graph.getModel().beginUpdate(); try { mxStylesheet stylesheet =
		 * graph.getStylesheet(); Hashtable<String, Object> style = new
		 * Hashtable<String, Object>(); style.put(mxConstants.STYLE_SHAPE,
		 * mxConstants.SHAPE_DOUBLE_ELLIPSE);
		 * style.put(mxConstants.STYLE_OPACITY, 50);
		 * style.put(mxConstants.STYLE_FONTCOLOR, "#774400");
		 * stylesheet.putCellStyle("ROUNDED", style);
		 * 
		 * String nome = "Inicio"; Object v0 = graph.insertVertex(parent, null,
		 * nome, 20, 20, 30, 30, ";strokeColor=red;fillColor=green");
		 * this.getM().put(nome, v0);
		 * 
		 * nome = "Hello,"; Object v1 = graph.insertVertex(parent, null, nome,
		 * 60, 60, 40, 40, "ROUNDED;strokeColor=red;fillColor=green");
		 * this.getM().put(nome, v1);
		 * 
		 * nome = "World!"; Object v2 = graph.insertVertex(parent, null,
		 * "World!", 200, 150, 80, 30, "defaultVertex;fillColor=blue");
		 * this.getM().put(nome, v2);
		 * 
		 * Object inicio = graph.insertEdge(parent, null, "", v0, v1); Object e1
		 * = graph.insertEdge(parent, null, "a", v1, v1);
		 * 
		 * } finally { // Updates the display graph.getModel().endUpdate(); }
		 */
		JButton botaoAdd = new JButton("Adicionar");
		botaoAdd.setBounds(243, 390, 100, 25);
		getContentPane().add(botaoAdd);
		botaoAdd.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if (texto.getText().length() > 0) {
					AdicionarEstado add = new AdicionarEstado(texto.getText());
					estAut.numEstados++;

					estAut.representacao = texto.getText().charAt(0);
				}

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
				estAut.numEstados--;
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
					este = (com.mxgraph.model.mxCell) estado;

					if (este.getValue().toString().equalsIgnoreCase("Inicio")) {
						JOptionPane.showMessageDialog(null,
								"Estado inicial já existe");
						// System.out.println("Não é para gerar!!!");
						existe = true;
						break;
					}
					// else break;
				}

				if (!existe) {
					AdicionarEstado add = new AdicionarEstado("Inicio", true);

					graph.getModel().beginUpdate();
					Object v0 = getM().get("Inicio");
					Object e1 = graph.insertEdge(parent, null, "", v0, cell);
					graph.getModel().endUpdate();
					com.mxgraph.model.mxCell estIni;
					estIni = (com.mxgraph.model.mxCell) cell;
					estAut.estadoInicial = Integer.parseInt(estIni.getValue()
							.toString().substring(1));
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
				style.put(mxConstants.STYLE_SHAPE,
						mxConstants.SHAPE_DOUBLE_ELLIPSE);
				estado.putCellStyle("ESTADOFINAL", style);

				graph.getModel().setStyle(cell, "ESTADOFINAL");
				estAut.numEstadosFinais++;
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
				System.out.println("Verificando sequência: "
						+ sequencia.getText());

				Object parent = getGraph().getDefaultParent();
				int numEstados = graph.getChildVertices(parent).length;

				char representCarac = '\0';
				int ordemEstado;

				// estAut.numEstados = graph.getChildVertices(parent).length -
				// 1;
				if (estAut.numEstadosFinais > 0)
					estAut.estados = new Memory(estAut.numEstados
							* Native.getNativeSize(int.class));
				if (estAut.numEstadosFinais > 0)
					estAut.estadosFinais = new Memory(estAut.numEstadosFinais
							* Native.getNativeSize(int.class));

				int i = 0;
				for (Object estado : graph.getChildVertices(parent)) {

					com.mxgraph.model.mxCell este;
					este = (com.mxgraph.model.mxCell) estado;

					if (!este.getValue().toString().equalsIgnoreCase("Inicio")) {
						representCarac = este.getValue().toString().charAt(0);
						ordemEstado = Integer.parseInt(este.getValue()
								.toString().substring(1));

						System.out.println("Estado [" + este.getId()
								+ "]: representação: " + representCarac
								+ " ordem na lista: " + ordemEstado);
						if (este.getStyle().equalsIgnoreCase("ESTADOFINAL")) {
							System.out.println("Estado de Aceitação");
							// estAut.estadosFinais.setInt(i, ordemEstado);
						}
						//estAut.estados.setInt(i, ordemEstado);

						/*
						 * if
						 * (este.getValue().toString().equalsIgnoreCase("Inicio"
						 * )) numEstados--;
						 */
						i++;
					}
				}
				// estAut.representacao = representCarac;
				// estAut.estadoInicial = 0;

				System.out.println("Símbolo de representação dos estados: "
						+ estAut.representacao);
				System.out.println("Estado inicial: " + estAut.estadoInicial);
				// System.out.println("Valor do estado[ "+i+"]: "
				// +estAut.estados[i]);
				System.out.println("Número de estados: " + estAut.numEstados);
				// System.out.println("Valor do estado final[ "+i+"]: "
				// +estAut.estadosFinais[i]);
				System.out.println("Número de estados finais: "
						+ estAut.numEstadosFinais);
				
				aut.a = alfAut;
				aut.e = estAut;
				aut.t = traAut;
			}
		});

		JButton botaoLimpar = new JButton("Limpar Autômato");
		botaoLimpar.setBounds(440, 455, 170, 25);
		getContentPane().add(botaoLimpar);
		botaoLimpar.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				Object parent = getGraph().getDefaultParent();
				for (Object estado : graph.getChildVertices(parent)) {

					com.mxgraph.model.mxCell este;
					este = (com.mxgraph.model.mxCell) estado;

					Object trash = getM().get(este.getValue().toString());
					graph.removeCells(new Object[] { trash });
				}
				if (estAut.estados != null)
					estAut.estados.clear(0);
				estAut.numEstados = 0;
				if (estAut.estadosFinais != null)
					estAut.estadosFinais.clear(0);
				estAut.numEstadosFinais = 0;
				estAut.representacao = '\0';
				estAut.estadoInicial = -1;
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