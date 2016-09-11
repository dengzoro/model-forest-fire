//
//  CSE6010HW01.c
//  CSE6010_homework1
//
//  Created by Zheng Deng on 16/8/28.
//  Copyright © 2016 ZhengDeng. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include "matrix.h"


int main(){
    srand((unsigned)time(NULL));//make number random
    
    matrix grid=init_matrix(ROW, COL);//generate a 2-D grid in size of ROW*COL
    
    time_step_loop(grid,ROW,COL,F,G);/* main funciton for Growth-Fire loop for n times
                                      * each Growth will print the number of trees
                                      * each Fire will print the remained number of trees
                                      * grid size of ROW*COL
                                      * F is the fire probability
                                      * G is the growth probability
                                      */
    return 0;

}


















