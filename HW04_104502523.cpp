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
    if(length <= 1) return;
    int l = 1, r = length;
    while(1){
	while(l < r && a[l] < a[0]) l++;
	while(l < r && a[r - 1] >= a[0]) r--;
	if(l < r){
	    int temp = a[l];
	    a[l] = a[r - 1];
	    a[r - 1] = temp;
	}else break;
    }
    int temp = a[l - 1];
    a[l - 1] = a[0];
    a[0] = temp;
    quickSort(a, l);
    quickSort(&(a[l]), length - l);
}

void heapSort(int *a,int length){
    int *heap = new int[length], h_l = 0;
    for(int i = 0; i < length; i++){ // insert into heap
	heap[h_l++] = a[i];
	int index = h_l - 1;
	while((index - 1) >= 0 && heap[index] < heap[(index - 1) / 2]){
	    int temp = heap[index];
	    heap[index] = heap[(index - 1) / 2];
	    heap[(index - 1) / 2] = temp;
	    index = (index - 1) / 2;
	}
    }
    for(int i = 0; i < length; i++){ // pop from heap
	a[i] = heap[0];
	heap[0] = heap[--h_l];
	int index = 0;
	while(2 * index + 1 < h_l){
	    int child = 2 * index + 1;
	    if(child + 1 < h_l && heap[child + 1] < heap[child]) child++;
	    if(heap[index] > heap[child]){
		int temp = heap[index];
		heap[index] = heap[child];
		heap[child] = temp;
	    }
	    index = child;
	}
    }
}

void mergeSort(int *a,int length){
    if(length <= 1) return;
    int *temp = new int[length], t_l = 0;
    for(int i = 0; i < length; i++) temp[i] = a[i];
    int m = length / 2, l = 0, r = m;
    mergeSort(temp, m);
    mergeSort(&(temp[m]), length - m);
    while(t_l < length){
	if(l < m && (temp[l] < temp[r] || r == length)) a[t_l++] = temp[l++];
	else if(r < length) a[t_l++] = temp[r++];
    }
    delete temp;
    return;
}

