// Justin Singsanavong
#include "robot.h"

Robot::Robot() {
    max_distance_ = 0;
    robot_position_ = {0, 0};
    treasure_position_ = {0, 0};
    new_path_ = "";
    path_ = {};
}

Robot::Robot(const int& max_distance, const Point & robot_pos, const Point & treasure_pos) {
    max_distance_ = max_distance;
    robot_position_ = robot_pos;
    treasure_position_ = treasure_pos;
    new_path_ = "";
    path_ = {};
    FindPaths(max_distance, robot_pos, treasure_pos, new_path_, path_);
    PrintPaths(path_);
}

int Robot::max_distance() const {
    return max_distance_;
}

Point Robot::robot_position() const {
    return robot_position_;
}

Point Robot::treasure_position() const {
    return treasure_position_;
}

vector<string> Robot::path() const {
    return path_;
}

string Robot::new_path() const {
    return new_path_;
}

void Robot::FindPaths(const int& max_distance, const Point& robot_pos, const Point& treasure_pos, const string& new_path, vector<string>& path) const {
    //base case: if robot reaches the treasure
    if (robot_pos.x == treasure_pos.x && robot_pos.y == treasure_pos.y) {
        path.push_back(new_path);
        return;
    }

    //move North
    if (robot_pos.y < treasure_pos.y && (new_path.empty() || CanMove(new_path, 'N' , max_distance))) {
        Point new_robot_pos = {robot_pos.x, robot_pos.y + 1};
        FindPaths(max_distance, new_robot_pos, treasure_pos, new_path + "N", path);
    }

    //move South
    if (robot_pos.y > treasure_pos.y && (new_path.empty() || CanMove(new_path, 'S', max_distance))) {
        Point new_robot_pos = {robot_pos.x, robot_pos.y - 1};
        FindPaths(max_distance, new_robot_pos, treasure_pos, new_path + "S", path);
    }

    //move East
    if (robot_pos.x < treasure_pos.x && (new_path.empty() || CanMove(new_path, 'E', max_distance))) {
        Point new_robot_pos = {robot_pos.x + 1, robot_pos.y};
        FindPaths(max_distance, new_robot_pos, treasure_pos, new_path + "E", path);
    }

    //move West
    if (robot_pos.x > treasure_pos.x && (new_path.empty() || CanMove(new_path, 'W', max_distance))) {
        Point new_robot_pos = { robot_pos.x - 1, robot_pos.y };
        FindPaths(max_distance, new_robot_pos, treasure_pos, new_path + "W", path);
    }
}

bool Robot::CanMove(const string& new_path, char direction, int max_distance) const
{
    int count = 0;
    for (int i = new_path.size() - 1; i >= 0; i--) {
        if (new_path[i] == direction) {
            count++;
        }
        else {
            break;
        }
    }
    return count < max_distance;
}

void Robot::PrintPaths(const vector<string>&path) const {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << endl;
    }
    cout << "Number of Paths: " << path.size() << endl;
}