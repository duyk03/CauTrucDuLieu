#include<stdio.h>
#include<stdlib.h>

/*
Tìm kiếm tuần tự lính canh và vét cạn
1 4 5 8 -9 4
x = 4
x = -9
*/

// int LinearSearch(int arr[], int n, int value){
//      for(int i = 0; i < n; i++){
//         if(arr[i] == value){
//             return i;  
//         }
//     }
//     return -1;  
// }

int LinearSearch(int arr[], int n, int value){
    for(int i = 0; i < n; i++){
        if(arr[i] == value)
        {
          return i;
            
        }
    }
    return -1;
     
    
}

int main(){
    int *arr;
    int n ;
    printf("Nhap so luong phan tu mang:");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int*));
    //Nhap mang
    for(int i = 0; i < n; i++){
        printf("Nhap arr[%d]", i);
        scanf("%d", &arr[i]);
    }
    int value;
    printf("Moi nhap gia tri can tim:");
    scanf("%d", &value);
    //nhap gia tri can tim
    int index = LinearSearch(arr, n, value);
    if(index == -1){
        printf("Khong tim thay gia tri trong mang");
    }else {
          printf("Vi tri: %d");
    }

    return 0;
}