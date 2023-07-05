import javax.swing.*;
import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.Date;

public class DigitalClock extends JFrame {

    private JLabel timeLabel;

    public DigitalClock() {
        setTitle("Digital Clock");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(200, 100);
        setResizable(false);
        setLocationRelativeTo(null);

        timeLabel = new JLabel();
        timeLabel.setHorizontalAlignment(SwingConstants.CENTER);
        timeLabel.setFont(new Font("Arial", Font.BOLD, 24));

        add(timeLabel);

        Timer timer = new Timer(1000, e -> updateTime());
        timer.start();

    }

    private void updateTime() {
        SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm:ss");
        String currentTime = dateFormat.format(new Date());
        timeLabel.setText(currentTime);
    }

    public static void main(String[] args) {
        DigitalClock clock = new DigitalClock();
        clock.setVisible(true);
    }
}
