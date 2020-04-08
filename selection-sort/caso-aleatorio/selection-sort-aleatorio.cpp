// Optimized implementation of Bubble sort 
#include <stdio.h> 
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;

void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   //get index of minimum data
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
         //placing in correct position
         swap(array[i], array[imin]);
   }
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
    arquivo= fopen ("resultado_selection_aleatorio.txt","a");
    fprintf(arquivo,"O tempo gasto para um vetor aleatorio com %i posições foi de ", n);
    fprintf(arquivo,"%i nanosegundos \n", tempo);
    return;
}
void CalcTempo(int arr[], int n){

	auto t1 =  chrono::high_resolution_clock::now();
  	selectionSort(arr, n); 
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
