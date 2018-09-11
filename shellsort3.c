#include <stdio.h>
int divide(int tam)
{
  int i;
  if (tam % 2 == 0)
  {
    i = tam / 2;
  }
  else
  {
    i = (tam - 1) / 2;
  }
  return i;
}
void insertionSort(int *v, int tam)
{
  int i, j, aux = 0;

  for (i = 1; i < tam; i++)
  {
    aux = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > aux)
    {
      v[j + 1] = v[j];
      j = j - 1;
    }
    v[j + 1] = aux;
  }

  return v;
}

#include <stdlib.h>

int **classifica(int **result, int *v, int n, int ini, int nbalde, int d)
{

  int i, i3, i4, i5, i6, i7, i8, i9, i10;
  i3 = 0;
  i4 = 0;
  i5 = 0;
  i6 = 0;
  i7 = 0;
  i8 = 0;
  i9 = 0;
  i10 = 0;
  int id, in;
  int d1, d2;
  int quantity = 0;
  for (id = 0; id < nbalde; id++)
  {
    d1 = ini + id * d;
    d2 = d1 + d;
    in = 0;
    result[id][0] = 0;
    quantity = 0;
    for (i = 0; i < n; i++)
    {
      if (v[i] >= d1 && v[i] < d2)
      {
        result[id][0] = result[id][0] + 1;
        result[id] = (int *)realloc(result[id], 1 * sizeof(int));
        result[id][quantity] = v[i];
        quantity++;
      }
    }
  }
  return result;
}
void printarresult(int **result)
{
  int i, in;
  for (i = 0; i < 10; i++)
  {
    if (result[i][0] > 0)
    {
      for (in = 1; in <= result[i][0]; in++)
      {
        printf("%d\n", result[i][in]);
      }
    }
  }
}
void printarresultn(int **v, int tam)
{
  int i;
  for (i = 0; i < tam; i++)
  {
    printf(" esta e posicao %d com valor \n", i, v[i]);
  }
}

int *troca(int *vet)
{
  if (vet[0] > vet[1])
  {
    int temp;
    temp = vet[0];
    vet[0] = vet[1];
    vet[1] = temp;
  }
  return vet;
}
int *sheelsort1(int *v, int gap, int i)
{
  int *vet;
  vet = (int *)malloc(2 * sizeof(int));
  int pos1 = i + gap;
  printf(" a posição 1 do subvetor é %d\n", pos1);
  vet[0] = v[i];
  vet[1] = v[pos1];
  vet = troca(vet);
  v[i] = vet[0];
  v[pos1] = vet[1];
  free(vet);
  return v;
}
void sheelsortmaior1(int *v, int gap, int i, int tamsheel)
{ // aplicada depois da primeira rodada
  int *vet;
  vet = (int *)malloc(tamsheel * sizeof(int));
  int pos1 = i + gap;
  printf(" a posição 1 do subvetor é %d\n", pos1);
  int i2;
  for (i2 = 0; i2 <= tamsheel; i2++)
  {
    vet[i2] = v[i2 * gap];
  };
  insertionSort(vet, tamsheel);
  for (i2 = 0; i2 <= tamsheel; i2++)
  {
    v[i2 * gap] = vet[i2];
  };
  free(vet);
  return v;
}
int *sheelsort2(int gap, int tam, int isheel, int *v)
{
  int i;

  for (isheel = 0; isheel < gap; isheel++)
  {
    v = troca(v);
  }
  for (i = 0; i < tam; i++)
  {
    printf("posicao do vetor: %d valor do vetor: %d \n", i, v[i]);
  }
  return v;
}
int **subvetormaior2(int i, int gap, int tam, int *v)
{
  int tamsheel, isheel;
  printf("este  gap é o  :%d, %d", i, gap);
  if (tam % gap == 0)
  {
    tamsheel = tam / gap;
  }
  else
  {
    tamsheel = tamsheel + 1;
    tamsheel = tam / gap;
  }
  for (isheel = 0; isheel <= gap; isheel++)
  {
    sheelsortmaior1(v, gap, isheel, tamsheel);
  }
}
int *sheelsortg(int gap, int tam, int *v)
{
  int isheel, i;
  for (i = 0; i < tam; i++)
  {
    printf(" este o %d numero do vetor de valor %d", i, v[i]);
  }
  i = 2;
  int tamsheel;
  if (tam / gap <= 2)
  {
    sheelsort2(gap, tam, isheel, v);
  }
  else
  {
    while (gap > 1)
    {
      gap = divide(gap);
      subvetormaior2(i, gap, tam, v);
      for (i = 0; i < tam; i++)
      {
        printf("posicao do vetor: %d valor do vetor: %d \n", i, v[i]);
      }
      i++;
    }
  }
}
int main(int argc, char const *argv[])
{
  int i, *v, tam, valor_vetor, busca, resultado;
  int gap;
  printf("insira o tamanho do vetor \n");
  scanf("%d", &tam);
  v = (int *)malloc(tam * sizeof(int));
  int **result;
  int in, in2;
  result = (int **)malloc(10 * sizeof(int *));
  for (in2 = 0; in2 <= 10; in2++)
  {
    result[in2] = (int *)malloc(sizeof(int));
  }

  for (i = 0; i < tam; i++)
  {
    printf("insira o valor do vetor na posicao %d \n", i);
    scanf("%d", &valor_vetor);
    v[i] = valor_vetor;
  }
  int balde1, interbalde, ultimobalde;
  printf(" digite o valor do primeiro  balde");
  scanf("%d", &balde1);
  printf("digite o intervalo numerico entre os baldes");
  scanf("%d", &interbalde);
  printf("digite o valor do ultimo balde");
  scanf("%d", &ultimobalde);
  int nbalde;
  if (balde1 == 0)
  {
    nbalde = (ultimobalde - balde1) / interbalde;
  }
  else
  {
    nbalde = (ultimobalde - balde1 + 1) / interbalde;
  }
  printf("o numero de baldes é: %d\n", nbalde);

  result = classifica(result, v, tam, balde1, nbalde, interbalde);

  printf(" primeiro valor do primeiro balde %d\n", result[0][0]);
  printf("segundo valor do primeiro balde %d\n", result[0][1]);
  //insertionSort(v,tam);

  gap = divide(tam);
  printf("este e o gap:%d", gap);
  printf("%d", gap);
  int *v2;
  v2 = (int *)malloc(nbalde * sizeof(int));
  int i2;

  for (i = 0; i < nbalde; i++)
  {
    for (i2 = 0; i2 < nbalde; i2++)
    {
      v2[i2] = result[i][i2];
    }
    sheelsortg(gap, interbalde, v2);
    for (i2 = 0; i2 < nbalde; i2++)
    {
      result[i][i2] = v2[i2];
    }
  }

  free(result);
  free(v);
  return 0;
}
