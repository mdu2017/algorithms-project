/*
    Author: Chris Helms
    Assignment Title: Project 1
    Assignment Description: Graphically displays input curves to the screen.
    Due Date: 1/28/2019
    Date Created: 1/22/2019
    Date Last Modified: 1/28/2019
*/

#include "color_rgb.h"

/*
    Description: Default constructor.
    Return: N/A
    Precondition: The instance does not already exist.
    Postcondition: An instance is created.
*/
color_rgb::color_rgb() {
    r = g = b = 0;
}

/*
    Description: Custom constructor.
    Return: N/A
    Precondition: The instance does not already exist.
    Postcondition: An instance is created with values r, g, b.
*/
color_rgb::color_rgb(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

/*
    Description: Destructor.
    Return: N/A
    Precondition: Instance exists.
    Postcondition: The instance is destroyed.
*/
color_rgb::~color_rgb() {

}

/*
    Description: Gets r.
    Return: int
    Precondition: Instance exists.
    Postcondition: r is unchanged.
*/
int color_rgb::getR() {
    return r;
}

/*
    Description: Gets g.
    Return: int
    Precondition: Instance exists.
    Postcondition: g is unchanged.
*/
int color_rgb::getG() {
    return g;
}

/*
    Description: Gets b.
    Return: int
    Precondition: Instance exists.
    Postcondition: b is unchanged.
*/
int color_rgb::getB() {
    return b;
}

/*
    Description: Sets r.
    Return: void
    Precondition: r is valid input.
    Postcondition: r value is set to r.
*/
void color_rgb::setR(int r) {
    this->r = r;
}

/*
    Description: Sets g.
    Return: void
    Precondition: g is valid input.
    Postcondition: g value is set to g.
*/
void color_rgb::setG(int g) {
    this->g = g;
}

/*
    Description: Sets b.
    Return: void
    Precondition: b is valid input.
    Postcondition: b value is set to b.
*/
void color_rgb::setB(int b) {
    this->b = b;
}

/*
    Description: Assignment operator override.
    Return: void
    Precondition: c is valid input.
    Postcondition: c is unchanged.
*/
void color_rgb::operator=(const color_rgb& c) {
    this->r = c.r;
    this->g = c.g;
    this->b = c.b;
}