/*
* Author: Marquise Bell, Garret Yero, Chris Helms, Mark Du, Grant Gasser
* Assignment Title: Divide and Conquer
* Assignment Description: This program finds the closest pair of points through a
*                           Divide and Conquer algorithm
* Due Date: 5/6/2019
* Date Created: 4/5/2019
* Date Last Modified: 5/5/2019
*/

#include "Divide_and_Conquer.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


double closestSplit(pair<int,int>* pointArray, int size, double d, SDL_Plotter &g){
    double minimum = d;
    bool sortX = false;

    heapSort(pointArray, size, sortX);

    for(int i = 0; i < size; ++i){
        for(int j = i + 1; j < size && (pointArray[j].second - pointArray[i].second) < minimum; ++j){
            if(pointDistance(pointArray[i],pointArray[j]) < minimum){
                minimum = pointDistance(pointArray[i],pointArray[j]);
            }
        }
    }
    return minimum;
}

double closestNow(pair<int,int>* pointArray, int size, SDL_Plotter& g){
    if(size <= 3){
        vector<pair<int,int>> pointVector;
        for(int i = 0; i < size; i++){
            pointVector.push_back(pointArray[i]);
        }
        return bruteForce(g, pointVector);
    }

    int middle = size/2;
    pair<int,int> midPoint = pointArray[middle];

    double dl = closestNow(pointArray, middle, g);
    double dr = closestNow(pointArray + middle, size - middle, g);

    double d = Min(dl, dr);


    int count = 0;
    pair<int,int> strip[size];

    for(int i = 0; i < size; i++){
        if(abs(pointArray[i].first - midPoint.first) < d){
            strip[count] = pointArray[i];
            count++;
        }
    }

    return Min(d, closestSplit(strip, count, d, g));
}

double divideAndConquerClosest(SDL_Plotter& g, vector<pair<int,int>>& vectorPtr){
    int size = vectorPtr.size();
    pair<int,int> *pointArray;
    pointArray = convertVector(vectorPtr);
    bool sortX = true;
    heapSort(pointArray, size, sortX);

    return closestNow(pointArray, size, g);
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
