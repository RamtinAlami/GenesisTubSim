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
    next_to_end = false;
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
        setX(dest_x);
        setY(dest_y);
        return true;
    }
    else
    {
        setX(x + (amount * cos(theta)));
        setY(y + (amount * sin(theta)));
        return false;
    }
}

void Location::move_directions(int rl, int ud, int speed)
{
    setX(x + rl * speed);
    setY(y + ud * speed);
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
void Location::setX(double nx)
{
    // x = mod(nx, X_LIMIT);
    // next_to_end = true;
    if (nx < 0)
    {
        // x = 1;
        x = mod(nx, X_LIMIT);
    }
    else if (nx >= X_LIMIT)
    {
        // x = X_LIMIT - 1;
        x = mod(nx, X_LIMIT);
    }
    else
    {
        next_to_end = false;
        x = nx;
    }
}
void Location::setY(double ny)
{
    // y = mod(ny, Y_LIMIT);
    // next_to_end = true;
    if (ny < 0)
    {
        // y = 1;
        y = mod(ny, Y_LIMIT);
    }
    else if (ny >= Y_LIMIT)
    {
        // y = Y_LIMIT - 1;
        y = mod(ny, Y_LIMIT);
    }
    else
    {
        next_to_end = false;
        y = ny;
    }
}