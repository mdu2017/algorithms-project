#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector>
#include "SDL_Plotter.h"
#include "point.h"
#include "line.h"
using namespace std;

// Test point for sorting
point test;
vector<point> convexHull;

//Function prototypes
void drawPoints(SDL_Plotter &g, vector<point> &data);

// Returns next top in stack
point nextTop(stack<point> &stack) {
    point p1 = stack.top();
    stack.pop();
    point p2 = stack.top();
    stack.push(p1);

    return p2;
}

// Swaps 2 points
int swapPt(point &p1, point &p2) {
    point temp = p1;
    p1 = p2;
    p2 = temp;
}

// Calculate distance of 2 points
int calcDist(point p1, point p2) {
    int dist = (int)(pow((p1.x-p2.x), 2.0) + pow((p1.x-p2.x), 2.0));
    return dist;
}

// Determine orientation of 3 points
// returns 0 if collinear, 1 for clockwise,
// 2 for counter-clockwise
int orientation(point p1, point p2, point p3) {
    int orientation = 0;
    int num = (p2.y-p1.y)*(p3.x-p2.x) -
              (p2.x-p1.x)*(p3.y-p2.y);

    //Check for orientation
    if (num == 0){
        orientation = 0;
    }
    else if(num > 0){
        orientation = 1;
    }
    else{
        orientation = 2;
    }
    return orientation;
}

// Helper function used with sorting
int compare(const void *vp1, const void *vp2) {
    point *pt1 = (point*)vp1;
    point *pt2 = (point*)vp2;

    // Find orientation
    int ori = orientation(test, *pt1, *pt2);

    // Calculate distance if collinear
    if (ori == 0) {
        if(calcDist(test, *pt2) >= calcDist(test, *pt1)){
            return -1;
        }
        else{
            return 1;
        }
    }

    //If counterclockwise, switch
    if(ori == 2){
        return -1;
    }
    else{
        return 1;
    }
}

// Makes the convex hull
void divAndConqConvexHull(SDL_Plotter &g, vector<point> &points, int size) {

    // Find the lowest Y value
    int minY = points[0].y;
    int minIndex = 0;

    //Find minimum Y
    for (int i = 1; i < size; i++) {
        int currY = points[i].y;

        // Set minY if current Y is less
        if ( (currY < minY) || (minY == currY &&
                           points[i].x < points[minIndex].x)) {
            minY = points[i].y;
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
        while (i < size-1 && ori == 0) {
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
        while (orientation(nextTop(stack), stack.top(), points[i]) != 2) {
            stack.pop();
            convexHull.pop_back();  //remove from convex hull
        }

        //Add to stack
        stack.push(points[i]);

        //Add to convex Hull
        convexHull.emplace_back(points[i]);
    }

    // Print contents of stack
    while (!stack.empty())
    {
        point pt = stack.top();
        cout << "(" << pt.x << ", " << pt.y <<")" << endl;
        stack.pop();
    }

    //Draw convex hull onto plotter
    drawPoints(g, convexHull);
}

void drawPoints(SDL_Plotter &g, vector<point> &data){
    for(int i = 0; i < data.size(); i++){
        point pt1, pt2;

        if(data.size() < 2){
            cout << "ONLY ONE POINT\n" << endl;
        }
        else{
            //If last point, connect to first point in graph
            if(i == data.size()-1){
                pt1 = point(data[i].x, 500-data[i].y);
                pt2 = point(data[0].x, 500-data[0].y);
            }
            else{
                pt1 = point(data[i].x, 500-data[i].y);
                pt2 = point(data[i+1].x, 500-data[i+1].y);
            }
            line line(pt1, pt2);
            line.draw(g);
            g.update();
        }
    }
}