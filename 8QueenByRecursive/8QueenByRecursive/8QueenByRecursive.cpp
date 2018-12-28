// 8QueenByRecursive.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define MAXQUEEN 8

int pad [MAXQUEEN][MAXQUEEN] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0
};

/*
 * 检查皇后是否有相互攻击
 */
int place(int x, int y)
{
	int x1, y1;

	if (x < 0 || y < 0 || x >= MAXQUEEN || y >= MAXQUEEN) {
		return 0;
	}

	if (pad[x][y] != 0) {
		return 0;
	}

	// 检查左上方
	x1 = x-1;
	y1 = y-1;
	while (x1 >= 0 && y1 >= 0) {
		if (pad[x1--][y1--] != 0) {
			return 0;
		}
	}

	// 检查上方
	x1 = x-1;
	y1 = y;
	while (x1 >= 0) {
		if (pad[x1--][y1] != 0) {
			return 0;
		}
	}

	// 检查右上方
	x1 = x-1;
	y1 = y+1;
	while (x1 >= 0 && y1 < MAXQUEEN) {
		if (pad[x1--][y1++] != 0) {
			return 0;
		}
	}

	// 检查右方
	x1 = x;
	y1 = y+1;
	while (y1 < MAXQUEEN) {
		if (pad[x1][y1++] != 0) {
			return 0;
		}
	}

	// 检查右下方
	x1 = x+1;
	y1 = y+1;
	while (x1 < MAXQUEEN && y1 < MAXQUEEN) {
		if (pad[x1++][y1++] != 0) {
			return 0;
		}
	}

	// 检查下方
	x1 = x+1;
	y1 = y;
	while (x1 < MAXQUEEN) {
		if (pad[x1++][y1] != 0) {
			return 0;
		}
	}

	// 检查左下方
	x1 = x+1;
	y1 = y-1;
	while (x1 < MAXQUEEN && y1 >= 0) {
		if (pad[x1++][y1--] != 0) {
			return 0;
		}
	}

	// 检查左方
	x1 = x;
	y1 = y-1;
	while (y1 >= 0) {
		if (pad[x1][y1--] != 0) {
			return 0;
		}
	}

	return 1;
}

/*
 * 放N 个皇后的递归函数
 */
int put_queen(int x, int y, int times)
{
	int i, j, result = 0;

	if (times > MAXQUEEN) {
		return 1;
	}
	else {
		if (place(x, y) ) {
			pad[x][y] = 1;
			for (i = 0; i < MAXQUEEN; i++) {
				for (j = 0; j < MAXQUEEN; j++) {
					result += put_queen(i, j, times+1);
					if (result > 0) {
						break;
					}
				}
			}

			if (result > 0) {
				return 1;
			}
			else {
				pad[x][y] = 0;
				return 0;
			}
		}
		else {
			return 0;
		}
	}
}

void print_pad(int *pad)
{
	for (int i = 0; i < MAXQUEEN; i++) {
		for (int j = 0; j < MAXQUEEN; j++) {
			printf("%d ", pad[i*MAXQUEEN+j]);
		}
		printf("\n");
	}

	printf("\n");
}

/*
 * 用递归的方法解决8 皇后问题
 */
int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;

	put_queen(0, 0, 1);

	print_pad(&pad[0][0]);

	return 0;
}
