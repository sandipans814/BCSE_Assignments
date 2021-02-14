import java.util.HashMap;
import java.util.Scanner;

class AccountList
{   
    HashMap <Integer, Account> map;
    int size;

    static Scanner sc = new Scanner(System.in);

    AccountList()
    {
        map = new HashMap <Integer, Account>();
    }

    private boolean doesExist(int ac_no)
    {
        return map.containsKey(ac_no);
    }

    void verifyExistence()
    {
        System.out.print("ENTER THE ACCOUNT NUMBER : "); int ac_no = sc.nextInt(); sc.nextLine();
        if (doesExist(ac_no))
            System.out.println("ACCOUNT DOES EXIST");
        else
            System.out.println("[ERROR] ACCOUNT DOES NOT EXIST");
    }

    void getBalance()
    {
        System.out.print("ENTER THE ACCOUNT NUMBER : "); int ac_no = sc.nextInt(); sc.nextLine();
        if (doesExist(ac_no))
            System.out.println("BALANCE : INR " + map.get(ac_no).getBalance());
        else
            System.out.println("[ERROR] ACCOUNT DOES NOT EXIST");
    }

    void addAccount()
    {
        System.out.print("ENTER THE ACCOUNT NUMBER : "); int ac_no = sc.nextInt(); sc.nextLine();
        System.out.print("ENTER THE NAME : "); String name = sc.nextLine();
        System.out.print("ENTER THE BALANCE IN INR : "); float balance = sc.nextFloat();

        Account A = new Account(ac_no, name, balance);

        if (doesExist(ac_no) == false)
            map.put(ac_no, A);
        else
            System.out.println("[ERROR] : ACCOUNT ALREADY EXISTS");
    }

    void displayAllAccounts()
    {
        for (Account A: map.values())
            A.display();
    }   

}