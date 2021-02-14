package Transaction;
import java.util.*;
import BookList.*;
import MemberList.*;
public class Transaction
{
    class TransactionEntry{
        String memberID;
        String bookID;
        int flag;
        TransactionEntry(){
            memberID = null;
            bookID = null;
            flag = 0;
        }
        TransactionEntry(String memberID){
            this.memberID = memberID;
            this.bookID = null;
            flag = 0;
        }
        TransactionEntry(String memberID, String bookID){
            this.memberID = memberID;
            this.bookID = bookID;
            flag = 0;
        }
        String returnMemberID(){
            return this.memberID;
        }
        String returnBookID(){
            return this.bookID;
        }
        int returnFlag(){
            return this.flag;
        }
        void changeFlag(){
            this.flag = 1;
        }
    }
    ArrayList<TransactionEntry> TL = new ArrayList<TransactionEntry>();
    public void processIssue(BookList B, MemberList M, Transaction T){
        String mID, bID;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter member ID : ");
        mID = sc.nextLine();
        Member m = M.search(mID);
        if(m != null){
            System.out.println("Enter book ID : ");
            bID = sc.nextLine();
            Book b = B.search(bID);
            if(b != null){
                if(m.returnBooksCurrentlyIssued() <= Member.getMaxBooks()){
                TransactionEntry t = new TransactionEntry(mID,bID);
                m.issueUtil(1);
                b.issueUtil(0);
                TL.add(t);
                }
                else{
                    System.out.println("\nReached maximum book issue limit !!!\n");
                }
            }
            else{
                System.out.println("\nInvalid Book ID !!!\n");
            }
        }
        else{
            System.out.println("\nInvalid Member ID !!!\n");
        }
    }
    public TransactionEntry search(String mID, String bID){
        for(TransactionEntry t: TL){
            if(t.returnMemberID().equals(mID) && t.returnBookID().equals(bID) && t.returnFlag() == 0){
                return t;
            }
        }
        return null;
    }
    public void processReturn(BookList B, MemberList M, Transaction T){
        String mID, bID;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter member ID & book ID : ");
        mID = sc.nextLine();
        bID = sc.nextLine();
        Member m = M.search(mID);
        Book b = B.search(bID);
        TransactionEntry t = T.search(mID,bID);
        if(t != null && m.returnBooksCurrentlyIssued() >= 0){
            m.issueUtil(0);
            b.issueUtil(1);
            t.changeFlag();
        }
        else{
            System.out.println("Invalid transaction details !!!");
        }
    }
    public void showDetails(){
        for(TransactionEntry t: TL){
            System.out.println("\nMember ID : "+t.memberID);
            System.out.println("Book ID   : "+t.bookID);
            System.out.println("Status    : "+t.flag+"\n");
        }
    }
}