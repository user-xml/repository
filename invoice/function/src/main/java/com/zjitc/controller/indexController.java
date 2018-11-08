package com.zjitc.controller;

import com.zjitc.utils.InvoiceUtils;
import org.apache.commons.io.FileUtils;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import java.io.File;
import java.io.IOException;

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
    @RequestMapping("/invoice")
    public ResponseEntity<byte[]> preduceInvoice(HttpServletRequest request) throws IOException {

        String userName ="用户X";
        String money = "8888";
        String productName ="火箭x1";
        String address = "北京中关村";
        String productImg = "/static/img/invoice/hj.png";
        String orderNumber = "9090909090909";
        String path = request.getSession().getServletContext().getRealPath("/")+"static/img/invoice/"+orderNumber+".png";
        File file = new File(path);
        if(file.exists()){
            file.delete();
        }
        InvoiceUtils.getInvoice(request,userName,money,productName,address,productImg,orderNumber);
        String fileName = path.split("/")[path.split("/").length-1];
        fileName = new String(fileName.getBytes("utf-8"), "iso-8859-1");
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        headers.setContentDispositionFormData("attachment", fileName);
        return new ResponseEntity<byte[]>(FileUtils.readFileToByteArray(file),headers, HttpStatus.CREATED);
    }
}
