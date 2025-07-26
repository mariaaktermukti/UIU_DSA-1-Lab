#include <iostream>
using namespace std;

int main() 
{
    int number;
    string sentence1, sentence2;

    cout << "Enter an integer: ";
    cin >> number;

    cin.ignore();

    cout << "Enter first sentence: ";
    getline(cin, sentence1);

    cout << "Enter second sentence: ";
    getline(cin, sentence2);

    cout << "Number: " << number << endl;
    cout << "Sentence 1: " << sentence1 << endl;
    cout << "Sentence 2: " << sentence2 << endl;

    return 0;
}
