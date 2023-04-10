#include <stdio.h>
int main()
{
    float precoAlcool, precoGasolina, kmAlcool, KmGasolina;
    float gastoKmAlcool, gastoKmGasolina;

    scanf("%f %f %f %f", &precoAlcool, &precoGasolina, &kmAlcool, &KmGasolina);
    gastoKmAlcool = (precoAlcool/kmAlcool);
    gastoKmGasolina = (precoGasolina/KmGasolina);

    if(gastoKmAlcool < gastoKmGasolina){
        printf("A\n");
    }else if (gastoKmGasolina < gastoKmAlcool)
    {
        printf("G\n");
    }else{
        printf("G");
    }
    
    return 0;
}
