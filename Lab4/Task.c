#include <stdio.h>

#define m 7
#define n 7

int main()
{
	float matrix[m][n];

	float target_num = 0;
	char found = 0;

	printf("Enter the target number: ");
	scanf("%f", &target_num);

	for (int i = 0; i < m; i++)
	{
		printf("Enter row %d(%d numbers) : ", i + 1, n);

		for (int j = 0; j < n; j++)
		{
			scanf("%f", &matrix[i][j]);
		}
	}

	printf("\nThe matrix:\n");

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.2f ", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		int left = 0;
		int right = m - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (matrix[mid][i] == target_num)
			{
				printf("\nNumber found: %.2f\n", target_num);
				printf("Row: %d\n", mid + 1);
				printf("Column: %d\n", i + 1);

				found = 1;
				break;
			}
			else if (matrix[mid][i] < target_num)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		if (found)
		{
			break;
		}
	}

	if (!found)
	{
		printf("\nNumber %.2f not found.\n", target_num);
	}
	return 0;
}