import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.BorderFactory;

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.Dimension;

import java.util.ArrayList;

public class Solution extends JFrame{
  private ArrayList<int[][]> solutions;
  private JButton[][] sudoku;
  private JPanel[] panels;
  private JScrollPane scrollthis;
  FlowLayout layout = new FlowLayout();
  GridLayout gridlayout;

  public Solution(String name, int[][] data){
    super(name);
    setLayout(layout);

    SudokuSolver solver = new SudokuSolver();
    solver.init(data, 0, 2);
    solutions = solver.findSolutions(data, 0, 2);

    panels = new JPanel[solutions.size()];
    sudoku = new JButton[4][4];

    gridlayout = new GridLayout(solutions.size(), 0);

    JPanel scrollpanel = new JPanel(gridlayout);

    for(int k=0; k<solutions.size(); k++){
      int[][] soln = solutions.get(k);
      panels[k] = new JPanel(new GridLayout(soln.length, soln[0].length));

      for(int i=0; i<soln.length; i++){
        for(int j=0; j<soln[0].length; j++){
          sudoku[i][j] = new JButton(Integer.toString(soln[i][j]));
          panels[k].add(sudoku[i][j]);
        }
      }

      panels[k].setBorder(BorderFactory.createTitledBorder("Solution " + (k+1)));
      scrollpanel.add(panels[k]);
    }

    scrollthis = new JScrollPane(scrollpanel, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
    scrollthis.setPreferredSize(new Dimension(600, 400));
    add(scrollthis);

    setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    setResizable(false);
    pack();
    setLocationRelativeTo(null);
    setVisible(true);
  }
}
