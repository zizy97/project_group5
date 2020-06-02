#include<stdio.h>

int partition(int arry[],int low,int high);
void quicksort(int arry[],int low,int high);
void swap(int* a,int* b);
void dispaly(int arry[],int high);

int p;

int main(){

	int data[10]={12,45,36,85,24,63,98,42,25,10};

	dispaly(data,10);
	quicksort(data,0,9);
	dispaly(data,10);
	
	return 0;
}

int partition(int arry[],int low,int high){

	int pivot,i;
	pivot=arry[high];
	i=low-1;

	for(int j=low;j<=high-1;j++){
		
		if(arry[j]<pivot){
	
			i++;
			swap(&arry[i],&arry[j]);
		}
			
	}
	swap(&arry[i+1],&arry[high]);
	
	return i+1;

}

void quicksort(int arry[],int low,int high){
	
	
	if(low<high){
		int p=partition(arry,low,high);
		//printf("hello");
	quicksort(arry,low,p-1);
	quicksort(arry,p+1,high);
	}
	
	


}

void swap(int* a,int* b){
	
	int temp = *a;
	*a = *b;
	*b = temp;
}

void dispaly(int arry[],int high){

	for(int i=0;i<high;i++){
		printf("%d\t",arry[i]);
	}
	printf("\n");
}
