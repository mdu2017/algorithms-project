#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "SDL_Plotter.h"
#include "point.h"
#include "line.h"
#include "color_rgb.h"
#include "curve.h"


using namespace std;

const int ROW_MAX = 500;
const int COL_MAX = 1000;


int main(int argc, char** argv) {
    SDL_Plotter g(ROW_MAX, COL_MAX);
    point p(50, 50);
    line s;
    curve crv;
    color_rgb c;
    char key;

    /*p.setColor( color_rgb( 50, 50, 50 ) );
    p.setX( 0 );
    p.setY( 0 );
    
    point p2( 100, 300 );
    p2.setColor( color_rgb( 50, 50, 50 ) );
    s.setP1( p );
    s.setP2( p2 );
    s.draw( g );*/

    vector<DataSet_t> data;

    DataSet_t set1;
    set1.push_back(make_pair(0, 0));
    set1.push_back(make_pair(1, 10));
    set1.push_back(make_pair(2, 20));
    set1.push_back(make_pair(3, 40));
    set1.push_back(make_pair(4, 80));
    set1.push_back(make_pair(5, 160));
    set1.push_back(make_pair(6, 320));
    set1.push_back(make_pair(7, 640));
    set1.push_back(make_pair(8, 1280));
    set1.push_back(make_pair(9, 2560));
    set1.push_back(make_pair(10, 5120));

    DataSet_t set2;
    for (int i = 0; i < 10000; i++) {
        set2.push_back(make_pair(i, i));
    }

    DataSet_t set3;
    for (int i = 0; i < 10000; i++) {
        set3.push_back(make_pair(i, (i*i)));
    }

    DataSet_t set4;
    for (long double i = 0; i < 12000; i++) {
        set4.push_back(make_pair((int) i, (i*i*i)));
    }

    DataSet_t set5;
    for (int i = 0; i < 100000; i += 1000) {
        set5.push_back(make_pair(i, log(i)));
    }

    data.push_back(set1);
    data.push_back(set2);
    data.push_back(set3);
    data.push_back(set4);
    data.push_back(set5);

    crv.setSameScale(true);
    //crv.display( data, cout );
    crv.draw(data, g);

    while (!g.getQuit()) {
        //cout << "RUNNING..." << endl;
        if (g.kbhit()) {     
            switch (g.getKey()) {
            case 'S':
                crv.setSameScale(!crv.getSameScale());
                g.clear();
                crv.draw(data, g);
                break;
            }
        }
        g.update();
    }
    return 0;
}