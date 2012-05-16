#ifndef POSITION_H
#define POSITION_H

class Position {
public:
	Position(int x, int y, int floor, int building) : x(x), y(y), floor(floor), building(building) {};

	int getX() {return x;}
	int getY() {return y;}
	int getFloor() {return floor;}
	int getBuilding() {return building;}
private:
	int x;
	int y;
	int floor;
	int building;
};

#endif