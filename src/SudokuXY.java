import java.awt.Dimension;

import javax.swing.JFrame;

import java.io.ObjectInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.FileOutputStream;

public class SudokuXY {

    private JFrame frame;

    private Options options;

    public SudokuXY() {
        frame = new JFrame("Ang Ganda Ni Ma'am Kat SudokuXY");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);

        // load options from file
        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream("config/options"));
            options = (Options) ois.readObject();
        } catch(IOException ioe) {
            System.err.println(ioe.getMessage());
            options = new Options();

            System.err.println("Creating default options file.");
            try {
                ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("config/options"));
                oos.writeObject(options);
            } catch(IOException ioe2) {
                System.err.println(ioe2.getMessage());
            }
        } catch(ClassNotFoundException cnfe) {
            System.err.println(cnfe.getMessage());
        }

        frame.getContentPane().add(new MenuPanel(options));

        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

}
