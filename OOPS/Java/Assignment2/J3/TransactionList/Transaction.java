package TransactionList;

public class Transaction
{
    String book_id; 
    String member_id;

    void setBookId(String book_id){ this.book_id = book_id; }
    public void setMemberId(String member_id){ this.member_id = member_id; }

    Transaction(String book_id, String member_id)
    {
        setBookId(book_id);
        setMemberId(member_id);
    }
}