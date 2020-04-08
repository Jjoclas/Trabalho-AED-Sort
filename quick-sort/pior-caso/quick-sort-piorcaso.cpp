#include <stdio.h> 
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
void quickSort(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) quickSort(vetor, inicio, j);
   if(i < fim) quickSort(vetor, i, fim);   

}
/* Função criar array*/
void GeraAleatorios(int numeros[], int quant, int limite){
    srand(time(NULL));

    for(int i=0;i<quant;i++){
        numeros[i]= rand() %limite;
    }
}
/* Funçao para printar o array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

void salvarTempo(int tempo, int n){
  	FILE *arquivo;
    arquivo= fopen ("resultado_quicksort_pior_caso.txt","a");
    fprintf(arquivo,"O tempo gasto para um vetor no pior caso com %i posições foi de ", n);
    fprintf(arquivo,"%i nanosegundos \n", tempo);
    return;
}
void CalcTempo(int arr[], int n){
    ordenaDecrescente(arr,n);
	auto t1 =  chrono::high_resolution_clock::now();
  	quickSort(arr,0, n); 
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

