import BookList.*;
import MemberList.*;
import TransactionList.*;


interface Library
{
    void addBook(BookList BL);
    void addCopies(String book_id, int copies, BookList BL);
    void showBookDetails(String book_id, BookList BL);
    void showAllBookDetails(BookList BL);
    
    void addMember(MemberList ML);
    void showMemberDetails(String member_id, MemberList ML);
    void showAllMemberDetails(MemberList ML);

    void issueBook(String book_id, BookList BL, String member_id, MemberList ML, TransactionList TL);
    void returnBook(String book_id, BookList BL, String member_id, MemberList ML, TransactionList TL);
}