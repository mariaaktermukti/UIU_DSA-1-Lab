// 1. Use a Singly Linked List to store student information (ID, Name, Marks).

// (a) Implement Insertion (add new student).

// (b) Implement Deletion (delete student by ID).

// 2. Implement a Sorting Algorithm (choose any one: Bubble Sort / Insertion Sort / Selection Sort / Counting Sort) to sort students by Marks.

// 3. Implement a Searching Algorithm to find a student by ID.

// (a) Use Linear Search if the list is unsorted.

// (b) Use Binary Search if the list is sorted.

// 4. Display all students’ information at any time.

#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int id;
    string name;
    int marks;
    Student *next;
};

Student *head = NULL;

// Insert Student
void insertStudent()
{
    int id, marks;
    string name;
    cout << "Enter ID, Name, Marks: ";
    cin >> id >> name >> marks;

    Student *newNode = new Student{id, name, marks, NULL};
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Student *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Student Inserted Successfully!\n";
}

// Delete Student by ID
void deleteStudent()
{
    if (!head)
    {
        cout << "List is empty!\n";
        return;
    }
    int id;
    cout << "Enter ID to Delete: ";
    cin >> id;

    if (head->id == id)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted Successfully!\n";
        return;
    }

    Student *cur = head;
    while (cur->next && cur->next->id != id)
        cur = cur->next;

    if (cur->next)
    {
        Student *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        cout << "Deleted Successfully!\n";
    }
    else
    {
        cout << "Student Not Found!\n";
    }
}

// Display Students
void displayStudents()
{
    if (!head)
    {
        cout << "No students to display!\n";
        return;
    }
    Student *temp = head;
    while (temp)
    {
        cout << "ID:" << temp->id
             << " Name:" << temp->name
             << " Marks:" << temp->marks << "\n";
        temp = temp->next;
    }
}

// Insertion Sort by Marks (descending) + display after sorting
void insertionSort()
{
    if (!head || !head->next)
        return;

    Student *sorted = NULL;
    Student *current = head;

    while (current)
    {
        Student *next = current->next;
        current->next = NULL;

        if (!sorted || current->marks > sorted->marks)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Student *temp = sorted;
            while (temp->next && temp->next->marks >= current->marks)
                temp = temp->next;
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    head = sorted;
    cout << "Students sorted by Marks (Highest First) using Insertion Sort.\n\n";
    cout << "Sorted List:\n";
    displayStudents();
}

// Linear Search by ID
void linearSearch()
{
    if (!head)
    {
        cout << "List is empty!\n";
        return;
    }
    int id;
    cout << "Enter ID to Search: ";
    cin >> id;

    Student *temp = head;
    while (temp)
    {
        if (temp->id == id)
        {
            cout << "Student Found → Name:" << temp->name
                 << ", Marks:" << temp->marks << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student Not Found!\n";
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n1. Insert Student\n2. Delete Student\n3. Sort Students (by Marks)\n4. Search Student (by ID)\n5. Display All Students\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            insertionSort();
            break;
        case 4:
            linearSearch();
            break;
        case 5:
            displayStudents();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid Choice! Try again.\n";
        }
    }
    return 0;
}
