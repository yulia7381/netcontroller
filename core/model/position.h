#ifndef POSITION_H
#define POSITION_H

#include <iostream>

class Position {
public:
    Position() : x(0), y(0), floor(-1), building(-1) {}
    Position(int x, int y, int floor, int building)
    		: x(x), y(y), floor(floor), building(building) {};
    Position(const Position& position)
    		: x(position.x), y(position.y), floor(position.floor), building(position.building) {}

    int getX() const {return x;}
    int getY() const {return y;}
    int getFloor() const {return floor;}
    int getBuilding() const {return building;}
private:
    int x;
    int y;
    int floor;
    int building;
};

std::ostream& operator<< (std::ostream& os, const Position& p);
std::istream& operator>> (std::istream& is, Position& p);


#endif
