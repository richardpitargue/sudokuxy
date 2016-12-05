import java.awt.Dimension;

import javax.swing.JFrame;

import java.io.ObjectInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.FileOutputStream;

public class SudokuXY {

    private JFrame frame;

    public SudokuXY() {
        frame = new JFrame("Ang Ganda Ni Ma'am Kat SudokuXY");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);

        frame.getContentPane().add(new MenuPanel());

        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

}
