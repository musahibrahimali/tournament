#pragma once
#include <iostream>
#include <string>
#include <map>
#include <typeinfo>
using namespace std;

class Club {
private:
    string ClubName;
    string ClubAbr;
    int ClubNumber;
    int ClubStrenght;
    int ClubPosition;
    int GoalsConceded;
    int GoalsFor;
    int GoalDifference;
    int GamesPlayed;
    int GamesLost;
    int GamesWon;
    int GamesTied;
    int Points;
    int GoalAverage;

    // for each round
    int Round;
    int RoundPoints;
    int RoundGoalsConceded;
    int RoundGoalsFor;
    int RoundGoalDifference;
    int RoundGamesPlayed;
    int RoundGamesLost;
    int RoundGamesWon;
    int RoundGamesTied;
    map<int, string> RoundGames;
public:
    Club(
        string _clubName,
        string _clubAbr,
        int _clubStrenght = 0,
        int _goalsConceded = 0,
        int _goalsFor = 0,
        int _gamesPlayed = 0,
        int _gamesLost = 0,
        int _gamesWon = 0,
        int _gamesTied = 0,
        int _points = 0,
        int _goalAverage = 0,
        int _round = 1
    ) {
        // check if _clubName and _clubAbr are valid
        if (_clubName.length() < 3) {
            throw "Club name must be at least three characters long";
            return;
        }
        if (_clubAbr.length() > 3) {
            throw "Club abbreviation must be at most three characters long";
            return;
        }
        // check if club name and club abbreviation are strings
        if (typeid(_clubName).name() != typeid(string).name()) {
            throw "Club name must be a string";
            return;
        }
        if (typeid(_clubAbr).name() != typeid(string).name()) {
            throw "Club name must be a string";
            return;
        }
        ClubName = _clubName;
        ClubAbr = _clubAbr;
        ClubStrenght = _clubStrenght;
        GoalsConceded = _goalsConceded;
        GoalsFor = _goalsFor;
        GoalDifference = 0;
        GamesPlayed = _gamesPlayed;
        GamesLost = _gamesLost;
        GamesWon = _gamesWon;
        GamesTied = _gamesTied;
        Points = _points;
        Round = _round;
        RoundGamesLost = 0;
        RoundGamesWon = 0;
        RoundGamesTied = 0;
        RoundGamesPlayed = 0;
        RoundGoalsConceded = 0;
        RoundGoalsFor = 0;
        RoundGoalDifference = 0;
        RoundPoints = 0;
    };

    // Setters / Mutators   
    void setClubName(string _clubName) {
        if (typeid(_clubName).name() != typeid(string).name()) {
            throw "Club name must be a string";
            return;
        }
        if (_clubName.length() < 3) {
            throw "Club name must be at least three characters long";
            return;
        }
        ClubName = _clubName;
    };
    void setClubAbr(string _clubAbr) {
        if (typeid(_clubAbr).name() != typeid(string).name()) {
            throw "Club Abbreviation must be a string";
            return;
        }
        if (_clubAbr.length() > 3) {
            throw "Club abbreviation must be at most three characters long";
            return;
        }
        ClubAbr = _clubAbr;
    };
    void setClubStrenght(int _clubStrenght) {
        ClubStrenght = _clubStrenght;
    };
    void setGoalsConceded(int _goalsConceded) {
        GoalsConceded += _goalsConceded;
    };
    void setGoalsFor(int _goalsFor) {
        GoalsFor += _goalsFor;
    };
    void calculateGoalDifference() {
        GoalDifference = GoalsFor - GoalsConceded;
    };
    void setGamesPlayed(int _gamesPlayed) {
        GamesPlayed += _gamesPlayed;
    };
    void setGamesLost(int _gamesLost) {
        GamesLost += _gamesLost;
    };
    void setGamesWon(int _gamesWon) {
        GamesWon += _gamesWon;
    };
    void setGamesTied(int _gamesTied) {
        GamesTied += _gamesTied;
    };
    void setRound(int _round) {
        Round = _round;
    };
    void setClubPosition(int _position) {
        ClubPosition = _position;
    };
    void calculatePoints() {
        Points = (GamesWon * 3) + GamesTied;
    };


    // Getters
    string getClubName() {
        return ClubName;
    };
    string getClubAbr() {
        return ClubAbr;
    };
    int getClubStrenght() {
        return ClubStrenght;
    };
    int getGoalsConceded() {
        return GoalsConceded;
    };
    int getGoalsFor() {
        return GoalsFor;
    };
    int getGoalDifference() {
        return GoalDifference;
    };
    int getGamesPlayed() {
        return GamesPlayed;
    };
    int getGamesLost() {
        return GamesLost;
    };
    int getGamesWon() {
        return GamesWon;
    };
    int getGamesTied() {
        return GamesTied;
    };
    int getPoints() {
        return Points;
    };
    int getGoalAverage() {
        return GoalAverage;
    };
    int getRound() {
        return Round;
    };
    int getClubPosition() {
        return ClubPosition;
    };

    // update round points
    void updateRoundPoints() {
        RoundPoints = (RoundGamesWon * 3) + RoundGamesTied;
    };

    // update round goals conceded
    void updateRoundGoalsConceded(int _goals) {
        RoundGoalsConceded += _goals;
    };

    // update round goals for
    void updateRoundGoalsFor(int _goals) {
        RoundGoalsFor += _goals;
    };

    // update round goal difference
    void updateRoundGoalDifference() {
        RoundGoalDifference = RoundGoalsFor - RoundGoalsConceded;
    };

    // update round games played
    void updateRoundGamesPlayed(int _gamesPlayed) {
        RoundGamesPlayed += _gamesPlayed;
    };

    // update round games lost
    void updateRoundGamesLost(int _gamesLost) {
        RoundGamesLost += _gamesLost;
    };

    // update round games won
    void updateRoundGamesWon(int _gamesWon) {
        RoundGamesWon += _gamesWon;
    };

    // update round games tied
    void updateRoundGamesTied(int _gamesTied) {
        RoundGamesTied += _gamesTied;
    };

    // get round games played
    int getRoundGamesPlayed() {
        return RoundGamesPlayed;
    };

    // get round games lost
    int getRoundGamesLost() {
        return RoundGamesLost;
    };

    // get round games won
    int getRoundGamesWon() {
        return RoundGamesWon;
    };

    // get round games tied
    int getRoundGamesTied() {
        return RoundGamesTied;
    };

    // get round goals conceded
    int getRoundGoalsConceded() {
        return RoundGoalsConceded;
    };

    // get round goals for
    int getRoundGoalsFor() {
        return RoundGoalsFor;
    };

    // get round goal difference
    int getRoundGoalDifference() {
        return RoundGoalDifference;
    };

    // get round points
    int getRoundPoints() {
        return RoundPoints;
    };

    // update round games
    void updateRoundGames(int _round, int _teamAScore, int _teamBScore, string _matchScoreLine) {
        setRound(_round);
        updateRoundGamesPlayed(1);
        int number = getRoundGamesPlayed();
        RoundGames.insert(pair<int, string>(number, _matchScoreLine));
        if (_teamAScore > _teamBScore) {
            updateRoundGamesWon(1);
            updateRoundGoalsFor(_teamAScore);
            updateRoundGoalsConceded(_teamBScore);
        }
        else if (_teamAScore < _teamBScore) {
            updateRoundGamesLost(1);
            updateRoundGoalsFor(_teamAScore);
            updateRoundGoalsConceded(_teamBScore);
        }
        else {
            updateRoundGamesTied(1);
            updateRoundGoalsFor(_teamAScore);
            updateRoundGoalsConceded(_teamBScore);
        }

    };

    // club statistics 
    void ClubStatistics() {
        calculatePoints();
        calculateGoalDifference();
        cout << getClubPosition() << " " << getClubName() << " \t\t" << getGamesPlayed() << " \t" << getGamesWon() << " \t" << getGamesTied() << " \t" << getGamesLost() << " \t" << getGoalsFor() << " \t" << getGoalsConceded() << " \t" << getGoalDifference() << " \t" << getPoints() << endl;
    };

    // club details
    void ShowClub() {
        cout << getClubPosition() << " \t" << getClubName() << " \t\t\t" << getClubAbr() << " \t\t\t\t" << getClubStrenght() << endl;
    }

    // show Round statistics
    void ShowRoundStatistics() {
        updateRoundPoints();
        updateRoundGoalDifference();
        cout << getClubPosition() << "\t" << getClubAbr() << " \t\t\t" << getRoundGamesPlayed() << " \t" << getRoundGamesWon() << " \t" << getRoundGamesTied() << " \t" << getRoundGamesLost() << " \t" << getRoundGoalsFor() << " \t" << getRoundGoalsConceded() << " \t" << getRoundGoalDifference() << " \t" << getRoundPoints() << endl;
    }

    // show round statistics
    void ShowRoundGames() {
        for (auto& game : RoundGames) {
            cout << game.second << endl;
        }
    }
};

