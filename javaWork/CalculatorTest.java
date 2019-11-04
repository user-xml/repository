package javaWork;

/**
 * @Author: xml
 * @Date: 2019/10/28 12:38
 * @Version 1.0
 */
class Calculator {
    public int add(int a, int b) {
        return a + b;
    }

    public String add(String a, String b) {
        return a + b;
    }

    public void add() {
        System.out.println("这是一个add方法");
    }
}

public class CalculatorTest {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        System.out.println(calculator.add(1, 2));
        System.out.println(calculator.add("a", "b"));
        calculator.add();
    }

}
