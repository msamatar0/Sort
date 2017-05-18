#include "sort.h"

int main(){
	srand(time(nullptr));

	cout << "\nP1 - Quick Sort\n";
	//p1(5000);
	//p1(10000);
	//p1(50000);

	cout << "\nP2 - Heap/Merge\n";
	p2(50000);
	p2(75000);
	
}

inline void p1(const size_t size){
	//Comparator
	auto less = [](auto a, auto b){ return a < b; };

	int *order = new int[size],
		*rev = new int[size],
		*random = new int[size];

	for(int i = 0; i < size; ++i){
		order[i] = i + 1;
		rev[size - (i + 1)] = i + 1;
		random[i] = 1 + rand() % size;
	}

	cout << "Arrays:\n";
	print(order);
	print(rev);
	print(random);

	quickSort(order, 0, size - 1, less);
	quickSort(rev, 0, size - 1, less);
	quickSort(random, 0, size - 1, less);
	
	print(order);
	print(rev);
	print(random);

	delete[] order;
	delete[] rev;
	delete[] random;
}

inline void p2(const size_t size){
	cout << "\nP2 - Heap/Merge\n";
	//Comparator
	auto less = [](auto a, auto b){ return a < b; };
	//Comparator used in heapsort to correctly order priority queue
	auto greater = [](auto a, auto b){ return a > b; };

	int *order = new int[size],
		*rev = new int[size],
		*random = new int[size];

	for(int i = 0; i < size; ++i){
		order[i] = i + 1;
		rev[size - (i + 1)] = i + 1;
		random[i] = 1 + rand() % size;
	}

	cout << "\nArrays:\n";
	print(order);
	print(rev);
	print(random);

	cout << "\nHeap Sort\nOrder:\n";
	heapSort(order, size, greater);
	print(order);
	cout << "Reverse:\n";
	heapSort(rev, size, greater);
	print(rev);
	cout << "Random:\n";
	heapSort(random, size, greater);
	print(random);

	cout << "\nMerge Sort\nOrder:\nTotal Statements: "
		<< mergeSort(order, 0, size - 1, less) << endl;
	print(order);
	cout << "Reverse:\nTotal Statements: " << mergeSort(rev, 0, size - 1, less)
		<< endl;
	print(rev);
	cout << "Random:\nTotal Statements: " << mergeSort(random, 0, size - 1, less)
		<< endl;
	print(random);
}

template<class type, class comparator>
inline void heapSort(type *arr, size_t size, comparator comp){
	priority_queue<int, vector<int>, comparator> heap(comp);
	int count = 0;
	for(int i = 0; i < size; ++i){
		count++;
		heap.push(arr[i]);
	}
	for(int i = 0; i < size; ++i){
		arr[i] = heap.top();
		heap.pop();
		count += 2;
	}
	cout << "Total Statements: " << count << endl;
}

template<class type, class comparator>
int mergeSort(type *arr, size_t l, size_t r, comparator comp){
	int msCount = 0;
	if(r - l <= 1)
		return msCount;
	int mid = l + (r - l) / 2;
	mergeSort(arr, l, mid, comp);
	mergeSort(arr, mid + 1, r, comp);
	msCount += merge(arr, l, mid, r, comp);
	return msCount;
}

template<class type, class comparator>
int merge(type *arr, size_t left, size_t mid, size_t right, comparator comp){
	int count = 1;
	int i, j, k,
		lsize = mid - left + 1,
		rsize = right - mid,
		*larr = new int[lsize],
		*rarr = new int[rsize];

	for(i = 0; i < lsize; i++){
		count++;
		larr[i] = arr[left + i];
	}
	for(j = 0; j < rsize; j++){
		count++;
		rarr[j] = arr[mid + 1 + j];
	}

	i = 0, j = 0, k = left;
	while(i < lsize && j < rsize){
		if(comp(larr[i], rarr[j])){
			count++;
			arr[k++] = larr[i++];
		}
		else{
			count++;
			arr[k++] = rarr[j++];
		}
	}

	while(i < lsize){
		arr[k++] = larr[i++];
		while(j < rsize){
			count++;
			arr[k++] = rarr[j++];
		}
	}
	delete[] larr;
	delete[] rarr;
	return count += 2;
}

template<class type, class comparator>
void quickSort(type *arr, size_t left, size_t right, comparator comp){
	static int qsCount = 0;
	if(left >= right){
		cout << "Total Statements: " << qsCount << endl;
		return;
	}
	type pivot = arr[
		left + (right - left) / 2
		//left + rand() % right
		//left
	];
	int i = left, j = right;
	qsCount += 3;

	while(i <= j){
		while(comp(arr[i], pivot)){
			i++;
			qsCount++;
		}
		while(comp(pivot, arr[j])){
			j--;
			qsCount++;
		}
		if(i <= j){
			type temp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = temp;
			qsCount += 3;
		}
	}

	if(left < j){
		qsCount++;
		quickSort(arr, left, j, comp);
	}
	if(right > i){
		qsCount++;
		quickSort(arr, i, right, comp);
	}
	cout << "Total Statements: " << qsCount << endl;
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
