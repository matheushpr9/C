#include <stdio.h>
#include "funcoes.h"

// TAM define a quantidade de pessoas
#define TAM 2

int main(void) {

  int opcao, i;
  Estudante turma[TAM];

  recebeDados(turma, TAM);

  do{
    
    apresentaMenu();
    scanf("%d", &opcao);

    // Switch-case para cada opção, sendo que cada opção chama funções
    switch (opcao){
      case 1:
        printf("Média de idade da turma: %f\n\n", mediaIdade(turma, TAM));
        break;
      case 2:
        printf("Média de frequência da turma: %f\n\n", mediaFrequencia(turma, TAM));
        break;
      case 3:
        printf("Quantidade de reprovados por frequência: %d\n\n", quantidadeReprovadosFreq(turma, TAM));
        break;
      case 4:
        printf("Quantidade de aprovados por média: %d\n\n", quantidadeAprovados(turma, TAM));
        break;
      case 5:
        printf("Média das Médias da Turma: %f\n\n", mediaDaTurma(turma, TAM));
        break;
      case 6:
        printf("Maior Média Final: %f\n\n", maiorMediaFinal(turma, TAM));
        break;
      case 7:
        printf("Menor Média Final: %f\n\n", menorMediaFinal(turma, TAM));
        break;
      case 8:
        printf("Finalizando...\n");
        break;
      default:
        printf("\nOpção inválida, entre novamente.\n\n");
    }

  } while(opcao != 8); // A opção 8 finaliza o programa
  
  return 0;
}