//
//  robot_room_cleaner.cpp
//
//  Created by omlenka on 02/05/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
class Solution {
public:
    typedef enum
    {
        up,
        down,
        left,
        right
    }direction;
    
    typedef enum
    {
        turn_left,
        turn_right,
        no_turn
    }turn;
    
    direction getNewDirection(direction curr_dirr, turn curr_turn)
    {
        if(curr_turn == no_turn)
            return curr_dirr;
        direction new_dirr;
        switch(curr_dirr)
        {
            case up:
                if(curr_turn == turn_left)
                    new_dirr = left;
                else if(curr_turn == turn_right)
                    new_dirr = right;
                break;
            case down:
                if(curr_turn == turn_left)
                    new_dirr = right;
                else if(curr_turn == turn_right)
                    new_dirr = left;
                break;
            case left:
                if(curr_turn == turn_left)
                    new_dirr = down;
                else if(curr_turn == turn_right)
                    new_dirr = up;
                break;
            case right:
                if(curr_turn == turn_left)
                    new_dirr = up;
                else if(curr_turn == turn_right)
                    new_dirr = down;
                break;
        }
        return new_dirr;
    }
    
    void turnDirection(Robot& robot, direction destination, direction curr)
    {
        while(curr != destination)
        {
            robot.turnLeft();
            curr = getNewDirection(curr,turn_left);
        }
    }
    
    void getNewLocation(int x, int y, int &new_x, int &new_y, direction dirr)
    {
        if(dirr == up)
        {
            new_x = x-1;
            new_y = y;
        }
        else if(dirr == down)
        {
            new_x = x+1;
            new_y = y;
        }
        else if(dirr == left)
        {
            new_x = x;
            new_y = y-1;
        }
        else if(dirr == right)
        {
            new_x = x;
            new_y = y+1;
        }
    }
    
    direction opposite(direction dir)
    {
        direction opp;
        switch(dir)
        {
            case left:
                opp = right;
                break;
            case right:
                opp = left;
                break;
            case up:
                opp = down;
                break;
            case down:
                opp = up;
                break;
        }
        return opp;
    }
    
    direction cleanRoomDFS(Robot& robot, unordered_set<pair<int,int>, pair_hash> &us,int x, int y, direction curr_direction)
    {
        us.insert(make_pair(x,y));
        robot.clean();
        direction initial_dirr = curr_direction;
        bool left_cell = false, right_cell = false, up_cell = false,down_cell = false;
        
        int new_x, new_y;
        
        while(!left_cell || !right_cell || !up_cell || !down_cell)
        {
            if(!left_cell)
            {
                turnDirection(robot, left, curr_direction);
                curr_direction = left;
                getNewLocation(x,y,new_x,new_y, curr_direction);
                if(us.find(make_pair(new_x,new_y)) == us.end() && robot.move())
                {
                    curr_direction = cleanRoomDFS(robot, us, new_x, new_y, curr_direction);
                }
                left_cell = true;
            }
            if(!right_cell)
            {
                turnDirection(robot, right, curr_direction);
                curr_direction = right;
                getNewLocation(x,y,new_x,new_y, curr_direction);
                if(us.find(make_pair(new_x,new_y)) == us.end() && robot.move())
                {
                    curr_direction = cleanRoomDFS(robot, us, new_x, new_y, curr_direction);
                }
                right_cell = true;
            }
            if(!up_cell)
            {
                turnDirection(robot, up, curr_direction);
                curr_direction = up;
                getNewLocation(x,y,new_x,new_y, curr_direction);
                if(us.find(make_pair(new_x,new_y)) == us.end() && robot.move())
                {
                    curr_direction = cleanRoomDFS(robot, us, new_x, new_y, curr_direction);
                }
                up_cell = true;
            }
            if(!down_cell)
            {
                turnDirection(robot, down, curr_direction);
                curr_direction = down;
                getNewLocation(x,y,new_x,new_y, curr_direction);
                if(us.find(make_pair(new_x,new_y)) == us.end() && robot.move())
                {
                    curr_direction = cleanRoomDFS(robot, us, new_x, new_y, curr_direction);
                }
                down_cell = true;
            }
        }
        direction return_dir = opposite(initial_dirr);
        turnDirection(robot, return_dir, curr_direction);
        robot.move();
        return return_dir;
    }
    
    void cleanRoom(Robot& robot)
    {
        unordered_set<pair<int,int>, pair_hash> us;
        cleanRoomDFS(robot, us,0,0, up);
    }
};
