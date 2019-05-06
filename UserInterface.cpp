//
// Created by BELLMA on 5/6/2019.
//

#include "UserInterface.h"

/**
 * description: Writes a word to the screen based on the letters
 * return: void
 * precondition: there is an SDL Plotter, string, color, integer, and point
 * postcondition: The word is written to the screen
 */
void writeWord( SDL_Plotter &g, string str, Color c, int s, Point p ) {
    int ndx = 0;
    for ( auto i : str ) {
        if ( i != ' ' ) {
            Letter( i, c, s, Point( p.x + ndx * s, p.y ) ).draw( g );
        }
        ndx += 12;
    }
}

/**
 * description: Start menu interface
 * return: void
 * precondition: There is an SDL Plotter g that exists
 * postcondition: the start screen is drawn
 */
void userInterface( SDL_Plotter &g ) {
    writeWord( g, "/) BRUTE FORCE", Color(), 1, Point( 0, 20 ) );
    writeWord( g, "   CLOSEST PAIR", Color(), 1, Point( 0, 35 ) );

    writeWord( g, "2) DIVIDE AND CONQUER", Color(), 1, Point( 0, 60 ) );
    writeWord( g, "   CLOSEST PAIR", Color(), 1, Point( 0, 75 ) );

    writeWord( g, "3) BRUTE FORCE", Color(), 1, Point( 0, 105 ) );
    writeWord( g, "   CONVEX HULL", Color(), 1, Point( 0, 120 ) );

    writeWord( g, "4) DIVIDE AND CONQUER", Color(), 1, Point( 0, 150 ) );
    writeWord( g, "   CONVEX HULL", Color(), 1, Point( 0, 165 ) );

    writeWord( g, "R) 2$ RANDOM POINTS", Color(), 1, Point( 0, 195 ) );

    writeWord( g, "INSTRUCTIONS:", Color(), 1, Point( 0, 225 ) );
    writeWord( g, "-CLICK TO SET POINTS", Color(), 1, Point( 0, 240 ) );
    writeWord( g, "-PRESS ENTER TO TEST", Color(), 1, Point( 0, 255 ) );
    writeWord( g, "-PRESS /-4 FOR ALGORITHMS", Color(), 1, Point( 0, 270 ) );
    writeWord( g, "-PRESS ENTER TO START OVER", Color(), 1, Point( 0, 285 ) );

    line( point( GUI_X-1, 0 ), point( GUI_X-1, ROW_MAX ) ).draw( g );
    line( point( GUI_X-2, 0 ), point( GUI_X-2, ROW_MAX ) ).draw( g );

    g.update();
}

/*
    Description: Redraws all points & lines of graphic.
    Return: void
    Precondition: Plotter has been initialzied & variables are valid.
    Postcondition: Graphic is redrawn.
*/
void redraw( SDL_Plotter &g, vector<pair<int, int>> &p,
             vector<line> *L ) {
    for ( int i = GUI_X; i < COL_MAX; i++ ) {
        for ( int j = 0; j < ROW_MAX; j++ ) {
            g.plotPixel( i, j, 255, 255, 255 );
        }
    }

    for ( auto i : p ) {
        point( i.first, i.second ).drawBig( g );
    }
    if ( L ) {
        for ( auto i : *L ) {
            i.draw( g );
        }
    }

    g.update();
}

/**
 * description: Clearrs the screen
 * return: void
 * precondition: There exists an SDL Plotter g
 * postcondition: The screen is cleared
 */
void clearScreen( SDL_Plotter &g ) {
    vector<pair<int, int>> empty;
    redraw( g, empty, nullptr );
    g.update();
}