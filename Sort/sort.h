#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <queue>
#include <functional>
#define SIZE 1000
using namespace std;

template<class type, class comparator> void heapSort(type *arr, size_t size, comparator comp);
template<class type, class comparator> void mergeSort(type *arr, size_t l, size_t r, comparator comp);
template<class type, class comparator> void merge(type *arr, size_t left, size_t mid, size_t right, comparator comp);
void print(int *arr);
