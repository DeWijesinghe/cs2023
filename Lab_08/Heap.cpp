#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int left_index = 2 * root +1;
   int right_index = 2 * root +2;

   int largest = root;

   if(left_index<n && arr[left_index]>arr[largest]){ 
      largest = left_index;
      }

   if(right_index<n && arr[right_index]>arr[largest]) {
      largest = right_index;
      }

   if(largest != root){
      swap(arr[root], arr[largest]);

      heapify(arr, n, largest);
   }


}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}


// implementing heap sort
void heapSort(int arr[], int n)
{

   //create the maxheap for the given array

   for(int j=n/2 -1; j>=0; j--){
      heapify(arr, n, j);
   }




      //swp the items to the end
       for (int i = n - 1; i > 0; i--) {


        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }

}


// main program
int main()
{


   //user inputs are stored in the vector
   vector<int> arr;


   string input;

    cout << "Enter your numbers seperated by white spaces and press enter: ";
    getline(cin, input);
   //conveting the numbers into a string stream
    istringstream is(input);
    int number;

    while(is >> number)
        arr.push_back(number);

   int n = arr.size();

   int heap_arr[n];

   for(int i=0; i<n;i++){
      heap_arr[i] = arr[i];
   }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
   return 0;
}