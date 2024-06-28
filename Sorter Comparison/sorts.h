// Justin Singsanavong
#ifndef SORTS_H_
#define SORTS_H_
#include <vector>
using namespace std;

void Merge(vector<int>& vec, int first, int mid, int last)
{
	int size = last - first + 1;
	int* tmp_arr;
	tmp_arr = new int[size];
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	int index = 0;
	while ((first1 <= last1) && (first2 <= last2))
	{
		if (vec[first1] < vec[first2])
		{
			tmp_arr[index] = vec[first1];
			first1++;
		}
		else
		{
			tmp_arr[index] = vec[first2];
			first2++;
		}
		index++;
	}
	while (first1 <= last1)
	{
		tmp_arr[index] = vec[first1];
		first1++;
		index++;
	}
	while (first2 <= last2)
	{
		tmp_arr[index] = vec[first2];
		first2++;
		index++;
	}
	for (index = 0; index < size; index++)
	{
		vec[first] = tmp_arr[index];
		first++;
	}
	delete[] tmp_arr;
}

void MergeSort(vector<int>& vec, int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MergeSort(vec, first, mid);
		MergeSort(vec, mid + 1, last);
		Merge(vec, first, mid, last);
	}
}

void IterativeMergeSort(vector<int>& vec, int first, int last) {
	if (first >= last) {
		return;
	}

	vector<int> temp(vec.size());
	for (int width = 1; width < (last - first + 1); width *= 2) {
		for (int i = first; i <= last; i += 2 * width) {
			int left = i;
			int mid = min(i + width - 1, last);
			int right = min(i + 2 * width - 1, last);
			int k = left;
			int j = mid + 1;

			for (int l = left; l <= right; l++) {
				temp[l] = vec[l];
			}

			for (int l = left; l <= right; l++) {
				if (k > mid) {
					vec[l] = temp[j++];
				}
				else if (j > right) {
					vec[l] = temp[k++];
				}
				else if (temp[k] < temp[j]) {
					vec[l] = temp[k++];
				}
				else {
					vec[l] = temp[j++];
				}
			}
		}
	}
}

void InsertionSort(vector<int>& vec, int first, int last) {
	for (int i = first; i <= last; i++) {
		int temp = vec[i];
		int j = i - 1;
		while (j >= first && vec[j] > temp) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = temp;
	}
}

void QuickSort(vector<int>& vec, int first, int last) {
	if (last - first < 5) {
		InsertionSort(vec, first, last);
		return;
	}
	int mid = (first + last) / 2;
	if (vec[first] > vec[last]) {
		swap(vec[first], vec[last]);
	}
	if (vec[first] > vec[mid]) {
		swap(vec[first], vec[mid]);
	}
	if (vec[mid] > vec[last]) {
		swap(vec[mid], vec[last]);
	}
	int pivot = vec[mid];
	swap(vec[mid], vec[last - 1]);
	int left = first + 1;
	int right = last - 2;
	bool done = false;
	while (!done) {
		while (vec[left] < pivot) {
			left++;
		}
		while (vec[right] > pivot) {
			right--;
		}
		if (right > left) {
			swap(vec[left], vec[right]);
			left++;
			right--;
		}
		else {
			done = true;
		}
	}
	swap(vec[left], vec[last - 1]);
	QuickSort(vec, first, left - 1);
	QuickSort(vec, left + 1, last);
}

void ShellSort(vector<int>& arr, int first, int last) {
	for (int gap = (last - first + 1) / 2; gap > 0; gap = (gap == 2) ? 1 : int(gap / 2.2))
	{
		for (int i = first + gap; i <= last; i++)
		{
			int tmp = arr[i];
			int j = i;
			for (; (j >= first + gap) && (tmp < arr[j - gap]); j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = tmp;
		}
	}
}

void BubbleSort(vector<int>& arr, int first, int last) {
	for (int i = 0; i <= last; i++) {
		for (int j = first; j <= last - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}
#endif
