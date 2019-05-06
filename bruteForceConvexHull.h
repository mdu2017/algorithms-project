/*
 * Brute force Convex Hull
 */

#ifndef GROUPPROJECT_BRUTEFORCECONVEXHULL_H
#define GROUPPROJECT_BRUTEFORCECONVEXHULL_H

#include "line.h"
#include "SDL_Plotter.h"
#include "UserInterface.h"
#include <vector>
using namespace std;

void bruteForceConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p );
int oneSideOfLine(pair<int, int> i,  pair<int, int> j, pair<int, int> k);

//O(n^3)
void bruteForceConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p ){
    vector<line> goodLines;
    bool skipAnimation = false;

    for(auto p1: p){

        for(auto p2: p){
            if(p1 != p2){

                bool allPtsOneSide = true;
                for(auto k: p){
                    if ( g.kbhit() && g.getKey() == 'S') {
                        skipAnimation = true;
                        cout << "here" << endl;
                    }

                    if(k != p1 and k != p2){
                        int side = oneSideOfLine(p1, p2, k);

                        if ( !skipAnimation ) {
                            draw( g, p1, p2 );
                            g.update();
                            redraw( g, p, &goodLines );
                        }

                        //Checks if a point is not on one side
                        if(side < 0){
                            allPtsOneSide = false;
                            break;
                        }
                    }
                }

                if(allPtsOneSide){
                    cout << "Adding segment with points: (" << p1.first << "," << p1.second << ") to (" << p2.first << "," << p2.second << ")" << endl;
                    line newLine( p1, p2 );
                    newLine.setColor(color_rgb(30, 225, 50));
                    goodLines.push_back( newLine );
                    newLine.draw( g );
                    g.update();
                }
            }
        }
    }
}

int oneSideOfLine(pair<int, int> i,  pair<int, int> j, pair<int, int> k){
    //(x3-x1) * (y2-y1) - (y3-y1) * (x2-x1)
    return (k.first - i.first) * (j.second - i.second) - (k.second - i.second) * (j.first - i.first);
}


#endif //GROUPPROJECT_BRUTEFORCECONVEXHULL_H
