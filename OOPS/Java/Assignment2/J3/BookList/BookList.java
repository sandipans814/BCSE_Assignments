package BookList;

import java.util.Scanner;

public class BookList
{
    static int CAPACITY = 10000;
    static Scanner sc = new Scanner(System.in);
    
    int size;
    Book books[];

    public BookList()
    {
        size = 0;
        books = new Book[CAPACITY];
    }

    private boolean checkBookId(String book_id)
    {
        for (int i = 0; i < size; i++)
        {
            if(books[i].getBookId().equals(book_id))
                return false;
        }
        return true;
    }

    public Book getBookFromList(String book_id)
    {
        for (int i = 0; i < size; i++)
        {
            if (books[i].getBookId().equals(book_id))
                return books[i];
        }
        return null;
    }

    public void addBook()
    {
        System.out.print("ENTER BOOK ID : "); String book_id = sc.nextLine();
        System.out.print("ENTER BOOK TITLE : "); String title = sc.nextLine();
        System.out.print("ENTER TOTAL NUMBER OF COPIES : "); int total = sc.nextInt(); sc.nextLine();

        if (checkBookId(book_id))
        {
            Book book = new Book(book_id, title, total);
            if (size <= CAPACITY)
                books[size++] = book;
            else
                System.out.println("[ERROR] : CAPACITY EXCEEDED");
        }
        else
            System.out.println("[ERROR] : BOOK_ID MUST BE UNIQUE");
    }

    public void addCopies(String book_id, int copies)
    {
        Book book = getBookFromList(book_id);
        if (book != null)
        {
            book.setTotal(book.getTotal() + copies);
            book.setAvailable(book.getAvailable() + copies);
        }
        else
            System.out.println("[ERROR] : NO SUCH BOOK EXISTS");
    }

    public void showBookDetails(String book_id)
    {
        Book book = getBookFromList(book_id);
        if (book != null)
            book.showDetails();
        else
            System.out.println("[ERROR] : NO SUCH BOOK EXISTS");
    }

    public void showAllBookDetails()
    {
        for (int i = 0; i < size; i++)
            books[i].showDetails();
    }
}