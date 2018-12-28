// 8QueenByRecursive.cpp : �������̨Ӧ�ó������ڵ㡣
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
 * ���ʺ��Ƿ����໥����
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

	// ������Ϸ�
	x1 = x-1;
	y1 = y-1;
	while (x1 >= 0 && y1 >= 0) {
		if (pad[x1--][y1--] != 0) {
			return 0;
		}
	}

	// ����Ϸ�
	x1 = x-1;
	y1 = y;
	while (x1 >= 0) {
		if (pad[x1--][y1] != 0) {
			return 0;
		}
	}

	// ������Ϸ�
	x1 = x-1;
	y1 = y+1;
	while (x1 >= 0 && y1 < MAXQUEEN) {
		if (pad[x1--][y1++] != 0) {
			return 0;
		}
	}

	// ����ҷ�
	x1 = x;
	y1 = y+1;
	while (y1 < MAXQUEEN) {
		if (pad[x1][y1++] != 0) {
			return 0;
		}
	}

	// ������·�
	x1 = x+1;
	y1 = y+1;
	while (x1 < MAXQUEEN && y1 < MAXQUEEN) {
		if (pad[x1++][y1++] != 0) {
			return 0;
		}
	}

	// ����·�
	x1 = x+1;
	y1 = y;
	while (x1 < MAXQUEEN) {
		if (pad[x1++][y1] != 0) {
			return 0;
		}
	}

	// ������·�
	x1 = x+1;
	y1 = y-1;
	while (x1 < MAXQUEEN && y1 >= 0) {
		if (pad[x1++][y1--] != 0) {
			return 0;
		}
	}

	// �����
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
 * ��N ���ʺ�ĵݹ麯��
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
 * �õݹ�ķ������8 �ʺ�����
 */
int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;

	put_queen(0, 0, 1);

	print_pad(&pad[0][0]);

	return 0;
}
