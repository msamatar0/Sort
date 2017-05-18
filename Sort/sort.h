#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;

void p1(const size_t size);
void p2(const size_t size);
template<class type, class comparator> void heapSort(type *arr, size_t size, comparator comp);
template<class type, class comparator> int mergeSort(type *arr, size_t l, size_t r, comparator comp);
template<class type, class comparator> int merge(type *arr, size_t left, size_t mid, size_t right, comparator comp);
template<class type, class comparator> void quickSort(type *arr, size_t left, size_t right, comparator comp);
template<class type, class comparator> void bucketSort(type *arr, size_t size, comparator comp);
template<class type, class comparator> void radixSort(type *arr, size_t size, comparator comp);
void print(int *arr);
