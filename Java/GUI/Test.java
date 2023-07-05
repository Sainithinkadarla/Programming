import java.awt.*;
import java.awt.event.*;

public class Test extends Frame
{
    public Test()
    {
        Button b = new Button("Joker");
        Label l = new Label("Start");
        b.setSize(50, 50);
        l.setSize(50,50);
        setLayout(new FlowLayout());
        setVisible(true);
        setSize(300,300);
        b.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                l.setText("Clicked");
            }
        });
        add(b);
        add(l);
        
    }

    public static void main(String[] args)
    {
        new Test();
    }
}