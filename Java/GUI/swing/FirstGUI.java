import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


class FirstGUI
{
		public static void main(String[] args)
		{
			new App();
			
		}
}

class App extends JFrame
{
	JLabel l;
	JLabel l2;
	JButton b;
	JButton b2;

	App()
	{
		l = new JLabel("OM");
		l2 = new JLabel("Label 2");
		b= new JButton("Button 1");
		b2= new JButton("Button 2");
		b.addActionListener(new ActionHandler());
		b2.addActionListener(new ActionHandler2());
		add(l);
		add(l2);
		add(b);
		add(b2);
		setLayout(new FlowLayout());
		setVisible(true);
		setSize(400,400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
	}
	class ActionHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			l.setText(b.getText()+" is clicked");
		}
	}
	class ActionHandler2 implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			l2.setText(b2.getText()+" is clicked");
		}
	}

}
