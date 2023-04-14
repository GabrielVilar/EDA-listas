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
/*
PDF Informativo:
    https://drive.google.com/file/d/1GrC9uGkENoiflS0u4x4LwK2fd4Ucp9yr/view
*/