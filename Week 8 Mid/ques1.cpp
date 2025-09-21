#include <bits/stdc++.h>
using namespace std;

struct Book
{
    int id;
    string title;
    string author;
    int year;
    int pages;
    Book *next;
};

Book *head = nullptr;
vector<int> bookIDs;

bool binarySearchID(int id)
{
    int l = 0, r = bookIDs.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (bookIDs[mid] == id)
            return true;
        else if (bookIDs[mid] < id)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

void insertBook(int id, string title, string author, int year, int pages)
{
    Book *newBook = new Book{id, title, author, year, pages, nullptr};

    if (!head || year < head->year)
    {
        newBook->next = head;
        head = newBook;
    }
    else
    {
        Book *curr = head;
        while (curr->next && curr->next->year <= year)
        {
            curr = curr->next;
        }
        newBook->next = curr->next;
        curr->next = newBook;
    }
}

void addBook()
{
    int id, year, pages;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;

    if (binarySearchID(id))
    {
        cout << "Book ID already exists! Cannot insert duplicate.\n";
        return;
    }

    cout << "Book not found in array. Adding new record.\n";
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Pages: ";
    cin >> pages;

    insertBook(id, title, author, year, pages);

    bookIDs.push_back(id);
    sort(bookIDs.begin(), bookIDs.end());

    cout << "Record inserted successfully!\n";
}

void searchBook()
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    if (!binarySearchID(id))
    {
        cout << "Book not found in the library.\n";
        return;
    }

    Book *curr = head;
    while (curr)
    {
        if (curr->id == id)
        {
            cout << "Book Found:\n";
            cout << "Title: " << curr->title << "\n";
            cout << "Author: " << curr->author << "\n";
            cout << "Year: " << curr->year << "\n";
            cout << "Pages: " << curr->pages << "\n";
            return;
        }
        curr = curr->next;
    }
}

void displayBooks()
{
    if (!head)
    {
        cout << "No books in the library.\n";
        return;
    }

    cout << "\n--- Library Records ---\n";
    Book *curr = head;
    while (curr)
    {
        cout << "ID: " << curr->id
             << " | Title: " << curr->title
             << " | Author: " << curr->author
             << " | Year: " << curr->year
             << " | Pages: " << curr->pages << "\n";
        curr = curr->next;
    }
    cout << "-----------------------\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Book\n2. Search Book\n3. Display All Books\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            displayBooks();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    int testID = 11;
    cout << "\n[Manual Trace] Searching with Book ID = " << testID << "\n";
    if (binarySearchID(testID))
    {
        cout << "Book with ID " << testID << " exists in array.\n";
    }
    else
    {
        cout << "Book with ID " << testID << " does not exist.\n";
    }

    return 0;
}
