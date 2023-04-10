#include <stdio.h>
int main()
{
    int largura_cnteinrs, comprimento_cnteinrs, altura_cnteinrs;
    int largura_navio, comprimento_navio, altura_navio;

    scanf("%d %d %d", &largura_cnteinrs, &comprimento_cnteinrs, &altura_cnteinrs);
    scanf("%d %d %d", &largura_navio, &comprimento_navio, &altura_navio);

    int largura_media, media_comprimento, media_altura;
    largura_media = (largura_navio/largura_cnteinrs);
    media_comprimento = (comprimento_navio/comprimento_cnteinrs);
    media_altura = (altura_navio/altura_cnteinrs);

    int nmrs_cnteinrs_base;
    nmrs_cnteinrs_base = (largura_media*media_comprimento);
    
    int nmr_max_cnteinrs_navio;
    nmr_max_cnteinrs_navio = (nmrs_cnteinrs_base*media_altura);

    printf("%d\n", nmr_max_cnteinrs_navio);
  
    return 0;
}
