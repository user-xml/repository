package javaWork;

import javax.swing.*;
import java.awt.*;

/**
 * @Author: xml
 * @Date: 2019/10/28 16:05
 * @Version 1.0
 */
class CustomDraw extends JPanel {
    public void paintComponent(Graphics g) {
        int x = 145, y = 250;
        g.setColor(Color.green);//设置颜色
        g.setFont(new Font("楷体", Font.BOLD, 100));
        g.drawString("xml", x, y);
    }
}
public class CustomDrawTest extends JFrame {
    public CustomDrawTest() {
        this.setTitle("xml");
        this.setSize(500, 500);
        this.setVisible(true);//设置可见
        this.getContentPane().add(new CustomDraw());
    }
    public static void main(String[] args) {
        new CustomDrawTest();
    }
}


