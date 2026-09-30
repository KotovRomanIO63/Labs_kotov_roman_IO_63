#include <stdio.h>


int main()
{
	double x = 1.0 / 3.0;
	int n = 0;
	double s = 0;
	double ssum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n + 1; i++)
	{
		double powerx = 1;
		double factorial = 1;
		int power = 1;

		for (int p1 = 0; p1 < i; p1++)
		{
			power *= (-1);
		}

		for (int f = 1; f <= 2 * i + 1; f++)
		{
			factorial *= f;
		}

		for (int p2 = 0; p2 < 2 * i + 1; p2++)
		{
			powerx *= x;
		}

		s = (power * powerx) / ((2 * i + 1) * factorial);

		ssum += s;
	}

	printf("%.7lf\n", ssum);
	printf("%lld\n", 16 * n * n + 50 * n + 43);

	return 0;
}

