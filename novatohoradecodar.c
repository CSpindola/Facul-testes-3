#include <stdio.h>

int main() {
    int idade, matricula;
    float altura;
    char nome[50];

    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    printf("Digite sua matrícula: \n");
    scanf("%d", &matricula);

    printf("Digite sua altura (em metros): \n");
    scanf("%f", &altura);

    printf("Digite seu nome: \n");
    // Usa scanf com largura máxima para evitar buffer overflow
    scanf("%49s", nome);

    printf("Nome do Aluno: %s\n", nome);
    printf("Matrícula: %d\n", matricula);
    // Corrigido 'print' para 'printf'
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f metros\n", altura);

    return 0;
}
