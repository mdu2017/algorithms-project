/*
* Author: Marquise Bell, Garret Yero
* Assignment Title: Closest Pair Brute Force
* Assignment Description: This program finds the closest pair of points through a
*                           Brute Force algorithm
* Due Date: 5/3/2018
* Date Created: 4/5/2018
* Date Last Modified: 4/15/2018
*/

#include "BruteForce.h"
#include "cfloat"
#include "cmath"
#include "line.h"
using namespace std;

void closestPairBruteForce( SDL_Plotter &g, vector<pair<int, int>> &p ) {
    pair<int, int> p1, p2;
    double minimum = DBL_MAX;
    vector<line> goodLines;

    if(p.size() == 1){
        // if there is only one point
        return;
    }

    for(int i = 0; i < p.size(); ++i){
        for(int j = i + 1; j < p.size(); ++j){
            double candidate = Min( pointDistance( p[ i ],
                                                p[ j ] ), minimum );
            draw( g, p[ i ], p[ j ] );
            g.update();
            redraw( g, p, &goodLines );
            if ( candidate < minimum ) {
                p1 = p[ i ];
                p2 = p[ j ];
                line li( p1, p2 );
                li.setColor(color_rgb(255,0,0));
                if ( !goodLines.empty() ) {
                    goodLines.pop_back();
                }
                goodLines.push_back( li );
                redraw( g, p, &goodLines );
                minimum = candidate;
            }
        }
    }
}

double pointDistance(pair<int,int> p1, pair<int,int> p2){
    return sqrt( (p1.first - p2.first)*(p1.first - p2.first) +
                 (p1.second - p2.second)*(p1.second - p2.second));
}

double Min(double n1, double n2){
    if(n1 < n2){
        return n1;
    }
    else{
        return n2;
    }
}