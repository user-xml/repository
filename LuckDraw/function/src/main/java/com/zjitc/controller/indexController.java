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

    @RequestMapping("/cj")
    public String cj(){
        return "cj";
    }


}
