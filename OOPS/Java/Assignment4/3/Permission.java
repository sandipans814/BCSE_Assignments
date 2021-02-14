class Permission 
{
    private int check_read;
    private int check_write;
    private int check_write_queue;

    synchronized public void seekReadPermission()
    {
        if(check_write > 0 || check_write_queue > 0)
        {
            try
            {
                wait();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }

    synchronized public void readOverNotify()
    {
        check_read--;
        notifyAll();
    }

    synchronized public void seekWritePermission()
    {
        check_write_queue++;
        if (check_read > 0 || check_write > 0)
        {
            try
            {
                wait();
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
        check_write_queue--;
        check_write++;
    }

    synchronized public void writeOverNotify()
    {
        check_write--;
        notifyAll();
    }
}