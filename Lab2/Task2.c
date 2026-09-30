#include <stdio.h>

int main()
{
	int n = 0;
	double x = 1.0 / 3.0;
	double s = x;
	double ssum = s;

	scanf("%d", &n);

	for (int i = 0;i < n; i++)
	{
		s = s * (-x * x) * (2 * i + 1) / ((2 * i + 2) * (2 * i + 3) * (2 * i + 3));

		ssum += s;
	}

	printf("%.7lf\n", ssum);
	printf("%d", 20 * n + 9);

	return 0;
}