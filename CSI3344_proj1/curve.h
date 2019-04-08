/*
    Author: Chris Helms
    Assignment Title: Project 1
    Assignment Description: Graphically displays input curves to the screen.
    Due Date: 1/28/2019
    Date Created: 1/22/2019
    Date Last Modified: 1/28/2019
*/

#pragma once

#include <vector>
#include <math.h>
#include "line.h"

typedef vector<pair<int, long double>> DataSet_t;
typedef vector<DataSet_t> Data_t;

class curve {
public:
    /*
        Description: Default constructor.
        Return: N/A
        Precondition: The instance does not already exist.
        Postcondition: An instance is created.
    */
    curve();

    /*
        Description: Destructor.
        Return: N/A
        Precondition: Instance exists.
        Postcondition: The instance is destroyed.
    */
    virtual ~curve();

    /*
        Description: Displays the data to the output stream.
        Return: void
        Precondition: Data & output stream are valid.
        Postcondition: Data is unchanged.
    */
    void display(Data_t data, ostream&);

    /*
        Description: Graphically displays data to screen.
        Return: void
        Precondition: Data is valid. Plotter has been initialized.
        Postcondition: Data is unchanged.
    */
    void draw(Data_t data, SDL_Plotter&);

    /*
        Description: Returns true if same scale.
        Return: bool
        Precondition: sameScale has been initialized.
        Postcondition: sameScale is unchanged.
    */
    bool getSameScale() { return sameScale; }

    /*
        Description: Reverses sameScale value.
        Return: void
        Precondition: Scale is set to same of individual.
        Postcondition: Scale is reversed.
    */
    void setSameScale(bool t) { sameScale = t; }

private:
    /*
        Description: Plots axis to screen.
        Return: void
        Precondition: margin, maxX, maxY are valid. Plotter has been
            initialized.
        Postcondition: margin, maxX, maxY are unchanged.
    */
    void plotAxis(int margin, int maxX, int maxY, SDL_Plotter& g);

    /*
        Description: Plots tick marks on axis.
        Return: void
        Precondition: margin, maxX, maxY are valid. Plotter has been
            initialized.
        Postcondition: margin, maxX, maxY are unchanged.
    */
    void plotTickMarks(int margin, int maxX, int maxY, SDL_Plotter& g);

    /*
        Description: Checks if points may be plotted by plotter.
        Return: bool
        Precondition: a, margin are valid. Plotter has been initialized.
        Postcondition: a, margin are unchanged.
    */
    bool goodPoints(line a, int margin, SDL_Plotter& g);

    bool sameScale;
};