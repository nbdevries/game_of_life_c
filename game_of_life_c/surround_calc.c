//
//  surround_calc.c
//  game_of_life_test
//
//  Created by Neil de Vries on 3/6/2014.
//  Copyright (c) 2014 Macrolith. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "main.h"

// see surround_calc.h for documentation
//
int pos_to_i (int x, int y)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return -1;
    }
    return y*WIDTH+x;
}

// see surround_calc.h for documentation
//
int live_surrounding(int pos_x, int pos_y)
{
    int count = 0;
    for (int p = 0; p <= cell_matrix_size; p += 2)
    {
        // index of currently being evaluated surrounding side
        int i = pos_to_i((pos_x + cell_matrix[p]),(pos_y + cell_matrix[p+1]));
        
        if (i != -1 && board[i] == 1)
        {
            count++;
        }
    }
    return count;
}

// see surround_calc.h for documentation
//
bool cell_surrounded(int pos_x, int pos_y)
{
    int count = 0;
    for (int p = 0; p <= cell_matrix_size; p += 2)
    {
        // index of currently being evaluated surrounding side
        int i = pos_to_i((pos_x + cell_matrix[p]),(pos_y + cell_matrix[p+1]));
        if (i != -1)
        {
            count++;
        }
    }
    return count == 8;
}