#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() Rj
{
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    /* Definição das variáveis para armazenar as propriedades das cidades */
    
    int carta1_populacao, carta2_populacao, carta1_numero_de_pontos_turisticos, carta2_numero_de_pontos_turisticos;
    float carta1_area, carta2_area, carta1_PIB, carta2_PIB;
    char carta1_Estado[50], carta2_Estado[50], carta1_Codigo_da_Carta[3], carta2_Codigo_da_Carta[3];
    char carta1_Nome_da_Cidade[50], carta2_Nome_da_Cidade[50];



    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    /* Cadastro da Carta 1 */
        printf ("Entre com o nome do Estado 1:\n");
        scanf ("%s", &carta1_Estado);

        printf ("Entre com o numero do Codigo da Carta:\n");
        scanf ("%s", &carta1_Codigo_da_Carta);

        printf ("Entre com o nome da Cidade:\n");
        scanf ("%s", &carta1_Nome_da_Cidade);

        printf ("Entre com a Área em m²:\n");
        scanf ("%f", &carta1_area);

        printf ("Entre com o PIB em R$ de 2024:\n");
        scanf ("%f", &carta1_PIB);

        printf ("Entre com a População total:\n");
        scanf ("%d", &carta1_populacao);

        printf ("Entre com o número de pontos turísticos:\n");
        scanf ("%d", &carta1_numero_de_pontos_turisticos);

    /* Cadastro da Carta 2 */
        printf ("Entre com o nome do Estado 2:\n");
        scanf ("%s", &carta2_Estado);

        printf ("Entre com o numero do Codigo da Carta:\n");
        scanf ("%s", &carta2_Codigo_da_Carta);

        printf ("Entre com o nome da Cidade:\n");
        scanf ("%s", &carta2_Nome_da_Cidade);

        printf ("Entre com a Área em m²:\n");
        scanf ("%f", &carta2_area);

        printf ("Entre com o PIB em R$ de 2024:\n");
        scanf ("%f", &carta2_PIB);

        printf ("Entre com a População total:\n");
        scanf ("%d", &carta2_populacao);

        printf ("Entre com o número de pontos turísticos:\n");
        scanf ("%d", &carta2_numero_de_pontos_turisticos);
    

    /* Exemplo:
    // printf("Digite o código da cidade: \n");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

/*Comparação de Cartas*/
    // Suponha que você tenha as variáveis populacaoA, populacaoB, etc., já definidas e preenchidas com os dados das cartas.

    if ( (carta1_PIB/carta1_populacao) > (carta2_PIB/carta2_populacao) )
        printf ("A cidade com maior PIB per Capita é: %s\n", carta1_Nome_da_Cidade);
        else 
            printf ("A cidade com maior PIB per Capita é: %s\n", carta2_Nome_da_Cidade);
    
        
    
    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);*/

    /* Exibição dos Resultados */
    printf("Resultados da Comparação:\n");
    printf("Cidade 1: %s\n", carta1_Nome_da_Cidade);
    printf("Cidade 2: %s\n", carta2_Nome_da_Cidade);

    return 0;
}