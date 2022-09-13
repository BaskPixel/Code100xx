#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void bubble_sort(int arr[], int len) {
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
void swap(int* a, int* b) //交換兩個變數
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void selection_sort(int arr[], int len)
{
	int i, j;

	for (i = 0; i < len - 1; i++)
	{
		int min = i;
		for (j = i + 1; j < len; j++)     //走訪未排序的元素
			if (arr[j] < arr[min])    //找到目前最小值
				min = j;    //紀錄最小值
		swap(&arr[min], &arr[i]);    //做交換
	}
}
void insertion_sort(int arr[], int len) {
	int i, j, key;
	for (i = 1; i < len; i++) {
		key = arr[i];
		j = i - 1;
		while ((j >= 0) && (arr[j] > key)) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}
void shell_sort(int arr[], int len) {
	int gap, i, j;
	int temp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
}
int min(int x, int y) {
	return x < y ? x : y;
}
int Paritition1(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot) {
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot) {
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
void QuickSort(int A[], int low, int high) //快排母函数
{
	if (low < high) {
		int pivot = Paritition1(A, low, high);
		QuickSort(A, low, pivot - 1);
		QuickSort(A, pivot + 1, high);
	}
}
void merge_sort(int arr[], int len) {
	int* a = arr;
	int* b = (int*)malloc(len * sizeof(int));
	int seg, start;
	for (seg = 1; seg < len; seg += seg) {
		for (start = 0; start < len; start += seg * 2) {
			int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		int i;
		for (i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	free(b);
}

int Msort(int data[], int n, int m)
{
	bool flag;
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				int t = data[j];
				data[j] = data[j + 1];
				data[j + 1] = t;
			}
		}
	}
	return data[m - 1];
}
/*
int main()
{
	int data[10];
	for (int i = 0; i < 10; i++)
	{
		data[i] = rand() % 100;
		cout << data[i] << " ";
	}
	int len = (int)sizeof(data) / sizeof(*data);
	cout << Msort(data, len, 7);
	return 0;
}
*/