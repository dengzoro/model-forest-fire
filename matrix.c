//
//  matrix.c
//  CS6010_homework1
//
//  Created by ZhengDeng on 9/7/16.
//  Copyright © 2016 ZhengDeng. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

//allocate matrix of size row*col
matrix make_matrix(int row, int col){
    matrix grid=(matrix)malloc(row*sizeof(int*));
    int i;
    for(i=0;i<row;i++){
        grid[i]=(int*)malloc(col*sizeof(int));
    }
    return grid;
    
}
//initialize the 2-D grid and make each cell's state to "0"(empty no tree)
matrix init_matrix(int row, int col){
    matrix grid=make_matrix(row, col);
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            grid[i][j]=0;
            
        }
    }
    return grid;
}

//print the grid function,only used for test not in the main.c file
void grid_print(matrix grid,int row,int col){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",grid[i][j]);
            
        }
        printf("\n");
    }
}

//count the number of the tree in the grid
int tree_count(matrix grid,int row,int col){
    int treecount=0;
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if (grid[i][j]==1) {
                treecount++;
            }
            
        }
    }
    return treecount;

}


//make the grid to the Growth phase
matrix growth_phase(int row,int col,matrix grid,float g){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            float random_p=rand() % (10000);//generate a rondom growth probability number for each cell and compare it with g
            random_p/=10000;
            if (random_p<=g){
                grid[i][j]=1;
            }
        }
        
    }
    return grid;
}


//make the grid to the fire phase and spread
matrix fire_phase(int row,int col, matrix grid,float f){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            float random_f=rand() % (10000);//generate a rondom fire probability for each cell and compare it with f
            random_f/=10000;
            if(random_f<=f){
                spread_fire(grid,i, j); //spreading the fire
            }
            
        }
    
    }
   
    
    return grid;

}

//fire spreading process
void spread_fire(matrix grid,int i,int j){
    if (i<0 || j<0 || i>99 || j>99){//boundary condition
        return;
    }
    if(grid[i][j]==1){
        grid[i][j]=0;
        
        spread_fire(grid,i-1,j);//to spread fire with recursion
        spread_fire(grid,i+1,j);
        spread_fire(grid,i,j-1);
        spread_fire(grid,i,j+1);
    }
    else{
        return;
    }
   
   
}

//main function for Growth-Fire loop process and output the average number of tree
//f is the fire probability,g is the growth probability
void time_step_loop(matrix grid,int row,int col,float f,float g){
    int n,tree_n,tree_n2,tree_n_total;
    int P;//average number of tree at end of each time step
    tree_n=0;//number of trees after each growth process
    tree_n2=0;//number of trees after each fire process
    tree_n_total=0;//accumulated total number of tree at end of each time step
    
    for (n=0; n<TIMESTEP; n++) {
        growth_phase(row,col,grid,g);
        tree_n=tree_count(grid,row,col);
        printf("The forest has %d trees after growth.\n",tree_n);//growth phase
        
        fire_phase(row,col,grid,f);
        tree_n2=tree_count(grid,row,col);
        tree_n_total+=tree_n2;
        P=tree_n_total/(n+1);
        printf("After the fire, %d trees remains.\n",tree_n2);//fire phase
        
        
        printf("Average number of tree is %d at time step :%d.\n",P,n+1);//record the number of time step
    
    }

}

    
    







