package TransactionList;

public class TransactionList
{
    static int CAPACITY = 10000;
    
    int size;
    Transaction transactions[];

    public TransactionList()
    {
        size = 0;
        transactions = new Transaction[CAPACITY];
    }

    public void addTransaction(String book_id, String member_id)
    {
        Transaction T = new Transaction(book_id, member_id);
        transactions[size++] = T;
    }

    public Transaction getTransactionFromList(String book_id, String member_id)
    {
        for (int i = 0; i < size; i++)
        {
            if(transactions[i].book_id.equals(book_id) && transactions[i].member_id.equals(member_id))
                return transactions[i];
        }
        return null;
    }
}