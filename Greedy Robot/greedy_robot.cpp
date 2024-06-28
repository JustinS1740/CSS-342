// Justin Singsanavong
#include <iostream>
#include "robot.h"

int main(int argc, char* argv[])
{
    int max_distance = atoi(argv[1]);
    Point robot_pos = {atoi(argv[2]), atoi(argv[3])};
    Point treasure_pos = {atoi(argv[4]), atoi(argv[5])};

    //checks if max_distance is valid
    if (max_distance < 0) {
        cout << "Negative max distance not allowed" << endl;
        return 0;
    }

    //checks if robot is already at treasure
    if (robot_pos.x == treasure_pos.x && robot_pos.y == treasure_pos.y) {
        cout << "Robot already at treasure!" << endl;
        return 0;
    }

    Robot rb(max_distance, robot_pos, treasure_pos);
}
