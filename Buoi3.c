#include <stdio.h>
#include <stdlib.h>
//Quản lý bộ nhớ động malloc(), calloc(), realloc()
//free() giả phóng bộ nhớ động
//trong C++ new delete 
/*
Con trỏ và mảng 1 chiều
Khi sử dụng con trỏ chúng ta sẽ cấp phát động cho mảng
1 chiều -> mảng động 
Lưu ý: KHÔNG thể thực hiện các phép toán * / % 
cho con trỏ

*/
void nhapMang(int* arr, int n){
    for(int i=0; i<n; i++){
        printf("Nhap vao arr[%d]= ", i);
        // scanf("%d",&arr[i]); Cách 1
        scanf("%d",arr);
        arr++;
    }
}

void inMang(int *arr,  int n){
    for(int i=0; i<n; i++){
        printf("%d\t",*arr);
        arr++;//Di chuyen con tro sang vi tri ke tiep
    }
}
// 1 4 8 6 Thêm số 21 vào sau số 4, vi tri thu 2
// 1 4 21 8 6
void themPhanTu(int *arr, int n, int viTriThem, int giaTriThem ){
    n++;//Kích thước thay đổi
    //Bộ nhớ thay đổi
    //Sử dụng hàm realloc() để thay dổi kích thước bộ nhớ được cấp phát
    arr = (int*)realloc(arr, n*sizeof(int));//Tính theo byte 
    for(int i = n-1; i>viTriThem; i--){
        arr[i] = arr[i-1];
    }
    //Thêm phần tử mới vào vị trí chèn
    arr[viTriThem] = giaTriThem;
}

void xoaPhanTu(int *arr, int n, int viTriXoa){
    // 1 3 7 9 11 
    for(int i = viTriXoa; i< n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;
    arr = (int*)realloc(arr, n*sizeof(int));
}

int main(){ 
   int* arr;
    int n;
    do{
        printf("Nhap vao phan tu:");
        scanf("%d",&n);
        if(n<0){
            printf("So luong ban nhap khong le\n");
        }
    }while (n<0);
//CẤP PHÁT ĐỘNG vùng nhớ
//Sử dụng hàm malloc() để Cấp Phát bộ nhớ
    arr = (int*)malloc(n*sizeof(int*));
    //(tên con trỏ) = (kieudulieu*)malloc(sốlượngônhớ * sizeof(kieudukieu*));
    nhapMang(arr, n);
    inMang(arr, n);
    printf("\n");
    themPhanTu(arr, n, 2, 21);
    inMang(arr, n+1);
    printf("\n");
    xoaPhanTu(arr, n, 2);
    inMang(arr, n);
    if(arr != NULL){
        free(arr);
    }

    return 0;
}