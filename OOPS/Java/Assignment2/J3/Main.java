import java.util.Scanner;

import BookList.*;
import MemberList.*;
import TransactionList.*;

class Main implements Library
{
    public void addBook(BookList BL)
    {
        BL.addBook();
    }

    public void addCopies(String book_id, int copies, BookList BL)
    {
        BL.addCopies(book_id, copies);
    }

    public void showBookDetails(String book_id, BookList BL)
    {
        BL.showBookDetails(book_id);
    }

    public void showAllBookDetails(BookList BL)
    {
        BL.showAllBookDetails();
    }

    public void addMember(MemberList ML)
    {
        ML.addMember();
    }

    public void showMemberDetails(String member_id, MemberList ML)
    {
        ML.showMemberDetails(member_id);
    }

    public void showAllMemberDetails(MemberList ML)
    {
        ML.showAllMemberDetails();
    }

    public void issueBook(String book_id, BookList BL, String member_id, MemberList ML, TransactionList TL)
    {
        Book B = BL.getBookFromList(book_id);
        Member M = ML.getMemberFromList(member_id);

        if (B != null && M != null)
        {
            if (B.getAvailable() >= 1 && M.isEligible() == true)
            {
                B.setAvailable(B.getAvailable() - 1);
                M.setIssued(M.getIssued() + 1);
                TL.addTransaction(B.getBookId(), M.getMemberId());
            }
            else
                System.out.println("[ERROR] : NO ISSUE AVAILABLE");
        }
        else if (B != null)
            System.out.println("[ERROR] : NO SUCH BOOK EXISTS");
        else
            System.out.println("[ERROR] : NO SUCH MEMBER EXISTS");
    }

    public void returnBook(String book_id, BookList BL, String member_id, MemberList ML, TransactionList TL)
    {
        Transaction T = TL.getTransactionFromList(book_id, member_id);
        if (T != null)
        {
            Book B = BL.getBookFromList(book_id);
            Member M = ML.getMemberFromList(member_id);
            
            if (B != null && M != null)
            {
                B.setAvailable(B.getAvailable() + 1);
                M.setIssued(M.getIssued() - 1);
                T.setMemberId("XXXX");
            }
            else if (B != null)
                System.out.println("[ERROR] : NO SUCH BOOK EXISTS");
            else
                System.out.println("[ERROR] : NO SUCH MEMBER EXISTS");
        }
        else
        {
            System.out.println("[ERROR] : NO SUCH TRANSACTION EXISTS");
        }
    }

    public static void main(String[] args) {
        BookList BL = new BookList();
        MemberList ML = new MemberList();
        TransactionList TL = new TransactionList();
        Main M = new Main();

        Scanner sc = new Scanner(System.in);

        int ch = 0;
        do {
            System.out.println("ENTER 1 : ADD NEW BOOK");
            System.out.println("ENTER 2 : ADD MORE COPIES OF A BOOK");
            System.out.println("ENTER 3 : SHOW ALL BOOK DETAILS");
            System.out.println("ENTER 4 : SHOW DETAILS OF A BOOK");
            System.out.println("ENTER 5 : ADD NEW MEMBER");
            System.out.println("ENTER 6 : SHOW ALL MEMBER DETAILS");
            System.out.println("ENTER 7 : SHOW DETAILS OF A MEMBER");
            System.out.println("ENTER 8 : ISSUE A BOOK");
            System.out.println("ENTER 9 : RETURN A BOOK");
            System.out.println("ENTER 0 : TO QUIT");
            System.out.print("CHOICE : "); ch = sc.nextInt(); sc.nextLine();


            if (ch == 1)
                M.addBook(BL);
            else if (ch == 2)
            {
                System.out.print("ENTER BOOK ID : "); String book_id = sc.nextLine();
                System.out.print("ENTER THE NUMBER OF COPIES : "); int copies = sc.nextInt(); sc.nextLine();             
                M.addCopies(book_id, copies, BL);
            }
            else if (ch == 3)
                M.showAllBookDetails(BL);
            else if (ch == 4)
            {
                System.out.print("ENTER BOOK ID : "); String book_id = sc.nextLine();
                M.showBookDetails(book_id, BL);
            }
            else if (ch == 5)
            {
                M.addMember(ML);
            }
            else if (ch == 6)
            {
                M.showAllMemberDetails(ML);
            }
            else if (ch == 7)
            {
                System.out.print("ENTER MEMBER ID : "); String member_id = sc.nextLine();
                M.showMemberDetails(member_id, ML);
            }
            else if (ch == 8)
            {
                System.out.print("ENTER BOOK ID : "); String book_id = sc.nextLine();
                System.out.print("ENTER MEMBER ID : "); String member_id = sc.nextLine();
                M.issueBook(book_id, BL, member_id, ML, TL);
            }
            else if (ch == 9)
            {
                System.out.print("ENTER BOOK ID : "); String book_id = sc.nextLine();
                System.out.print("ENTER MEMBER ID : "); String member_id = sc.nextLine();
                M.returnBook(book_id, BL, member_id, ML, TL);
            }
        }while(ch != 0);

        sc.close();
    }
}

