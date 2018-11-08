package com.zjitc.utils;

import javax.imageio.ImageIO;
import javax.servlet.http.HttpServletRequest;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;

/**
 * @Author: xml
 * @Date: 2018/11/5 17:08
 * @Version 1.0
 */
public class InvoiceUtils {

    /**
     * 注意---》字段不要超过12个字！
     * 发票名==订单号
     * @param request
     * @param userName
     * @param money
     * @param productName
     * @param address
     * @param productImg
     * @param orderNumber
     */
    public static void getInvoice(HttpServletRequest request, String userName, String money, String productName, String address, String productImg, String orderNumber){
       String path =  request.getSession().getServletContext().getRealPath("");
       String backgroundImgPath = path+"static/img/invoice/bgi.png";
       String produceImgPath = path+"static/img/invoice/"+orderNumber+".png";
        try {
            //创建画布
            BufferedImage image = new BufferedImage(480, 270, BufferedImage.TYPE_INT_RGB);
            //背景图
            BufferedImage background = ImageIO.read(new File(backgroundImgPath));
            //商品照片
            BufferedImage icon = ImageIO.read(new File(path+productImg));
            //开启画图
            Graphics2D graphics = image.createGraphics();
            //把背景图、头像添加到画布中
            graphics.drawImage(background.getScaledInstance(480, 270, Image.SCALE_DEFAULT), 0, 0, null);
            graphics.drawImage(icon.getScaledInstance(180, 227, Image.SCALE_DEFAULT), 300, 43, null);
            //写入信息
            setMsgIntoGraphics(graphics, userName, 100, 70);
            setMsgIntoGraphics(graphics, money, 100, 110);
            setMsgIntoGraphics(graphics, productName, 100, 155);
            setMsgIntoGraphics(graphics, address, 100, 195);
            //关闭画布创作
            graphics.dispose();
            //根据画布内容生成图片
            File file = new File(produceImgPath);
            if(file.exists()){
                file.delete();
            }
            ImageIO.write(image, "png",file );
            System.out.println("xml--->发票生成成功");
        } catch (Exception ex) {
            System.out.println("error: " + ex.getMessage());
            ex.printStackTrace();
        }

    }
    private static   void setMsgIntoGraphics(Graphics2D graphics, String msg, int x, int y) {
        graphics.setFont(new Font("微软雅黑", Font.PLAIN, 17));
        graphics.setColor(Color.white);
        graphics.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        graphics.drawString(msg, x, y);

    }

}
