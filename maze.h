/*
 * By: Sergey Petrushkevich & Luke Ackerman
 * Project 5
 * Grid class that stores the nxn grid.
 * Uses the given d_matrix.h class.
 */

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "iostream"
#include "fstream"
#include <vector>
#include <algorithm>
#include "d_matrix.h"

#ifndef MAZE_H
#define MAZE_H

using namespace std;

class grid
{
public:
    int amtNodes = 0;
    int rows;
    int columns;
    matrix<unsigned char> gridMatrix;
    grid();
    void readGrid();
    void outputGrid();
    void LabelNodes();
    void findAmountNodes();
    void resize(int r, int c);
    void reformatGrid();
};
#endif //MAZE_H