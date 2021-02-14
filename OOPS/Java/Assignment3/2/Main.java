import java.util.Scanner;

class Main
{
    public static void main(String[] args) {
        AccountList AL = new AccountList();
        Scanner sc = new Scanner(System.in);

        int ch = 0;
        do
        {
            System.out.println("ENTER 1 : TO ADD A NEW ACCOUNT");
            System.out.println("ENTER 2 : TO FETCH BALANCE");
            System.out.println("ENTER 3 : TO VERIFY EXISTENCE OF ACCOUNT");
            System.out.println("ENTER 4 : TO DISPLAY ALL ACCOUNTS");
            System.out.println("ENTER 0 : TO QUIT");
            System.out.print("CHOICE : "); ch = sc.nextInt();

            if (ch == 1)
                AL.addAccount();
            else if (ch == 2)
                AL.getBalance();
            else if (ch == 3)
                AL.verifyExistence();
            else if (ch == 4)
                AL.displayAllAccounts();

        }while(ch != 0);      

    }
}