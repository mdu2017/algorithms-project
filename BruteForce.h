/*
* Author: Marquise Bell, Garret Yero, Chris Helms, Mark Du, Grant Gasser
* Assignment Title: Closest Pair Brute Force
* Assignment Description: This program finds the closest pair of points through a
*                           Brute Force algorithm
* Due Date: 5/6/2019
* Date Created: 4/5/2019
* Date Last Modified: 5/5/2019
*/

#ifndef DIVDE_AND_CONQUER_BRUTEFORCE_H
#define DIVDE_AND_CONQUER_BRUTEFORCE_H
#include <iostream>
#include <vector>
#include "Point.h"
#include "line.h"
#include "UserInterface.h"
using namespace std;

/*
 * description: calculate total price of item with tax
 * return: double
 * precondition: price and tax are valid
 * postcondition: returns sum of price and tax
 *
*/
double bruteForce(SDL_Plotter& , vector<pair<int,int>>);

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
