#include <iostream>
#include <windows.h>
#include <ctime>

using std::cout;


int main()
{
	const int n = 5;
	const int MOD = 20;
	srand(time(0));

	int mas[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			mas[i][j] = rand() % MOD - MOD/2;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << mas[i][j] << "\t";
		cout << "\n";
	}

	int min_i, min_j;
	int max_i;
	for(int j=0; j<n; j++)
	{
		max_i = 0;
		for(int i=1; i<n; i++)
			if (mas[i][j] > mas[max_i][j]) max_i = i;
		printf("In %d column max element %d\n", j, mas[max_i][j]);
		if (j == 0)
		{
			min_i = max_i;
			min_j = j;
		}
		if (mas[max_i][j] < mas[min_i][min_j])
		{
			min_i = max_i;
			min_j = j;
		}
	}

	printf("Minimal element have index [%d][%d] (numeration start from 0)\n", min_i, min_j);

	system("PAUSE");
	return 0;
}
