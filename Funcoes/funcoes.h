typedef struct {
  int idade;
  float notas[2];
  float frequencia;
} Estudante;

void recebeDados(Estudante v[], int tam);
void apresentaMenu(void);
float mediaIdade(Estudante v[], int tam);
float mediaFrequencia(Estudante v[], int tam);
int quantidadeReprovadosFreq(Estudante v[], int tam);
int quantidadeAprovados(Estudante v[], int tam);
float mediaDaTurma(Estudante v[], int tam);
float maiorMediaFinal(Estudante v[], int tam);
float menorMediaFinal(Estudante v[], int tam);
float calculaMediaFinal(Estudante v);

//Funcao adicionada para verificar os dados de entrada

int verificaDados(Estudante v);