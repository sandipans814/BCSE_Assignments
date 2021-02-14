package mypackage;

//import memberList;
import java.util.Scanner;

class Book{
    String name;
    long bookID = 0;
    long numberOfCopies = 0;
    long available = 0;
    long issued = 0;
    long add = 0;

    Scanner scanner = new Scanner(System.in);
    public void setData(){
        System.out.print("Enter the Book ID: ");
        bookID = scanner.nextLong();
        System.out.print("Enter the title of the book: ");
        name = scanner.nextLine();
        System.out.print("Enter the total number of copies purchased: ");
        numberOfCopies = scanner.nextLong();
    }

    public void getData(){
        System.out.println("Book ID: " + bookID);
        System.out.println("Title: " + name);
        System.out.println("Total number of copies: " + numberOfCopies);
        System.out.println("Total number of copies available: " + available);
    }

    public void addCopies(){
        System.out.print("How many copies do you want to add?: ");
        add = scanner.nextLong();
        numberOfCopies += add;
        available = numberOfCopies - issued;
    }


}

class BookList{
    private Book[] bookOb = new Book[5];
    private int i;
    int count;
    int flag;

    Scanner scanner = new Scanner(System.in);

    BookList(){

    }

    private int availablePlace(){
        for(i=0; i<bookOb.length; i++){
            if(bookOb[i].bookID == 0)
                return i;
        }
        return -1;
    }

    public void addBook(){
        System.out.print("How many new books you want to add?: ");
        count = scanner.nextInt();
        flag = availablePlace();
        if(flag == -1){
            System.out.println("No more space available.");
            return ;
        }
        for(i=flag; i<count+flag; i++) {
            bookOb[i] = new Book();
            bookOb[i].setData();
        }
    }

    /*boolean isPresent(long id){
        for(i=0; i<bookOb.length; i++){
            if(bookOb[i].bookID == id) return true;
        }
        return false;
    }*/

    int isPresent(long id){
        for(i=0; i<bookOb.length; i++){
            if(bookOb[i].bookID == id) return i;
        }
        return -1;
    }

    public void addCopies(long id, int copies){
        if(isPresent(id) != -1){
            bookOb[isPresent(id)].addCopies();
        }
        else{
            System.out.println("Invalid Book ID.");
        }
    }

    public void showOne(long id){
        if(isPresent(id) != 1){
            bookOb[isPresent(id)].getData();
        }
        else{
            System.out.println("Invalid Book ID.");
        }
    }

    public void showAll(){
        for(i=0; i<bookOb.length; i++)
            bookOb[i].getData();
    }

}

public class J3 {
    public static void main(String[] args) {

    }
}
