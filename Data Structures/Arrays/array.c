#include <stdio.h>

int test_pointers_arrays(){
    int numbers [5] = {1,2,3,4,5};
    int* member_pointer = &numbers[2];
    *member_pointer = 6;
    printf("%d",numbers[2]);
    return 0;
}

int print_array_elements(int * p_arr){

    printf("%d",p_arr);

    // int size = sizeof(arr) / sizeof(arr[0]);

    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d \n",arr[i]);
    // }

    return 0;
}

int main(){

    // declaring array
    int numbers_a [5] = {1,2,3,4,5};    

    print_array_elements(&numbers_a[0]);

    return 0;

}