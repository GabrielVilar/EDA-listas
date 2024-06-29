#include <stdio.h>
#include <stdbool.h>

#define MAX 100

char mapa[MAX][MAX];
bool visitado[MAX][MAX];
int largura, altura;

// Movimentos correspondentes às setas
int movX[] = {0, 0, 1, -1};  // > < v ^
int movY[] = {1, -1, 0, 0};
char direcao[] = {'>', '<', 'v', '^'};

// Função para verificar se a célula está dentro do mapa
bool dentro(int x, int y) {
    return x >= 0 && x < altura && y >= 0 && y < largura;
}

// Função para verificar se o mapa faz sentido e se é possível alcançar o baú
bool verifica_mapa() {
    // Inicia a busca a partir do canto superior esquerdo
    int x = 0, y = 0;
    int dir = 0; // 0: direita, 1: esquerda, 2: baixo, 3: cima
    
    while (true) {
        // Se já visitado, retornar mapa inválido
        if (visitado[x][y]) return false;
        
        visitado[x][y] = true;
        
        // Se encontrou o baú, retornar mapa válido
        if (mapa[x][y] == '*') return true;
        
        // Verifica a direção corrente
        if (mapa[x][y] == '>') dir = 0;
        else if (mapa[x][y] == '<') dir = 1;
        else if (mapa[x][y] == 'v') dir = 2;
        else if (mapa[x][y] == '^') dir = 3;
        
        // Próxima posição baseada na direção
        int nx = x + movX[dir];
        int ny = y + movY[dir];
        
        // Se a nova posição está fora do mapa, retornar mapa inválido
        if (!dentro(nx, ny)) return false;
        
        // Atualiza a posição para a próxima célula
        x = nx;
        y = ny;
    }
    
    // Se sair do loop, deveria ter encontrado o baú ou retornado antes
    return false;
}

int main() {
    // Leitura da entrada
    scanf("%d %d", &largura, &altura);
    
    for (int i = 0; i < altura; i++) {
        scanf("%s", mapa[i]);
    }
    
    // Inicializa a matriz de visitados
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            visitado[i][j] = false;
        }
    }
    
    // Verifica se o mapa faz sentido e se é possível alcançar o baú
    if (verifica_mapa()) {
        printf("*\n");
    } else {
        printf("!\n");
    }
    
    return 0;
}