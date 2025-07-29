#include <stdio.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char estado;
    char carta;
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int turismo;
    float pibpercapita;
    float densidadepopulacional;
} Carta;

// Função para criar uma carta // Solicita os dados ao usuário, confirma e calcula área, PIB per capita e densidade
Carta criarCarta(int numero) {
    Carta nova;
    char confirmacao;

    printf("\n--- Criando carta %d ---\n", numero);

    do {
        printf("Digite um estado (letra de A a H): ");
        scanf(" %c", &nova.estado);
        printf("Você digitou o estado: %c. Está certo? (S/N): ", nova.estado);
        scanf(" %c", &confirmacao);
    } while (confirmacao != 'S' && confirmacao != 's');

    printf("Digite o número da carta (de 1 a 4): ");
    scanf(" %c", &nova.carta);

    printf("Digite o nome da cidade (máx. 50 caracteres): ");
    while ((getchar()) != '\n');
    fgets(nova.cidade, sizeof(nova.cidade), stdin);
    nova.cidade[strcspn(nova.cidade, "\n")] = 0;

    do {
        printf("Digite o número da população (inteiro): ");
        scanf(" %lu", &nova.populacao);
        printf("Você digitou a população: %lu. Está certo? (S/N): ", nova.populacao);
        scanf(" %c", &confirmacao);
    } while (confirmacao != 'S' && confirmacao != 's');

    float base, altura;
    printf("Digite a base da cidade: ");
    scanf("%f", &base);

    printf("Digite a altura da cidade: ");
    scanf("%f", &altura);

    nova.area = base * altura;
    printf("Área da cidade: %.2f km²\n", nova.area);

    printf("Digite o PIB da cidade em milhões: ");
    scanf("%f", &nova.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &nova.turismo);

    nova.pibpercapita = nova.pib * 1000000 / nova.populacao;
    nova.densidadepopulacional = (float)nova.populacao / nova.area;

    return nova;
}

// Função para exibir os dados da carta // Mostra todas as informações armazenadas da carta
void mostrarCarta(Carta c, int numero) {
    printf("\n--- Resumo da Carta %d ---\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Número da carta: %c\n", c.carta);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %lu habitantes\n", c.populacao);
    printf("Área da cidade: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f milhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.turismo);
    printf("PIB per capita: R$ %.2f\n", c.pibpercapita);
    printf("Densidade populacional: %.2f hab/km²\n", c.densidadepopulacional);
}

// Função para comparar cartas // Compara o atributo escolhido entre as duas cartas e imprime o vencedor
void compararCartas(Carta carta1, Carta carta2) {
    int opcao;

    printf("\n--- Menu de comparação ---\n");
    printf("1 - População\n");
    printf("2 - PIB\n");
    printf("3 - PIB per capita\n");
    printf("4 - Densidade populacional\n");
    printf("5 - Pontos turísticos\n");
    printf("0 - Sair da comparação\n");
    printf("Escolha uma opção para comparar: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("\nComparando população...\n");
            printf("Carta 1: %lu | Carta 2: %lu\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Carta 1 venceu na população!\n");
            else if (carta2.populacao > carta1.populacao)
                printf("Carta 2 venceu na população!\n");
            else
                printf("Empate na população.\n");
            break;

        case 2:
            printf("\nComparando PIB...\n");
            printf("Carta 1: R$ %.2f milhões | Carta 2: R$ %.2f milhões\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Carta 1 venceu no PIB!\n");
            else if (carta2.pib > carta1.pib)
                printf("Carta 2 venceu no PIB!\n");
            else
                printf("Empate no PIB.\n");
            break;

        case 3:
            printf("\nComparando PIB per capita...\n");
            printf("Carta 1: R$ %.2f | Carta 2: R$ %.2f\n", carta1.pibpercapita, carta2.pibpercapita);
            if (carta1.pibpercapita > carta2.pibpercapita)
                printf("Carta 1 venceu no PIB per capita!\n");
            else if (carta2.pibpercapita > carta1.pibpercapita)
                printf("Carta 2 venceu no PIB per capita!\n");
            else
                printf("Empate no PIB per capita.\n");
            break;

        case 4:
            printf("\nComparando densidade populacional...\n");
            printf("Carta 1: %.2f hab/km² | Carta 2: %.2f hab/km²\n", carta1.densidadepopulacional, carta2.densidadepopulacional);
            if (carta1.densidadepopulacional > carta2.densidadepopulacional)
                printf("Carta 1 venceu na densidade populacional!\n");
            else if (carta2.densidadepopulacional > carta1.densidadepopulacional)
                printf("Carta 2 venceu na densidade populacional!\n");
            else
                printf("Empate na densidade populacional.\n");
            break;

        case 5:
            printf("\nComparando pontos turísticos...\n");
            printf("Carta 1: %d | Carta 2: %d\n", carta1.turismo, carta2.turismo);
            if (carta1.turismo > carta2.turismo)
                printf("Carta 1 venceu nos pontos turísticos!\n");
            else if (carta2.turismo > carta1.turismo)
                printf("Carta 2 venceu nos pontos turísticos!\n");
            else
                printf("Empate nos pontos turísticos.\n");
            break;

        case 0:
            printf("Saindo da comparação...\n");
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }
}

int main() {
    // Cria duas cartas e mostra elas
    Carta carta1 = criarCarta(1);
    Carta carta2 = criarCarta(2);

    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}