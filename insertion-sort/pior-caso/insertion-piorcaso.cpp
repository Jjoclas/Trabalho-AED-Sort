#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;

void ordenaDecrescente(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho ; i++)
    {
        for (int j = i; j < tamanho ; j++)
        {
            if (vetor[i] < vetor[j])
            {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}
void InsertionSort(int *pVetor, int n)
{
    int vAux;
    int vTemp;
    int vTroca;

    for (vAux=1; vAux < n; vAux++) // vAux começa na posição 1 do vetor e vai até a ultima posição;
    {
        vTemp = vAux; // vTemp recebe a posição que está passando no "for";

        while (pVetor[vTemp] < pVetor[vTemp-1]) // Enquanto o valor que está passando na posição "vTemp" for menor que a posição "vTemp" menos 1, ocorre a troca;
        { // Ocorre a troca;
            vTroca          = pVetor[vTemp];
            pVetor[vTemp]   = pVetor[vTemp-1];
            pVetor[vTemp-1] = vTroca;
            vTemp--; // vTemp decrementa 1;

            if (vTemp == 0) // Quando "vTemp" chegar na posição 0, primeira posição do vetor, o laço while para;
                break;
        }

    }
}
void GeraAleatorios(int numeros[], int quant, int limite){
    srand(time(NULL));

    for(int i=0;i<quant;i++){
        numeros[i]= rand() %limite;
    }
}
/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 
void salvarTempo(int tempo, int n){
  	FILE *arquivo;
    arquivo= fopen ("resultado_insertion_sort_pior_caso.txt","a");
    fprintf(arquivo,"O tempo gasto para o vetor com um vetor no pior caso de %i posições foi de ", n);
    fprintf(arquivo,"%i nanosegundos \n", tempo);
    return;
}
void CalcTempo(int arr[], int n){
 	ordenaDecrescente(arr,n);
	auto t1 =  chrono::high_resolution_clock::now();
  	InsertionSort(arr, n); 
	auto t2 =  chrono::high_resolution_clock::now();
	auto duration =  chrono::duration_cast<chrono::nanoseconds>( t2 - t1 ).count();
	cout<<"O tempo para ordenar um vetor de "<<n<<" posicoes ";
	cout<<" O tempo gasto foi de " << duration<<" nanosegundos"<<"\n";
  	salvarTempo(duration, n);
}
void salvaVariosTempos(int NInicial, int Nmax, int Nsoma){
  while (NInicial <= Nmax)
  {
	int arr[NInicial];
	int n = sizeof(arr)/sizeof(arr[0]);
	int m= n*5;
	GeraAleatorios(arr,n,m); 
    CalcTempo(arr,NInicial);
    NInicial+=Nsoma; 
  }
}

int main()
{
    
    salvaVariosTempos(0,100000,5000);
    return 0;
}

