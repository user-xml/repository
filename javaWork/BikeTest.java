package javaWork;

/**
 * @Author: xml
 * @Date: 2019/10/28 12:43
 * @Version 1.0
 */
class Bike {
    public void maxSpeed() {
        System.out.println("自行车的最高时速是30公里");
    }
}

class Ebike extends Bike {
    public void maxSpeed() {
        System.out.println("电动自行车的最高时速是40公里");
    }
}

public class BikeTest {
    public static void main(String[] args) {
        Bike bike = new Ebike();
        bike.maxSpeed();
    }
}
