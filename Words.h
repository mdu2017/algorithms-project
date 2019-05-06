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

#ifndef WORDS_H_INCLUDED
#define WORDS_H_INCLUDED

#include <string>

#include "Letter.h"
#include "SDL_Plotter.h"

using namespace std;

class Words{
    private:
        Color color;
        Point pos;
        int size;

    public:
        /*
         *DESCRIPTION: constructor for a word that assigns color,
                       start point, and scale
         *RETURN: N/A
         *PRECONDITION: Words.h is included in the file
         *POSTCONDITION: a word object is created with specified values
        */
        Words(Color, Point, int );

        /*
         *DESCRIPTION: writes "PACMAN" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "PACMAN" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writePacman(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "READY" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "READY" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeReady(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "PLAY" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "PLAY" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writePlay(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "(ENTER)" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "(ENTER)" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeEnter(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "QUIT" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "QUIT" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeQuit(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "(ESC)" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "(ESC)" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeEsc(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "SKILL" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "SKILL" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeSkill(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "(D)" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "(D)" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeD(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "SOUND" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "SOUND" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeSound(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "(S)" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "(S):" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeS(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "ON" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "ON" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeOn(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "OFF" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "OFF" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeOff(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "EASY" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "EASY" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeEasy(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "MEDIUM" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "MEDIUM" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeMedium(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "HARD" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "HARD" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeHard(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "SCORE" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "SCORE" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeScore(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "HIGH" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "HIGH" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeHigh(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "RETURN" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "RETURN" is written to the SDL_Plotter and the word
         *               object is unchanged
        */
        void writeReturn(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "(SPACE)" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "(SPACE)" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeSpace(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "NAME" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "NAME" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeName(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "N" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "N" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeN(SDL_Plotter& g);

        /*
         *DESCRIPTION: writes "Level" to the SDL_Plotter
         *RETURN: void
         *PRECONDITION: word object and SDL_Plotter exist
         *POSTCONDITION: "Level" is written to the SDL_Plotter and the word
                         object is unchanged
        */
        void writeLevel(SDL_Plotter& g);

        /*
         *DESCRIPTION: sets the color of the word object
         *RETURN: void
         *PRECONDITION: a word object exists
         *POSTCONDITION: color of word is changed to c
        */
        void setColor(Color c);

        /*
         *DESCRIPTION: sets the initial Point of the word object
         *RETURN: void
         *PRECONDITION: a word object exists
         *POSTCONDITION: starting point of word object is changed to p
        */
        void setPoint(Point p);

        /*
         *DESCRIPTION: sets the size of the word object
         *RETURN: void
         *PRECONDITION: a word object exists
         *POSTCONDITION: scalable size of word is changed to s
        */
        void setSize(int s);

        /*
         *DESCRIPTION: returns the color of the word object
         *RETURN: Color
         *PRECONDITION: a word object w/color exists
         *POSTCONDITION: the word object is unchanged
        */
        Color getColor() const;

        /*
         *DESCRIPTION: returns the initial point of the word object
         *RETURN: Point
         *PRECONDITION: a word object w/an initial point exists
         *POSTCONDITION: the word object is unchanged
        */
        Point getPoint() const;

        /*
         *DESCRIPTION: returns the scale of the word object
         *RETURN: int
         *PRECONDITION: a word object w/size exists
         *POSTCONDITION: the word object is unchanged
        */
        int getSize()  const;
};

#endif // WORDS_H_INCLUDED
