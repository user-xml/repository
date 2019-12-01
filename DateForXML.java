package com.xml.springboot;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Scanner;
/**
 * @Author: xml
 * @Date: 2019/11/30 21:31
 * @Version 1.0
 */
public class DateForXML {
    public static void main(String[] args) throws ParseException {
        Calendar calendar = Calendar.getInstance();
        SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
        String dateCount = "7123456";
        String weekend = "一二三四五六日";
        int day = 1;
        Scanner scanner = new Scanner(System.in);
        System.out.print("请您输入年份:");
        int year = scanner.nextInt();
        System.out.print("请您输入月份:");
        int month = scanner.nextInt();
        Date date = format.parse(year + "-" + month + "-" + day);
        int dayCount = judgeMonthDay(year,month);
        calendar.setTime(date);
        int weekDay = calendar.get(Calendar.DAY_OF_WEEK);
        String startWeekDay = dateCount.substring(weekDay - 1, weekDay);
        int flag = Integer.parseInt(startWeekDay) - 1;
        for (int i = 0; i < weekend.length(); i++) {
            System.out.print(weekend.charAt(i) + "  ");
        }
        System.out.println();
        for (int j = 0; j < Integer.parseInt(startWeekDay) - 1; j++) {
            System.out.print("    ");
        }

        for (int i = 0; i < dayCount; i++) {
            if (day >= 10) {
                System.out.print(day++ + "  ");
            } else {
                System.out.print(day++ + "   ");
            }
            flag++;
            if (flag % 7 == 0) {
                System.out.println();
            }
        }
    }
    /**
     * 天数31天的月份 1 3 5 7 8 10 12
     * 天数30天的月份 4 6 9 11
     * 闰年二月份29天
     * 平年二月份28天
     *
     * @param year
     * @param month
     * @return
     */
    protected  static int judgeMonthDay(int year, int month) {
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }
}


