/*
* Author: Mark Du, Chris Helms, Grant Gass
* Assignment Title: Algorithms Project
* Assignment Description: Convex Hull using divide and conquer algorithm
* Due Date: 5/5/2019
* Date Created: 3/5/2019
* Date Last Modified: 5/5/2019
*/

#include <bits/stdc++.h>
#include <set>
#include <vector>
#include "SDL_Plotter.h"
using namespace std;

#ifndef GROUPPROJECT_CONVHULLDC_H
#define GROUPPROJECT_CONVHULLDC_H

const color_rgb RED = color_rgb(70, 40, 20);
const color_rgb GREEN = color_rgb(20, 205, 20);
const color_rgb BLUE = color_rgb(20, 20, 220);
const color_rgb TEAL = color_rgb(40, 170, 200);
const color_rgb MYSTERY = color_rgb(174, 102, 179);

/**
 * description: Checks if the points are on a side of line
 * return: int  
 * precondition: There are three points that exist
 * postcondition: returns 1 if cross product is positive
 *  else returns -1
 */
int sideOfLine(pair<int, int> i, pair<int, int> j, pair<int, int> test);

/**
 * description: Calculates distance beteween points
 * return: int
 * precondition: three points exist 
 * postcondition: The distance is returned
 */
int calcDist(pair<int, int> i, pair<int, int> j, pair<int, int> test);

/**
 * description: Merge the subhulls together
 * return: void
 * precondition: there is a set of points and 2 integers, two points, and
 *  and SDL plotter that exists
 * postcondition: The two parts are merged together
 */
void mergeParts(vector<pair<int, int>> &points, int num, int side,
            pair<int, int> p1, pair<int, int> p2, SDL_Plotter&);

/**
 * description: The divide and conquer algorithm for convex hull
 * return: void
 * precondition: there is a set of points, size and SDL plotter
 * postcondition: The convex hull is created and drawn onto the screen
 */
void divAndConqConvexHull(vector<pair<int, int>> &points, int size, SDL_Plotter&);

//Keeps points in the convex hull
set<pair<int, int>> convexHullPoints;

/****** Implemented Functions *******/

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

    //Draws each split line in recursive calls
    point minPt(p1.first, p1.second);
    point maxPt(p2.first, p2.second);
    line l1(minPt, maxPt);
    l1.setColor(RED);
    l1.draw(g);
    g.Sleep(200);
    g.update();

    // If point is not found, add points of line to
    // convex hull
    if(index == -1){
        convexHullPoints.insert(p1);
        convexHullPoints.insert(p2);

        //Draws the convex hull part
        point pt1(p1.first, p1.second);
        point pt2(p2.first, p2.second);
        line line(pt1, pt2);
        line.setColor(GREEN);
        line.draw(g);
        g.Sleep(200);
        g.update();

        return;
    }

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

    //Draws first split line
    point minPt(points[minIndex].first, points[minIndex].second);
    point maxPt(points[maxIndex].first, points[maxIndex].second);
    line maxLine(minPt, maxPt);
    maxLine.setColor(MYSTERY);
    maxLine.draw(g);
    g.Sleep(50);
    g.update();

    //Find points for the convex hull on each side of line
    mergeParts(points, size, 1, points[minIndex], points[maxIndex], g);
    mergeParts(points, size, -1, points[minIndex], points[maxIndex], g);
}

#endif //GROUPPROJECT_CONVHULLDC_H
