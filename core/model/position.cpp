#include "position.h"

namespace core {

    std::ostream& operator<< (std::ostream& os, const Position& p) {
        os << p.getX() << " " << p.getY() << " " <<p.getFloor() << " " << p.getBuilding();
        return os;
    }

    std::istream& operator>> (std::istream& is, Position& p) {
        int x;
        int y;
        int floor;
        int building;

        is >> x >> y >> floor >> building;

        p = Position(x, y, floor, building);

        return is;
    }

    Position& Position::operator= (const Position& pos) {
        x = pos.x;
        y = pos.y;
        floor = pos.floor;
        building = pos.building;
        return *this;
    }

}
