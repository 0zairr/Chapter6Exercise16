/*
File name: Chapter6Exercise16.cpp
Programmer: Ozair Ghaissi
Date: 11/29/2024
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Function prototypes
void loadTeams(vector<string>& teams);
void loadWinners(vector<string>& winners);
void displayTeams(const vector<string>& teams);
int countTeamWins(const string& team, const vector<string>& winners);

int main() {
    vector<string> teams;
    vector<string> winners;

    // Load data from files
    loadTeams(teams);
    loadWinners(winners);

    // Display teams
    cout << "List of MLB teams that have won the World Series:\n";
    displayTeams(teams);

    // Get user input
    string team;
    cout << "\nEnter the name of a team to see how many times they have won the World Series: ";
    getline(cin, team);

    // Count wins for the team
    int wins = countTeamWins(team, winners);
    if (wins == 0) {
        cout << "The team \"" << team << "\" did not win the World Series during this period or was not found.\n";
    }
    else {
        cout << "The team \"" << team << "\" has won the World Series " << wins << " time(s) between 1903 and 2012.\n";
    }

    return 0;
}

// Function to load teams from Teams.txt
void loadTeams(vector<string>& teams) {
    ifstream inputFile("Teams.txt");
    if (!inputFile) {
        cerr << "Error: Could not open Teams.txt.\n";
        exit(1);
    }

    string team;
    while (getline(inputFile, team)) {
        teams.push_back(team);
    }
    inputFile.close();
}

// Function to load winners from WorldSeriesWinners.txt
void loadWinners(vector<string>& winners) {
    ifstream inputFile("WorldSeriesWinners.txt");
    if (!inputFile) {
        cerr << "Error: Could not open WorldSeriesWinners.txt.\n";
        exit(1);
    }

    string winner;
    while (getline(inputFile, winner)) {
        winners.push_back(winner);
    }
    inputFile.close();
}

// Function to display teams
void displayTeams(const vector<string>& teams) {
    for (const string& team : teams) {
        cout << team << endl;
    }
}

// Function to count the number of wins for a given team
int countTeamWins(const string& team, const vector<string>& winners) {
    int count = 0;
    for (const string& winner : winners) {
        if (winner == team) {
            count++;
        }
    }
    return count;
}
