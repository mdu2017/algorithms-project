/*
* Author: Marquise Bell, Garret Yero
* Assignment Title: Divide and Conquer
* Assignment Description: This program finds the closest pair of points through a
*                           Divide and Conquer algorithm
* Due Date: 5/3/2018
* Date Created: 4/5/2018
* Date Last Modified: 4/15/2018
*/

#include "Divide_and_Conquer.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

pair<double, line> globalBest;

double closestSplit(pair<int,int>* pointArray, int size, double d, SDL_Plotter &g, line &best){
    double minimum = d;
    bool sortX = false;

    heapSort(pointArray, size, sortX);

    for(int i = 0; i < size; ++i){
        for(int j = i + 1; j < size && (pointArray[j].second - pointArray[i].second) < minimum; ++j){
            if(pointDistance(pointArray[i],pointArray[j]) < minimum){
                minimum = pointDistance(pointArray[i],pointArray[j]);
                best = line(pointArray[i],pointArray[j]);
            }
        }
    }
    return minimum;
}

pair<double, line> closestNow(pair<int,int>* pointArray, int size, SDL_Plotter& g, vector<pair<int, int>> &p, vector<line> &gl, line &best){
    if(size <= 3){
        vector<pair<int,int>> pointVector;
        for(int i = 0; i < size; i++){
            pointVector.push_back(pointArray[i]);
        }
        if(pointVector.size() == 1){
            // if there is only one point
            return make_pair(0, line());
        }
        double minimum = DBL_MAX;
        line li;

        for(int i = 0; i < pointVector.size(); ++i){
            for(int j = i + 1; j < pointVector.size(); ++j){
                if( pointDistance(pointVector[i], pointVector[j]) < minimum){
                    minimum = pointDistance(pointVector[i], pointVector[j]);
                    li = line(pointVector[i], pointVector[j]);
                }
            }
        }
        return make_pair(minimum, li);
    }

    int middle = size/2;
    pair<int,int> midPoint = pointArray[middle];
    gl.push_back(line(make_pair(midPoint.first,ROW_MAX-1), make_pair(midPoint.first, 0)));
    redraw(g, p, &gl);
    best.setColor(color_rgb(0,0,255));
    best.draw(g);
    globalBest.second.setColor(color_rgb(255,0,0));
    globalBest.second.draw(g);
    g.update();
    g.Sleep(500);
    pair<double, line> dl = closestNow(pointArray, middle, g, p, gl, best);
    pair<double, line> dr = closestNow(pointArray + middle, size - middle, g, p, gl, best);

    pair<double, line> d;

    if(dl.first < dr.first){
        d = dl;
    }
    else{
        d = dr;
    }
    best = d.second;

    int count = 0;
    pair<int,int> strip[size];

    for(int i = 0; i < size; i++){
        if(abs(pointArray[i].first - midPoint.first) < d.first){
            strip[count] = pointArray[i];
            count++;
        }
    }

    d = make_pair(Min(d.first, closestSplit(strip, count, d.first, g, best)),best);
    redraw(g, p, &gl);
    best.setColor(color_rgb(0,0,255));
    best.draw(g);
    if( d.first < globalBest.first){
        globalBest = d;
    }
    globalBest.second.setColor(color_rgb(255,0,0));
    globalBest.second.draw(g);
    g.update();

    return d;
}

double divideAndConquerClosest(SDL_Plotter& g, vector<pair<int,int>>& vectorPtr){
    globalBest = make_pair(DBL_MAX, line());
    int size = vectorPtr.size();
    pair<int,int> *pointArray;
    pointArray = convertVector(vectorPtr);
    bool sortX = true;
    heapSort(pointArray, size, sortX);
    vector<line> goodLines;
    line best;

    return closestNow(pointArray, size, g, vectorPtr, goodLines, best).first;
}

void heapify(pair<int,int>* pointArray, int size, int index, bool decide){
    int maximum = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(decide){
        if(left < size && pointArray[left].first > pointArray[maximum].first){
            maximum = left;
        }
        if(right < size && pointArray[right].first > pointArray[maximum].first){
            maximum = right;
        }
    }
    else{
        if(left < size && pointArray[left].second > pointArray[maximum].second){
            maximum = left;
        }
        if(right < size && pointArray[right].second > pointArray[maximum].second){
            maximum = right;
        }
    }


    if(maximum != index){
        swap(pointArray[index], pointArray[maximum]);

        heapify(pointArray, size, maximum, decide);
    }
}

void heapSort(pair<int,int>* pointArray, int size, bool decide){
    for(int i = size/2 - 1; i >=0; i--){
        heapify(pointArray, size, i, decide);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(pointArray[0], pointArray[i]);
        heapify(pointArray, i, 0, decide);
    }
}


pair<int,int>* convertVector(vector<pair<int,int>>& pointVector){
    pair<int,int>* pointArrayPtr = &pointVector[0];
    return pointArrayPtr;
}
