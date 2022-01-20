#include <iostream>
#include <list>
#include <typeinfo>
#include "Tournament.h"
#include "Team.h"

using namespace std;

int main() {

    Tournament fantasyLeague = Tournament("Fantasy League");
    list<Team> teams;
    list<Team>::iterator iterator;

    Team livpool = Team("Liverpool", "LIV", 6);
    Team mancty = Team("Man City", "MNC", 6);
    Team manuntd = Team("Man United", "MNU", 4);
    Team chel = Team("Chelsea", "CHL", 5);
    Team westh = Team("Westham", "WHU", 2);
    Team ast = Team("Aston Villa", "AST", 3);
    Team ars = Team("Arsenal", "ARS", 4);
    Team tott = Team("Tottenham", "TOT", 5);
    Team burn = Team("Burnley", "BUR", 2);
    Team ever = Team("Everton", "EVE", 3);
    Team newc = Team("Newcastle", "NEW", 4);
    Team lei = Team("Leicester", "LEI", 5);
    Team nor = Team("Norwich", "NOR", 2);
    Team crys = Team("Crystal", "PAL", 3);
    Team sheff = Team("Sheffield", "SHU", 2);
    Team south = Team("Southampton", "SOT", 3);
    Team wat = Team("Watford", "WAT", 2);
    Team wolver = Team("Wolverhampt", "WOL", 3);
    Team brent = Team("BrentFord", "BRF", 3);
    Team bri = Team("Brighton", "BHA", 2);

    teams.push_back(mancty);
    teams.push_back(livpool);
    teams.push_back(chel);
    teams.push_back(westh);
    teams.push_back(manuntd);
    teams.push_back(ars);
    teams.push_back(ast);
    teams.push_back(bri);
    teams.push_back(burn);
    teams.push_back(ever);
    teams.push_back(lei);
    teams.push_back(newc);
    teams.push_back(nor);
    teams.push_back(crys);
    teams.push_back(sheff);
    teams.push_back(south);
    teams.push_back(tott);
    teams.push_back(wat);
    teams.push_back(wolver);
    teams.push_back(brent);

    for (iterator = teams.begin(); iterator != teams.end(); ++iterator) {
        fantasyLeague.CreateTeam(*iterator);
    }
    fantasyLeague.CreateFixtures();

    int choice = 0;
    string team;
    int round = 1;
    while (choice != 6) {
        cout << endl;
        cout << "-----------------------" << endl;
        cout << "      " << "TOURNAMENT MENU" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Teams" << endl;
        cout << "2. Fixtures" << endl;
        cout << "3. Simulate Next Round" << endl;
        cout << "4. Team Result" << endl;
        cout << "5. League Table" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter option: ";
        cin >> choice;
        if (choice < 1 || choice > 6) {
            cout << "Invalid option" << endl;
            break;
        }
        if (typeid(choice).name() != typeid(int).name()) {
            cout << "Invalid option" << endl;
            break;
        }
        switch (choice) {
        case 1:
            fantasyLeague.DisplayTeams();
            break;
        case 2:
            fantasyLeague.ShowFixtures();
            break;
        case 3:
            cout << "Enter a Round number(1 - 8): ";
            cin >> round;
            if (round > 8 || round < 1) {
                cout << "Round number be between 1 and 8" << endl;
                break;
            }
            fantasyLeague.SimulateRound(round);
            fantasyLeague.DisplayResults(round);
            fantasyLeague.DisplayRoundTable(round);
            break;
        case 4:
            cout << "Enter team name: ";
            cin >> team;
            cout << "Enter a Round number: ";
            cin >> round;
            fantasyLeague.TeamRoundResults(team, round);
            break;
        case 5:
            fantasyLeague.DisplayLeagueTable();
            break;
        case 6:
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
    return 0;
}