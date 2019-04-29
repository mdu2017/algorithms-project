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

int compX(const void* ptr1, const void* ptr2){
    auto *pointptr1 = (pair<int,int>*)ptr1;
    auto *pointptr2 = (pair<int,int>*)ptr2;

    return (pointptr1->first - pointptr2->first);
}

int compY(const void* ptr1, const void* ptr2){
    auto *pointptr1 = (pair<int,int>*)ptr1;
    auto *pointptr2 = (pair<int,int>*)ptr2;

    return (pointptr1->second - pointptr2->second);
}

double closestSplit(pair<int,int>* pointArray, int size, double d){
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

double closestNow(pair<int,int>* pointArray, int size){
    if(size <= 3){
        vector<pair<int,int>> pointVector;
        for(int i = 0; i < size; i++){
            pointVector.push_back(pointArray[i]);
        }
        return bruteForce(pointVector);
    }

    int middle = size/2;
    pair<int,int> midPoint = pointArray[middle];

    double dl = closestNow(pointArray, middle);
    double dr = closestNow(pointArray + middle, size - middle);

    double d = Min(dl, dr);


    int count = 0;
    pair<int,int> strip[size];

    for(int i = 0; i < size; i++){
        if(abs(pointArray[i].first - midPoint.first) < d){
            strip[count] = pointArray[i];
            count++;
        }
    }

    return Min(d, closestSplit(strip, count, d));
}

double closest(vector<pair<int,int>>& vectorPtr, int size){
    pair<int,int> *pointArray;
    pointArray = convertVector(vectorPtr);
    bool sortX = true;
    heapSort(pointArray, size, sortX);

    return closestNow(pointArray, size);
}

void merge(vector<pair<int,int>> pointVector, int l, int m, int r, int decide){
    int n1 = m - l + 1;
    int n2 = r - m;

    pair<int,int> leftPoint[n1], rightPoint[n2];

    for(int i = 0; i < n1; i++){
        leftPoint[i] = pointVector[l + i];
    }
    for(int i = 0; i < n2; i++){
        rightPoint[i] = pointVector[m + 1 + i];
    }

    while(!pointVector.empty()){
        pointVector.pop_back();
    }

    // Merge temp arrays back into pointVector
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        // sort by x-coordinate
        if(decide == 1){
            if(leftPoint[i].first <= rightPoint[i].first){
                pointVector.push_back(leftPoint[i]);
                i++;
            }
            else{
                pointVector.push_back(rightPoint[j]);
                j++;
            }
            k++;
        }
        // sort by y-coordinate
        else if(decide == 0){
            if(leftPoint[i].second <= rightPoint[i].second){
                pointVector.push_back(leftPoint[i]);
                i++;
            }
            else{
                pointVector.push_back(rightPoint[j]);
                j++;
            }
            k++;
        }
    }

    while(i < n1){
        pointVector.push_back(leftPoint[i]);
        i++;
        k++;
    }
    while(j < n2){
        pointVector.push_back(rightPoint[j]);
        j++;
        k++;
    }
}

void mergeSort(vector<pair<int,int>> pointVector, int l, int r, int decide){
    if(l < r){
        int middle = l + (r - 1)/2;

        mergeSort(pointVector, l, middle, decide);
        mergeSort(pointVector, middle + 1, r, decide);

        merge(pointVector, l, middle, r, decide);
    }
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

// change to be passing a vector of int pairs
pair<int,int>* convertVector(vector<pair<int,int>>& pointVector){
    pair<int,int>* pointArrayPtr = &pointVector[0];
    return pointArrayPtr;
}
