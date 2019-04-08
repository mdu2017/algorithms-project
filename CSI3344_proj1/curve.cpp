/*
    Author: Chris Helms
    Assignment Title: Project 1
    Assignment Description: Graphically displays input curves to the screen.
    Due Date: 1/28/2019
    Date Created: 1/22/2019
    Date Last Modified: 1/28/2019
*/

#include "curve.h"

/*
    Description: Default constructor.
    Return: N/A
    Precondition: The instance does not already exist.
    Postcondition: An instance is created.
*/
curve::curve() {
    sameScale = 0;
}

/*
    Description: Destructor.
    Return: N/A
    Precondition: Instance exists.
    Postcondition: The instance is destroyed.
*/
curve::~curve() {

}

/*
    Description: Displays the data to the output stream.
    Return: void
    Precondition: Data & output stream are valid.
    Postcondition: Data is unchanged.
*/
void curve::display(Data_t data, ostream& out) {
    for (unsigned i = 0; i < data.size(); i++) {
        out << "Data set " << i << ":\n";
        for (unsigned j = 0; j < data[i].size(); j++) {
            out << "(" << data[i][j].first << ", " << data[i][j].second << ")\n";
        }
        out << endl;
    }
}

/*
    Description: Graphically displays data to screen.
    Return: void
    Precondition: Data is valid. Plotter has been initialized.
    Postcondition: Data is unchanged.
*/
void curve::draw(Data_t data, SDL_Plotter& g) {
    int margin = 50, maxX = 0;
    double sX = 1;
    long double maxY = 0, sY = 1;
    line li;
    plotAxis( margin, g.getCol() - margin, g.getRow() - margin, g );
    if ( sameScale ) {
        for ( unsigned i = 0; i < data.size(); i++ ) {
            for ( unsigned j = 0; j < data[i].size(); j++ ) {
                if ( maxX < data[ i ][ j ].first ) {
                    maxX = data[ i ][ j ].first;
                    sX = (double) ( g.getCol() - 2 * margin ) / maxX;
                }
                if ( maxY < data[ i ][ j ].second ) {
                    maxY = data[ i ][ j ].second;
                    sY = ( g.getRow() - 2 * margin ) / maxY;
                }
            }
        }
        /*cout << maxX << " " << maxY << endl;
        cout << sX << " " << sY << endl;
        cout << endl;*/
    }
    for (unsigned i = 0; i < data.size(); i++) {
        //cout << "curve " << i + 1 << endl;
        if ( !sameScale ) {
            maxX = 0;
            maxY = 0;
            for ( unsigned j = 0; j < data[i].size(); j++ ) {
                if ( maxX < data[ i ][ j ].first ) {
                    maxX = data[ i ][ j ].first;
                    sX = (double) ( g.getCol() - 2 * margin ) / maxX;
                }
                if ( maxY < data[ i ][ j ].second ) {
                    maxY = data[ i ][ j ].second;
                    sY = ( g.getRow() - 2 * margin ) / maxY;
                }
            }
            /*cout << maxX << " " << maxY << endl;
            cout << sX << " " << sY << endl;
            cout << endl;*/
        }
        for (unsigned j = 0; j < data[i].size() - 1; j++) {
            int x1 = (int) ( data[ i ][ j ].first * sX ) + margin,
                y1 = (int) ( data[ i ][ j ].second * sY ) + margin,
                x2 = (int) ( data[ i ][ j + 1 ].first * sX ) + margin,
                y2 = (int) ( data[ i ][ j + 1 ].second * sY ) + margin;
            /*point( x1, y1 ).display( cout );
            point( x2, y2 ).display( cout );*/
            li.setP1( point( x1, y1 ) );
            li.setP2( point( x2, y2 ) );
            /*li.display( cout );
            cout << endl;*/
            if ( goodPoints( li, margin, g ) ) {
                li.draw( g );
                //g.update();
            }
        }
        li.nextColor();
        //cout << "next color...\n";
    }
}

/*
    Description: Plots axis to screen.
    Return: void
    Precondition: margin, maxX, maxY are valid. Plotter has been
        initialized.
    Postcondition: margin, maxX, maxY are unchanged.
*/
void curve::plotAxis(int margin, int maxX, int maxY, SDL_Plotter& g) {
    point yAxis = point( margin, maxY ),
        origin = point( margin, margin ),
        xAxis = point( maxX, margin );
    line( origin, yAxis ).draw( g );
    line( origin, xAxis ).draw( g );
    plotTickMarks( margin, maxX, maxY, g );
}

/*
    Description: Plots tick marks on axis.
    Return: void
    Precondition: margin, maxX, maxY are valid. Plotter has been
        initialized.
    Postcondition: margin, maxX, maxY are unchanged.
*/
void curve::plotTickMarks(int margin, int maxX, int maxY, SDL_Plotter& g) {
    int tickLength = 20, numTicks = 10,
        yAxisLength = maxY - margin, xAxisLength = maxX - margin,
        yDif = yAxisLength / numTicks, xDif = xAxisLength / numTicks;
    for ( int y = margin + yDif; y <= maxY; y += yDif ) {
        point p1 = point( margin + tickLength / 2, y ),
            p2 = point( margin - tickLength / 2, y );
        line( p1, p2 ).draw( g );
    }
    for ( int x = margin + xDif; x <= maxX; x += xDif ) {
        point p1 = point( x, margin + tickLength / 2 ),
            p2 = point( x, margin - tickLength / 2 );
        line( p1, p2 ).draw( g );
    }
}

/*
    Description: Checks if points may be plotted by plotter.
    Return: bool
    Precondition: a, margin are valid. Plotter has been initialized.
    Postcondition: a, margin are unchanged.
*/
bool curve::goodPoints(line a, int margin, SDL_Plotter& g) {
    int maxX = g.getCol() - margin, maxY = g.getRow() - margin;
    if ( a.getP1().getX() <= maxX && margin <= a.getP1().getX()
         && a.getP1().getY() <= maxY && margin <= a.getP1().getY()
         && a.getP2().getX() <= maxX && margin <= a.getP2().getX()
         && a.getP2().getY() <= maxY && margin <= a.getP2().getY() ) {
        return true;
    }
    /*a.getP1().display( cout );
    a.getP2().display( cout );
    cout << endl;*/
    return false;
}