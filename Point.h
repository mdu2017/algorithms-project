/*
    Author: Chris Helms
    Assignment Title: Project 1
    Assignment Description: Graphically displays input curves to the screen.
    Due Date: 1/28/2019
    Date Created: 1/22/2019
    Date Last Modified: 1/28/2019
*/

#pragma once

#include <ostream>
#include "SDL_Plotter.h"
#include "color_rgb.h"
using namespace std;

class point {
public:
    /*
        Description: Default constructor.
        Return: N/A
        Precondition: The instance does not already exist.
        Postcondition: An instance is created.
    */
    point();

    /*
        Description: Custom constructor.
        Return: N/A
        Precondition: The instance does not already exist.
        Postcondition: An instance is created with coordinates x & y.
    */
    point(int x, int y);

    /*
        Description: Copy constructor.
        Return: N/A
        Precondition: The instance does not already exist.
        Postcondition: A copy of point p is created.
    */
    point(const point& p);

    /*
        Description: Destructor.
        Return: N/A
        Precondition: Instance exists.
        Postcondition: The instance is destroyed.
    */
    virtual ~point();

    /*
        Description: Sets y value.
        Return: void
        Precondition: y is valid.
        Postcondition: y value is set to y.
    */
    void setY(int y);

    /*
        Description: Sets x value.
        Return: void
        Precondition: x is valid.
        Postcondition: x value is set to x.
    */
    void setX(int x);

    /*
        Description: Sets color.
        Return: void
        Precondition: c is valid.
        Postcondition: color is set to c.
    */
    void setColor(color_rgb c);

    /*
        Description: Gets x.
        Return: int
        Precondition: Instance exists.
        Postcondition: x is unchanged.
    */
    int getX();

    /*
        Description: Gets y.
        Return: int
        Precondition: Instance exists.
        Postcondition: y is unchanged.
    */
    int getY();

    /*
        Description: Gets color.
        Return: color_rgb
        Precondition: Instance exists.
        Postcondition: color is unchanged.
    */
    color_rgb getColor();

    /*
        Description: Assignment operator override.
        Return: point&
        Precondition: rhs is valid input.
        Postcondition: rhs is unchanged.
    */
    point& operator=(const point& rhs);

    /*
        Description: Displays points to output stream.
        Return: void
        Precondition: Output stream is valid.
        Postcondition: Data is unchanged.
    */
    void display(ostream&);

    /*
        Description: Plots point to screen.
        Return: void
        Precondition: Plotter has been initialized.
        Postcondition: Data is unchanged.
    */
    //void draw(SDL_Plotter&);

private:
    int x, y;
    color_rgb color;
};