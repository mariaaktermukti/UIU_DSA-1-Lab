#include <bits/stdc++.h>
#include <limits>
#include <iostream>
#include <string>
using namespace std;

struct player
{
    string name;
    int age;
    int rating;
    double salary;
    string position;
    player *next;
};

struct team
{
    string name;
    int yearOfFormation;
    double revenue;
    player *players;
    team *next;
};

team *leagueHead = NULL;

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void AddTeam()
{
    string name;
    int year;
    int position;
    double revenue;

    // team details
    cout << "Enter name: ";
    clearInputBuffer();
    getline(cin, name);

    cout << "Enter year of formation: ";
    cin >> year;

    cout << "Enter yearly revenue: ";
    cin >> revenue;

    cout << "Enter the position in the list: ";
    cin >> position;

    // create new team
    team *newTeam = new team();
    newTeam->name = name;
    newTeam->yearOfFormation = year;
    newTeam->revenue = revenue;
    newTeam->players = NULL;
    newTeam->next = NULL;

    if (leagueHead == NULL || position == 1)
    {
        newTeam->next = leagueHead;
        leagueHead = newTeam;
        cout << "Team added successfully." << endl;
        return;
    }

    team *current = leagueHead;
    int curr_position = 1;

    while (current != NULL && curr_position < position - 1)
    {
        current = current->next;
        curr_position++;
    }

    if (current != NULL)
    {
        newTeam->next = current->next;
        current->next = newTeam;
        cout << "Team added successfully." << endl;
    }
    else
    {
        cout << "Invalid position." << endl;
        delete newTeam;
    }
}

void deleteTeam()
{
    if (leagueHead == NULL)
    {
        cout << "No teams in the league." << endl;
        return;
    }

    string teamName;
    cout << "Enter team name to be deleted: ";
    clearInputBuffer();
    getline(cin, teamName);

    team *current = leagueHead;
    team *prev = NULL;

    while (current != NULL && current->name != teamName)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "Team not found." << endl;
        return;
    }

    player *player_curr = current->players;
    while (player_curr != NULL)
    {
        player *temp = player_curr;
        player_curr = player_curr->next;
        delete temp;
    }

    if (prev == NULL)
    {
        leagueHead = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    delete current;
    cout << "Team deleted successfully." << endl;
}

void displayALL()
{
    if (leagueHead == NULL)
    {
        cout << "No teams in the league." << endl;
        return;
    }

    cout << "List of teams: " << endl;
    team *currentTeam = leagueHead;

    while (currentTeam != NULL)
    {
        cout << currentTeam->name << endl;
        cout << "Year: " << currentTeam->yearOfFormation << endl;
        cout << "Revenue: " << currentTeam->revenue << endl;

        cout << "list of players in contract: " << endl;
        if (currentTeam->players == NULL)
        {
            cout << "No player contracts." << endl;
        }
        else
        {
            player *player_curr = currentTeam->players;

            while (player_curr != NULL)
            {
                cout << "Name: " << player_curr->name << endl;
                cout << "Age: " << player_curr->age << ", ";
                cout << "Rating: " << player_curr->rating << ", ";
                cout << "Salary: " << player_curr->salary << ", ";
                cout << "Position: " << player_curr->position << endl;
                player_curr = player_curr->next;
            }
        }
        currentTeam = currentTeam->next;
    }
}

void swap_teams()
{
    if (leagueHead == NULL)
    {
        cout << "No teams in the league." << endl;
        return;
    }

    int position1, position2;
    cout << "Which two positions do you want to swap?" << endl;
    cin >> position1 >> position2;

    if (position1 == position2)
    {
        cout << "No need to swap." << endl;
        return;
    }

    if (position1 > position2)
    {
        int temp = position1;
        position1 = position2;
        position2 = temp;
    }

    team *team1 = NULL;
    team *prev1 = NULL;

    team *team2 = NULL;
    team *prev2 = NULL;

    team *current = leagueHead;
    int position = 1;

    while (current != NULL)
    {
        if (position == position1 - 1)
        {
            prev1 = current;
        }
        if (position == position2 - 1)
        {
            prev2 = current;
        }
        if (position == position1)
        {
            team1 = current;
        }
        if (position == position2)
        {
            team2 = current;
        }

        current = current->next;
        position++;
    }

    if (team1 == NULL || team2 == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (prev1 != NULL)
    {
        prev1->next = team2;
    }
    else
    {
        leagueHead = team2;
    }

    if (prev2 != NULL)
    {
        prev2->next = team1;
    }
    else
    {
        leagueHead = team1;
    }

    team *temp = team1->next;
    team1->next = team2->next;
    team2->next = temp;

    cout << "Team swapped successfully." << endl;
}

void add_player()
{
    if (leagueHead == NULL)
    {
        cout << "League is empty. Add team first." << endl;
        return;
    }

    string playerName, teamName, position;
    string ageStr, ratingStr, salaryStr; // declare string variables for input
    int age, rating;
    double salary;

    clearInputBuffer();

    cout << "Player name: ";
    getline(cin, playerName);

    cout << "Age of player: ";
    getline(cin, ageStr);
    age = stoi(ageStr); // convert string to int

    cout << "Player rating: ";
    getline(cin, ratingStr);
    rating = stoi(ratingStr); // convert string to int

    cout << "Yearly salary: ";
    getline(cin, salaryStr);
    salary = stod(salaryStr); // convert string to double

    cout << "Position: ";
    getline(cin, position);

    cout << "Club contract: ";
    getline(cin, teamName);

    team *currentTeam = leagueHead;
    while (currentTeam != NULL && currentTeam->name != teamName)
    {
        currentTeam = currentTeam->next;
    }

    if (currentTeam == NULL)
    {
        cout << "Team not found." << endl;
        return;
    }

    // create new player
    player *newPlayer = new player();
    newPlayer->name = playerName;
    newPlayer->age = age;
    newPlayer->rating = rating;
    newPlayer->salary = salary;
    newPlayer->position = position;
    newPlayer->next = NULL;

    if (currentTeam->players == NULL)
    {
        currentTeam->players = newPlayer;
    }
    else
    {
        player *currenPlayer = currentTeam->players;
        while (currenPlayer->next != NULL)
        {
            currenPlayer = currenPlayer->next;
        }
        currenPlayer->next = newPlayer;
    }

    cout << "Player added successfully." << endl;
}

void deletePlayer()
{
    if (leagueHead == NULL)
    {
        cout << "No team in the league." << endl;
        return;
    }

    string playerName;
    string teamName;

    clearInputBuffer();

    cout << "Enter the name of player to deleted: ";
    getline(cin, playerName);

    cout << "Enter the team name of the player: ";
    getline(cin, teamName);

    // search for the team
    team *currentTeam = leagueHead;
    while (currentTeam != NULL && currentTeam->name != teamName)
    {
        currentTeam = currentTeam->next;
    }

    if (currentTeam == NULL)
    {
        cout << "Team not found.";
        return;
    }

    player *currentPlayer = currentTeam->players;
    player *prev_player = NULL;

    while (currentPlayer != NULL && currentPlayer->name != playerName)
    {
        prev_player = currentPlayer;
        currentPlayer = currentPlayer->next;
    }

    if (prev_player == NULL)
    {
        currentTeam->players = currentPlayer->next;
    }
    else
    {
        prev_player->next = currentPlayer->next;
    }

    delete currentPlayer;
    cout << "Player deleted successfully." << endl;
}

int main()
{
    int choice;
    cout << "La Liga Database Initializing......" << endl;

    while (true)
    {
        cout << "\nWhat do you want to do?\n";
        cout << "1. Create club\n";
        cout << "2. Delete club\n";
        cout << "3. View club info\n";
        cout << "4. Swap Clubs\n";
        cout << "5. Add players\n";
        cout << "6. Delete player\n";
        cout << "7. Exit\n";
        cout << "------------------------\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddTeam();
            break;

        case 2:
            deleteTeam();
            break;
        case 3:
            displayALL();
            break;
        case 4:
            swap_teams();
            break;
        case 5:
            add_player();
            break;
        case 6:
            deletePlayer();
            break;
        case 7:
            cout << "Exiting program" << endl;
            return 0;
        default:
            cout << "Invalid choice!Try again." << endl;
            clearInputBuffer();
        }
    }
    return 0;
}