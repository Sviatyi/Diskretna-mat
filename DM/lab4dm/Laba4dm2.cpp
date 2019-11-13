#include <iostream>

using namespace std;



int main()
{
	int rebro[18][4] = {
		{1,2,1,0},//1ver 2ver masa 
		{1,3,2,0},
		{1,4,4,0},
		{2,5,3,0},
		{2,7,2,0},
		{3,5,7,0},
		{3,6,6,0},
		{4,6,2,0},
		{4,7,3,0},
		{5,8,7,0},
		{5,9,5,0},
		{6,8,7,0},
		{6,10,3,0},
		{7,9,5,0},
		{7,10,4,0},
		{8,11,4,0},
		{9,11,1,0},
		{10,11,4,0}
	};
	int top[11][2] = {
		{1,0},
		{2,0},
		{3,0},
		{4,0},
		{5,0},
		{6,0},
		{7,0},
		{8,0},
		{9,0},
		{10,0},
		{11,0}
	};
	
	for (int i = 0; i < 18; i++) {
		for (int k = 0; k < 17-i; k++) {
			if (rebro[k][2] > rebro[k + 1][2]) {
				for (int j = 0,a=0; j < 4; j++) {
					a = rebro[k + 1][j];
					rebro[k + 1][j] = rebro[k][j];
					rebro[k][j] = a;
				}
			}
		}
	}
	int count = 1;
	for (int i = 0; i < 18; i++) {
		if (top[rebro[i][0] - 1][1] != top[rebro[i][1] - 1][1]) {
			rebro[i][3] = 1;
			if (top[rebro[i][0] - 1][1] == 0 && top[rebro[i][1] - 1][1]!=0) {
				top[rebro[i][0] - 1][1] = top[rebro[i][1] - 1][1];
				}
			if (top[rebro[i][0] - 1][1] != 0 && top[rebro[i][1] - 1][1] == 0) {
				top[rebro[i][1] - 1][1] = top[rebro[i][0] - 1][1];
			}
			if (top[rebro[i][0] - 1][1] != 0 && top[rebro[i][1] - 1][1] != 0) {
				for (int j = 0; j < 11; j++) {
					if (top[j][1] == top[rebro[i][1] - 1][1]) {
						top[j][1] = top[rebro[i][0] - 1][1];
					}
				}
			}
		}

		if (top[rebro[i][0] - 1][1] == 0 && top[rebro[i][1] - 1][1] == 0) {
			rebro[i][3] = 1;
			top[rebro[i][0] - 1][1] = count;
			top[rebro[i][1] - 1][1] = count;
			count++;
		}
	}

	for (int i = 0; i < 18; i++) {
		if (rebro[i][3] == 1) {
			cout << rebro[i][0] << "  " << rebro[i][1] << "  " << rebro[i][2]<<endl;
		}
	}
	return 0;
}

