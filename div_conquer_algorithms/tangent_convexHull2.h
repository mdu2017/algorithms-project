/*
* Author: Mark Du, Grant Gasser, Chris Helms
* Assignment Title: Divide and Conquer
* Assignment Description: This program finds the convex hull of points through a
*                           Divide and Conquer algorithm
* Due Date: 5/5/2019
* Date Created: 3/5/2019
* Date Last Modified: 5/5/2019
*/

#ifndef GROUPPROJECT_DC_CONVEXHULL_H
#define GROUPPROJECT_DC_CONVEXHULL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <afxres.h>
#include <set>
#include "SDL_Plotter.h"
#include "line.h"

using namespace std;

// Color constants
const color_rgb RED = color_rgb(250, 60, 20);
const color_rgb GREEN = color_rgb(20, 140, 20);
const color_rgb BLUE = color_rgb(20, 20, 220);
const color_rgb TEAL = color_rgb(20, 200, 200);
const color_rgb MYSTERY = color_rgb(174, 102, 179);

// Quadrant constants
const int QUAD1 = 1;
const int QUAD2 = 2;
const int QUAD3 = 3;
const int QUAD4 = 4;

/**
 * description: Checks which quadrant point is in
 * return: int
 * precondition: there is a pair p that exists
 * postcondition: 
 */
int quad(pair<int, int> p);

/**
 * description: Compares two points
 * return: bool
 * precondition: two pairs exist
 * postcondition: true if pts not in same quadrant
 */
bool compare(pair<int, int> p1, pair<int, int> p2);

/**
 * description: merges two convex hulls
 * return: vector<pair<int, int>>
 * precondition: there are two convex hulls a and b that exist
 *  an SDL plotter exists
 * postcondition: the convex hull is merged
 */
vector<pair<int, int>> mergeHull(vector<pair<int, int>> &p1,
                              vector<pair<int, int>> &p2, SDL_Plotter &gr);

/**
 * description: uses brute force for small set of points
 * return: vector<pair<int,int>>
 * precondition: there is an SDL plotter and a set of points that exists
 * postcondition: the convex hull from the points is returned
 */
vector<pair<int, int>> bruteForceHull(vector<pair<int, int>> &p, SDL_Plotter &g);

/**
 * description: divides the convex hull into two
 * return: vector<pair<int,int>>
 * precondition: there is a vector of pairs and SDL that exist
 * postcondition: the divided convex hull is returned
 */
vector<pair<int, int>> divide(vector<pair<int, int>> &data, SDL_Plotter &g);

/**
 * description: Divide and conquer algorithm convex hull
 * return: void
 * precondition: There is a set of points and SDL plotter that exist
 * postcondition: The convex hull is drawn to the screen
 */
void divAndConqConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p);

/**
 * description: draws the points in the data set
 * return: void
 * precondition: SDL plotter and data set exist 
 * postcondition: The points are drawn to the screen
 */
void drawPoints(SDL_Plotter &g, vector<pair<int, int>> &data);

/**
 * description: draws a line given two points
 * return: void
 * precondition: SDL plotter and two points exist
 * postcondition: the line is drawn to the screen
 */
void drawLine(SDL_Plotter &g, point pt1, point pt2);

/**
 * description: determines orientation of three points
 * return: int
 * precondition: three points a, b, c exist
 * postcondition: the orientation of the points is returned
 */
int orientation(pair<int, int> a, pair<int, int> b,
                pair<int, int> c);

/**
 * description: Plots inidividual points
 * return: void
 * precondition: there is an SDL plotter and data that exists
 * postcondition: the points are plotted on the screen
 */
void dp2(SDL_Plotter &g, vector<pair<int, int>> &data);

/************** IMPLEMENT FUNCTIONS **********************/

//Divide and conquer for Convex Hull

// stores the center of polygon (used in compare func)
pair<int, int> center;

int quad(pair<int, int> p) {
    int q = QUAD1;

    if (p.first >= 0 && p.second >= 0) {
        q = QUAD1;
    }
    else if(p.first <= 0 && p.second <= 0){
        q = QUAD3;
    }
    else if(p.first <= 0 && p.second >= 0){
        q = QUAD2;
    }
    else{
        q = QUAD4;
    }

    return q;
}
// Determine if line crosses polygon
int orientation(pair<int, int> p1, pair<int, int> p2,
                pair<int, int> p3) {
    int ori = -1;

    //Cross product
    int num = (p2.second-p1.second) * (p3.first-p2.first)-
              (p3.second-p2.second) * (p2.first-p1.first);
    if(num == 0) {
        ori = 0;
    }
    else if(num > 0) {
        ori = 1;
    }

    return ori;

}
// compare function for sorting (Checks dist from center)
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    bool comp;

    // Points for dist from center
    pair<int, int> pt1 = make_pair(p1.first - center.first,
                                 p1.second - center.second);
    pair<int, int> pt2 = make_pair(p2.first - center.first,
                                 p2.second - center.second);
    // Quadrant of the two points
    int q1 = quad(pt1);
    int q2 = quad(pt2);

    // If not in same quadrant
    if (q1 != q2) {
        comp = (q1 < q2);
    }
    else{
        comp = (pt1.second*pt2.first < pt2.second*pt1.first);
    }
    return comp;
}

// Finds and returns upper tangent of two polygons
vector<pair<int, int>> mergeHull(vector<pair<int, int>> &p1,
                              vector<pair<int, int>> &p2, SDL_Plotter &gr) {

    //Gets size of the polygons
    int size1 = p1.size();
    int size2 = p2.size();

    //Holds indexes for right most(p1) and left most(p2)
    int indexA = 0;
    int indexB = 0;

    //indexA is right most point of p1
    for (int i = 1; i < size1; i++) {
        // If curr X is greater than max X of p1
        if (p1[i].first > p1[indexA].first) {
            indexA = i;
        }
    }
    // indexB is the left most point of p2
    for (int i = 1; i < size2; i++) {
        if (p2[i].first < p2[indexB].first) {
            indexB = i;
        }
    }

    // Finds the upper tangent
    int polyA = indexA;
    int polyB = indexB;
    bool done = 0;
    while (!done) {
        done = 1;

        //Checks each point in p1 to see if it upper tangent
        while (orientation(p2[polyB], p1[polyA], p1[(polyA + 1) % size1]) >=0) {
            polyA = (polyA+1) % size1;
        }

        // Checks each point in p2 to see if it is upper tangent
        while (orientation(p1[polyA], p2[polyB], p2[(size2 + polyB-1) % size2]) <=0) {
            polyB = (size2 + polyB-1) % size2;
            done = 0;
        }
    }
    int upperA = polyA;
    int upperB = polyB;

    // Finds the lower tangent (reset polyA and polyB index)
    polyA = indexA;
    polyB = indexB;
    done = 0;
    int g = 0;

    while (!done) {
        done = 1;

        //Checks points in p2 to find lower tangent to 2nd convex hull
        while (orientation(p1[polyA], p2[polyB], p2[(polyB+1) % size2]) >= 0) {
            polyB = (polyB + 1) % size2;
        }

        //Checks points in p1 to find lower tangent to 1st convex hull
        while (orientation(p2[polyB], p1[polyA], p1[(size1 + polyA-1) % size1]) <= 0) {
            polyA = (size1 + polyA-1) % size1;
            done = 0;
        }
    }
    int lowerA = polyA;
    int lowerB = polyB;

    // Contains convex hull after merging
    // and the pts are sorted anti-clockwise
    vector<pair<int, int>> combHull;

    //Combine top part
    int index = upperA;
    combHull.emplace_back(p1[upperA]); //put first upper pt in hull

    while (index != lowerA) {
        index = (index + 1) % size1;
        combHull.push_back(p1[index]);
    }

    //Combine lower part
    index = lowerB;
    combHull.emplace_back(p2[lowerB]); //put first lower pt in hull

    while (index != upperB) {
        index = (index + 1) % size2;
        combHull.push_back(p2[index]);
    }

    return combHull;
}

// Uses brute force for a small set of points
vector<pair<int, int>> bruteForceHull(vector<pair<int, int>> &p, SDL_Plotter &g) {

    // Check if the points are on same side of line
    vector<pair<int, int>> data;
    int size1 = p.size();

    //Loop through every point
    for (int i = 0; i < size1; i++) {
        for (int j = i + 1; j < size1; j++) {

            //Create points
            point pt1(p[i].first, p[i].second);
            point pt2(p[j].first, p[j].second);

            //distance vals
            int p1 = pt1.getY() - pt2.getY();
            int p2 = pt2.getX() - pt1.getX();
            int p3 = (pt1.getX()*pt2.getY())-
                     (pt1.getY()*pt2.getX());
            int pos = 0;
            int neg = 0;

            //Check current point with other point
            for (int k = 0; k < size1; k++) {
                if (p1*p[k].first + p2*p[k].second + p3 <= 0) {
                    neg += 1;
                }
                if (p1*p[k].first + p2*p[k].second + p3 >= 0) {
                    pos += 1;
                }
            }
            if (pos == size1 || neg == size1) {
                data.emplace_back(p[i]);
                data.emplace_back(p[j]);
            }
        }
    }

    //Stores the convex hull
    vector<pair<int, int>> hull;
    for (auto v : data) {
        hull.emplace_back(v);
    }

    // Sorts pts anti-clockwise order
    int numPts = hull.size();
    center = make_pair(0, 0); //init center to origin

    for (int i = 0; i < numPts; i++) {
        //Adds center X and Y from point in hull
        center.first += hull[i].first;
        center.second += hull[i].second;

        //Multiply by number of points
        hull[i].first *= numPts;
        hull[i].second *= numPts;
    }
    sort(hull.begin(), hull.end(), compare);

    //Creates pair from the sorted points
    for (int i = 0; i < numPts; i++) {
        hull[i] = make_pair(hull[i].first / numPts, hull[i].second / numPts);
    }

    return hull;
}
// Returns the convex hull for the given set of points
vector<pair<int, int>> divide(vector<pair<int, int>> &data, SDL_Plotter &g)
{
    int numPts = data.size();

    // Uses brute force for less than five points
    if (numPts <= 5) {
        return bruteForceHull(data, g);
    }

    // Vector for the left and right half of points
    vector<pair<int, int>> leftPts;
    vector<pair<int, int>> rightPts;

    //Fills left half
    for (int i = 0; i < numPts/2; i++) {
        leftPts.emplace_back(data[i]);
    }

    //Fills right half
    for (int i = numPts/2; i < numPts; i++) {
        rightPts.emplace_back(data[i]);
    }

    //Draw sub-hulls (intermediate steps)
//    for(auto i : left){
//        point pt(i.first, i.second);
//        pt.drawBig(g);
//    }
//    drawPoints(g, left);
//    for(auto i : right){
//        point pt(i.first, i.second);
//        pt.drawBig(g);
//    }
//    drawPoints(g, right);
//    Sleep(1000);
//    g.clear();


    // convex hull for the left and right sets
    vector<pair<int, int>> left_hull = divide(leftPts, g);
    vector<pair<int, int>> right_hull = divide(rightPts, g);

    // merging the convex hulls
    return mergeHull(left_hull, right_hull, g);
}

void divAndConqConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p) {

    int numPts = p.size();

    // sorting points by X values
    sort(p.begin(), p.end());

    //The convex hull
    vector<pair<int, int>> convexHull = divide(p, g);

    //Plot all points
    for(auto x : p){
        point pt(x.first, x.second);
        pt.drawBig(g);
    }

    //Draw final convex hull
    drawPoints(g, convexHull);
//    dp2(g, convexHull);
//    g.update();
}

//Function to draw the convex hull
void drawPoints(SDL_Plotter &g, vector<pair<int, int>> &data) {

    vector<line> goodLines;

    for(unsigned int i = 0; i < data.size()-1; i++){
        line line(data[i], data[i+1]);
        line.setColor(MYSTERY);
        goodLines.emplace_back(line);
    }
    goodLines.emplace_back(line(data.front(),data.back()));
    redraw(g, data , &goodLines);
}

//Plots individual points
void dp2(SDL_Plotter &g, vector<pair<int, int>> &data) {
    for(auto x : data){
        point pt(x.first, x.second);
        pt.drawBig(g);
    }
}


#endif //GROUPPROJECT_DC_CONVEXHULL_H
