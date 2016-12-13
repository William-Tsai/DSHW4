#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

void bubbleSort(int *a,int length);     //Performing bubble sorting method with ascending order
void selectionSort(int *a,int length);  //Performing selection sorting method with ascending order
void quickSort(int *a,int length);      //Performing quick sorting method with ascending order
void heapSort(int *a,int length);       //Performing heap sorting method with ascending order
void mergeSort(int *a,int length);      //Performing merge sorting method with ascending order


int main()
{
    srand(time(NULL));
    int length = 200;
    int *ori= (int*)malloc(sizeof(int)*length);
    int *a= (int*)malloc(sizeof(int)*length);

    cout << "Prior : " << endl;
    for(int i=0; i<length; i++) {
        ori[i]=rand()%500+1;
        a[i]=ori[i];
        cout << ori[i] << " ";
    }
    cout << endl << endl;

    //bubbleSort
    cout << "bubbleSort:" << endl;
    bubbleSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    //selectionSort
    cout << "selectionSort:" << endl;
    selectionSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    //quickSort
    cout << "quickSort:" << endl;
    quickSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    //heapSort
    cout << "heapSort:" << endl;
    heapSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    //mergeSort
    cout << "mergeSort:" << endl;
    mergeSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    return 0;
}

void bubbleSort(int *a, int length){
    for(int i = 0; i < length; i++){
	for(int j = 0; j < length - i - 1; j++){
	    if(a[j] > a[j + 1]){
		int temp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = temp;
	    }
	}
    }
}

void selectionSort(int *a,int length){
    for(int i = 0; i < length; i++){
	int index = i, min = a[i];
	for(int j = i + 1; j < length; j++){
	    if(a[j] < min){
		min = a[j];
		index = j;
	    }
	}
	if(index != i){
	    int temp = a[i];
	    a[i] = a[index];
	    a[index] = temp;
	}
    }
}

void quickSort(int *a,int length){
}

void heapSort(int *a,int length){
}

void mergeSort(int *a,int length){
}

