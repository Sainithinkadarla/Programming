import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class RecursiveFibonacciSwing extends JFrame {
    private JTextField inputField;
    private JTextArea outputArea;
    private JButton calculateButton;

    public RecursiveFibonacciSwing() {
        setTitle("Recursive Fibonacci Series");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        inputField = new JTextField(10);

        outputArea = new JTextArea();
        outputArea.setEditable(false);
        outputArea.setLineWrap(true);

        calculateButton = new JButton("Calculate");
        calculateButton.addActionListener(new CalculateButtonListener());

        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.add(new JLabel("Enter the number of terms:"), BorderLayout.NORTH);
        panel.add(inputField, BorderLayout.CENTER);
        panel.add(calculateButton, BorderLayout.SOUTH);

        getContentPane().add(panel, BorderLayout.NORTH);
        getContentPane().add(new JScrollPane(outputArea), BorderLayout.CENTER);

        setVisible(true);
    }

    class CalculateButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {

            int n = Integer.parseInt(inputField.getText());

            outputArea.setText("");

            for (int i = 0; i < n; i++) {
                int fibonacci = calculateFibonacci(i);
                outputArea.append(fibonacci + " ");
            }
        }
    }

    private int calculateFibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return calculateFibonacci(n - 1) + calculateFibonacci(n - 2);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new RecursiveFibonacciSwing();
            }
        });
    }
}
