#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de cada carta
typedef struct {
    char nome[100];
    char estado[100];
    int codigo;
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta* carta) {
    printf("Digite o nome da cidade: ");
    fgets(carta->nome, 100, stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0;  // Remove o '\n' da string

    printf("Digite o estado da cidade: ");
    fgets(carta->estado, 100, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = 0;

    printf("Digite o código da cidade: ");
    scanf("%d", &carta->codigo);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta->pontos_turisticos);

    // Limpa o buffer de entrada para próximas leituras
    getchar();
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta carta1, Carta carta2, int atributo) {
    int vitoria = 0;

    switch (atributo) {
        case 1: // Comparar População
            if (carta1.populacao > carta2.populacao) {
                vitoria = 1;
            } else if (carta1.populacao < carta2.populacao) {
                vitoria = 2;
            }
            break;

        case 2: // Comparar Área
            if (carta1.area > carta2.area) {
                vitoria = 1;
            } else if (carta1.area < carta2.area) {
                vitoria = 2;
            }
            break;

        case 3: // Comparar PIB
            if (carta1.pib > carta2.pib) {
                vitoria = 1;
            } else if (carta1.pib < carta2.pib) {
                vitoria = 2;
            }
            break;

        case 4: // Comparar Pontos turísticos
            if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
                vitoria = 1;
            } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
                vitoria = 2;
            }
            break;

        case 5: // Comparar Densidade Populacional
            float densidade1 = carta1.populacao / carta1.area;
            float densidade2 = carta2.populacao / carta2.area;
            if (densidade1 < densidade2) { // Menor densidade vence
                vitoria = 1;
            } else if (densidade1 > densidade2) {
                vitoria = 2;
            }
            break;

        default:
            printf("Atributo inválido!\n");
            return;
    }

    // Exibindo o resultado da comparação
    if (vitoria == 1) {
        printf("A carta 1 (Cidade: %s) venceu!\n", carta1.nome);
    } else if (vitoria == 2) {
        printf("A carta 2 (Cidade: %s) venceu!\n", carta2.nome);
    } else {
        printf("As cartas são iguais no atributo selecionado!\n");
    }
}

int main() {
    Carta carta1, carta2;
    int atributo;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&carta2);

    // Exibindo as informações das cartas
    printf("\nInformações da carta 1:\n");
    printf("Nome: %s\n", carta1.nome);
    printf("Estado: %s\n", carta1.estado);
    printf("Código: %d\n", carta1.codigo);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontos_turisticos);

    printf("\nInformações da carta 2:\n");
    printf("Nome: %s\n", carta2.nome);
    printf("Estado: %s\n", carta2.estado);
    printf("Código: %d\n", carta2.codigo);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontos_turisticos);

    // Escolha do atributo para comparar
    printf("\nEscolha um atributo para comparar (1- População, 2- Área, 3- PIB, 4- Pontos Turísticos, 5- Densidade Populacional): ");
    scanf("%d", &atributo);

    // Realizando a comparação
    compararCartas(carta1, carta2, atributo);

    return 0;
}