#include <iostream>
#include <windows.h> //для задержки экрана
#include <ctime> //для генерации семя рандома

using std::cout;


int main()
{
	const int n = 5;
	const int MOD = 20; //для генерации
	srand(time(0)); //генерация семя

	int mas[n][n]; //создание массива
	/*заполнение массива случайными числами*/
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			mas[i][j] = rand() % MOD - MOD/2;
	/*вывод массива на экран*/
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << mas[i][j] << "\t";
		cout << "\n";
	}

	/*сами расчёты*/
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

	system("PAUSE"); //задержка экрана
	return 0; //и выход)
}
