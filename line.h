/*
    Author: Chris Helms
    Assignment Title: Project 1
    Assignment Description: Graphically displays input curves to the screen.
    Due Date: 1/28/2019
    Date Created: 1/22/2019
    Date Last Modified: 1/28/2019
*/

#pragma once

#include "point.h"

class line {
public:
    /*
        Description: Default constructor.
        Return: N/A
        Precondition: The instance does not already exist.
        Postcondition: An instance is created.
    */
    line();

    /*
        Description: Custom constructor.
        Return: N/A
        Precondition: The instance does not already exist.
        Postcondition: An instance is created with points p1 & p2.
    */
    line(point p1, point p2);

    /*
        Description: Destructor.
        Return: N/A
        Precondition: Instance exists.
        Postcondition: The instance is destroyed.
    */
    virtual ~line();

    /*
        Description: Displays line to screen.
        Return: void
        Precondition: Output stream is valid.
        Postcondition: Data is unchanged.
    */
    void display(ostream&  out);

    /*
        Description: Graphically displays line to screen.
        Return: void
        Precondition: Plotter has been initialized.
        Postcondition: Data is unchanged.
    */
    void draw(SDL_Plotter& g);

    /*
        Description: Sets p1 to p.
        Return: void
        Precondition: p is valid.
        Postcondition: p1 is set to p.
    */
    void setP1(point p);

    /*
        Description: Sets p2 to p.
        Return: void
        Precondition: p is valid.
        Postcondition: p2 is set to p.
    */
    void setP2(point p);

    /*
        Description: Sets color to c.
        Return: void
        Precondition: c is valid.
        Postcondition: Color is set to c.
    */
    void setColor(color_rgb c) { color = c; }

    /*
        Description: Gets p1.
        Return: point
        Precondition: Instance exists.
        Postcondition: p1 is unchanged.
    */
    point getP1() { return p1; }

    /*
        Description: Gets p2.
        Return: point
        Precondition: Instance exists.
        Postcondition: p2 is unchanged.
    */
    point getP2() { return p2; }

    /*
        Description: Gets color.
        Return: color_rgb
        Precondition: Instance exists.
        Postcondition: color is unchanged.
    */
    color_rgb getColor() { return color; }

    /*
        Description: Iterates color.
        Return: void
        Precondition: Instance exists.
        Postcondition: Color is advanced to next color.
    */
    void nextColor();

    /*
        Description: Color is reset to default.
        Return: void
        Precondition: Instance exists.
        Postcondition: Color is reset to default.
    */
    void resetColor();

private:
    point p1, p2;
    color_rgb color;

    /*
        Description: Determines if slope exists & calculates.
        Return: bool
        Precondition: m is valid.
        Postcondition: m is set to the calculated slope.
    */
    bool slope(double& m);

    /*
        Description: Determines if intercept exists & calculates.
        Return: bool
        Precondition: b is valid.
        Postcondition: b is set to the calculated intercept.
    */
    bool intercept(double& b);

    int currentColor;
};