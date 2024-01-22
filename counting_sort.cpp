#include<iostream>
#include<vector>
using namespace std;

vector<int> countSort(vector<int>&arr){
	int n = arr.size();
	int m = 0;

	for (int i = 0; i < n; i++)
		m = max(m, arr[i]);
	vector<int> carr(m + 1, 0);
	for (int i = 0; i < n; i++)
		carr[arr[i]]++;
	for (int i = 1; i <= m; i++)
		carr[i] += carr[i - 1];
	vector<int> ans(n);

	for (int i = n - 1; i >= 0; i--){
        ans[carr[arr[i]] - 1] =arr[i];
		carr[arr[i]]--;
	}

	return ans;
}

int main(){
	vector<int>arr= { 3,5,3,24,3,56,44,3,0};
	vector<int>res= countSort(arr);
	for (int i = 0; i < arr.size(); i++){
		cout << res[i] << " ";
    }
   
	return 0;

}
