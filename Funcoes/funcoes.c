#include <stdio.h>
#include "funcoes.h"

// Função que recebe os dados dos estudantes e armaezena no vetor recebido
void recebeDados(Estudante v[], int tam){
  int i;
  // Laço para receber dados dos estudantes
  for(i = 0; i < tam; i++){
    do{
      printf("\nEntre com a idade do estudante %d: ", i + 1);
      scanf("%d", &v[i].idade);
      printf("Entre com a nota 1 do estudante %d: ", i + 1);
      scanf("%f", &v[i].notas[0]);
      printf("Entre com a nota 2 do estudante %d: ", i + 1);
      scanf("%f", &v[i].notas[1]);
      printf("Entre com a frequência do estudante %d: ", i + 1);
      scanf("%f", &v[i].frequencia);
      printf("\n\n");
    }while(verificaDados(v[i]) != 4);
  }
}

// Função que apresenta o menu na tela
void apresentaMenu(void){
   // Opções do menu
    printf("Opção 1: Média de idade da turma;\n");
    printf("Opção 2: Média de frequência da turma;\n");
    printf("Opção 3: Quantidade de reprovados por frequência;\n");
    printf("Opção 4: Quantidade de aprovados por média final;\n");
    printf("Opção 5: Média da Média Final da turma;\n");
    printf("Opção 6: Maior Média Final da turma;\n");
    printf("Opção 7: Menor Média Final da turma;\n");
    printf("Opção 8: Finaliza o programa.\n");
    printf("Entre com o opção desejada: ");
}

// Função que calcula a média de idade entre os estudantes
float mediaIdade(Estudante v[], int tam){
  float media;
  int i, idades;
  
  for(i=0; i<tam; i++){
    idades = idades + v[i].idade;
  }

  media = idades/tam;
  return media;
}

// Função que retorna a média de frequência dos estudantes
float mediaFrequencia(Estudante v[], int tam){
  float media;
  int i, freq;
  
  for(i=0; i<tam; i++){
    freq = freq + v[i].frequencia;
  }

  media = freq/tam;
  return media;
}

// Função que retorna a quantidade de estudantes com frequência menor de 75%
int quantidadeReprovadosFreq(Estudante v[], int tam){
  int i;
  float alunos_faltantes;

  for(i=0; i<tam; i++){
    if(v[i].frequencia < 75.0){
      alunos_faltantes++;
    }
  }

  return alunos_faltantes;
}

// Função que retorna a quantidade de estudantes com média final >= 6,0 e frequência maior ou igual a 75%
int quantidadeAprovados(Estudante v[], int tam){
  int i;
  float alunos_aprovados;

  for(i=0; i<tam; i++){
    if((v[i].frequencia >= 75.0) && (calculaMediaFinal(v[i]) >= 6.0)){
      alunos_aprovados++;
    }
  }
  return alunos_aprovados;
}

// Função que retorna a média das médias finais da turma
float mediaDaTurma(Estudante v[], int tam){
  float media_turma;
  int i, soma;
  
  for(i=0; i<tam; i++){
    soma = soma + calculaMediaFinal(v[i]);
  }

  media_turma = soma/tam;
  
  return media_turma;
}

// Função que retorna a maior média final entre os estudantes
float maiorMediaFinal(Estudante v[], int tam){
  float maior, media;
  int i;

  maior = 0;

  for(i = 0; i < tam; i++){
    media = calculaMediaFinal(v[i]);
    if(media > maior) maior = media;
  }
  return maior;
}

// Função que retorna a menor média final entre os estudantes
float menorMediaFinal(Estudante v[], int tam){
  float menor, media;
  int i;

  menor = 10;

  for(i = 0; i < tam; i++){
    media = calculaMediaFinal(v[i]);
    if(media < menor){
      menor = media;
    }
  }
  return menor;
}

// Função que calcula a média das notas dos estudantes
float calculaMediaFinal(Estudante v){
  return (v.notas[0] * 0.4) + (v.notas[1] * 0.6);
}

//Verificação dos dados na entrada
int verificaDados(Estudante v){
  int verifica = 0;
  
  if(v.idade > 0){
    printf("\nIdade ok");
    verifica++;
  }else{
    printf("\nIdade Invalida");
  }


  if(v.notas[0] >= 0 && v.notas[0] <= 10){
    printf("\nNota 1 ok");
    verifica++;
  }else{
    printf("\nNota 1 Invalida");
  }

  if(v.notas[1] >= 0 && v.notas[1] <= 10){
    printf("\nNota 2 ok");
    verifica++;
  }else{
    printf("\nNota 2 Invalida");
  }

  
  if(v.frequencia > 0.0 && v.frequencia < 100.0){
    printf("\nFrequencia ok");
    verifica++;
  }else{
    printf("\nFrquencia Invalida");
  }
    
  return verifica;
}
