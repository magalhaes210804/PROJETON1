// Leonardo Magalhães 32318359
// Matheus Chediac Rodrigues 32325746

#include <stdio.h>
#include <stdlib.h>

float *aloca_p(int grau) {
    float *polinomio = (float *)malloc((grau + 1) * sizeof(float));
    if (polinomio == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    return polinomio;
}

void inputp(float *polinomio, int grau) {
    for (int i = grau; i >= 0; i--) {
        printf("Digite o coeficiente para x^%d: ", i);
        scanf("%f", &polinomio[i]);
    }
}

void somap(float *polinomio1, int grau1, float *polinomio2, int grau2, float *resultado) {
    int maior_grau = (grau1 > grau2) ? grau1 : grau2;
    for (int i = 0; i <= maior_grau; i++) {
        float coef1 = (i <= grau1) ? polinomio1[i] : 0;
        float coef2 = (i <= grau2) ? polinomio2[i] : 0;
        resultado[i] = coef1 + coef2;
    }
}

void multp(float *polinomio1, int grau1, float *polinomio2, int grau2, float *resultado) {
    int grauresul = grau1 + grau2;
    for (int i = 0; i <= grauresul; i++) {
        resultado[i] = 0;
        for (int j = 0; j <= grau1; j++) {
            for (int k = 0; k <= grau2; k++) {
                if (j + k == i) {
                    resultado[i] += polinomio1[j] * polinomio2[k];
                }
            }
        }
    }
}

int main() {
    int opcao, grau1, grau2;

    do {
        printf("Menu:\n");
        printf("1. Soma de polinomios\n");
        printf("2. Multiplicacao de polinomios\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {
            printf("Informe o grau do primeiro polinomio: ");
            scanf("%d", &grau1);

            float *polinomio1 = aloca_p(grau1);
            inputp(polinomio1, grau1);

            printf("Informe o grau do segundo polinomio: ");
            scanf("%d", &grau2);

            float *polinomio2 = aloca_p(grau2);
            inputp(polinomio2, grau2);

            if (opcao == 1) {
                int grauresul = (grau1 > grau2) ? grau1 : grau2;
                float *resultado = aloca_p(grauresul);
                somap(polinomio1, grau1, polinomio2, grau2, resultado);
                printf("Resultado da soma:\n");
                for (int i = grauresul; i >= 0; i--) {
                    printf("%.2fx^%d ", resultado[i], i);
                    if (i > 0) {
                        printf("+ ");
                    }
                }
                printf("\n");
                free(resultado);
            } else if (opcao == 2) {
                int grauresul = grau1 + grau2;
                float *resultado = aloca_p(grauresul);
                multp(polinomio1, grau1, polinomio2, grau2, resultado);
                printf("Resultado da multiplicacao:\n");
                for (int i = grauresul; i >= 0; i--) {
                    printf("%.2fx^%d ", resultado[i], i);
                    if (i > 0) {
                        printf("+ ");
                    }
                }
                printf("\n");
                free(resultado);
            }

            free(polinomio1);
            free(polinomio2);
        } else if (opcao != 3) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}
