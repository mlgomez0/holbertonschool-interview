#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: grid to sum up
 * @grid2: grid to sum up
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int grid_copy[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (check_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		copy_grid(grid_copy, grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid_copy[i][j] > 3)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if (i != 0)
						grid1[i - 1][j] = grid1[i - 1][j] + 1;
					if (j != 0)
						grid1[i][j - 1] = grid1[i][j - 1] + 1;
					if (i != 2)
						grid1[i + 1][j] = grid1[i + 1][j] + 1;
					if (j != 2)
						grid1[i][j + 1] = grid1[i][j + 1] + 1;
				}
			}
		}
	}
}

/**
 * check_stable - computes the sum of two sandpiles
 * @grid1: grid to sum up
 * Return: one or cero
 */
int check_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (1);
		}
	}
	return (0);

}

/**
 * print_grid - print a sandpiles
 * @grid: grid to sum up
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * copy_grid- makes a copy of the grid
 * @grid_copy: where copy will be
 * @grid1: grid to copy
 */

void copy_grid(int grid_copy[3][3], int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid_copy[i][j] = grid1[i][j];
		}
	}
}
