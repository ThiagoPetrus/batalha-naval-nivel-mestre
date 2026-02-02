#include <stdio.h>

#define TAM 10
#define HAB 5

void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = 0;
}

void exibirTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tab[TAM][TAM], int hab[HAB][HAB], int origemL, int origemC) {
    int offset = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (hab[i][j] == 1) {
                int l = origemL + i - offset;
                int c = origemC + j - offset;

                if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                    if (tab[l][c] == 0)
                        tab[l][c] = 5;
                }
            }
        }
    }
}

void criarCone(int hab[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            hab[i][j] = (j >= (HAB/2 - i) && j <= (HAB/2 + i)) ? 1 : 0;
        }
    }
}

void criarCruz(int hab[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            hab[i][j] = (i == HAB/2 || j == HAB/2) ? 1 : 0;
        }
    }
}

void criarOctaedro(int hab[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int dist = abs(i - HAB/2) + abs(j - HAB/2);
            hab[i][j] = (dist <= HAB/2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int habilidade[HAB][HAB];

    inicializarTabuleiro(tabuleiro);

    // Exemplo de navio
    tabuleiro[4][4] = 3;

    printf("=== Habilidade Cone ===\n");
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 2);
    exibirTabuleiro(tabuleiro);

    inicializarTabuleiro(tabuleiro);
    tabuleiro[5][5] = 3;

    printf("\n=== Habilidade Cruz ===\n");
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    exibirTabuleiro(tabuleiro);

    inicializarTabuleiro(tabuleiro);
    tabuleiro[6][6] = 3;

    printf("\n=== Habilidade Octaedro ===\n");
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 6, 6);
    exibirTabuleiro(tabuleiro);

    return 0;
}
