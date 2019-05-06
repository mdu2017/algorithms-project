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

#include "Words.h"

Words::Words(Color c, Point p, int s){
    pos = p;
    size = s*S;
    color = c;
}

void Words::writePacman(SDL_Plotter& g){
    Letter P = Letter('P', color, size, pos),
           A1= Letter('A', color, size, Point(pos.x+(ROW+5)*size, pos.y)),
           C = Letter('C', color, size, Point(pos.x+(ROW+5)*size*2, pos.y)),
           M = Letter('M', color, size, Point(pos.x+(ROW+5)*size*3, pos.y)),
           A2= Letter('A', color, size, Point(pos.x+(ROW+5)*size*4, pos.y)),
           N = Letter('N', color, size, Point(pos.x+(ROW+5)*size*5, pos.y));

    P.draw(g);
    A1.draw(g);
    C.draw(g);
    M.draw(g);
    A2.draw(g);
    N.draw(g);

}

void Words::writeReady(SDL_Plotter& g){
    Letter R = Letter('R', color, size, pos),
           E = Letter('E', color, size, Point(pos.x+(ROW+6)*size, pos.y)),
           A = Letter('A', color, size, Point(pos.x+(ROW+6)*size*2, pos.y)),
           D = Letter('D', color, size, Point(pos.x+(ROW+6)*size*3, pos.y)),
           Y = Letter('Y', color, size, Point(pos.x+(ROW+6)*size*4, pos.y));

    R.draw(g);
    E.draw(g);
    A.draw(g);
    D.draw(g);
    Y.draw(g);
}

void Words::writePlay(SDL_Plotter& g){
    Letter P = Letter('P', color, size, pos),
           L = Letter('L', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           A = Letter('A', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           Y = Letter('Y', color, size, Point(pos.x+(ROW+2)*size*3, pos.y));

    P.draw(g);
    L.draw(g);
    A.draw(g);
    Y.draw(g);
}

void Words::writeEnter(SDL_Plotter& g){
    Letter P1= Letter('(', color, size, pos),
           E1= Letter('E', color, size, Point(pos.x+(ROW+1)*size, pos.y)),
           N = Letter('N', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           T = Letter('T', color, size, Point(pos.x+(ROW+2)*size*3, pos.y)),
           E2= Letter('E', color, size, Point(pos.x+(ROW+2)*size*4, pos.y)),
           R = Letter('R', color, size, Point(pos.x+(ROW+2)*size*5, pos.y)),
           P2= Letter(')', color, size, Point(pos.x+(ROW+2)*size*6, pos.y));

    P1.draw(g);
    E1.draw(g);
    N.draw(g);
    T.draw(g);
    E2.draw(g);
    R.draw(g);
    P2.draw(g);
}

void Words::writeSkill(SDL_Plotter& g){
    Letter S = Letter('S', color, size, pos),
           K = Letter('K', color, size, Point(pos.x+(ROW+1)*size, pos.y)),
           I = Letter('I', color, size, Point(pos.x+(ROW+1)*size*2, pos.y)),
           L1= Letter('L', color, size, Point(pos.x+(ROW+1)*size*3, pos.y)),
           L2= Letter('L', color, size, Point(pos.x+(ROW+1)*size*4, pos.y));

    S.draw(g);
    K.draw(g);
    I.draw(g);
    L1.draw(g);
    L2.draw(g);
}

void Words::writeD(SDL_Plotter& g){
    Letter P1= Letter('(', color, size, pos),
           D = Letter('D', color, size, Point(pos.x+(ROW+1)*size, pos.y)),
           P2= Letter(')', color, size, Point(pos.x+(ROW+1)*size*2, pos.y));

    P1.draw(g);
    D.draw(g);
    P2.draw(g);
}

void Words::writeQuit(SDL_Plotter& g){
    Letter Q = Letter('Q', color, size, pos),
           U = Letter('U', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           I = Letter('I', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           T = Letter('T', color, size, Point(pos.x+(ROW+2)*size*3, pos.y));

    Q.draw(g);
    U.draw(g);
    I.draw(g);
    T.draw(g);
}

void Words::writeEsc(SDL_Plotter& g){
    Letter P1= Letter('(', color, size, pos),
           E = Letter('E', color, size, Point(pos.x+(ROW+1)*size, pos.y)),
           S = Letter('S', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           C = Letter('C', color, size, Point(pos.x+(ROW+2)*size*3, pos.y)),
           P2= Letter(')', color, size, Point(pos.x+(ROW+2)*size*4, pos.y));

    P1.draw(g);
    E.draw(g);
    S.draw(g);
    C.draw(g);
    P2.draw(g);
}

void Words::writeSound(SDL_Plotter& g){
    Letter S = Letter('S', color, size, pos),
           O = Letter('O', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           U = Letter('U', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           N = Letter('N', color, size, Point(pos.x+(ROW+2)*size*3, pos.y)),
           D = Letter('D', color, size, Point(pos.x+(ROW+2)*size*4, pos.y));

    S.draw(g);
    O.draw(g);
    U.draw(g);
    N.draw(g);
    D.draw(g);
}

void Words::writeScore(SDL_Plotter& g){
    Letter S = Letter('S', color, size, pos),
           C = Letter('C', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           O = Letter('O', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           R = Letter('R', color, size, Point(pos.x+(ROW+2)*size*3, pos.y)),
           E = Letter('E', color, size, Point(pos.x+(ROW+2)*size*4, pos.y));

    S.draw(g);
    C.draw(g);
    O.draw(g);
    R.draw(g);
    E.draw(g);
}

void Words::writeSpace(SDL_Plotter& g){
    Letter P1= Letter('(', color, size, pos),
           S = Letter('S', color, size, Point(pos.x+(ROW+1)*size, pos.y)),
           P = Letter('P', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           A = Letter('A', color, size, Point(pos.x+(ROW+2)*size*3, pos.y)),
           C = Letter('C', color, size, Point(pos.x+(ROW+2)*size*4, pos.y)),
           E = Letter('E', color, size, Point(pos.x+(ROW+2)*size*5, pos.y)),
           P2= Letter(')', color, size, Point(pos.x+(ROW+2)*size*6, pos.y));

    P1.draw(g);
    S.draw(g);
    P.draw(g);
    A.draw(g);
    C.draw(g);
    E.draw(g);
    P2.draw(g);
}

void Words::writeS(SDL_Plotter& g){
    Letter P1= Letter('(', color, size, pos),
           S = Letter('S', color, size, Point(pos.x+(ROW+1)*size, pos.y)),
           P2= Letter(')', color, size, Point(pos.x+(ROW+1)*size*2, pos.y)),
           C = Letter(':', color, size, Point(pos.x+(ROW-3)*size*3, pos.y));

    P1.draw(g);
    S.draw(g);
    P2.draw(g);
    C.draw(g);
}

void Words::writeOn(SDL_Plotter& g){
    Letter O = Letter('O', color, size, pos),
           N = Letter('N', color, size, Point(pos.x+(ROW+1)*size, pos.y));

    O.draw(g);
    N.draw(g);
}

void Words::writeOff(SDL_Plotter& g){
    Letter O = Letter('O', color, size, pos),
           F1= Letter('F', color, size, Point(pos.x+(ROW)*size, pos.y)),
           F2= Letter('F', color, size, Point(pos.x+(ROW)*size*2, pos.y));

    O.draw(g);
    F1.draw(g);
    F2.draw(g);
}

void Words::writeEasy(SDL_Plotter& g){
    Letter E = Letter('E', color, size, pos),
           A = Letter('A', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           S = Letter('S', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           Y = Letter('Y', color, size, Point(pos.x+(ROW+2)*size*3, pos.y));

    E.draw(g);
    A.draw(g);
    S.draw(g);
    Y.draw(g);
}

void Words::writeHigh(SDL_Plotter& g){
    Letter H1= Letter('H', color, size, pos),
           I = Letter('I', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           G = Letter('G', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           H2= Letter('H', color, size, Point(pos.x+(ROW+2)*size*3, pos.y));

    H1.draw(g);
    I.draw(g);
    G.draw(g);
    H2.draw(g);
}

void Words::writeReturn(SDL_Plotter& g){
    Letter R1= Letter('R', color, size, pos),
           E = Letter('E', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           T = Letter('T', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           U = Letter('U', color, size, Point(pos.x+(ROW+2)*size*3, pos.y)),
           R2= Letter('R', color, size, Point(pos.x+(ROW+2)*size*4, pos.y)),
           N = Letter('N', color, size, Point(pos.x+(ROW+2)*size*5, pos.y));

    R1.draw(g);
    E.draw(g);
    T.draw(g);
    U.draw(g);
    R2.draw(g);
    N.draw(g);
}

void Words::writeMedium(SDL_Plotter& g){
    Letter M1= Letter('M', color, size, pos),
           E = Letter('E', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           D = Letter('D', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           I = Letter('I', color, size, Point(pos.x+(ROW+2)*size*3, pos.y)),
           U = Letter('U', color, size, Point(pos.x+(ROW+2)*size*4, pos.y)),
           M2= Letter('M', color, size, Point(pos.x+(ROW+2)*size*5, pos.y));

    M1.draw(g);
    E.draw(g);
    D.draw(g);
    I.draw(g);
    U.draw(g);
    M2.draw(g);
}

void Words::writeHard(SDL_Plotter& g){
    Letter H = Letter('H', color, size, pos),
           A = Letter('A', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           R = Letter('R', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           D = Letter('D', color, size, Point(pos.x+(ROW+2)*size*3, pos.y));

    H.draw(g);
    A.draw(g);
    R.draw(g);
    D.draw(g);
}

void Words::writeName(SDL_Plotter& g){
    Letter N = Letter('N', color, size, pos),
           A = Letter('A', color, size, Point(pos.x+(ROW+2)*size, pos.y)),
           M = Letter('M', color, size, Point(pos.x+(ROW+2)*size*2, pos.y)),
           E = Letter('E', color, size, Point(pos.x+(ROW+2)*size*3, pos.y)),
           C = Letter(':', color, size, Point(pos.x+(ROW+1)*size*4, pos.y));

    N.draw(g);
    A.draw(g);
    M.draw(g);
    E.draw(g);
    C.draw(g);
}

void Words::writeN(SDL_Plotter& g){
    Letter P1= Letter('(', color, size, pos),
           N = Letter('N', color, size, Point(pos.x+(ROW+1)*size, pos.y)),
           P2= Letter(')', color, size, Point(pos.x+(ROW+1)*size*2, pos.y)),
           C = Letter(':', color, size, Point(pos.x+(ROW-3)*size*3, pos.y));

    P1.draw(g);
    N.draw(g);
    P2.draw(g);
    C.draw(g);
}

void Words::writeLevel( SDL_Plotter& g ) {
    Letter L = Letter( 'L', color, size, pos ),
        E = Letter( 'E', color, size, Point( pos.x + ( ROW + 2 )*size, pos.y ) ),
        V = Letter( 'V', color, size, Point( pos.x + ( ROW + 2 )*size * 2, pos.y ) ),
        EE = Letter( 'E', color, size, Point( pos.x + ( ROW + 2 )*size * 3, pos.y ) ),
        LL = Letter( 'L', color, size, Point( pos.x + ( ROW + 2 )*size * 4, pos.y ) );

    L.draw( g );
    E.draw( g );
    V.draw( g );
    EE.draw( g );
    LL.draw( g );
}

void Words::setColor(Color c){
    color = c;
}

void Words::setPoint(Point p){
    pos = p;
}

void Words::setSize(int s){
    size = s;
}

Color Words::getColor() const{
    return color;
}

Point Words::getPoint() const{
    return pos;
}

int Words::getSize() const{
    return size;
}
