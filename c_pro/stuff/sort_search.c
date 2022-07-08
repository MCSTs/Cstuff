#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 20
#define ARR_BIGEST 30

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printarr(int *arr, char *ms)
{
	printf("%s", ms);
	for(int i=0; i<ARRSIZE; i++)
		printf("%d ", arr[i]);
	putchar('\n');
}

void rand_creatArray(int *arr)
{
	srand(time(NULL));
	for(int i=0; i<ARRSIZE; i++)
	{
		arr[i] = rand() % ARR_BIGEST +1;
	}
}

// Bubble_Sort
void bubbleSort(int *arr)
{
	for(int i=0; i<ARRSIZE; i++)
	{
		for(int j=0; j<ARRSIZE-1-i; j++)
		{
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}


// Quick_Sort
void quickSort(int *arr, int start, int end)
{
	if(start >= end)
		return;
	int pivot = arr[end];
	int index = start;
	for(int i=start; i<=end; i++)
	{
		if(arr[i] <= pivot)
		{
			swap(&arr[i], &arr[index]);
			index++;
		}
	}
	index--;

	quickSort(arr, start, index-1);
	quickSort(arr, index+1, end);
}

int binary_search(int *arr, int tar, int l, int r)
{
	int mid;
	while(l <= r)
	{
		mid = (l+r) / 2;

		if(arr[mid] == tar)
			return mid;
		else if(arr[mid] < tar)
			l = mid+1;
		else if(arr[mid] > tar)
			r = mid-1;
	}
	return -1;
}

int main(int argc, char **argv)
{
	int arr[ARRSIZE];

	rand_creatArray(arr);
	printarr(arr, "The source array is: ");

	//bubbleSort(arr);
	quickSort(arr, 0, ARRSIZE-1);
	printarr(arr, "Sorted array is: ");


	// search number

	putchar('\n');
	int tar, re;
	printf("enter a number to search in array\n");
	while(1)
	{
		printf("enter other number: ");
		if(scanf("%d", &tar)==0)
			break;
		re = binary_search(arr, tar, 0, ARRSIZE-1);
		if(re == -1)
			printf("The number is not found\n");
		else
			printf("The number's subscrip is %d in array\n", re);
	}

	return 0;
}
