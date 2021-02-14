class Account
{
    int ac_no;
    String name;
    float balance;

    void setAccountNumber(int ac_no) { this.ac_no = ac_no; }
    void setName(String name) { this.name = name; }
    void setBalance(float balance) { this.balance = balance; }

    float getBalance() { return balance;}

    Account(int ac_no, String name, float balance)
    {
        setAccountNumber(ac_no);
        setName(name);
        setBalance(balance);
    }

    Account(int ac_no)
    {
        setAccountNumber(ac_no);
    }

    @Override
    public int hashCode()
    {
        return ac_no * name.hashCode();
    }

    void display()
    {
        System.out.println("------------------------------------------");
        System.out.println("ACCOUNT NUMBER : " + ac_no);
        System.out.println("NAME : " + name);
        System.out.println("BALANCE : " + balance);
        System.out.println("------------------------------------------");
    }

}