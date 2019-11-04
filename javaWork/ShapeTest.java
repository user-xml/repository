package javaWork;

/**
 * @Author: xml
 * @Date: 2019/10/28 16:22
 * @Version 1.0
 */
abstract class Shape {
    String name;
    Shape(String name) {
        this.name = name;
        System.out.print("图形为:" + this.name);
    }

    abstract  public double area();
}

class Circle extends Shape {
    double r;

    Circle(String name, double r) {
        super(name);
        this.r = r;
        System.out.print("  半径为:" + this.r);
    }

    public double area() {
        return Math.PI * this.r * this.r;
    }
}

class Square extends Shape {
    double a;
    double b;

    public Square(String name, double a, double b) {
        super(name);
        this.a = a;
        this.b = b;
        System.out.print("  长为:" + this.a + "  宽为:" + this.b);
    }

    public double area() {
        return this.a * this.b;
    }
}

class Triangle extends Shape {
    double h;
    double x;

    public Triangle(String name, double h, double x) {
        super(name);
        this.h = h;
        this.x = x;
        System.out.print("  底为:" + this.x + "  高为:" + this.h);
    }

    public double area() {
        return this.h * this.x * 0.5;
    }
}

public class ShapeTest {
    public static void main(String[] args) {
        Shape circle = new Circle("圆形", 2);
        System.out.println("  面积为:" + circle.area());
        Shape square = new Square("正方形", 4, 5);
        System.out.println("  面积为:" + square.area());
        Shape triangle =  new Triangle("三角形",4,5);
        System.out.println("  面积为:" + triangle.area());
    }
}

