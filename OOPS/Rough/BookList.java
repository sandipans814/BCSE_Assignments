package BookList;
import java.util.*;
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