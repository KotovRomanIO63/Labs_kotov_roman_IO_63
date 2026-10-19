#include <stdio.h>

#define m 8
#define n 8

int main()
{
	int matrix[m][n];

	for (int i = 0; i < m; i++)
	{
		printf("Enter row %d(%d numbers) : ", i + 1, n);

		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 1; i < n; i += 2)
	{
		int minIndex = i;

		for (int j = i + 2; j < n; j += 2)
		{
			if (matrix[m - 1][j] < matrix[m - 1][minIndex])
			{
				minIndex = j;
			}
		}

		int temp_num = matrix[m - 1][i];
		matrix[m - 1][i] = matrix[m - 1][minIndex];
		matrix[m - 1][minIndex] = temp_num;
	}

	printf("-------------------------------------\n");

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}