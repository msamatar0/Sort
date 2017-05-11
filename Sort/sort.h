#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#define SIZE 1000
using namespace std;

void init(int *order, int *rev, int *random, size_t size);
template<class type, class comparator> void heapSort(type *arr, size_t size, comparator comp);
template<class type, class comparator> void mergeSort(type *arr, size_t l, size_t r, comparator comp);
template<class type, class comparator> void merge(type *arr, size_t left, size_t mid, size_t right, comparator comp);
template<class type, class comparator> void quickSort(type *arr, size_t left, size_t right, comparator comp, size_t pivot);
void print(int *arr);
