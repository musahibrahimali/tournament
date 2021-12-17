#pragma once
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <ctime>
#include "club.h"

using namespace std;

class League {
private:
    string LeagueName;
    string LeagueSeason;
    int LeagueWeeek;
    int TotalNumberOfTeams = 0;
    int TotalNumberOfFixtures = 0;
    int TotalNumberOfResults = 0;
    map<int, Club> LeagueTable;
    map<int, string> LeagueFixtures;
    map<int, string> RoundResults;
public:
    League(string _leagueName, int _leageWeek = 1, string _leagueSeason = "2021 - 2022") {
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

    // mutators
    string getLeagueName() {
        return LeagueName;
    };

    string getLeagueSeason() {
        return LeagueSeason;
    };

    int getLeagueWeeek() {
        return LeagueWeeek;
    };

    // update the total number of teams in the league
    void updateNumberOfTeams() {
        TotalNumberOfTeams += 1;
    }

    // update the number of fixtures
    void updateNumberOfFixtures() {
        TotalNumberOfFixtures += 1;
    }

    // update the number of results
    void updateNumberOfResults() {
        TotalNumberOfResults += 1;
    }

    // add a team to the league table
    void AddTeam(Club club) {
        updateNumberOfTeams();
        club.setClubPosition(TotalNumberOfTeams);
        LeagueTable.insert(pair<int, Club>(TotalNumberOfTeams, club));
    };

    // generate fixtures and display them to user on call
    void GenerateFixtures() {
        // generete fixtures for all teams in the round of the league
        for (auto& teamOne : LeagueTable) {
            // generate fixtures for all teams in the league
            for (auto& teamTwo : LeagueTable) {
                // generate fixtures for all teams in the league
                if (teamOne.first != teamTwo.first) {
                    string fixture = teamOne.second.getClubName() + "\t\t\t vs \t\t\t" + teamTwo.second.getClubName();
                    updateNumberOfFixtures();
                    LeagueFixtures.insert(pair<int, string>(TotalNumberOfFixtures, fixture));
                }
            }
        }
    };

    // show the fixtures of the various teams
    void ShowFixtures() {
        cout << endl;
        cout << "\t\t\t\t" << "Fixtures" << endl;
        cout << "-------------------------------------------------------------------" << endl << endl;
        cout << " Home Team \t\t\t" << "   \t\t\t" << "Away Team" << endl << endl;
        cout << "-------------------------------------------------------------------" << endl;
        for (auto& fixture : LeagueFixtures) {
            cout << fixture.first << " " << fixture.second << endl;
        }
        cout << endl;
    }

    void ShowRoundResults(int _round = 1) {
        cout << endl;
        cout << "\t\t\t" << " Round " << _round << " Results " << endl;
        cout << "-------------------------------------------------------------------" << endl << endl;
        cout << " Home Team \t\t\t" << "   \t\t\t" << "Away Team" << endl << endl;
        cout << "-------------------------------------------------------------------" << endl;
        for (auto& result : RoundResults) {
            cout << result.first << " " << result.second << endl;
        }
        cout << endl;
    }

    // simulate round of the league
    void SimulateRound(int _round = 1) {
        // play all matches and get the results based on the league fixtures
        for (auto& teamOne : LeagueTable) {
            for (auto& teamTwo : LeagueTable) {
                if (teamOne.first != teamTwo.first) {
                    int teamAStrength = teamOne.second.getClubStrenght();
                    int teamBStrength = teamTwo.second.getClubStrenght();
                    // generate the goals scored by each team based on the strenght of the team
                    int teamAGoals = rand() % teamAStrength;
                    int teamBGoals = rand() % teamBStrength;
                    string matchResult = teamOne.second.getClubName() + " \t\t\t " + to_string(teamAGoals) + " - " + to_string(teamBGoals) + " \t\t\t" + teamTwo.second.getClubName();
                    updateNumberOfResults();
                    RoundResults.insert(pair<int, string>(TotalNumberOfResults, matchResult));
                    teamOne.second.updateRoundGames(_round, teamAGoals, teamBGoals, matchResult);
                    teamTwo.second.updateRoundGames(_round, teamBGoals, teamAGoals, matchResult);
                    // update team games played
                    teamOne.second.setGamesPlayed(1);
                    teamTwo.second.setGamesPlayed(1);
                    // update team goals scored
                    teamOne.second.setGoalsFor(teamAGoals);
                    teamTwo.second.setGoalsFor(teamBGoals);
                    // update team goals conceded
                    teamOne.second.setGoalsConceded(teamBGoals);
                    teamTwo.second.setGoalsConceded(teamAGoals);
                    // update team wins and losses
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

    // simulate a full tornament
    void SimulateTornament() {
        // simulate all rounds of the league
        setLeagueWeeek(8);
        for (int i = 1; i <= getLeagueWeeek(); i++) {
            GenerateFixtures();
            SimulateRound(i);
            ShowRoundResults(i);
        }
        // show the league table
        ShowLeagueTable();
        setLeagueWeeek(1);
    }

    // sort table for teams with highest points
    void SortTable() {
        // sort the league table based on points
        for (auto& team : LeagueTable) {
            team.second.calculatePoints();
        }
        // campare team points to the next team point in the map
        for (auto& team : LeagueTable) {
            for (auto& nextTeam : LeagueTable) {
                if (team.second.getPoints() > nextTeam.second.getPoints()) {
                    // swap the teams based on points
                    Club temp = team.second;
                    team.second = nextTeam.second;
                    nextTeam.second = temp;

                    // generate the new positions for the teams
                    int tempPosition = team.second.getClubPosition();
                    team.second.setClubPosition(nextTeam.second.getClubPosition());
                    nextTeam.second.setClubPosition(tempPosition);
                }
            }
        }
    };

    // show all teams
    void ShowAllTeams() {
        cout << endl;
        cout << "\t\t\t\t" << " All Teams " << endl;
        cout << "--------------------------------------------------------------------------------" << endl << endl;
        cout << "Pos  " << "\t  Club \t\t\t" << "        Code \t\t\t" << "     Strenght " << endl << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        for (auto& team : LeagueTable) {
            team.second.ShowClub();
        }
        cout << endl;
    }

    // show round stats for a team
    void RoundTable(int _round = 1) {
        cout << endl;
        cout << "\t\t\t" << getLeagueName() << " " << getLeagueSeason() << " Round " << _round << endl << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl << endl;
        cout << "Pos  \t" << "Club \t\t\t" << "MP \t" << "W \t" << "D \t" << "L \t" << "GF \t" << "GA \t" << "GD \t" << "Pts" << endl << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        for (auto& team : LeagueTable) {
            team.second.ShowRoundStatistics();
        }
    }

    // round game results for a tema
    void RoundGameResultsForTeam(string _teamName, int _round = 1) {
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

    void ShowLeagueTable() {
        cout << endl;
        cout << "\t\t\t" << getLeagueName() << " " << getLeagueSeason() << " Standings " << endl << endl;
        cout << "----------------------------------------------------------------------------------------" << endl << endl;
        cout << "  " << "Club \t\t\t" << "MP \t" << "W \t" << "D \t" << "L \t" << "GF \t" << "GA \t" << "GD \t" << "Pts" << endl << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        SortTable();
        for (auto team : LeagueTable) {
            team.second.ClubStatistics();
        }
    };
};