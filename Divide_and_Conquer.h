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
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
int compX(const void*, const void*);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
int compY(const void*, const void*);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
pair<int,int>* convertVector(vector<pair<int,int>>&);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
double closestSplit(pair<int,int>* pointArray, int, double);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
double closestNow(pair<int,int>* pointArray, int);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
void heapify(pair<int,int>* pointArray, int, int);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
void heapSort(pair<int,int>* pointArray, int, bool);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
double closest(vector<pair<int,int>>&, int);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
void merge(vector<pair<int,int>>, int, int, int, int);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
void mergeSort(vector<pair<int,int>>, int, int, int);



#endif //DIVDE_AND_CONQUER_DIVIDE_AND_CONQUER_H
