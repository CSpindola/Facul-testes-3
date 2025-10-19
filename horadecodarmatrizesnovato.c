#include <stdio.h>
// Hora de Codar - Matrizes para Iniciantes
int main() {
 
    int index;
    char * nomesalunos = {
        {"aluno1", "Pt: 30", "Mat:90"},
        {"aluno2", "Pt: 50", "Mat:80"},
        {"aluno3", "Pt: 70", "Mat:70"},
        {"aluno4", "Pt: 90", "Mat:60"},
        {"aluno5", "Pt: 100", "Mat:50"}
    };
    printf("Digite o número do aluno para ver suas notas:\n");
    printf("0 - aluno1\n1 - aluno2\n2 - aluno3\n3 - aluno4\n4 - aluno5\n");
    scanf("%d", &index);

    printf("As notas do %s são: %s e %s\n", nomesalunos[index][0], nomesalunos[index][1], nomesalunos[index][2]);
    
    return 0;
}