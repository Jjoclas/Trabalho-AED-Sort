/* C program for Merge Sort */
#include<stdlib.h> 
#include<stdio.h>
#include <chrono>
#include <iostream>
using namespace std; 

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 

/* UTILITY FUNCTIONS */
/* Função criar array*/
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
    arquivo= fopen ("resultado_MergeSort_ordenado.txt","a");
    fprintf(arquivo,"O tempo gasto para um vetor aleatorio com %i posições foi de ", n);
    fprintf(arquivo,"%i nanosegundos \n", tempo);
    return;
}
void CalcTempo(int arr[], int n){
	mergeSort(arr, 0, n-1);
	auto t1 =  chrono::high_resolution_clock::now();
  	mergeSort(arr, 0, n-1); 
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
/* Driver program to test above functions */
int main() 
{ 
	
	salvaVariosTempos(0,100000,5000);
	return 0; 
} 
