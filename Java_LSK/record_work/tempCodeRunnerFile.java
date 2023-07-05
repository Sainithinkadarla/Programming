import java.awt.*;
import java.awt.event.*;
import java.io.*;

import javax.swing.*;

public class DigitalClock_Demo extends JFrame 
{
    private JButton readFileButton;
    private JButton writeFileButton;
    private JTextArea textArea;

    public DigitalClock_Demo() {        
        setTitle("File Read/Write Example");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        
        readFileButton = new JButton("Read File");
        writeFileButton = new JButton("Write File");
        textArea = new JTextArea();
        
        readFileButton.addActionListener(new ReadFileButtonListener());
        writeFileButton.addActionListener(new WriteFileButtonListener());
        
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.add(readFileButton, BorderLayout.NORTH);
        panel.add(writeFileButton, BorderLayout.SOUTH);
        panel.add(new JScrollPane(textArea), BorderLayout.CENTER);        
        add(panel);        
        setVisible(true);
    }

    class ReadFileButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {            
            JFileChooser fileChooser = new JFileChooser();
            int result = fileChooser.showOpenDialog(DigitalClock.this);

            if (result == JFileChooser.APPROVE_OPTION) {
                File inputFile = fileChooser.getSelectedFile();
                try 
                {                    
                    BufferedReader reader = new BufferedReader(new FileReader(inputFile));
                    StringBuilder content = new StringBuilder();
                    String line;
                    while ((line = reader.readLine()) != null) {
                        content.append(line).append("\n");
                    }
                    reader.close();                    
                    textArea.setText(content.toString());
                } catch (IOException ex) {ex.printStackTrace();}
            }
        }
    }

    class WriteFileButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            
            JFileChooser fileChooser = new JFileChooser();
            int result = fileChooser.showSaveDialog(DigitalClock.this);

            if (result == JFileChooser.APPROVE_OPTION) {
                File outputFile = fileChooser.getSelectedFile();

                try {
                    
                    BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
                    writer.write(textArea.getText());
                    writer.close();

                    JOptionPane.showMessageDialog(DigitalClock.this,
                            "File written successfully!", "File Write",
                            JOptionPane.INFORMATION_MESSAGE);
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        new DigitalClock();
    }
}
