#include <iostream>
#include "Point.h"
#include "BruteForce.h"
#include <vector>
#include <cfloat>
#include <cmath>
#include <time.h>
#include "Divide_and_Conquer.h"
using namespace std;

int main() {
    vector<pair<int,int>> pointVector;
    //vector<pair<int,int>> pointVector;

    /*** Will be passing a vector pair of ints! ***/

    cout << "Points in the vector..." << endl;
    srand(time(0));
    for(int i = 0; i < 8; i++){
        point p(rand() % 50 + i, rand() % 50);
        pointVector.push_back(pair<int,int> (rand() % 50 + i, rand() % 50));

        cout << "(" << pointVector[i].first << "," << pointVector[i].second << ")" << endl;
    }
    cout << endl;

    cout << "\nBrute Force: " << bruteForce(pointVector) << endl;
    cout << "Divide and Conquer: " << closest(pointVector, pointVector.size()) << endl;
    return 0;
}






