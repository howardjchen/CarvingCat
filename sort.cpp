#include <stdio.h>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> merge_both(vector<int>& left_sub, vector<int>& right_sub){
	vector<int> output;
	int left = 0;
	int right = 0;

	left_sub.push_back(INT_MAX);
	right_sub.push_back(INT_MAX);

	while (left_sub[left] != INT_MAX || right_sub[right] != INT_MAX) {
		if(left_sub[left] <= right_sub[right]){
			output.push_back(left_sub[left]);
			left++;
		} else {
			output.push_back(right_sub[right]);
			right++;
		}
	}

	return output;
}


vector<int> merge_sort(vector<int>& nums, int left, int right){
	vector<int> output;

	if(left == right){
		output.push_back(nums[left]);
		return output;
	}

	vector<int> left_sub, right_sub;
	int pivot = (left + right)/2;

	left_sub = merge_sort(nums, left, pivot);
	right_sub = merge_sort(nums, pivot+1, right);
	output = merge_both(left_sub, right_sub);

	return output;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void bubble_sort(vector<int>& nums) {
	bool clean = false;

	while(clean == false) {
		clean = true;
		for(int i = 0; i < nums.size()-1; i++) {
			if(nums[i] > nums[i+1]) {
				swap(nums[i], nums[i+1]);
				clean = false;
			}
		}
	}

	return;
}

vector<int> quick_sort(vector<int> list)
{
    if (list.size() < 2)
        return list;

    // random pivot
    //int pivot = list[(int)((double)rand() / (RAND_MAX + 1) * list.size())];
    //srand(rand());

    // middle pivot
    int pivot = list[list.size() / 2];
    list.erase (list.begin() + list.size() / 2);
    vector<int> less;
    vector<int> greater;
    vector<int> result;
    for(int i = 0;i < list.size();++i)
    {
        if (list[i] > pivot)
            greater.push_back(list[i]);
        else
            less.push_back(list[i]);
    }

    less = quick_sort(less);
	result.insert(result.begin(), less.begin(), less.end());

    result.push_back(pivot);

    greater = quick_sort(greater);
	result.insert(result.begin(), greater.begin(), greater.end());

    return result;
}

int main(void)
{
	vector<int>nums(10);
	vector<int> output;
	int n = nums.size();
	int i = 0;

	srand( time(NULL) );

	while(i < n) {
		nums[i] = rand()%1000;
		cout << nums[i] << " ";
		i++;
	}
	cout << endl;

	output = merge_sort(nums, 0, n-1);
    //bubble_sort(nums);
    //output = quick_sort(nums);

	for(i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	cout << endl;

	return 0;
}