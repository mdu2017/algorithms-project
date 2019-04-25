/*
    Author: Chris Helms
    Assignment Title: Project 1
    Assignment Description: Graphically displays input curves to the screen.
    Due Date: 1/28/2019
    Date Created: 1/22/2019
    Date Last Modified: 1/28/2019
*/

#pragma once

class color_rgb {
public:
    /*
        Description: Default constructor.
        Return: N/A
        Precondition: The instance does not already exist.
        Postcondition: An instance is created.
    */
    color_rgb();

    /*
        Description: Custom constructor.
        Return: N/A
        Precondition: The instance does not already exist.
        Postcondition: An instance is created with values r, g, b.
    */
    color_rgb(int r, int g, int b);

    /*
        Description: Destructor.
        Return: N/A
        Precondition: Instance exists.
        Postcondition: The instance is destroyed.
    */
    virtual ~color_rgb();

    /*
        Description: Gets r.
        Return: int
        Precondition: Instance exists.
        Postcondition: r is unchanged.
    */
    int getR();

    /*
        Description: Gets g.
        Return: int
        Precondition: Instance exists.
        Postcondition: g is unchanged.
    */
    int getG();

    /*
        Description: Gets b.
        Return: int
        Precondition: Instance exists.
        Postcondition: b is unchanged.
    */
    int getB();

    /*
        Description: Sets r.
        Return: void
        Precondition: r is valid input.
        Postcondition: r value is set to r.
    */
    void setR(int r);

    /*
        Description: Sets g.
        Return: void
        Precondition: g is valid input.
        Postcondition: g value is set to g.
    */
    void setG(int g);

    /*
        Description: Sets b.
        Return: void
        Precondition: b is valid input.
        Postcondition: b value is set to b.
    */
    void setB(int b);

    /*
        Description: Assignment operator override.
        Return: void
        Precondition: c is valid input.
        Postcondition: c is unchanged.
    */
    void operator=(const color_rgb& c);

private:
    int r, g, b;
};