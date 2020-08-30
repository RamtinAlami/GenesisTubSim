#include <math.h>
#include <bsd/stdlib.h>

#include "location.h"
#include "simulator.h"

#define CLOSE_ENOUGH 0.05 // The precision

Location::Location()
// Init a location to a random location
{
    x = arc4random_uniform(X_LIMIT);
    y = arc4random_uniform(Y_LIMIT);
}

Location::Location(double input_x, double input_y)
// Init a location based on input
{
    x = input_x;
    y = input_y;
}

bool Location::move_toward(Location destination, double amount)
{
    // going towards point x
    double dx = destination.x - x;
    double dy = destination.y - y;
    double theta = atan2(dy, dx);

    double distance = sqrt((dx * dx) + (dy * dy));

    if (distance < amount) // checks so we don't overshoot
    {
        x = destination.x;
        y = destination.y;
        return true;
    }
    else
    {
        x = x + (amount * cos(theta));
        y = y + (amount * sin(theta));
        return false;
    }
}

bool Location::move_toward(double dest_x, double dest_y, double amount)
{
    // going towards point x
    double dx = dest_x - x;
    double dy = dest_y - y;
    double theta = atan2(dy, dx);

    double distance = sqrt((dx * dx) + (dy * dy));

    if (distance < amount) // checks so we don't overshoot
    {
        x = dest_x;
        y = dest_y;
        return true;
    }
    else
    {
        x = x + (amount * cos(theta));
        y = y + (amount * sin(theta));
        return false;
    }
}

double Location::get_distance(Location other_location)
{
    // Return distance between two points
    double dx = other_location.x - x;
    double dy = other_location.y - y;
    return sqrt((dx * dx) + (dy * dy));
}

double Location::get_angle(Location other_location)
{
    // Return distance between two points
    double dx = other_location.x - x;
    double dy = other_location.y - y;
    return atan2(dy, dx);
}

// returns true if two locations are pretty much next to each other
bool Location::at_location(Location destination)
{
    return (get_distance(destination) < CLOSE_ENOUGH);
}

// getters and setter functions
double Location::getX() { return x; }
double Location::getY() { return y; }
void Location::setX(double nx) { x = nx; }
void Location::setY(double ny) { y = ny; }