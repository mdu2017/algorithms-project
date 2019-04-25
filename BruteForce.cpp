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

double bruteForce(vector<pair<int,int>> pointVector){
    if(pointVector.empty()){

    }
    if(pointVector.size() == 1){
        // if there is only one point
        return 0;
    }
    double minimum = DBL_MAX;

    for(int i = 0; i < pointVector.size(); ++i){
        for(int j = i + 1; j < pointVector.size(); ++j){
            minimum = Min(pointDistance(pointVector[i], pointVector[j]), minimum);

        }
    }
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