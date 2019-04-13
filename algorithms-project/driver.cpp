// 4/10/2019

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>
#include <Windows.h>
#include "line.h"

using namespace std;

const int ROW_MAX = 500, COL_MAX = 1000;

void receiveInput( SDL_Plotter &g, vector<pair<int, int>> &p );
void cleanData( vector<pair<int, int>> &d );
void runAlgorithm( SDL_Plotter &g, vector<pair<int, int>> &p );
void bruteForceConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p );
int oneSideOfLine(pair<int, int> i,  pair<int, int> j, pair<int, int> k);

int quad(pair<int, int> p);
bool compare(pair<int, int> p1, pair<int, int> q1);
vector<pair<int, int>> merger(vector<pair<int, int> > a,
                              vector<pair<int, int> > b);
vector<pair<int, int>> bruteHull(vector<pair<int, int>> a, SDL_Plotter &g);
vector<pair<int, int>> divide(vector<pair<int, int>> a, SDL_Plotter &g);
void divAndConqConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p);
void drawPoints(SDL_Plotter &g, vector<pair<int, int>> &data);

int main( int argc, char** argv ) {
    SDL_Plotter plotter( ROW_MAX, COL_MAX );
    vector<pair<int, int>> data;

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
        plotter.clear();
        plotter.update();

        // reset data for next set of points
        data = vector<pair<int, int>>();
    }

    return 0;
}

void receiveInput( SDL_Plotter &g, vector<pair<int, int>> &d ) {
    bool isDone = false;
    int mX = 0, mY = 0;

    // while user is inputting data
    while ( !g.getQuit() && !isDone ) {
        // if user hits enter
        if ( g.kbhit() && g.getKey() == SDL_SCANCODE_RETURN ) {
            // exit receiveInput
            isDone = true;
        }

        // if user releases mouse button at a point on screen
        if ( g.getMouseUp( mX, mY ) ) {
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

void runAlgorithm( SDL_Plotter &g, vector<pair<int, int>> &p ) {
    bool isDone = false;

    while ( !g.getQuit() && !isDone ) {
        if ( g.kbhit() ) {
            // clear the screen & redraw the points
            g.clear();
            for ( vector<pair<int, int>>::iterator i = p.begin();
                  i != p.end(); i++ ) {
                point( i->first, i->second ).drawBig( g );
            }
            g.update();

            switch ( g.getKey() ) {
                // brute-force closest-pair
                case '1':
                    cout << "brute-force closest-pair\n";
                    break;

                // divide-&-conquer closest-pair
                case '2':
                    cout << "divide-&-conquer closest-pair\n";
                    break;

                // brute-force convex hull
                case '3':
                    cout << "brute-force convex hull\n";
                    bruteForceConvexHull(g, p);
                    break;

                // divide-&-conquer convex hull
                case '4':
                    cout << "divide-&-conquer convex hull\n";
                    divAndConqConvexHull(g, p);
                    break;

                // user requested to exit runAlgorithm
                case SDL_SCANCODE_RETURN:
                    isDone = true;
                    break;
            }
        }
    }
}


//O(n^3)
void bruteForceConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p ){
    cout << "You called Brute Force Convex Hull with the following data:" << endl;

    for(auto p1: p){

        for(auto p2: p){
            if(p1 != p2){

                bool allPtsOneSide = true;
                for(auto k: p){
                    if(k != p1 and k != p2){
                        int side = oneSideOfLine(p1, p2, k);

                        //Drawing intermediate steps
//                        line l1(point(p1.first, 500-p1.second), point(p2.first, 500-p2.second));
//                        line l2(point(p2.first, 500-p2.second), point(k.first, 500-k.second));
//                        l1.draw(g);
//                        l2.draw(g);
//                        g.update();
//                        Sleep(100);

                        //Checks if a point is not on one side
                        if(side < 0){
                            allPtsOneSide = false;
                            break;
                        }
                    }
                }

                if(allPtsOneSide){
                    cout << "Adding segment with points: (" << p1.first << "," << p1.second << ") to (" << p2.first << "," << p2.second << ")" << endl;
                    line line(point(p1.first, 500-p1.second), point(p2.first, 500-p2.second));
                    line.draw(g);
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

/***************/

// A divide and conquer program to find convex
// hull of a given set of points.
#include<bits/stdc++.h>
//using namespace std;
// stores the centre of polygon (It is made
// global because it is used in compare function)
pair<int, int> mid;
// determines the quadrant of a point
// (used in compare())
int quad(pair<int, int> p)
{
    if (p.first >= 0 && p.second >= 0)
        return 1;
    if (p.first <= 0 && p.second >= 0)
        return 2;
    if (p.first <= 0 && p.second <= 0)
        return 3;
    return 4;
}
// Checks whether the line is crossing the polygon
int orientation(pair<int, int> a, pair<int, int> b,
                pair<int, int> c)
{
    int res = (b.second-a.second)*(c.first-b.first) -
              (c.second-b.second)*(b.first-a.first);
    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}
// compare function for sorting
bool compare(pair<int, int> p1, pair<int, int> q1)
{
    pair<int, int> p = make_pair(p1.first - mid.first,
                                 p1.second - mid.second);
    pair<int, int> q = make_pair(q1.first - mid.first,
                                 q1.second - mid.second);
    int one = quad(p);
    int two = quad(q);
    if (one != two)
        return (one < two);
    return (p.second*q.first < q.second*p.first);
}
// Finds upper tangent of two polygons 'a' and 'b'
// represented as two vectors.
vector<pair<int, int>> merger(vector<pair<int, int> > a,
                              vector<pair<int, int> > b)
{
    // n1 -> number of points in polygon a
    // n2 -> number of points in polygon b
    int n1 = a.size(), n2 = b.size();
    int ia = 0, ib = 0;
    for (int i=1; i<n1; i++)
        if (a[i].first > a[ia].first)
            ia = i;
    // ib -> leftmost point of b
    for (int i=1; i<n2; i++)
        if (b[i].first < b[ib].first)
            ib=i;
    // finding the upper tangent
    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orientation(b[indb], a[inda], a[(inda+1)%n1]) >=0)
            inda = (inda + 1) % n1;
        while (orientation(a[inda], b[indb], b[(n2+indb-1)%n2]) <=0)
        {
            indb = (n2+indb-1)%n2;
            done = 0;
        }
    }
    int uppera = inda, upperb = indb;
    inda = ia, indb=ib;
    done = 0;
    int g = 0;
    while (!done)//finding the lower tangent
    {
        done = 1;
        while (orientation(a[inda], b[indb], b[(indb+1)%n2])>=0)
            indb=(indb+1)%n2;
        while (orientation(b[indb], a[inda], a[(n1+inda-1)%n1])<=0)
        {
            inda=(n1+inda-1)%n1;
            done=0;
        }
    }
    int lowera = inda, lowerb = indb;
    vector<pair<int, int>> ret;
    //ret contains the convex hull after merging the two convex hulls
    //with the points sorted in anti-clockwise order
    int ind = uppera;
    ret.push_back(a[uppera]);
    while (ind != lowera)
    {
        ind = (ind+1)%n1;
        ret.push_back(a[ind]);
    }
    ind = lowerb;
    ret.push_back(b[lowerb]);
    while (ind != upperb)
    {
        ind = (ind+1)%n2;
        ret.push_back(b[ind]);
    }
    return ret;
}

// Brute force algorithm to find convex hull for a set
// of less than 6 points
vector<pair<int, int>> bruteHull(vector<pair<int, int>> a, SDL_Plotter &g)
{
    // Take any pair of points from the set and check
    // whether it is the edge of the convex hull or not.
    // if all the remaining points are on the same side
    // of the line then the line is the edge of convex
    // hull otherwise not
    set<pair<int, int> >s;
    for (int i=0; i<a.size(); i++)
    {
        for (int j=i+1; j<a.size(); j++)
        {
            int x1 = a[i].first, x2 = a[j].first;
            int y1 = a[i].second, y2 = a[j].second;
            int a1 = y1-y2;
            int b1 = x2-x1;
            int c1 = x1*y2-y1*x2;
            int pos = 0, neg = 0;
            for (int k=0; k<a.size(); k++)
            {
                if (a1*a[k].first+b1*a[k].second+c1 <= 0)
                    neg++;
                if (a1*a[k].first+b1*a[k].second+c1 >= 0)
                    pos++;
            }
            if (pos == a.size() || neg == a.size())
            {
                s.insert(a[i]);
                s.insert(a[j]);
            }
        }
    }
    vector<pair<int, int>>ret;
    for (auto e:s)
        ret.push_back(e);
    // Sorting the points in the anti-clockwise order
    mid = {0, 0};
    int n = ret.size();
    for (int i=0; i<n; i++)
    {
        mid.first += ret[i].first;
        mid.second += ret[i].second;
        ret[i].first *= n;
        ret[i].second *= n;
    }
    sort(ret.begin(), ret.end(), compare);
    for (int i=0; i<n; i++)
        ret[i] = make_pair(ret[i].first/n, ret[i].second/n);
    return ret;
}
// Returns the convex hull for the given set of points
vector<pair<int, int>> divide(vector<pair<int, int>> a, SDL_Plotter &g)
{
    // If the number of points is less than 6 then the
    // function uses the brute algorithm to find the
    // convex hull
    if (a.size() <= 5)
        return bruteHull(a, g);

    // left contains the left half points
    // right contains the right half points
    vector<pair<int, int>>left, right;
    for (int i=0; i<a.size()/2; i++)
        left.push_back(a[i]);
    for (int i=a.size()/2; i<a.size(); i++)
        right.push_back(a[i]);

    //Draw sub-hulls (intermediate steps)
//    drawPoints(g, left);
//    drawPoints(g, right);
//    Sleep(1000);
//    g.clear();


    // convex hull for the left and right sets
    vector<pair<int, int>>left_hull = divide(left, g);
    vector<pair<int, int>>right_hull = divide(right, g);

    // merging the convex hulls
    return merger(left_hull, right_hull);
}

void divAndConqConvexHull(SDL_Plotter &g, vector<pair<int, int>> &p) {
    int n = p.size();
    // sorting the set of points according
    // to the x-coordinate
    sort(p.begin(), p.end());
    vector<pair<int, int> > ans = divide(p, g);
    cout << "convex hull:\n";

    //Draw divide and conquer convex hull
    for(int i = 0; i < ans.size(); i++){
        point pt1, pt2;
        if(ans.size() >= 2) {
            //If at last point, draw line connecting to first point
            if(i == ans.size()-1){
                pt1 = point(ans[i].first, 500 - ans[i].second);
                pt2 = point(ans[0].first, 500 - ans[0].second);
            }
            else {
                pt1 = point(ans[i].first, 500 - ans[i].second);
                pt2 = point(ans[i + 1].first, 500 - ans[i + 1].second);
            }
            line line(pt1, pt2);
            line.draw(g);
            g.update();
        }
        else{
            cout << "ONLY ONE POINT IN GRAPH" << endl;
        }

        //Display points
        cout << "Divide and Conquer convex hull points:\n";
        cout << ans[i].first << ", " << ans[i].second << endl;
    }
}

//Function to draw the convex hull
void drawPoints(SDL_Plotter &g, vector<pair<int, int>> &data){
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

        //Plot point
        //point curr(data[i].first, data[i].second);
        //curr.drawBig(g);
    }
}