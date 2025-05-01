#include<iostream>
#include<vector>
using namespace std;


void selection_sort(vector<int>& arr)
{
    for(int i = 0; i < arr.size() - 1; i++) 
    {
        int min_index = i; 
        for(int j = i + 1; j < arr.size(); j++) 
        {
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]); 
        
    }
}


void merge(vector<int>& arr, int start, int mid, int end)
{
    int i = start; 
    int j = mid + 1; 
    vector<int> temp; 


    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j]) 
        {
            temp.push_back(arr[i++]); 
        }
        else 
        {
            temp.push_back(arr[j++]); 
        }
    }

    
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while(j <= end)
    {
        temp.push_back(arr[j++]);
    }
    for(int k = start; k <= end; k++)
    {
        arr[k] = temp[k - start];
    }
}


void merge_sort(vector<int>& arr, int start, int end)
{
    if(start >= end)
        return;

    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid); 
    merge_sort(arr, mid + 1, end); 
    merge(arr, start, mid, end); 
}


int linear_search(vector<int>& arr, int target)
{
    for(int i = 0; i < arr.size(); i++) 
    {
        if(arr[i] == target) 
        {
            return i;
        }
    }
    return -1; 
}


int binary_search(vector<int>& arr, int target)
{
    int start = 0; 
    int end = arr.size() - 1; 

    while(start <= end) 
    {
        int mid = (start + end) / 2; 

        if(arr[mid] == target) 
        {
            return mid; 
        }
        else if(arr[mid] < target) 
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1; 
        }
    }
    return -1; 
}



void print_array(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++) 
    {
        cout<<arr[i]<<" "; 
    }
    cout<<endl; 
}

int main()
{
    int choice, target, result; 
    vector<int> arr; 

    

        int n;
        cout<<endl;
        cout<<"Enter the size of array: "; 
        cin>>n;
        arr.resize(n); 
        for (int i = 0; i < arr.size(); i++) 
        {
            cout<<"Enter element of array ["<< i <<"]: ";
            cin>>arr[i];
        }
        cout<<endl<<"Array is: "; 
        print_array(arr); 


    do
    {
        cout<<endl;
        cout<<"****** Menu ******"<<endl;
        cout<<"1. Selection Sort"<<endl;
        cout<<"2. Merge Sort"<<endl;
        cout<<"3. Linear Search"<<endl;
        cout<<"4. Binary Search"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"*******************"<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:    
            cout<<endl<<"Array is: ";
            print_array(arr);

            selection_sort(arr); 
            cout<<"Sorted array using Selection Sort: ";
            print_array(arr); 

            break;

        case 2:
            cout<<endl<<"Array is: ";
            print_array(arr); 

            merge_sort(arr, 0, arr.size() - 1); 
            cout<<"Sorted array using Merge Sort: ";
            print_array(arr); 

            break;

        case 3:

            cout<<"Array is: ";
            print_array(arr); 

            if(arr.size() != 0) 
            {
                cout<<"Enter the target value to search: ";
                cin>>target; 
                result = linear_search(arr, target); 
            }
            else
            {
                cout<<"Array is Empty."<<endl; 
                break;
            }

            if (result != -1) {
                cout << "Element found at index: " << result << endl;
            } 
            else 
            {
                cout << "Element not found." << endl;
            }
            break;

        case 4:
            selection_sort(arr); 
            cout << "Sorted array: ";
            print_array(arr); 

            if(arr.size() != 0) 
            {
    
                cout << "Enter the target value to search: ";
                cin >> target;
                result = binary_search(arr, target); 
            }
            else
            {
                cout<<"Array is Empty."<<endl; 
                break;
            }

            if (result != -1) {
                cout << "Element found at index: " << result << endl;
            } 
            else 
            {
                cout << "Element not found." << endl;
            }
            break;

        case 0:
            cout<<"Exiting the program."<<endl; 
            break;

        default:
            cout<<"Invalid choice. Please try again."<<endl; 
            break;
        }

    } while (choice != 0); 

    return 0;
}