#include <iostream>

void insertion_sort(int array[], int array_size);

void print_array(int arr[], int n);

void insertion_sort(int array[], int array_size){
    
    int i, j, key;
// {12,40,32,1,0,22,69,16,8,14,12,31};
    for (i = 1; i < array_size; i++) // O(n)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) // O(n)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j+1] = key;
        
    }

}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 54, 4, 16, 32, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    insertion_sort(arr, n);
    print_array(arr, n);
 
    return 0;
}

void print_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

