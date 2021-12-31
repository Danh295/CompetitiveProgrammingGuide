#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int h)
{
	int i, j, k;

	int n1 = mid - l + 1;
	int n2 = h - mid;
	int templ[n1], temph[n2];

	for (int i = 0; i < n1; i++)
		templ[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		temph[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (templ[i] <= temph[j])
		{
			arr[k] = templ[i];
			i++;
		}
		else
		{
			arr[k] = temph[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = templ[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = temph[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int h)
{
	if (l < h)
	{
		int mid = l + (h - l) / 2;

		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, h);

		merge(arr, l, mid, h);
	}
}

int main() 
{
	ios::sync_with_stdio(0);

	int arr[] = {12, 11, 13, 5, 6, 7};
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < arrSize; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";

	mergeSort(arr, 0, arrSize - 1);

	for (int i = 0; i < arrSize; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

