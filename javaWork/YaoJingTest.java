package javaWork;

/**
 * @Author: xml
 * @Date: 2019/10/28 12:24
 * @Version 1.0
 */
class YaoJing {
    String name;
    int age;
    String gender;

    public YaoJing(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    public void showBasicInfo() {
        System.out.println("姓名：" + this.name + "  道行:" + this.age + "  性别:" + this.gender);
    }

    public void eatTangseng() {
        System.out.println(this.name + "想吃唐僧");
    }
}

class Zhizhujing extends YaoJing {
    public Zhizhujing(String name, int age, String gender) {
        super(name, age, gender);
    }

    public void buildNet() {
        System.out.println("我会织网");
    }
}

class Baigujing extends YaoJing {
    public Baigujing(String name, int age, String gender) {
        super(name, age, gender);
    }

    public void beBeauty() {
        System.out.println("变成美女咯");
    }
}

public class YaoJingTest {
    public static void main(String[] args) {
        Zhizhujing zhizhujing = new Zhizhujing("蜘蛛精", 200, "女");
        zhizhujing.showBasicInfo();
        zhizhujing.buildNet();
        Baigujing baigujing = new Baigujing("白骨精", 100, "女");
        baigujing.showBasicInfo();
        baigujing.beBeauty();
    }
}

