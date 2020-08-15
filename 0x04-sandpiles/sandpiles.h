#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

int check_stable(int grid1[3][3]);
static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void copy_grid(int grid_copy[3][3], int grid1[3][3]);

#endif
