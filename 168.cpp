#include <stdio.h>

int main()
{
	int tam, suma, aux;

	scanf("%d",&tam);

	while (tam != 0)
	{
		suma = tam*(tam + 1) / 2;

		for (int i = 0; i < tam-1; i++)
			{scanf("%d",&aux); suma -= aux;}

		printf("%d\n",suma);

		scanf("%d",&tam);
	}

	return 0;
}
