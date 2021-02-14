import java.util.Scanner;

class BankAcct{
    int accountNumber;
    static double interestRate;
    double balance;
    double interest;
    double time;

    public static void displayRate(){
        System.out.println("The interest rate is: "+ interestRate);
    }
    public static void setInterestRate(){
      System.out.print("Enter the interest rate : ");
      Scanner sc= new Scanner(System.in);
      interestRate = sc.nextDouble();
      System.out.println("Rate is set");
    }
    public void updateData()
    {
    	interest = balance * time * interestRate;
     }
    public void setData(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the account number :");
        accountNumber = scanner.nextInt();
        System.out.print("Enter the balance: ");
        balance = scanner.nextDouble();
        System.out.print("Enter the duration: ");
        time = scanner.nextDouble();
        interest = balance * time * interestRate;
    }

    double returnBalance(){
        return balance;
    }

    double returnInterest(){
        return interest;
    }

}


public class Main {
    public static void main(String[] args) {
        int key,ac;
        Scanner scanner = new Scanner(System.in);
        //System.out.print("Enter the interest rate for all accounts: ");
        BankAcct.setInterestRate();
        BankAcct ob[] = new BankAcct[3];
        System.out.println("1.Enter account details. 2.Show account details. 3.Change interest rate for all accounts.");
        System.out.println("Enter your choice. Press 0 to stop.");
        key = scanner.nextInt();
        for(int i=0; key!=0; i++){
            switch(key){
                case 1:
                	ob[i] = new BankAcct();
                    ob[i].setData();
                    break;

                case 2:
                    System.out.print("Enter the account number: ");
                    int flag = 0;
                    ac = scanner.nextInt();
                    for(int j=0; j<3; j++){
                        if(ob[j].accountNumber == ac) {
                            BankAcct.displayRate();
                            System.out.println("Principal is: "+ob[j].returnBalance());
                            System.out.println("Interest is: "+ob[j].returnInterest());
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0) System.out.println("No information available.");
                    break;

                case 3:
                    System.out.print("Enter the interest rate for all accounts: ");
                    BankAcct.setInterestRate();
                    for(int k=0;k<3;k++)
                    {
                    	ob[k].updateData();
                    }
                    break;
            }
            System.out.print("Enter your choice: ");
            key = scanner.nextInt();
        }

    }
}
