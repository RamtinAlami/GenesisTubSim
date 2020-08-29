#ifndef LOCATION_H
#define LOCATION_H

class Location
{
private:
    double x, y;

public:
    Location();
    Location(double nx, double ny);

    double getX();
    double getY();
    void setX(double nx);
    void setY(double ny);

    double get_distance(Location other_location); // for moving towards
    double get_angle(Location other_location);    // for seeing later
    bool move_toward(Location destination, double amount);
    bool at_location(Location destination);
};

#endif