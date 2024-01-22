#include<iostream>
using namespace std;

void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int left[nl], right[nr];
   for(i = 0; i<nl; i++)
      left[i] = array[l+i];
   for(j = 0; j<nr; j++)
      right[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   while(i < nl && j<nr) {
      if(left[i] <= right[j]) {
         array[k] = left[i];
         i++;
      }else{
         array[k] = right[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       
      array[k] = left[i];
      i++; k++;
   }
   while(j<nr) {   
      array[k] = right[j];
      j++; k++;
   }
}
void mergeSort(int *array, int left, int right) {
   int m;
   if(left < right) {
      int m = left+(right-left)/2;
      mergeSort(array, left, m);
      mergeSort(array, m+1, right);
      merge(array, left, m, right);
   }
}
void print(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int main() {
   int n;
   cout << "Enter no. of elements: ";
   cin >> n;
   int arr[n];  
   cout << "Enter the elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "before Sorting: ";
   print(arr, n);
   mergeSort(arr, 0, n-1);     
   cout << "after Sorting: ";
   print(arr, n);
}