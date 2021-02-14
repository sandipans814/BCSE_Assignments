import java.lang.Thread;

class Reader implements Runnable
{
    Data d; Permission p;
    Reader(Data d, Permission p)
    {
        this.d = d;
        this.p = p;
    }

    public void run()
    {
        while(true)
        {   
            p.seekReadPermission();
            try { Thread.sleep(1000); } catch (InterruptedException e) { e.printStackTrace(); }
            System.out.println("READ : " + d.read());
            p.readOverNotify();
        }
    }
}

class Writer implements Runnable
{
    Data d; Permission p;
    Writer(Data d, Permission p)
    {
        this.d = d;
        this.p = p;
    }

    public void run()
    {
        int i = 0;
        while(true)
        {
            p.seekWritePermission();
            try { Thread.sleep(2000); } catch (InterruptedException e) { e.printStackTrace(); }
            System.out.println("WRITTEN : " + i);
            d.write(i);
            p.writeOverNotify();
            i++;
        }
    }
}

class Main
{
    public static void main(String[] args) {
        Data d = new Data();
        Permission p = new Permission();
        Reader r = new Reader(d, p);
        Writer w = new Writer(d, p);

        Thread rt = new Thread(r);
        Thread wt = new Thread(w);

        rt.start();
        wt.start();

        try
        {
            rt.join();
            wt.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
    }
}