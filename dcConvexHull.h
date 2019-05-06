/*
* Author: Mark Du, Grant Gasser, Chris Helms
* Assignment Title: Divide and Conquer
* Assignment Description: This program finds the convex hull of points through a
*                           Divide and Conquer algorithm
* Due Date: 5/5/2019
* Date Created: 3/5/2019
* Date Last Modified: 5/5/2019
*/

#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector>
#include "SDL_Plotter.h"
#include "point.h"
#include "line.h"
using namespace std;

const color_rgb RED = color_rgb(250, 60, 20);
const color_rgb GREEN = color_rgb(20, 140, 20);
const color_rgb BLUE = color_rgb(20, 20, 220);
const color_rgb TEAL = color_rgb(20, 200, 200);
const color_rgb MYSTERY = color_rgb(174, 102, 179);

const int COLLINEAR = 0;
const int CLOCKWISE = 1;
const int CTR_CLOCKWISE = 2;

/**
 * description: Creates a point vector from pair vector
 * return: vector<point>
 * precondition: there is a vector of pairs that exists
 * postcondition: a vector of points is created
 */
vector<point> makePointVector(vector<pair<int, int>> &data);

/**
 * description: Draws a points in a given vector of data
 * return: void
 * precondition: there is an sdl plotter, vector of pairs and points that exist
 * postcondition: Points are drawn to the screen
 */
void drawPoints(SDL_Plotter &g, vector<point> &data, vector<pair<int,int>> &p);

/**
 * description: Plots points in the data set
 * return: void
 * precondition: there is an SDL Plotter and data that exists
 * postcondition: Points are plotted to the screen
 */
void dp2(SDL_Plotter &g, vector<point> &data);

// Test point for sorting
point test;
vector<point> convexHull;

/**
 * description: Returns next top in stack
 * return: point
 * precondition: there is a stack that exists
 * postcondition: next top point is returned
 */
point nextTop(stack<point> &stack) {
    point p1 = stack.top();
    stack.pop();
    point p2 = stack.top();
    stack.push(p1);

    return p2;
}

/**
 * description: Swaps two points
 * return: int
 * precondition: there exists a point p1 and p2
 * postcondition: the points are swapped
 */
int swapPt(point &p1, point &p2) {
    point temp = p1;
    p1 = p2;
    p2 = temp;

    return 0;
}

/**
 * description: Calculates the distance between 2 points
 * return: int
 * precondition: there is a point p1 and p2
 * postcondition: the distance between 2 points is calculated
 */
int calcDist(point p1, point p2) {
    int dist = ( int ) ( pow( ( p1.getX() - p2.getX() ), 2.0 )
                         + pow( ( p1.getX() - p2.getX() ), 2.0 ) );

    line line(p1, p2);
    return dist;
}

/**
 * description: Determines orientation of 3 points,
 * returns 0 if collinear, 1 for clockwise,
 * 2 for counter-clockwise
 * return: int
 * precondition: there exists 3 points p1, p2, p3
 * postcondition: integer representing orientation is returned
 */
int orientation(point p1, point p2, point p3) {
    int orientation = COLLINEAR;
    int num = ( p2.getY() - p1.getY() )*( p3.getX() - p2.getX() ) -
              ( p2.getX() - p1.getX() )*( p3.getY() - p2.getY() );

    //Check for orientation
    if (num == 0){
        orientation = COLLINEAR;
    }
    else if(num > 0){
        orientation = CLOCKWISE;
    }
    else{
        orientation = CTR_CLOCKWISE;
    }
    return orientation;
}

/**
 * description: Helper function for sorting
 * return: int
 * precondition: there are two pointers vp1, vp2
 * postcondition: two points are compared
 */
int compare(const void *vp1, const void *vp2) {
    point *pt1 = (point*)vp1;
    point *pt2 = (point*)vp2;

    // Find orientation
    int ori = orientation(test, *pt1, *pt2);

    // Calculate distance if collinear
    if (ori == COLLINEAR) {
        if(calcDist(test, *pt2) >= calcDist(test, *pt1)){
            return -1;
        }
        else{
            return 1;
        }
    }

    //If counterclockwise, switch
    if(ori == CTR_CLOCKWISE){
        return -1;
    }
    else{
        return 1;
    }
}

/**
 * description: Creates the convex hull
 * return: void
 * precondition: there is an SDL PLotter and vector of pairs
 * postcondition: The convex hull is created
 */
void divAndConqConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p) {

    vector<point> points = makePointVector(p);
    int size = points.size();

    // Find the lowest Y value
    int minY = points[0].getY();
    int minIndex = 0;

    //Find minimum Y
    for (int i = 1; i < size; i++) {
        int currY = points[i].getY();


        // Set minY if current Y is less
        if ( (currY < minY) || (minY == currY &&
                                points[i].getX() < points[minIndex].getX())) {
            minY = points[i].getY();
            minIndex = i;
        }
    }

    // Put min Y first
    swapPt(points[0], points[minIndex]);

    // Sort the points compared to the test point
    // based on the orientation
    test = points[0];
    qsort(&points[1], size-1, sizeof(point), compare);

    // Remove duplicate angles when compared to test point
    int tSize = 1; // Initialize size of modified array
    for (int i = 1; i < size; i++) {

        // Update points
        int ori = orientation(test, points[i], points[i+1]);

        //Visualization
        line l1(test, points[i]);
        l1.setColor(GREEN);
        l1.draw(g);
        g.update();
        g.Sleep(50);

        while (i < size-1 && ori == COLLINEAR) {
            i++;
        }

        //Set temp index to current index
        points[tSize] = points[i];

        //Update temp size
        tSize++;
    }

    // If less than 3 points, no convex hull
    if (tSize < 3){
        cout << "Less than 3 points, cannot build convex hull\n";
    }

    // Create stack and push 3 points
    // Also create convex hull along with stack
    stack<point> stack;
    stack.push(points[0]);
    stack.push(points[1]);
    stack.push(points[2]);
    convexHull.emplace_back(points[0]);
    convexHull.emplace_back(points[1]);
    convexHull.emplace_back(points[2]);

    // Process rest of points
    for (int i = 3; i < tSize; i++) {

        // Remove until angle is not counterclockwise
        while (orientation(nextTop(stack), stack.top(), points[i]) != CTR_CLOCKWISE) {
            stack.pop();
            convexHull.pop_back();  //remove from convex hull

            //Visualization
            line l1(points[0], points[i]);
            line l2(nextTop(stack), points[i]);
            line l3(stack.top(), points[i]);
            line l4(stack.top(), nextTop(stack));
            l1.setColor(RED);
            l2.setColor(TEAL);
            l3.setColor(TEAL);
            l4.setColor(TEAL);
            l1.draw(g);
            l2.draw(g);
            l3.draw(g);
            l4.draw(g);
            g.update();
            g.Sleep(200);
        }

        //Add to stack
        stack.push(points[i]);

        //Add to convex Hull
        convexHull.emplace_back(points[i]);

        //Visualization
        drawPoints(g, convexHull, p);

//        g.Sleep(200);
//        g.clear();
    }

    // Print contents of stack
    while (!stack.empty())
    {
        point pt = stack.top();
        cout << "(" << pt.getX() << ", " << pt.getY() <<")" << endl;
        stack.pop();
    }

    //Draw convex hull onto plotter
    drawPoints(g, convexHull, p);

    //Reset data after drawing
    convexHull.clear();
}

// Draws the points in the data set
void drawPoints(SDL_Plotter &g, vector<point> &data, vector<pair<int,int>> &p){
    vector<line> goodLines;

    for(unsigned int i = 0; i < data.size()-1; i++){
        line line(data[i], data[i+1]);
        line.setColor(MYSTERY);
        goodLines.emplace_back(line);
    }
    goodLines.emplace_back(line(data.front(),data.back()));

    redraw(g,p,&goodLines);

}

// Helper function to generate vector<points>
vector<point> makePointVector(vector<pair<int, int>> &data){
    vector<point> pointVector;
    for(auto i : data){
        point pt(i.first, i.second);
        pointVector.emplace_back(pt);
    }

    return pointVector;
}

//Plots individual points
void dp2(SDL_Plotter &g, vector<point> &data) {
    for(auto x : data){
        x.drawBig(g);
    }
}