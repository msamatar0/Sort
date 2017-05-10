#include "sort.h"

int main(){
	srand(time(nullptr));
	int order[SIZE], rev[SIZE], random[SIZE];
	auto comparator = [](auto a, auto b){ return a > b; };

	//Initialize all three arrays
	for(int i = 0; i < SIZE; ++i){
		order[i] = i + 1;
		rev[SIZE - (i + 1)] = i + 1;
		random[i] = 1 + rand() % SIZE;
	}

	cout << "P1 - Heap Sort\n";
	heapSort(order, SIZE, comparator);
	heapSort(rev, SIZE, comparator);
	heapSort(random, SIZE, comparator);
	print(order);
	print(rev);
	print(random);

	//Initialize all three arrays, again
	for(int i = 0; i < SIZE; ++i){
		order[i] = i + 1;
		rev[SIZE - (i + 1)] = i + 1;
		random[i] = 1 + rand() % SIZE;
	}

	cout << "\nP2 - Merge Sort\n";
	mergeSort(order, 0, SIZE, comparator);
	mergeSort(rev, 0, SIZE, comparator);
	mergeSort(random, 0, SIZE, comparator);
	print(order);
	print(rev);
	print(random);
}

template<class type, class comparator>
inline void heapSort(type *arr, size_t size, comparator comp){
	priority_queue<int, vector<int>, decltype(comp)> heap(comp);
	for(int i = 0; i < size; ++i)
		heap.push(arr[i]);
	for(int i = 0; i < size; ++i){
		arr[i] = heap.top();
		heap.pop();
	}
}

template<class type, class comparator>
void mergeSort(type *arr, size_t l, size_t r, comparator comp){
	if(l < r){
		int mid = l + (r - 1) / 2;
		mergeSort(arr, l, mid, comp);
		mergeSort(arr, mid + 1, r, comp);
		merge(arr, l, mid, r, comp);
	}
}

template<class type, class comparator>
void merge(type *arr, size_t left, size_t mid, size_t right, comparator comp){
	int i, j, k,
		lsize = mid - left + 1,
		rsize = right - mid,
		*larr = new int[lsize],
		*rarr = new int[rsize];

	for(i = 0; i < lsize; i++)
		larr[i] = arr[left + i];
	for(j = 0; j < rsize; j++)
		rarr[j] = arr[mid + 1 + j];

	i = 0, j = 0, k = left;
	while(i < lsize && j < rsize)
		if(comp(rarr[j], larr[i]))
			arr[k++] = larr[i++];
		else
			arr[k++] = rarr[j++];

	while(i < lsize)
		arr[k++] = larr[i++];
	while(j < rsize)
		arr[k++] = rarr[j++];

	delete[] larr;
	delete[] rarr;
}

void print(int *arr){
	for(int i = 0; i < 5; ++i)
		cout << arr[i] << " ";
	cout << endl;
}