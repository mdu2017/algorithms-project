/*
* Author: Marquise Bell, Garret Yero
* Assignment Title: Divide and Conquer
* Assignment Description: This program finds the closest pair of points through a
*                           Divide and Conquer algorithm
* Due Date: 5/3/2018
* Date Created: 4/5/2018
* Date Last Modified: 4/15/2018
*/

#ifndef DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H
#define DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "BruteForce.h"
using namespace std;

/*
 * description: creates a pointer to the vector of points being passed
 * return: pair<int,int>*
 * precondition: a vector of points exists
 * postcondition: a pointer to a vector of points exists
 *
*/
pair<int,int>* convertVector(vector<pair<int,int>>&);

/*
 * description: calculates the closest pair in each respective partition
 * return: double
 * precondition: a vector of points exists in a section
 * postcondition: the distance of the closest pair in the section is known
 *
*/
double closestSplit(pair<int,int>* pointArray, int, double, SDL_Plotter& g);

/*
 * description: calculates if two points are closer along the divide
 * return: double
 * precondition: the closest pair in each section is known
 * postcondition: the closest pair overall is now known
 *
*/
double closestNow(pair<int,int>* pointArray, int, SDL_Plotter& g);

/*
 * description: reheaps the heap of points
 * return: none
 * precondition: a pointer to a pair of points exists
 * postcondition: the heap is heapified
 *
*/
void heapify(pair<int,int>* pointArray, int, int);

/*
 * description: sorts the points smallest to largest using a heap
 * return: none
 * precondition: a pointer to a pair of points exists
 * postcondition: the pairs of points are now ordered
 *
*/
void heapSort(pair<int,int>* pointArray, int, bool);

/*
 * description: recursive funciton that finds the closest pair of points
 * return: double
 * precondition: points exist
 * postcondition: the distance of the closest pair is known
 *
*/
double closest(vector<pair<int,int>>&, int, SDL_Plotter& g);


#endif //DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H
