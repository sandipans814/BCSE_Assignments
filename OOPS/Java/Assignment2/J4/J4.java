import java.util.Scanner;
import BookList.*;
import MemberList.*;
import Transaction.*;
interface LibraryInterface{
    void addBook();
    void searchBook();
    void viewAllBooks();
    void addMember();
    void searchMember();
    void viewAllMembers();
    void issueBook();
    void returnBook();
}
class J4 implements LibraryInterface{
    Scanner sc = new Scanner(System.in);
    BookList B;
    MemberList M;
    Transaction T;
    J4(){
        B = new BookList();
        M = new MemberList();
        T = new Transaction();
    }
    String ID;
    @Override
    public void addBook() {
        B.addNewBook();
    }
    @Override
    public void searchBook(){
        System.out.println("\nEnter book ID : ");
        ID = sc.nextLine();
        B.showDetails(ID);
    }
    @Override
    public void viewAllBooks(){
        B.showDetails();
    }
    @Override
    public void addMember(){
        M.addNewMember();
    }
    @Override
    public void searchMember(){
        System.out.println("\nEnter member ID : ");
        ID = sc.nextLine();
        M.showDetails(ID);
    }
    @Override
    public void viewAllMembers(){
        M.showDetails();
    }
    @Override
    public void issueBook(){
        T.processIssue(B, M, T);
    }
    @Override
    public void returnBook(){
        T.processReturn(B, M, T);
    }

    public void viewAllTransaction(){
        T.showDetails();
    }

    public void simulate(){
        int ch;
        System.out.println("\n_____________________LIBRARY_____________________\n");
        do{
            System.out.print("\nEnter 1 to add new book\nEnter 2 to search for a book\nEnter 3 to view all books\n");
            System.out.print("Enter 4 to add a member\nEnter 5 to search for a member\nEnter 6 to view all members\n");
            System.out.print("Enter 7 to issue a book\nEnter 8 to return a book\nEnter 9 to show all transaction details\n");
            System.out.print("Enter 10 to exit\n");
            System.out.print("\nEnter choice : ");
            ch = sc.nextInt();
            sc.nextLine();
            switch(ch){
                case 1:
                    addBook();
                    break;
                case 2:
                    searchBook();
                    break;
                case 3:
                    viewAllBooks();
                    break;
                case 4:
                    addMember();
                    break;
                case 5:
                    searchMember();
                    break;
                case 6:
                    viewAllMembers();
                    break;
                case 7:
                    issueBook();
                    break;
                case 8:
                    returnBook();
                    break;
                case 9:
                    viewAllTransaction();
                    break;
                case 10:
                    System.out.print("Exiting...\n");
                    break;
                default:
                    System.out.print("Wrong Choice !!!\n");
            }
        }while(ch != 10);
        sc.close();
    }
                    
    public static void main(String[] args){
        J4 Lib = new J4();
        Lib.simulate();
    }
}
