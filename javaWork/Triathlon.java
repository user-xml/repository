package javaWork;

/**
 * @Author: xml
 * @Date: 2019/10/28 16:44
 * @Version 1.0
 */
interface Swim {
    abstract public void showSwim();
}

interface RideBike {
    abstract public void showRideBike();
}

interface Running {
    abstract public void showRunning();
}

class IronMan implements Swim, RideBike, Running {

    @Override
    public void showSwim() {
        System.out.println("我在游泳");
    }

    @Override
    public void showRideBike() {
        System.out.println("我在骑车");
    }

    @Override
    public void showRunning() {
        System.out.println("我在长跑");
    }
}

public class Triathlon {
    public static void main(String[] args) {
        IronMan ironMan = new IronMan();
        ironMan.showRideBike();
        ironMan.showRunning();
        ironMan.showSwim();

    }
}
