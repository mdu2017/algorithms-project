/*
* Author: Marquise Bell, Garret Yero
* Assignment Title: Closest Pair Brute Force
* Assignment Description: This program finds the closest pair of points through a
*                           Brute Force algorithm
* Due Date: 5/3/2018
* Date Created: 4/5/2018
* Date Last Modified: 4/15/2018
*/

#ifndef DIVDE_AND_CONQUER_BRUTEFORCE_H
#define DIVDE_AND_CONQUER_BRUTEFORCE_H
#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
double bruteForce(vector<pair<int,int>>);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
double pointDistance(pair<int,int>, pair<int,int>);

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
double Min(double, double);


#endif //DIVDE_AND_CONQUER_BRUTEFORCE_H
