#include <stdio.h> //codigo da biblioteca

int main() {

char estado; //declarar a variavel para amarzenar o estado
char confirmacao;

do
{
    /* code */


printf("digite um estado(letra de A a h): "); //pede para o usuario digitar de A a H
scanf(" %c", &estado); //le a letra digitada e guarda na variavel

    printf("Você digitou o estado: %c. Está certo? (S/N): ", estado);
    scanf(" %c", &confirmacao); 
} while (confirmacao != 'S' && confirmacao != 's');

char carta; //declara a variavel da carta

printf("digite o numero da carta (de 1 a 4): ");
scanf(" %c", &carta);

char cidade[50]; //nome da cidade 

printf("digite um nome para cidade (de no maximo 50 caractere): ");
scanf(" %[^\n]", cidade);

int populacao;
char populacaopop;



do
{
    /* code */
printf("digite o numero da populacao (numero inteiro):  ");
scanf(" %d", &populacao);

printf("voce digitou a populacao: %d . esta certa? S/N; ", populacao);
scanf(" %c", &populacaopop);
 

} while (populacaopop != 'S' && populacaopop != 's');

float base, altura, area;

printf("digete a area da cidade  ");
scanf("%f", &base);

printf("digite a altura da cidade  ");
scanf("%f", &altura);

area= base* altura;

printf("area da cidade: %.2f\n", area);


float pib;

printf("digite o pib da cidade em milhoes por exemplo 1,5   ");
scanf("%f", &pib);

int turismo;

printf("digite o numero de pontos de turismo  ");
scanf("%d", &turismo);

printf("Você digitou %d pontos de turismo.\n", turismo);


// --- Mostrar resumo final ---
    printf("\n--- Resumo dos dados digitados ---\n");
    printf("Estado: %c\n", estado);
    printf("Número da carta: %c\n", carta);
    printf("Cidade: %s\n", cidade);
    printf("População: %d habitantes\n", populacao);
    printf("Área da cidade: %.2f\n", area);
    printf("PIB da cidade: %.2f milhões\n", pib);
    printf("Número de pontos de turismo: %d\n", turismo);


return 0;


}
