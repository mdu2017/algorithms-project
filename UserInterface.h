#pragma once

#include "SDL_Plotter.h"
#include "line.h"
#include "Letter.h"
#include <vector>

const int ROW_MAX = 500, COL_MAX = 1000, RAN_PTS = 20, GUI_X = 320;

void writeWord( SDL_Plotter &g, string str, Color c, int s, Point p ) {
    int ndx = 0;
    for ( auto i : str ) {
        if ( i != ' ' ) {
            Letter( i, c, s, Point( p.x + ndx * s, p.y ) ).draw( g );
        }
        ndx += 12;
    }
}

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

void clearScreen( SDL_Plotter &g ) {
    vector<pair<int, int>> empty;
    redraw( g, empty, nullptr );
    g.update();
}