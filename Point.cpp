/*
    Author: Chris Helms
    Assignment Title: Project 1
    Assignment Description: Graphically displays input curves to the screen.
    Due Date: 1/28/2019
    Date Created: 1/22/2019
    Date Last Modified: 1/28/2019
*/

#include "point.h"
#include <iostream>
using namespace std;

/*
    Description: Default constructor.
    Return: N/A
    Precondition: The instance does not already exist.
    Postcondition: An instance is created.
*/
point::point() {
    x = y = 0;
    color = color_rgb();
}

/*
    Description: Custom constructor.
    Return: N/A
    Precondition: The instance does not already exist.
    Postcondition: An instance is created with coordinates x & y.
*/
point::point(int x, int y) {
    this->x = x;
    this->y = y;
    color = color_rgb();
}

/*
    Description: Copy constructor.
    Return: N/A
    Precondition: The instance does not already exist.
    Postcondition: A copy of point p is created.
*/
point::point(const point& p) {
    this->x = p.x;
    this->y = p.y;
    this->color = p.color;
}

/*
    Description: Destructor.
    Return: N/A
    Precondition: Instance exists.
    Postcondition: The instance is destroyed.
*/
point::~point() {

}

/*
    Description: Sets y value.
    Return: void
    Precondition: y is valid.
    Postcondition: y value is set to y.
*/
void point::setY(int y) {
    this->y = y;
}

/*
    Description: Sets x value.
    Return: void
    Precondition: x is valid.
    Postcondition: x value is set to x.
*/
void point::setX(int x) {
    this->x = x;
}

/*
    Description: Sets color.
    Return: void
    Precondition: c is valid.
    Postcondition: color is set to c.
*/
void point::setColor(color_rgb c) {
    this->color = c;
}

/*
    Description: Gets x.
    Return: int
    Precondition: Instance exists.
    Postcondition: x is unchanged.
*/
int point::getX() {
    return x;
}

/*
    Description: Gets y.
    Return: int
    Precondition: Instance exists.
    Postcondition: y is unchanged.
*/
int point::getY() {
    return y;
}

/*
    Description: Gets color.
    Return: color_rgb
    Precondition: Instance exists.
    Postcondition: color is unchanged.
*/
color_rgb point::getColor() {
    return color;
}

/*
    Description: Assignment operator override.
    Return: point&
    Precondition: rhs is valid input.
    Postcondition: rhs is unchanged.
*/
point& point::operator=(const point& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->color = rhs.color;

    return *this;
}

/*
    Description: Displays points to output stream.
    Return: void
    Precondition: Output stream is valid.
    Postcondition: Data is unchanged.
*/
void point::display(ostream& out) {
    out << "(" << x << ", " << y << ")" << endl;
}

/*
    Description: Plots point to screen.
    Return: void
    Precondition: Plotter has been initialized.
    Postcondition: Data is unchanged.
*/
//void point::draw(SDL_Plotter& g) {
//    if ( -y + g.getRow() < 0 || g.getRow() < -y + g.getRow() ) {
//        cout << "ERROR: out of bounds." << endl;
//        cout << y << " " << -y + g.getRow() << endl;
//    }
//    g.plotPixel( x, -y + g.getRow(), color.getR(), color.getG(), color.getB() );
//}