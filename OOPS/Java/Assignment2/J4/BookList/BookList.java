package BookList;
import java.util.*;
class Book{
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
public class BookList {
    ArrayList<Book> BL;
    public BookList(){
        BL = new ArrayList<Book>();
    }
    public void addNewBook(){
        Book b = new Book();
        System.out.println("\nENTER BOOK DETAILS\n");
        b.getDetails();
        BL.add(b);
    }
    public void addCopies(String ID, int n){
        for(Book b: BL){
            if(b.returnBookID().equals(ID)){
                b.addCopyUtil(n);
                return;
            }
        }
        System.out.println("Invalid Book ID\n");
    }
    public Book search(String ID){
        for(Book b: BL){
            if(b.returnBookID().equals(ID)){
                return b;
            }
        }
        return null;
    }
    public void showDetails(){
        for(Book b: BL){
            b.showDetails();
            System.out.println();
        }
    }
    public void showDetails(String ID){
        for(Book b: BL){
            if(b.returnBookID().equals(ID)){
                b.showDetails();
                return;
            }
        }
        System.out.println("Invalid Book ID\n");
    }
}
