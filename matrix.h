//
//  matrix.h
//  CS6010_homework1
//
//  Created by ZhengDeng on 9/7/16.
//  Copyright © 2016 ZhengDeng. All rights reserved.


#ifndef MATRIX_H_
#define MATRIX_H_
#define G 0.9//define the probability of growth can be change in 0.1-0.9
#define F 0.05//define the probability of fire can be change in 0.01 0.02 0.05
#define TIMESTEP 1000//define the number of timesteps
#define ROW 100//define the row size of the 2-D grid
#define COL 100//define the column size of the 2-D grid
#endif /* MATRIX_H */

#include <stdio.h>


typedef int** matrix; //matrix type is array of pointers pointing to array of elements of type int(0 or 1)

matrix make_matrix(int row,int col);
/*
 * allocate space for a matrix of size row*col(in this problem is 100*100)
 *
 * @parameter row  the size of the allocated row for matrix
 * @parameter col  the size of the allocated column for matrix
 * @return the allocated matrix gird;
 */

matrix init_matrix(int row,int col);
/*
 * allocate space for a matrix of size n1*n2
 *
 * @parameter row  the size of the allocated row for matrix
 * @parameter col  the size of the allocated column for matrix
 * @return the empty matrix gird with all cell is '0';
 */

void grid_print(matrix grid,int row,int col);
/*
 * Print the matrix for matrix of size row*col
 *
 * @parameter grid is matrix or 2-D grid we use
 * @parameter row is the size of row for matrix grid
 * @parameter col is the size of column for matrix grid
 * @
 */




int tree_count(matrix grid,int row,int col);
/*
 * Calculate the number of tree in the matrix grid
 *
 * @parameter grid is matrix or 2-D grid we use
 * @parameter row is the size of row for matrix grid
 * @parameter col is the size of column for matrix grid
 * @return the number of tree
 */





matrix growth_phase(int row,int col,matrix grid,float g);
/*
 * Growth phase of the process and make cell occupied in probability g
 *
 * @parameter grid is matrix or 2-D grid we use
 * @parameter row is the size of row for matrix grid
 * @parameter col is the size of column for matrix grid
 * @parameter g is the probability of growth,defined in G,which can be changed to test
 */


matrix fire_phase(int row,int col, matrix grid,float f);
/*
 * Fire phase of the process and make cell empty n probability f and spread fire
 *
 * @parameter grid is matrix or 2-D grid we use
 * @parameter row is the size of row for matrix grid
 * @parameter col is the size of column for matrix grid
 * @parameter f is the probability of fire,defined in F,which can be changed to test
 */


void spread_fire(matrix grid,int i,int j);
/*
 * Fire spread process contained in fire_phase
 *
 * @parameter grid is matrix or 2-D grid we use
 * @parameter i is the row number of the grid
 * @parameter j is the column number of the grid
 */

void time_step_loop(matrix grid,int row,int col,float f,float g);
/*
 * Whole growth-fire process and output the average number at the end of each time step
 *
 * @parameter grid is matrix or 2-D grid we use
 * @parameter row is the size of row for matrix grid
 * @parameter col is the size of column for matrix grid
 * @parameter f is the probability of fire,defined in F,which can be changed to test
 * @parameter g is the probability of growth,defined in G,which can be changed to test
 *
 */




