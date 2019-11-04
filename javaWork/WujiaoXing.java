package javaWork;

import javax.swing.*;
import java.awt.*;

/**
 * @Author: xml
 * @Date: 2019/10/28 12:47
 * @Version 1.0
 */
class MyPanel extends JPanel{
    public void paintComponent(Graphics g){
        int xPoints[] = {239,180,52,146,124,238,353,332,423,295};//五角星的横坐标集合
        int yPoints[] = {75,194,215,312,446,383,445,311,218,197};//五角星的纵坐标集合
        g.setColor(Color.red);//设置颜色
       // g.fillPolygon(xPoints,yPoints,10);//以填充方式绘制五角星
        g.drawPolygon(xPoints,yPoints,10);
    }
}
public class WujiaoXing extends JFrame{
    WujiaoXing(){
        this.setTitle("五角星");//设置标题
        this.setSize(500,500);//设置窗体大小
        this.setVisible(true);//设置可见
        this.getContentPane().add(new MyPanel());//添加窗体元素
    }

    public static void main(String[] args) {
            new WujiaoXing();
    }
}
