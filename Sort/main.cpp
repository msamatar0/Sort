#include "sort.h"

int main(){
	int order[SIZE], rev[SIZE], random[SIZE];
	auto less = [](int a, int b){ return a - b; };

	//Initialize all three arrays
	for(int i = 0; i < SIZE; ++i){
		order[i] = i + 1;
		rev[SIZE - (i + 1)] = i + 1;
		random[i] = 1 + rand() % SIZE;
	}

	heapSort(order, SIZE, less);
	heapSort(rev, SIZE, less);
	heapSort(random, SIZE, less);
}

template<class type, class comparator>
inline void heapSort(type *arr, size_t size, comparator compare){
	priority_queue<type, comparator> heap(compare);
	for(int i = 0; i < size; ++i)
		heap.push(arr[i]);
	for(int i = 0; i < size; ++i){
		arr[i] = heap.top();
		heap.pop();
	}
}