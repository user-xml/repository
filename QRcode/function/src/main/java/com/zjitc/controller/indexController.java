package com.zjitc.controller;


import com.zjitc.utils.QRcode;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;


/**
 * @Author: xml
 * @Date: 2018/11/7 17:23
 * @Version 1.0
 */
@Controller
public class indexController {
    @RequestMapping("/index")
    public String index(){
        return "index";
    }

    public static void main(String[] args) {
        boolean flag = false;
        String msg = "解析错误！";
        //生成二维码
        flag = QRcode.encodeQRCodeImage("https://www.baidu.com/","utf-8","D:\\二维码.png",200,200,"D:\\jh.png");
        //解析二维码
         if(flag){
            msg =  QRcode.decodeQRCodeImage("D:\\二维码.png","utf-8");
         }
        System.out.println(msg);
    }

}
