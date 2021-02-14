package BookList;
import java.util.*;
public class Book{
    String bookID;
    String title;
    int totalCopiesPurchased;
    int totalCopiesAvailable;
    public Book(){
        bookID = null;
        title = null;
        totalCopiesPurchased = 0;
        totalCopiesAvailable = 0;
    }
    public Book(String bookID, String title, int totalCopiesPurchased, int totalCopiesAvailable){
        this.bookID = bookID;
        this.title = title;
        this.totalCopiesPurchased = totalCopiesPurchased;
        this.totalCopiesAvailable = totalCopiesAvailable;
    }
    public void getDetails()
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Book ID                 : ");
        this.bookID = sc.nextLine();
        System.out.print("Enter title                   : ");
        this.title = sc.nextLine();
        System.out.print("Enter no. of copies purchased : ");
        this.totalCopiesPurchased = sc.nextInt();
        this.totalCopiesAvailable = this.totalCopiesPurchased;
    }
    public void showDetails()
    {
        System.out.println("\nBook ID                 : "+this.bookID);
        System.out.println("Title                   : "+this.title);
        System.out.println("No. of copies purchased : "+this.totalCopiesPurchased);
        System.out.println("No. of copies available : "+this.totalCopiesAvailable);
    }
    public void addCopyUtil(int copies)
    {
        this.totalCopiesPurchased += copies;
        this.totalCopiesAvailable += copies;
    }
    public void issueUtil(int flag)
    {
        if(flag == 0)
            this.totalCopiesAvailable--;
        else if(flag == 1)
            this.totalCopiesAvailable++;
    }
    String returnBookID()
    {
        return this.bookID;
    }
}