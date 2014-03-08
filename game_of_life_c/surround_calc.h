//
//  surround_calc.h
//  game_of_life_c
//
//  Created by Neil de Vries on 3/7/2014.
//  Copyright (c) 2014 Macrolith. All rights reserved.
//

#ifndef game_of_life_c_surround_calc_h
#define game_of_life_c_surround_calc_h

// global functions

// int state_around(int pos_x, int pos_y, bool value):
// DESC: returns the count of cells that are alive (==1) around
//       the given pos.
int live_surrounding(int pos_x, int pos_y);

// bool cell_surrounded(pos_x, pos_y):
// DESC: returns the count of cells in existence around
//       the given pos.
int cell_surrounded(int pos_x, int pos_y);

// int pos_to_i(int x, int y):
// DESC: converts a pos to the equivalent 2D array index - returns
//       an invalid valued array as -1.
int pos_to_i (int x, int y);

#endif
