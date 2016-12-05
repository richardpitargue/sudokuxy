import java.awt.Dimension;

import java.io.Serializable;

public class Options implements Serializable {

    private boolean fullscreen;
    private Dimension dimension;

    public Options() {
        this.fullscreen = false;
        this.dimension = new Dimension(800, 600);
    }

    public void setFullScreen(boolean fullscreen) {
        this.fullscreen = fullscreen;
    }

    public void setDimension(int width, int height) {
        this.dimension.setSize(width, height);
    }

    public void setDimension(Dimension d) {
        this.dimension.setSize(d);
    }

    public boolean isFullscreen() {
        return this.fullscreen;
    }

    public Dimension getDimension() {
        return dimension;
    }

}
