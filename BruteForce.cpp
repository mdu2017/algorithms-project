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
using namespace std;

double bruteForce(SDL_Plotter &g, vector<pair<int,int>> pointVector){
    if(pointVector.size() == 1){
        // if there is only one point
        return 0;
    }
    double minimum = DBL_MAX;
    vector<line> goodLines;

    for(int i = 0; i < pointVector.size(); ++i){
        for(int j = i + 1; j < pointVector.size(); ++j){
            redraw(g, pointVector, &goodLines);
            line temp(pointVector[i], pointVector[j]);
            temp.draw(g);
            g.update();
            if( pointDistance(pointVector[i], pointVector[j]) < minimum){
                minimum = pointDistance(pointVector[i], pointVector[j]);
                if( goodLines.size() > 0){
                    goodLines.pop_back();
                }
                goodLines.push_back(line(pointVector[i], pointVector[j]));
            }
        }
    }
    redraw(g, pointVector, &goodLines);
    return minimum;
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