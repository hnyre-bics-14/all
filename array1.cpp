#include <stdlib.h>
#include <stdio.h>
#include <ctime>

int main()
{
    const int n = 5;
    const int m = 7;
    const int MOD = 20;
    int mas[n][m];

    srand(time(0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            mas[i][j] = rand() % MOD - MOD;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%d\t", mas[i][j]);
        printf("\n");
    }
    printf("\n");

    int min_j;
    int max_i, max_j;
    for(int i=0; i<n; i++)
    {
        min_j = 0;
        for(int j=1; j<m; j++)
            if (mas[i][j] < mas[i][min_j]) min_j = j;
        if (i == 0)
        {
            max_i = i;
            max_j = min_j;
        }
        if (mas[i][min_j] > mas[max_i][max_j])
        {
            max_i = i;
            max_j = min_j;
        }
        printf("In %d line minimal element mas[%d] = %d\n", i, min_j, mas[i][min_j]);
    }
    printf("Maximal element mas[%d][%d] = %d\n", max_i, max_j, mas[max_i][max_j]);

    //system("PAUSE");
    return 0;
}
