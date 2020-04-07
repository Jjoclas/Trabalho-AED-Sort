// Optimized implementation of Bubble sort 
#include <stdio.h> 
#include <time.h>
#include <chrono>
#include <iostream>
using namespace std;
void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// Versão otimizada do Bubble sort 
void bubbleSort(int arr[], int n) 
{ 
int i, j; 
bool swapped; 
for (i = 0; i < n-1; i++) 
{ 
	swapped = false; 
	for (j = 0; j < n-i-1; j++) 
	{ 
		if (arr[j] > arr[j+1]) 
		{ 
		swap(&arr[j], &arr[j+1]); 
		swapped = true; 
		} 
	} 

	// Se os elementos forem trocados o loop para
	if (swapped == false) 
		break; 
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
    arquivo= fopen ("tempo_bubble_aleatorio.txt","a");
    fprintf(arquivo,"O tempo gasto para um vetor aleatorio com %i posições foi de ", n);
    fprintf(arquivo,"%i nanosegundos \n", tempo);
    return;
}
void CalcTempo(int arr[], int n){

	auto t1 =  chrono::high_resolution_clock::now();
  	bubbleSort(arr, n); 
	auto t2 =  chrono::high_resolution_clock::now();
	auto duration =  chrono::duration_cast<chrono::nanoseconds>( t2 - t1 ).count();
	cout<<"O tempo para ordenarum vetor de "<<n<<" posicoes ";
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
