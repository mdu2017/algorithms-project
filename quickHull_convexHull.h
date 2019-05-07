//Divide and conquer convex hull algorithm

#include <bits/stdc++.h>
#include <set>
#include <vector>
#include "SDL_Plotter.h"
#include "UserInterface.h"
using namespace std;

#ifndef GROUPPROJECT_CONVHULLDC_H
#define GROUPPROJECT_CONVHULLDC_H

int sideOfLine(pair<int, int> i, pair<int, int> j, pair<int, int> test);
int calcDist(pair<int, int> i, pair<int, int> j, pair<int, int> test);
void mergeParts(vector<pair<int, int>> &points, int num, int side,
            pair<int, int> p1, pair<int, int> p2, SDL_Plotter&);
void divAndConqConvexHull(vector<pair<int, int>> &points, int size, SDL_Plotter&);
void drawPoints(SDL_Plotter &g, set<pair<int, int>> &points);



//Keeps points in the convex hull
set<pair<int, int>> convexHullPoints;

int sideOfLine(pair<int, int> i, pair<int, int> j, pair<int, int> test){
    int side = 0;

    int n = (test.second-i.second)*(j.first-i.first) -
            (j.second-i.second)*(test.first-i.first);

    if(n > 0){
        side = 1;
    }
    else if(n < 0){
        side = -1;
    }

    return side;
}

int calcDist(pair<int, int> i, pair<int, int> j, pair<int, int> test){
    int dist1 = (test.second-i.second)*(j.first-i.first);
    int dist2 = (j.second-i.second)*(test.first-i.first);
    return abs(dist1-dist2);
}

void mergeParts(vector<pair<int, int>> &points, int num, int side,
                pair<int, int> p1, pair<int, int> p2, SDL_Plotter &g){

    int maxDist = 0;
    int index = -1;

    //Searches for maximum distance from the line
    for(int i = 0; i < num; i++){
        int dist = calcDist(p1, p2, points[i]);
        if(side == sideOfLine(p1, p2, points[i]) && dist > maxDist){
            index = i;
            maxDist = dist;
        }
    }

    // If point is not found, add points of line to
    // convex hull
    if(index == -1){
        convexHullPoints.insert(p1);
        convexHullPoints.insert(p2);
        return;
    }
    drawPoints(g, convexHullPoints);

    //Merge subproblems recursively
    mergeParts(points, num, -sideOfLine(points[index], p1, p2), points[index], p1, g);
    mergeParts(points, num, -sideOfLine(points[index], p2, p1), points[index], p2, g);
}

void divAndConqConvexHull(vector<pair<int, int>> &points, int size, SDL_Plotter &g){
    if(size < 3){
        cout << "Not enough points for convex hull" << endl;
        return;
    }

    int minIndex = 0;
    int maxIndex = 0;
    for(int i = 1; i < size; i++){
        if(points[i].first < points[minIndex].first){
            minIndex = i;
        }

        if(points[i].first > points[maxIndex].first){
            maxIndex = i;
        }
    }

    //Find points for the convex hull on each side of line
    mergeParts(points, size, 1, points[minIndex], points[maxIndex], g);
    mergeParts(points, size, -1, points[minIndex], points[maxIndex], g);

    //Print convex hull points
//    cout << "Convex Hull Points:\n";
//    for(auto x : convexHullPoints){
//        cout << "(" << x.first << ", " << x.second << ")" << endl;
//    }
    //drawPoints(g, convexHullPoints);
}

void drawPoints(SDL_Plotter &g, set<pair<int, int>> &points){

    //Create vector of points from set
    vector<pair<int, int>> data(convexHullPoints.begin(),
                                convexHullPoints.end());

    for(int i = 0; i < data.size(); i++){
        point pt1, pt2;

        if(data.size() < 2){
            cout << "ONLY ONE POINT\n" << endl;
        }
        else{
            //If last point, connect to first point in graph
            if(i == data.size()-1){
                pt1 = point(data[i].first, 500-data[i].second);
                pt2 = point(data[0].first, 500-data[0].second);
            }
            else{
                pt1 = point(data[i].first, 500-data[i].second);
                pt2 = point(data[i+1].first, 500-data[i+1].second);
            }
            line line(pt1, pt2);
            line.draw(g);
            g.update();
        }
    }
}

#endif //GROUPPROJECT_CONVHULLDC_H