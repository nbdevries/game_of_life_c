//
//  main.c
//  game_of_life_test
//
//  Created by Neil de Vries on 3/6/2014.
//  Copyright (c) 2014 Macrolith. All rights reserved.
//

// NOTES: 'pos' indicates a two integer pair in the form
//         of (x,y) mimicing the cartesian plane.

// includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <strings.h>
#include "surround_calc.h"

// defined board & board size
const int HEIGHT = 73;
const int WIDTH  = 108;
const int B_SIZE = HEIGHT*WIDTH;
int board[B_SIZE] = {0};
int next_board[B_SIZE] = {0};

// with pos = d(x,y)
const int cell_matrix_size = 14;
const int cell_matrix[] = {-1,-1,   0,-1,  1,-1,
                           -1, 0,          1, 0,
                           -1, 1,   0, 1,  1, 1};

// update_visible():
// DESC: displays the current state of the gameboard.
//
void update_visible (void)
{
    
    char string_to_print[(WIDTH*2 + 1)*HEIGHT + 1] = {0};
    
    printf("\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
        {
            if (board[pos_to_i(x,y)] == 1) {
                strcat(string_to_print," 0");
            }else{
                strcat(string_to_print," .");
            }
        }
        strcat(string_to_print,"\n");
    }
    printf("%s", string_to_print);
}

// void update_board(void):
// DESC: sets the board to be displayed equal to
//       next_board
//
void update_board(void)
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
        {
            int i = pos_to_i(x, y);
            board[i] = next_board[i];
        }
    }
}

// void game_of_life(void):
// DESC: determines the next state of the board by applying
//       the rules of the game of life to the current board.
//
void game_of_life(void)
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
        {
            int i = pos_to_i(x, y);
            
            if (cell_surrounded(x, y))
            {
                int live_around = live_surrounding(x, y);
                
                if (board[i] == 1) {
                    if (live_around < 2 || live_around > 3) {
                        next_board[i] = 0;
                    } else {
                        next_board[i] = 1;
                    }
                } else {
                    if (live_around == 3) {
                        next_board[i] = 1;
                    } else {
                        next_board[i] = 0;
                    }
                }
            } else {
                next_board[i] = 0;
            }
        }
    }
    
    update_board();
    update_visible();
}


// start_seq():
// DESC: determines what coordinates will begin as living cells
//       to start life and displays a basic startup sequence.
//
void start_seq(void)
{
    printf("Welcome to the game of life!\n"
           "Grid size defined to %dx%d.\n", WIDTH, HEIGHT);
    
    printf("  Enter coordinates of start living cells:\n"
           "  Enter # > %d or %d to start animation.\n\n", WIDTH-1, HEIGHT-1);
    int x = 0;
    int y = 0;
    do {
        printf("Enter x co-ordinate [<%d]: ", WIDTH);
        scanf("%d", &x);
        if (x > WIDTH && x > HEIGHT) {
            break;
        }
        printf("Enter y co-ordinate [<%d]: ", HEIGHT);
        scanf("%d", &y);
        if (y > WIDTH && y > HEIGHT) {
            break;
        }
        board[y*WIDTH+x] = 1;
        printf("Position successfully entered: (%d,%d)\n", x,y);
    } while (1);
    
    update_visible();
    
    while(1)
    {
        sleep(1);
        game_of_life();
    }
}

int main(int argc, const char * argv[])
{
    start_seq();
    return 0;
}

