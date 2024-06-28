// Justin Singsanavong
#ifndef ROBOT_H_
#define ROBOT_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
    int x;
    int y;
};

class Robot {
public:
    //constructors
    Robot();
    Robot(const int& maxdistance, const Point& robot_pos, const Point& treasure_pos);

    //getters
    int max_distance() const;
    Point robot_position() const;
    Point treasure_position() const;
    vector<string> path() const;
    string new_path() const;

    //functions
    void FindPaths(const int& max_distance, const Point& robot_pos, const Point& treasure_pos, const string& new_path, vector<string>& path) const;
    void PrintPaths(const vector<string>& path) const;
    bool CanMove(const string& new_path, char direction, int max_distance) const;

private:
    //data members
    int max_distance_;
    Point robot_position_;
    Point treasure_position_;
    vector<string> path_;
    string new_path_;
};
#endif