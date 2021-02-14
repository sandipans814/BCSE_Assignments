package MemberList;
import java.util.*;
public class Member{
    String memberID;
    String name;
    String DOB;
    int booksCurrentlyIssued;
    static final int maxBooks = 2;
    public Member(){
        memberID = null;
        name = null;
        DOB = null;
        booksCurrentlyIssued = 0;
    }
    public Member(String memberID, String name, String DOB, int booksCurrentlyIssued){
        this.memberID = memberID;
        this.name = name;
        this.DOB = DOB;
        this.booksCurrentlyIssued = booksCurrentlyIssued;
    }
    public void getDetails()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Member ID              : ");
        this.memberID = sc.nextLine();
        System.out.print("Enter name                   : ");
        this.name = sc.nextLine();
        System.out.print("Enter date of birth          : ");
        this.DOB = sc.nextLine();
        this.booksCurrentlyIssued = 0;
    }
    public void showDetails()
    {
        System.out.println();
        System.out.println("Member ID                     : "+this.memberID);
        System.out.println("Name                          : "+this.name);
        System.out.println("Date of birth                 : "+this.DOB);
        System.out.println("No. of books currently issued : "+this.booksCurrentlyIssued);
    }
    public void issueUtil(int flag)
    {
        if(flag == 0)
            this.booksCurrentlyIssued--;
        else if(flag == 1)
            this.booksCurrentlyIssued++;
    }
    public String returnMemberID()
    {
        return this.memberID;
    }
    public int returnBooksCurrentlyIssued(){
        return this.booksCurrentlyIssued;
    }
    public static int getMaxBooks(){
        return maxBooks;
    }
}