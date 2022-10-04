#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 * ISSUES:
 * (1) Am I adding the authors correctly? Switch case 1.
 * (2) Make NEW book object each time. Naming issue, so use new? but pointers?
 * (3) Give book to Inventory object in all options of Switch case 1. (send book object to addBook())
 * (4) Is my getter and setter for authors[] correct?
 * (5) Create a way to make a book ID from Title and Author, and put in Switch Case 1.
 * (6) On the search() in Inventory I need to make a way to give back an error if the book is not found
 * hence the index = 199. Need to finish this somehow.
 * (7) Create a toString for Case 5 (and 4)
 * (8) The char case issue. Not easily found online.
 */


/*
 * BOOK CLASS - 50 pts
 * INVENTORY CLASS - 100 pts
 * MAIN - 30 pts
 * DOCUMENTATION - 20 pts
 */

/*
 * ABOUT THIS PROGRAM
 * This program manages an inventory system for a bookstore to manage book objects. The inventory of the books
 * is in the Inventory class.
 *
 * For 1: Ask user what information they would like to provide (choice between three constructors). Then ask
 * that info and add to the constructor and place in inventory. Create ID at that time combining two variables?
 */


/*
 * The Book Class models a book that is held in inventory.
 */
class Book {
public:
    string ID;
    string title;
    string authors[5] = {};
    string genre;
    double price;
    int year;
    int numberAvailable;

    //getters
    string getID() {
        return ID;
    }
    string getTitle() {
        return title;
    }
    const string *getAuthors() const {
        return authors;
    }
    string getGenre(){
        return genre;
    }
    double getPrice() {
        return price;
    }
    int getYear() {
        return year;
    }
    int getNumberAvailable() {
        return numberAvailable;
    }

    //setters
    void setID(string ID){
        ID = ID;
    }
    void setTitle(string title) {
        title = title;
    }
    void setAuthors(string authorName){
        for (int k = 0; k <=5; k++){ //this is going to put the author in each element
            if (authors[k] == "") {
                authors[k] = authorName;
                break; //does break bring you where?
            }
        }
    }

//    void setAuthors (string author[]){//IS THIS RIGHT?
//        string authorCounter;
//        for (int i = 0; i <= 5; i++) {
//            authors[i] = author;
//        }
//    }
    void setGenre(string genre) {
        genre = genre;
    }
    void setYear(int year) {
        year = year;
    }
    void setPrice(double price) {
        price = price;
    }
    void setNumberAvailable(int numberAvailable) {
        numberAvailable = numberAvailable;
    }
    //constructors
    Book(){ //error if I don't do this
    }
    //WHY AM I FILLING THE AUTHORS ARRAY WITH NUMBERS?? what kind of crack
    Book(string pTitle, string pAuthors[5]) {
        title = pTitle;
        for (int i = 0; i <= 5; i++) {
            authors[i] = pAuthors[i];
        }
    }
    Book(string pTitle, string pAuthors[5], int pYear) {
        title = pTitle;
        for (int i = 0; i <= 5; i++) {
            authors[i] = pAuthors[i];
        }
        year = pYear;
    }
    Book(string pTitle, string pAuthors[5], int pYear, string pGenre) {
        title = pTitle;
        for (int i = 0; i <= 5; i++) {
            authors[i] = pAuthors[i];
        }
        year = pYear;
        genre = pGenre;
    }
};

/*
 * This class will manage multiple Book objects to simulate an inventory management system for a bookstore.
 */
class Inventory {
public:
    Book books[100];
    int counter = 0;

    Inventory() {//creates the array
    }
    Inventory(Book pBook) {//create the array and assign first index to this book object
        books[0] = pBook;
        counter++;
    }

    //adding new book objects to the array
    void addBook(Book book) {
        books[counter] = book;
        counter++;
    }

    //update the price of a book object in the array
    void updatePrice(Book book, double price) {
        books->setPrice(price);
    }

    //update the availability/stock count of Book objects
    void updateNumAvailable(Book book, int numAvailable) {
        books->setNumberAvailable(numAvailable);
    }

    //search the inventory for Book by its title and year and return its price OR number available //string stream?
    int searchBooks(string title, int year) {

        int index;
        for (int i = 0; i <= counter; i++) {
            if (books[i].getTitle() == title && books[i].getYear() == year){
                index = i;
            } else
                index = 199;
        }
        return index;
    }

};

/*
 * The main() function will present the user with a menu that loops until the user exits.
 */

int main() {

    //instantiate Inventory object
    Inventory i;

    //instantiate Book object for use with setAuthors() function in Book Class. Do I need this?
    Book b;


    //   Book bObjectA(string, string[]);
    //   Book bObjectB(string, string[], int);
    //   Book bObjectC(string, string[], int, string);

    string stringChoice;
    int choice;
    do {
        //present the user with the menu of options
        cout << "______________________________________________\n";
        printf("%-20s%-20s\n", "Action", "Option No.");
        cout << "----------------------------------------------\n";
        printf("%-20s%-20s\n", "Add a Book to the Inventory", "1");
        printf("%-20s%-20s\n", "Update the price of a Book specified by a title and year", "2");
        printf("%-20s%-20s\n", "Update the inventory count for a Book specified by title and year", "3");
        printf("%-20s%-20s\n", "Print the Books currently in the Inventory – their title, author(s), year, genre, number available,\n"
                               "etc.", "4");
        printf("%-20s%-20s\n", "Print the member data for a Book by searching for it by title and year", "5");
        printf("%-20s%-20s\n", "Exit Program", "6");
        cout << "----------------------------------------------\nEnter your selection here:";

        //read selection from the user and use that selection to call the applicable function
        getline(cin, stringChoice);
        stringstream(stringChoice) >> choice;

        //instantiate variables to use below
        string bookTitle;
        string bookAuthor;
        string bookAuthors[5] = {};
        int numOfAuthors;
        int bookYear;
        string bookGenre;

        //for switch case 1
        /*
  bookTitle = rainbows
  author = Jennifer

  cout << ask for title
  cin >> bookTitle
  cout << ask for author
  cin >> author
  if(A)
    book (booktitle, author)
  else if (B)
    cout << ask for year
    cin >> year
    book (booktitle, author, year)
  else if (C)
    cout << ask for year
    cin >> year
    cout << ask for genre
    cin >> genre
    book (booktitle, author, year, genre)
  */

        //perform option based upon user choice
        switch(choice){
            //Add a book to the inventory
            case 1: {
                cout << "\nAdd a Book to the Inventory. What information do you have about the book?" << endl;
                char Option1;
                cout << "Option 'A' Title and author(s).\n" <<
                        "Option 'B' Title, author(s), and year.\n" <<
                        "Option 'C' Title, author(s), year, and genre." << endl;
                cin.get(Option1);
                toupper(Option1); //error? idk i just want to ignore case on the char
                //I could make this slightly shorter, but ehh (see above commenting)
                //Has title and author(s) only
                if (Option1 == 'A') {

                    cout << "Enter the Title of the Book:";
                    cin.ignore();
                    getline(cin, bookTitle);
                    cout << "\nHow many authors does the book have?";
                    cin >> numOfAuthors;
                    for (int p = 0; p < numOfAuthors; p++) {
                        cout << "\nEnter an Author of the book:";
                        getline(cin, bookTitle);
                        b.setAuthors(bookAuthor); //I think I need to ask first, then set to the object
                        }
                        //b.authors[bookAuthor];
                       i.addBook(*(new Book(bookTitle, &bookAuthors[numOfAuthors]))); //how to create this with a string[]
                        //authors[bookAuthor];//add to object
                        //could I create a function in Book to add the authors for a book? and use an int as the parameter?
                    //give book to Inventory object
                    }
                //has title, authors, and year only
                 else if (Option1 == 'B'){
                    cout << "Enter the Title of the Book:";
                    cin.ignore();
                    getline(cin, bookTitle);
                    cout << "\nHow many authors does the book have?";
                    cin >> numOfAuthors;
                    for (int p = 0; p < numOfAuthors; p++) {
                        cout << "\nEnter an Author of the book:";
                        cin.ignore();
                        getline(cin, bookTitle);
                        b.setAuthors(bookAuthor);
                    }
                    cout << "\nEnter the year the book was published:";
                    cin >> bookYear;
                    //bObjectB(bookTitle, bookAuthor, bookYear); //create the book object
                    //give book to Inventory object
                }
                 //user has title, author(s), year, and genre
                else if (Option1 == 'C') {
                    cout << "Enter the Title of the Book:";
                    cin.ignore();
                    getline(cin, bookTitle);
                    cout << "\nHow many authors does the book have?";
                    cin >> numOfAuthors;
                    for (int p = 0; p < numOfAuthors; p++) {
                        cout << "\nEnter an Author of the book:";
                        cin.ignore();
                        getline(cin, bookAuthor);
                        b.setAuthors(bookAuthor);
                    }
                    cout << "\nEnter the year the book was published:";
                    cin >> bookYear;
                    cout << "\nEnter the genre of the book:";
                    cin.ignore();
                    getline(cin, bookGenre);
                    //create the book object
                    //give book to Inventory object
                }
                else {
                    break; //this will bring us back to while loop, right? No, I think the Switch. Fix it.
                }
                cin.ignore();
                break;
            }
            //Update price of a book specified by title and year
            case 2: { //done?
                cout << "\nUpdate the price of a Book specified by a title and year.";
                cout << "\nWhat is the title of the book you would like to update?";
                cin >> bookTitle;
                cout << "\nWhat is the year of the book you would like to update?";
                cin >> bookYear;
                int updatePriceIndex = i.searchBooks(bookTitle, bookYear); // use search() function here and make it = to a variable called index
                int updatedPrice;
                cout << "\nWhat would you like to update the price to?";
                cin >> updatedPrice;
                i.books[updatePriceIndex].setPrice(updatedPrice);
                cin.ignore();
                break;
            }
            //Update the inventory count for a book specified by title and year
            case 3: {
                cout << "\nUpdate the inventory count for a Book specified by title and year.";
                cout << "\nWhat is the title of the book you would like to update?";
                cin >> bookTitle;
                cout << "\nWhat is the year of the book you would like to update?";
                cin >> bookYear;
                int updateInventoryCount = i.searchBooks(bookTitle, bookYear);
                int updateInventory;
                cout << "\nWhat would you like to update the amount available to?";
                cin >> updateInventory;
                i.books[updateInventoryCount].setNumberAvailable(updateInventory);
                cin.ignore();
                break;
            }
            //Print all info about books currently in inventory
            case 4: {
                cout << "Books currently in the Inventory:\n";
                for (int j = 0; j <= i.counter; j++) {
                    cout << i.books[j].getID() << i.books[j].getTitle() << i.books[j].getAuthors() << i.books[j].getYear() \
                    << i.books[j].getGenre() << i.books[j].getNumberAvailable() << "\n" << endl;
                }
                cin.ignore();
                break;
            }
            //Print member data for a book by searching by title and year
            case 5: {
                cout << "Data for a particular book.";
                cout << "\nWhat is the title of the book you would like to update?";
                cin >> bookTitle;
                cout << "\nWhat is the year of the book you would like to update?";
                cin >> bookYear;
                int bookDataIndex = i.searchBooks(bookTitle, bookYear);
               cout << i.books[bookDataIndex].getID() << i.books[bookDataIndex].getTitle() << \
               i.books[bookDataIndex].getAuthors() << i.books[bookDataIndex].getYear() \
                    << i.books[bookDataIndex].getGenre() << i.books[bookDataIndex].getNumberAvailable() << "\n" << endl;
                    //nooo create a tostring?
                cin.ignore();
                break;
            }
            //Exit program
            case 6:
                cout << "Program exited successfully." << endl;
                break;
            default:
                cout << "Invalid selection. Please input either 1, 2, 3, 4, 5, or 6.\n" << endl;
        }

    } while (choice != 6);

    return 0;

}



