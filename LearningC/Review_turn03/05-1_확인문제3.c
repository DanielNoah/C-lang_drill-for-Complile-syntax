#include <stdio.h>

int main(void)
{
	double height;
	double weight;
	scanf("%lf %lf", &height, &weight);

	if ((height >= 187.5 && weight < 80))
	{
		printf("ok\n");
	}
	else
	{
		printf("cancel\n");
	}	
	return 0;
}