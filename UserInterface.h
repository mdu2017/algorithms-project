/*
* Author: Marquise Bell, Garret Yero
* Assignment Title: Divide and Conquer
* Assignment Description: This program finds the convex hull of points through a
*                           brute force algorithm
* Due Date: 5/6/2019
* Date Created: 4/5/2019
* Date Last Modified: 5/5/2019
*/

#ifndef GROUPPROJECT_USERINTERFACE_H
#define GROUPPROJECT_USERINTERFACE_H

#include "SDL_Plotter.h"
#include "line.h"
#include "Letter.h"
#include <vector>

const int ROW_MAX = 500, COL_MAX = 1000, RAN_PTS = 20, GUI_X = 320;

/**
 * description: Writes a word to the screen based on the letters
 * return: void
 * precondition: there is an SDL Plotter, string, color, integer, and point
 * postcondition: The word is written to the screen
 */
void writeWord( SDL_Plotter &g, string str, Color c, int s, Point p );

/**
 * description: Start menu interface
 * return: void
 * precondition: There is an SDL Plotter g that exists
 * postcondition: the start screen is drawn
 */
void userInterface( SDL_Plotter &g );

/*
    Description: Redraws all points & lines of graphic.
    Return: void
    Precondition: Plotter has been initialzied & variables are valid.
    Postcondition: Graphic is redrawn.
*/
void redraw( SDL_Plotter &g, vector<pair<int, int>> &p,
             vector<line> *L );

/**
 * description: Clearrs the screen
 * return: void
 * precondition: There exists an SDL Plotter g
 * postcondition: The screen is cleared
 */
void clearScreen( SDL_Plotter &g );

#endif //GROUPPROJECT_USERINTERFACE_H