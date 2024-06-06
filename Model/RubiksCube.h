//
// Created by dell on 24-05-2024.
//

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include "bits/stdc++.h"
using namespace std;

class RubiksCube {
public:
    enum class FACE {
      UP,
      LEFT,
      FRONT,
      RIGHT,
      BACK,
      DOWN
    };

    enum class COLOR {
      WHITE,
      GREEN,
      RED,
      BLUE,
      ORANGE,
      YELLOW
    };

    enum class MOVE {
      L, LPRIME, L2,
      R, RPRIME, R2,
      U, UPRIME, U2,
      D, DPRIME, D2,
      F, FPRIME, F2,
      B, BPRIME, B2
    };
    /*
     * Returns the color of the cell at (row, col) in face.
     * If Rubik's Cube face is pointing at you, then the row numbering starts from the
     * top to bottom, and column numbering starts from the left to right.
     * The rows and columns are 0-indexed.
     * @param Face, row, and column index
    */
    virtual COLOR getColor(FACE face,unsigned row,unsigned col) const=0;
    /*
     * Returns the first letter of the given COLOR
     * Eg: For COLOR::GREEN, it returns 'G'
     */
    static char getColorLetter(COLOR color);

    /*
     * Returns true if the Rubik Cube is solved, otherwise returns false.
     */
    virtual bool isSolved() const=0;

    /*
     * Returns the move in the string format.
     */
    static string getMove(MOVE ind);

    /*
     * Print the Rubik Cube in Planar format.
     *
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings:
     * rx -> row numbering
     * cx -> column numbering
     * bx -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     */
    void print() const;

    /*
     * Randomly shuffle the cube with 'times' moves and returns the moves performed.
     */
     vector<MOVE> randomShuffleCube(unsigned int times);

     /*
     * Perform moves on the Rubik Cube
     */
     RubiksCube &move(MOVE ind);

     /*
     * Invert a move
     */
     RubiksCube &invert(MOVE ind);

     /*
     * Rotational Moves on the Rubik Cubes
     *
     * F, F’, F2,
     * U, U’, U2,
     * L, L’, L2,
     * D, D’, D2,
     * R, R’, R2,
     * B, B’, B2
     */
     virtual RubiksCube &f()=0;
     virtual RubiksCube &fprime()=0;
     virtual RubiksCube &f2()=0;
     virtual RubiksCube &l()=0;
     virtual RubiksCube &lprime()=0;
     virtual RubiksCube &l2()=0;
     virtual RubiksCube &r()=0;
     virtual RubiksCube &rprime()=0;
     virtual RubiksCube &r2()=0;
     virtual RubiksCube &u()=0;
     virtual RubiksCube &uprime()=0;
     virtual RubiksCube &u2()=0;
     virtual RubiksCube &b()=0;
     virtual RubiksCube &bprime()=0;
     virtual RubiksCube &b2()=0;
     virtual RubiksCube &d()=0;
     virtual RubiksCube &dprime()=0;
     virtual RubiksCube &d2()=0;

 string getCornerColorString(uint8_t ind) const;

 uint8_t getCornerIndex(uint8_t ind) const;

 uint8_t getCornerOrientation(uint8_t ind) const;

};
#endif //RUBIKSCUBE_H
