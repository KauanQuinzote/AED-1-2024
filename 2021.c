#include <stdio.h>

int main()
{
    int m, n, p, q, i, sub, sum;

    // Lê os valores iniciais de m, n e p
    scanf("%d %d %d", &m, &n, &p);

    // Loop até que qualquer um dos valores seja zero
    while (m != 0 && n != 0 && p != 0)
    {
        sum = 0;
        sub = 0;
        // Loop para ler os valores de q e calcular sum
        for (i = 0; i < p; i++)
        {
            scanf("%d", &q);
            if (q > n)
            {
                q = q % n; 

                if (q == 0)
                    sum += 1;
                else
                {
                    sub = (n - q) + 1;
                    sum += sub;
                }
            }
            else
            {
                sub = (n - q) + 1;
                sum += sub;
            }
        }

        // Imprime o resultado da soma
        printf("Lights: %d\n", sum);
        // Lê os próximos valores de m, n e p
        scanf("%d %d %d", &m, &n, &p);
    }

    return 0;
}
