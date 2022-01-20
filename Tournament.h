#pragma once
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <ctime>
#include "Team.h"

using namespace std;

class Tournament {
private:
    string LeagueName;
    string LeagueSeason;
    int LeagueWeeek;
    int NumberOfTeams = 0;
    int NumberOfFixtures = 0;
    int NumberOfResults = 0;
    map<int, Team> LeagueTable;
    map<int, string> LeagueFixtures;
    map<int, string> RoundResults;
public:
    Tournament(string _leagueName, int _leageWeek = 1, string _leagueSeason = "2021 - 2022") {
        LeagueName = _leagueName;
        LeagueSeason = _leagueSeason;
        LeagueWeeek = _leageWeek;
    };

    void setLeagueName(string _leagueName) {
        LeagueName = _leagueName;
    };

    void setLeagueSeason(string _leagueSeason) {
        LeagueSeason = _leagueSeason;
    };

    void setLeagueWeeek(int _leageWeek) {
        LeagueWeeek = _leageWeek;
    };

    string getLeagueName() {
        return LeagueName;
    };

    string getLeagueSeason() {
        return LeagueSeason;
    };

    int getLeagueWeeek() {
        return LeagueWeeek;
    };

    void updateNumberOfTeams() {
        NumberOfTeams += 1;
    }

    void updateNumberOfFixtures() {
        NumberOfFixtures += 1;
    }

    void updateNumberOfResults() {
        NumberOfResults += 1;
    }

    void CreateTeam(Team team) {
        updateNumberOfTeams();
        team.setClubPosition(NumberOfTeams);
        LeagueTable.insert(pair<int, Team>(NumberOfTeams, team));
    };

    void CreateFixtures() {
        for (auto& teamOne : LeagueTable) {
            for (auto& teamTwo : LeagueTable) {
                if (teamOne.first != teamTwo.first) {
                    string fixture = teamOne.second.getClubName() + "\t\t\t vs \t\t\t" + teamTwo.second.getClubName();
                    updateNumberOfFixtures();
                    LeagueFixtures.insert(pair<int, string>(NumberOfFixtures, fixture));
                }
            }
        }
    };

    void ShowFixtures() {
        cout << endl;
        cout << "\t\t\t\t" << "Fixtures" << endl;
        cout << "-------------------------------------------------------------------" << endl << endl;
        cout << " Team A \t\t\t" << "   \t\t\t" << " Team B " << endl << endl;
        cout << "-------------------------------------------------------------------" << endl;
        for (auto& fixture : LeagueFixtures) {
            cout << fixture.first << " " << fixture.second << endl;
        }
        cout << endl;
    }

    void DisplayResults(int _round = 1) {
        cout << endl;
        cout << "\t\t\t" << " Round " << _round << " Outcome " << endl;
        cout << "-------------------------------------------------------------------" << endl << endl;
        cout << " Team B \t\t\t" << "   \t\t\t" << " Team B " << endl << endl;
        cout << "-------------------------------------------------------------------" << endl;
        for (auto& result : RoundResults) {
            cout << result.first << " " << result.second << endl;
        }
        cout << endl;
    }

    void SimulateRound(int _round = 1) {
        for (auto& teamOne : LeagueTable) {
            for (auto& teamTwo : LeagueTable) {
                if (teamOne.first != teamTwo.first) {
                    int teamAStrength = teamOne.second.getClubStrenght();
                    int teamBStrength = teamTwo.second.getClubStrenght();
                    int teamAGoals = rand() % teamAStrength;
                    int teamBGoals = rand() % teamBStrength;
                    string matchResult = teamOne.second.getClubName() + " \t\t\t " + to_string(teamAGoals) + " - " + to_string(teamBGoals) + " \t\t\t" + teamTwo.second.getClubName();
                    updateNumberOfResults();
                    RoundResults.insert(pair<int, string>(NumberOfResults, matchResult));
                    teamOne.second.updateRoundGames(_round, teamAGoals, teamBGoals, matchResult);
                    teamTwo.second.updateRoundGames(_round, teamBGoals, teamAGoals, matchResult);
                    teamOne.second.setGamesPlayed(1);
                    teamTwo.second.setGamesPlayed(1);
                    teamOne.second.setGoalsFor(teamAGoals);
                    teamTwo.second.setGoalsFor(teamBGoals);
                    teamOne.second.setGoalsAgainst(teamBGoals);
                    teamTwo.second.setGoalsAgainst(teamAGoals);
                    if (teamAGoals > teamBGoals) {
                        teamOne.second.setGamesWon(1);
                        teamTwo.second.setGamesLost(1);
                    }
                    else if (teamAGoals < teamBGoals) {
                        teamOne.second.setGamesLost(1);
                        teamTwo.second.setGamesWon(1);
                    }
                    else {
                        teamOne.second.setGamesTied(1);
                        teamTwo.second.setGamesTied(1);
                    }
                }
            }
        }
        SortTable();
    };

    void SortTable() {
        for (auto& team : LeagueTable) {
            team.second.calculatePoints();
        }
        for (auto& team : LeagueTable) {
            for (auto& nextTeam : LeagueTable) {
                if (team.second.getPoints() > nextTeam.second.getPoints()) {
                    Team temp = team.second;
                    team.second = nextTeam.second;
                    nextTeam.second = temp;

                    int tempPosition = team.second.getClubPosition();
                    team.second.setClubPosition(nextTeam.second.getClubPosition());
                    nextTeam.second.setClubPosition(tempPosition);
                }
            }
        }
    };

    void DisplayTeams() {
        cout << endl;
        cout << "\t\t\t\t" << " All Teams " << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "Pos  " << "\t  Club \t\t\t" << "        Code \t\t\t" << "     Strenght " << endl << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        for (auto& team : LeagueTable) {
            team.second.DisplayClub();
        }
        cout << endl;
    }

    void DisplayRoundTable(int _round = 1) {
        cout << endl;
        cout << "\t\t\t" << getLeagueName() << " " << getLeagueSeason() << " Round " << _round << endl << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl << endl;
        cout << "Pos  \t" << "Club \t\t\t" << "MP \t" << "W \t" << "D \t" << "L \t" << "GF \t" << "GA \t" << "GD \t" << "Pts" << endl << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        for (auto& team : LeagueTable) {
            team.second.DisplayRoundStats();
        }
    }

    void TeamRoundResults(string _teamName, int _round = 1) {
        cout << endl << endl;
        cout << "\t\t\t" << " Round " << _round << " Results " << endl << endl;
        cout << "-------------------------------------------------------------------" << endl << endl;
        cout << " Home Team \t\t\t" << "   \t\t\t" << "Away Team" << endl << endl;
        cout << "-------------------------------------------------------------------" << endl;
        for (auto& team : LeagueTable) {
            if (team.second.getClubName() == _teamName) {
                team.second.ShowRoundGames();
            }
        }
    }

    void DisplayLeagueTable() {
        cout << endl;
        cout << "\t\t\t" << getLeagueName() << " " << getLeagueSeason() << " Standings " << endl << endl;
        cout << "----------------------------------------------------------------------------------------" << endl << endl;
        cout << "  " << "Club \t\t\t" << "MP \t" << "W \t" << "D \t" << "L \t" << "GF \t" << "GA \t" << "GD \t" << "Pts" << endl << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        SortTable();
        for (auto team : LeagueTable) {
            team.second.ClubStats();
        }
    };
};