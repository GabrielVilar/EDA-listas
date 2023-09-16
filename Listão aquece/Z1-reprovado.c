#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[21];
    int problemas_resolvidos;
};

int main() {
    int n, i, j, caso = 1;
    
    while (scanf("%d", &n) != EOF) {
        struct Aluno alunos[n];
        
        for (i = 0; i < n; i++) {
            scanf("%s %d", alunos[i].nome, &alunos[i].problemas_resolvidos);
        }
        
        // Ordena os alunos pelo número de problemas resolvidos e, em caso de empate, por ordem alfabética
        for (i = 0; i < n-1; i++) {
            for (j = i+1; j < n; j++) {
                if (alunos[i].problemas_resolvidos < alunos[j].problemas_resolvidos ||
                    (alunos[i].problemas_resolvidos == alunos[j].problemas_resolvidos && strcmp(alunos[i].nome, alunos[j].nome) > 0)) {
                    struct Aluno temp = alunos[i];
                    alunos[i] = alunos[j];
                    alunos[j] = temp;
                }
            }
        }
        
        // Imprime o resultado
        printf("Instancia %d\n", caso++);
        printf("%s\n\n", alunos[n-1].nome);
    }
    
    return 0;
}
