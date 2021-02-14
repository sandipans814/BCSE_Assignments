import java.lang.Thread;

class Data {
    int value;
    // boolean check;

    synchronized public void increment() 
    // public void increment() 
    {
        value++;
    }

    synchronized public void decrement() 
    // public void decrement() 
    {
        value--;
    }

    int getValue()
    {
        return value;
    }
}

class Incrementor implements Runnable {
    Data d;

    Incrementor(Data d) {
        this.d = d;
    }

    public void run() {
        int i = 0;
        int value = 1000;
        while (i < value) {
            d.increment();
            i++;
        }
    }
}

class Decrementor implements Runnable {
    Data d;

    Decrementor(Data d) {
        this.d = d;
    }

    public void run() {
        int i = 0;
        int value = 1000;
        while (i < value) {
            d.decrement();
            i++;
        }
    }
}

class Main 
{
    public static void main(String[] args) {
        Data d = new Data();
        Runnable in = new Incrementor(d);
        Runnable de = new Decrementor(d);

        Thread t1 = new Thread(in);
        Thread t2 = new Thread(in);

        Thread t3 = new Thread(de);
        Thread t4 = new Thread(de);

        t1.start();
        t2.start();
        t3.start();
        t4.start();

        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }       

        System.out.println("RESULT : " + d.getValue());
        
    }
}