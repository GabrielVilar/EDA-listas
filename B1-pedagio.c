#include <stdio.h>
int main()
{
    int comprimento_estrada, distancia_pedagio, custo_km, valor_pedagio;
    scanf("%d %d",&comprimento_estrada, &distancia_pedagio);
    scanf("%d %d",&custo_km, &valor_pedagio);

    int quantidade_pedagios, total_pedagio, custo_total;
    quantidade_pedagios = (comprimento_estrada/distancia_pedagio);
    total_pedagio = (valor_pedagio*quantidade_pedagios);
    custo_total = ((custo_km*comprimento_estrada)+total_pedagio);

    printf("%d\n",custo_total);
    return 0;
}
