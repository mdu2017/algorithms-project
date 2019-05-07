/*
* Author: Marquise Bell, Garret Yero, Chris Helms, Mark Du, Grant Gasser
* Assignment Title: Final Project
* Assignment Description: Driver to display divide & conquer & brute force algorithms
*   for closest pair & convex hull.
* Due Date: 5/3/2019
* Date Created: 4/5/2019
* Date Last Modified: 5/6/2019
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include "line.h"
#include "bruteForceConvexHull.h"
#include "BruteForce.h"
#include "dcConvexHull.h"
#include "Divide_and_Conquer.h"
#include "UserInterface.h"

using namespace std;

/*
 * description: receives input from user
 * return: void
 * precondition: g has been initialized
 * postcondition: data has been stored in p
 */
void receiveInput( SDL_Plotter &g, vector<pair<int, int>> &p );

/*
 * description: cleans data provided from user
 * return: void
 * precondition: d has data
 * postcondition: duplicates have been removed from d
 */
void cleanData( vector<pair<int, int>> &d );

/*
 * description: runs algorithms based off user input
 * return: void
 * precondition: g has been initialized & p has data
 * postcondition: data is unchanged, results are displayed to screen
 */
void runAlgorithm( SDL_Plotter &g, vector<pair<int, int>> &p );

/*
 * description: runs main loop of program
 * return: int
 * precondition: program is requested to execute
 * postcondition: user has requested quit
 */
int main( int argc, char** argv ) {
    SDL_Plotter plotter( ROW_MAX, COL_MAX );
    vector<pair<int, int>> data;

    // display user interface
    userInterface( plotter );

    // while user has not requested to quit
    while (!plotter.getQuit()) {
        // receive data input from user
        cout << "receiving input...\n";
        receiveInput( plotter, data );

        // remove duplicates from data
        cout << "cleaning data...\n";
        cleanData( data );

        // perform requested algorithm on data
        cout << "running algorithms...\n";
        runAlgorithm( plotter, data );

        // reset display for next set of points
        cout << "resetting...\n";
        clearScreen( plotter );

        // reset data for next set of points
        data = vector<pair<int, int>>();
    }

    return 0;
}

/*
 * description: receives input from user
 * return: void
 * precondition: g has been initialized
 * postcondition: data has been stored in p
 */
void receiveInput( SDL_Plotter &g, vector<pair<int, int>> &d ) {
    bool isDone = false;
    int mX = 0, mY = 0;

    // while user is inputting data
    while ( !g.getQuit() && !isDone ) {
        // if user hits enter
        if ( g.kbhit() ) {
            if ( g.getKey() == SDL_SCANCODE_RETURN ) {
                // exit receiveInput
                isDone = true;
            }
            else if ( g.getKey() == 'R' ) {
                // create RAN_PTS random points
                srand( ( unsigned ) time( NULL ) );
                for ( int i = 0; i < RAN_PTS; i++ ) {
                    d.push_back( make_pair( rand() % ( COL_MAX - GUI_X) + GUI_X,
                                            rand() % ROW_MAX ) );
                    point( d.back().first, d.back().second ).drawBig( g );
                    g.update();
                }
            }
        }

        // if user releases mouse button at a point on screen
        if ( g.getMouseUp( mX, mY ) && mX > GUI_X ) {
            // push point onto vector
            d.push_back( make_pair( mX, mY ) );

            // draw point to screen
            point( mX, mY ).drawBig( g );

            // display point to console (for testing)
            //p.display( cout );

            // update screen with new point
            g.update();
        }
    }
}

/*
 * description: cleans data provided from user
 * return: void
 * precondition: d has data
 * postcondition: duplicates have been removed from d
 */
void cleanData( vector<pair<int, int>> &d ) {
    unordered_set<string> goodPts;
    vector<int> goodNdx;
    stringstream convert;
    string str = "";
    int ndx = d.size() - 1;

    for ( int i = 0; i < ( int ) d.size(); i++ ) {
        convert.clear();

        // convert point to single string value
        convert << d[ i ].first << d[ i ].second;
        convert >> str;

        // if point has not already been found in d
        if ( goodPts.find( str ) == goodPts.end() ) {
            // add to set & mark as not a duplicate
            goodNdx.push_back( i );
            goodPts.insert( str );
        }
    }

    // remove duplicates from d
    vector<pair<int, int>> noDup;
    for ( vector<int>::iterator i = goodNdx.begin();
          i != goodNdx.end(); i++ ) {
        // add values with no duplicates to temporary vector
        noDup.push_back( d[ *i ] );

        // print value (for testing)
        //cout << "(" << d[ *i ].first << ", " << d[ *i ].second << ")\n";
    }
    d = noDup;
}

/*
 * description: runs algorithms based off user input
 * return: void
 * precondition: g has been initialized & p has data
 * postcondition: data is unchanged, results are displayed to screen
 */
void runAlgorithm( SDL_Plotter &g, vector<pair<int, int>> &p ) {
    bool isDone = false;
    vector<point> points;

    while ( !g.getQuit() && !isDone ) {
        if ( g.kbhit() ) {
            // clear the screen & redraw the points
            clearScreen( g );
            for ( vector<pair<int, int>>::iterator i = p.begin();
                  i != p.end(); i++ ) {
                point( i->first, i->second ).drawBig( g );
            }
            g.update();

            switch ( g.getKey() ) {
                // brute-force closest-pair
                case '1':
                    cout << "brute-force closest-pair\n";
                    bruteForce( g, p );
                    break;

                // divide-&-conquer closest-pair
                case '2':
                    cout << "divide-&-conquer closest-pair\n";
                    divideAndConquerClosest(g, p);
                    break;
                // brute-force convex hull
                case '3':
                    cout << "brute-force convex hull\n";
                    bruteForceConvexHull(g, p);
                    break;

                // divide-&-conquer convex hull
                case '4':
                    cout << "divide-&-conquer convex hull\n";
                    divAndConqConvexHull( g, p );
                    break;

                // user requested to exit runAlgorithm
                case SDL_SCANCODE_RETURN:
                    isDone = true;
                    break;
            }
        }
    }
}