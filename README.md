# Algorithms Project
Using C++ and the SDL, write an application to graphically represent the runtime characteristics of the following closest-pair algorithms.

* Brute-Force Closest-Pair 
* Divide-And-Conquer Closest Pair 
* Brute-Force Convex Hull 
  - https://semisignal.com/brute-force-convex-hull-construction/
* Divide-And-Conquer Convex Hull
  - https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/


//O(n^3)
void bruteForceConvexHull(vector<pair<int, int>> &p ){
    cout << "You called Brute Force Convex Hull with the following data:" << endl;

    for(auto i: p){
        cout << i.first << " " << i.second << endl;

        for(auto j: p){
            if(i != j){
                cout << "\t" << j.first << " " << j.second << endl;

                for(auto k: p){
                    if(k != i and k != j){
                        cout << "\t\t" << k.first << " " << k.second << endl;
                        cout << "\t\t\t" << ((j.first - i.first)*(k.second - i.second) - (j.second - i.second)*(k.first - i.first)) << endl;
                    }
                }
            }
        }
    }
}
