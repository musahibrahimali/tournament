#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Team {
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
        Team(string _clubName, string _clubAbr,int _clubStrenght = 0, int _goalsConceded = 0, int _goalsFor = 0,int _gamesPlayed = 0, int _gamesLost = 0,int _gamesWon = 0, int _gamesTied = 0,int _points = 0,int _goalAverage = 0,int _round = 1) {
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

    
        void setClubName(string _clubName) {
            ClubName = _clubName;
        };
        void setClubAbr(string _clubAbr) {
            ClubAbr = _clubAbr;
        };
        void setClubStrenght(int _clubStrenght) {
            ClubStrenght = _clubStrenght;
        };
        void setGoalsAgainst(int _goalsConceded) {
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
        void updateRoundPoints() {
            RoundPoints = (RoundGamesWon * 3) + RoundGamesTied;
        };
        void updateRoundGoalsConceded(int _goals) {
            RoundGoalsConceded += _goals;
        };
        void updateRoundGoalsFor(int _goals) {
            RoundGoalsFor += _goals;
        };
        void updateRoundGoalDifference() {
            RoundGoalDifference = RoundGoalsFor - RoundGoalsConceded;
        };
        void updateRoundGamesPlayed(int _gamesPlayed) {
            RoundGamesPlayed += _gamesPlayed;
        };
        void updateRoundGamesLost(int _gamesLost) {
            RoundGamesLost += _gamesLost;
        };
        void updateRoundGamesWon(int _gamesWon) {
            RoundGamesWon += _gamesWon;
        };
        void updateRoundGamesTied(int _gamesTied) {
            RoundGamesTied += _gamesTied;
        };
        int getRoundGamesPlayed() {
            return RoundGamesPlayed;
        };
        int getRoundGamesLost() {
            return RoundGamesLost;
        };
        int getRoundGamesWon() {
            return RoundGamesWon;
        };
        int getRoundGamesTied() {
            return RoundGamesTied;
        };
        int getRoundGoalsConceded() {
            return RoundGoalsConceded;
        };
        int getRoundGoalsFor() {
            return RoundGoalsFor;
        };
        int getRoundGoalDifference() {
            return RoundGoalDifference;
        };
        int getRoundPoints() {
            return RoundPoints;
        };
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
        void ClubStats() {
            calculatePoints();
            calculateGoalDifference();
            cout << getClubPosition() << " " << getClubName() << " \t\t" << getGamesPlayed() << " \t" << getGamesWon() << " \t" << getGamesTied() << " \t" << getGamesLost() << " \t" << getGoalsFor() << " \t" << getGoalsConceded() << " \t" << getGoalDifference() << " \t" << getPoints() << endl;
        };
        void DisplayClub() {
            cout << getClubPosition() << " \t" << getClubName() << " \t\t\t" << getClubAbr() << " \t\t\t\t" << getClubStrenght() << endl;
        }
        void DisplayRoundStats() {
            updateRoundPoints();
            updateRoundGoalDifference();
            cout << getClubPosition() << "\t" << getClubAbr() << " \t\t\t" << getRoundGamesPlayed() << " \t" << getRoundGamesWon() << " \t" << getRoundGamesTied() << " \t" << getRoundGamesLost() << " \t" << getRoundGoalsFor() << " \t" << getRoundGoalsConceded() << " \t" << getRoundGoalDifference() << " \t" << getRoundPoints() << endl;
        }
        void ShowRoundGames() {
            for (auto& game : RoundGames) {
                cout << game.second << endl;
            }
        }
};

