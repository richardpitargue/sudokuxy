import javax.swing.JPanel;

public class MenuPanel extends JPanel {

    private Options options;

    public MenuPanel(Options options) {
        super();
        this.options = options;
        setPreferredSize(options.getDimension());
    }

}
