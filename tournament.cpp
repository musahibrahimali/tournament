#include <iostream>
#include <list>
#include <typeinfo>
#include "league.h"
#include "Club.h"

using namespace std;

int main() {
    // create a league
    League premierLeague = League("Premier League");

    // create a list to hold all clubs you will be adding to the league
    list<Club> clubs;
    // iterator for the list of clubs
    list<Club>::iterator it;
    // the individual clubs to be added to the league (team name, abbreviation and strength) are required
    Club mancity = Club("Man City", "MNC", 6);
    Club liverpool = Club("Liverpool", "LIV", 6);
    Club chelsea = Club("Chelsea", "CHL", 5);
    Club westham = Club("Westham", "WHU", 2);
    Club manunited = Club("Man United", "MNU", 4);
    Club arsenal = Club("Arsenal", "ARS", 4);
    Club aston = Club("Aston Villa", "AST", 3);
    Club brighton = Club("Brighton", "BHA", 2);
    Club burnley = Club("Burnley", "BUR", 2);
    Club everton = Club("Everton", "EVE", 3);
    Club leicester = Club("Leicester", "LEI", 5);
    Club newcastle = Club("Newcastle", "NEW", 4);
    Club norwich = Club("Norwich", "NOR", 2);
    Club crystal = Club("Crystal", "PAL", 3);
    Club sheffield = Club("Sheffield", "SHU", 2);
    Club southampton = Club("Southampton", "SOT", 3);
    Club tottenham = Club("Tottenham", "TOT", 5);
    Club watford = Club("Watford", "WAT", 2);
    Club wolverhampton = Club("Wolverhampt", "WOL", 3);
    // add the clubs to the list of clubs
    clubs.push_back(mancity);
    clubs.push_back(liverpool);
    clubs.push_back(chelsea);
    clubs.push_back(westham);
    clubs.push_back(manunited);
    clubs.push_back(arsenal);
    clubs.push_back(aston);
    clubs.push_back(brighton);
    clubs.push_back(burnley);
    clubs.push_back(everton);
    clubs.push_back(leicester);
    clubs.push_back(newcastle);
    clubs.push_back(norwich);
    clubs.push_back(crystal);
    clubs.push_back(sheffield);
    clubs.push_back(southampton);
    clubs.push_back(tottenham);
    clubs.push_back(watford);
    clubs.push_back(wolverhampton);

    // add all clubs to the league table
    for (it = clubs.begin(); it != clubs.end(); ++it) {
        premierLeague.AddTeam(*it);
    }
    premierLeague.GenerateFixtures();

    // main menu from which user can select options
    int option = 0;
    string teamName;
    int roundNumber = 1;
    while (option != 7) {
        cout << endl;
        cout << "-----------------------" << endl;
        cout << "      " << "LEAGUE MENU" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Clubs" << endl;
        cout << "2. Fixtures" << endl;
        cout << "3. Simulate Tornament" << endl;
        cout << "4. Simulate Next Round" << endl;
        cout << "5. Results - Single Club" << endl;
        cout << "6. Current Standing" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;
        // check if option is valid
        if (option < 1 || option > 7) {
            cout << "Invalid option" << endl;
            break;
        }
        // check if option is an integer
        if (typeid(option).name() != typeid(int).name()) {
            cout << "Invalid option" << endl;
            break;
        }
        // switch statement to select the option
        switch (option) {
        case 1:
            premierLeague.ShowAllTeams();
            break;
        case 2:
            premierLeague.ShowFixtures();
            break;
        case 3:
            cout << "This will simulate a tournament of 8 rounds" << endl;
            premierLeague.SimulateTornament();
            break;
        case 4:
            cout << "Enter a Round number(1 - 8): ";
            cin >> roundNumber;
            if (roundNumber > 8 || roundNumber < 1) {
                cout << "Round number cannot be greater than 8 or less than 1" << endl;
                break;
            }
            premierLeague.SimulateRound(roundNumber);
            premierLeague.ShowRoundResults(roundNumber);
            premierLeague.RoundTable(roundNumber);
            break;
        case 5:
            cout << "Enter team name: ";
            cin >> teamName;
            cout << "Enter a Round number: ";
            cin >> roundNumber;
            premierLeague.RoundGameResultsForTeam(teamName, roundNumber);
            break;
        case 6:
            premierLeague.ShowLeagueTable();
            break;
        case 7:
            // exit the application
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
    return 0;
}