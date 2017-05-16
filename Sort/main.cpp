#include "sort.h"

int main(){
	srand(time(nullptr));
	int order[SIZE], rev[SIZE], random[SIZE];
	//Comparator
	auto less = [](auto a, auto b){ return a < b; };
	//Used in heapsort to correctly order priority queue
	auto greater = [](auto a, auto b){ return a > b; };
	
	//Initialize arrays
	auto init = [&](size_t size){
		for(int i = 0; i < size; ++i){
			order[i] = i + 1;
			rev[size - (i + 1)] = i + 1;
			random[i] = 1 + rand() % size;
		}
	};

	init(SIZE);
	cout << "Arrays:\n";
	print(order);
	print(rev);
	print(random);

	cout << "\nP1 - Quick Sort\n";
	quickSort(order, 0, SIZE - 1, less);
	quickSort(rev, 0, SIZE - 1, less);
	quickSort(random, 0, SIZE - 1, less);
	print(order);
	cout << "\nP2 - Heap/Merge\n";

	cout << "\nHeap Sort\n";
	init(SIZE);
	heapSort(order, SIZE, greater);
	heapSort(rev, SIZE, greater);
	heapSort(random, SIZE, greater);
	print(order);
	print(rev);
	print(random);

	cout << "\nMerge Sort\n";
	init(SIZE);
	mergeSort(order, 0, SIZE - 1, less);
	mergeSort(rev, 0, SIZE - 1, less);
	mergeSort(random, 0, SIZE - 1, less);
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
		int mid = (l + (r - 1)) / 2;
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
		if(comp(larr[i], rarr[j]))
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

template<class type, class comparator>
void quickSort(type *arr, size_t left, size_t right, comparator comp){
	if(left >= right)
		return;
	size_t pidx = (left + (right - 1)) / 2;
	//size_t pidx = rand() % right;
	//size_t pidx = left;
	type pivot = arr[pidx];
	int i = left, j = right;
	while(i <= j){
		while(comp(arr[i], pivot))
			i++;
		while(comp(pivot, arr[j]))
			j--;
		if(i <= j){
			type temp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = temp;
		}
	}
	if(left < j)
		quickSort(arr, left, j, comp);
	if(i < right)
		quickSort(arr, i, right, comp);
}

template<class type, class comparator>
void bucketSort(type *arr, size_t size, comparator comp){
	;
}

template<class type, class comparator>
void radixSort(type *arr, size_t size, comparator comp){
	;
}

//Print an array
void print(int *arr){
	for(int i = 0; i < 5; ++i)
		cout << arr[i] << " ";
	cout << endl;
}