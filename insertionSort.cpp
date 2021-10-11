// C++ program for insertion sort

//IN THE INSERTION SORTING ALGORITHM, WE PICK UP A KEY ARR[1] ONWARDS; SLIDE ALL THE NUMBER(WHICH R  GREATER THAN THE KEY) TOWARDS THE RIGHT AND "INSERT" THAT KEY 
//IN THE SPACE HANCE CREATED.

#include <bits/stdc++.h>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i]; //SELECT THE FRIST UNSORTED ELEMENT`	
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key) //THIS LOOP SHIFT ALL THE ELEMENT TO THE RIGHT
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key; //IT INSERT THE UNSORTED ELEMENT IN THE SPACE CREATED
	}
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

/* Driver code */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}

