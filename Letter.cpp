/* AUTHORS: Chris Helms
 *          Adam Naumann
 *          Garrett Yero,
 *          Stirling Strafford
 *          Gilbert Tao
 * ASSIGNMENT TITLE: Pac-Man
 * ASSIGNMENT DESCIRPTION: Emulates Pac-Man in C++
 * DATE CREATED: 11/2/2017
 * DUE DATE: 12/4/2017
 * DATE LAST MODIFIED: 12/3/2017
 */

#include "Letter.h"

Letter::Letter(char let, Color c, int s, Point p){
    letter = let;
    scale = s;
    topLeftCorner = p;
    color = c;
}

void Letter::findLetter(char let){
    ifstream alphabet;
    char input;

    alphabet.open("Alphabet.txt");

    if ( !alphabet.is_open() ) {
        cout << "ERROR: Alphabet.txt failed to open." << endl;
        exit( EXIT_FAILURE );
    }

    do{
        alphabet >> input;
    }while(input != let);

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            alphabet >> pixel[i][j];
        }
    }

    alphabet.close();

    return;
}

void Letter::scaleLetter(){
    for(int i = 0; i < ROW*scale; i++){
        for(int j = 0; j < COL*scale; j++){
            scaled[i][j] = pixel[i/scale][j/scale];
        }
    }
    return;
}

void Letter::draw(SDL_Plotter& g){
    int dx = 0, dy = 0;

    findLetter(letter);
    scaleLetter();

    for(int i = 0; i < ROW*scale; i++){
        for(int j = 0; j < COL*scale; j++){
            if(scaled[i][j] == '1'){
                g.plotPixel(topLeftCorner.x+dx, topLeftCorner.y+dy, color.R, color.G, color.B);
            }
            dx++;
        }
        dy++;
        dx -= 13*scale;
    }

    return;
}
