import java.util.Scanner;
class Book {
    private String title;
    private String author;
    private String isbn;

    public Book(String title, String author, String isbn) {
        this.title = title;
        this.author = author;
        this.isbn = isbn;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public String getIsbn() {
        return isbn;
    }
    public void displayBookDetails() {
        System.out.println(" Title: " + title + "\n Author: " + author+"\n ISBN: " + isbn);
    }
}

class EBook extends Book {
    private int fileSize;
    
    public EBook(String title, String author, String isbn, int fileSize) {
        super(title, author, isbn);
        this.fileSize = fileSize;
    }
    public int getFileSize() {
        return fileSize;
    }
    public void displayBookDetails() {
        super.displayBookDetails();
        System.out.println(" File Size: " + fileSize + " KB");
    }
}

class Library {
    private Book[] books;
    private int bookCount;

    public Library(int capacity) {
        books = new Book[capacity];
        bookCount = 0;
    }

    public void addBook(Book book) {
        if (bookCount < books.length) {
            books[bookCount] = book;
            bookCount++;
            System.out.println("Book added to the library.");
        } else {
            System.out.println("Library is full, cannot add more books.");
        }
    }

    public void displayAllBooks() {
        System.out.println("All Books in the Library:");
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBookDetails();
            System.out.println();
        }
    }

    public void findBooksByAuthor(String author) {
        System.out.println("Books by Author " + author + ":");
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getAuthor().equalsIgnoreCase(author)) {
                books[i].displayBookDetails();
                System.out.println();
                return;
            }
        }
        System.out.println("No book Found ");
    }

    public void removeBookByIsbn(String isbn) {
    	if(bookCount==0) {
    		System.out.println("Nothing to delete here");
    	}
    	else {
    		for (int i = 0; i < bookCount; i++) {
    			if (books[i].getIsbn().equals(isbn)) {
    				System.out.println("Book removed from the library:");
    				books[i].displayBookDetails();
    				books[i] = null;
    				bookCount--;
    				for (int j = i; j < bookCount; j++) {
    					books[j] = books[j + 1];
    				}
    				return;
    			}
    		}
    		System.out.println("Book with ISBN " + isbn + " not found in the library.");
    	}
    }
}
public class LibrarySystem {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
    	System.out.println("Enter the capacity of Library: ");
        int c=s.nextInt();
    	Library library = new Library(c);
    	while(true) {
    		System.out.println("1.ADD BOOK \n2.ADD EBOOK \n3.DISPLAY ALL BOOKS \n4.SEARCH A BOOK \n5.DELETE A BOOK \n6.EXIT");
        	int choice=s.nextInt();
        	s.nextLine();
        	switch(choice) {
        	case(1):{
        		System.out.println("Enter the name,author,isbn details of book: ");
        		String n=s.nextLine();
        		String a=s.nextLine();
        		String is=s.nextLine();
        		Book book1 = new Book(n,a,is);
        		library.addBook(book1);
        	}
        	break;
        	case(2):{
        		System.out.println("Enter the name,author,isbn,file size details of book: ");
        		String n=s.nextLine();
            	String a=s.nextLine();
            	String is=s.nextLine();
            	int f=s.nextInt();
            	Book book2 = new EBook(n,a,is,f);
            	library.addBook(book2);
        	}
        	break;
        	case(3):{
        		library.displayAllBooks();
        	}
        	break;
        	case(4):{
        		System.out.println("Enter the author name to search");
        		String a=s.nextLine();
        		library.findBooksByAuthor(a);
        	}
        	break;
        	case(5):{
        		System.out.println("Enter the ISBN number to delete book");
        		String a=s.nextLine();
        		library.removeBookByIsbn(a);
        	}
        	break;
        	case(6):{
        		System.out.println("Thank You!");
        	}
        	break;
        	default:{
        		System.out.println("Invalid choice");
        	}
        	break;
        	}
        	if(choice==6) {
        		break;
        	}
    	}
    }
}
