package BookList;

public class Book
{
    String book_id;
    String title;
    int total;
    int available;

    void setBookId(String book_id){ this.book_id = book_id; }
    void setTitle(String title){ this.title = title; }
    void setTotal(int total){ this.total = total; }
    public void setAvailable(int available){ this.available = available; }

    public String getBookId(){ return book_id; }
    String getTitle(){ return title; }
    int getTotal(){ return total; }
    public int getAvailable(){ return available; }

    Book(String book_id, String title, int total)
    {
        setBookId(book_id);
        setTitle(title);
        setTotal(total);
        setAvailable(total);
    }

    void showDetails()
    {
        System.out.println("--------------------------------------------");
        System.out.println("BOOK ID : " + book_id);
        System.out.println("BOOK TITLE : " + title);
        System.out.println("TOTAL NUMBER OF COPIES : " + total);
        System.out.println("AVAILABLE COPIES : " + available);
        System.out.println("--------------------------------------------");
    }

}