#include<stdio.h>
/*
+ Bộ nhớ RAM chứa rất nhiều ô nhớ, mỗi ô nhớ có kích 
thước mỗi ô nhớ có kích thước 1 byte
+ Địa chỉ có value được lưu trữ ở hệ thập lục phân
(hexadecimal)
+ Con trở trong lập trình C:
Con trỏ không có kiểu dữ liệu, con trỏ chỉ trỏ đến địa chỉ,
địa chỉ nào cũng giống nhau, địa chỉ KHÔNg có kiểu dữ liệu: int,
float, double,....
Công thức dùng: 
<Kiểu dữ liệu>* <tên con trỏ>
- Đặt địa chỉ của biên vào con trỏ sử dụng toán tử &
<Tên con trỏ> =& <tên biển>
+ Kích thước con trỏ:
Con trỏ chỉ lưu địa chỉ lên kích thước của mọi con trỏ là 
như nhau 2byte
- Truy xuất/ Trỏ đến địa chỉ đó để
 - LẤY GIÁ TRỊ dùng dấu *
*<tên con trỏ>
-   LẤY ĐỊA CHỈ dùng &
&giá trị

*/

void KhaiBaoBien(){
    int* ptr; //khai báo 1 con trỏ
    //pointer có tên là ptr, trỏ đến vùng dữ liệu có kiểu int
    int a;
    float* ptr1;
    int b = 9;
    //ptr1 ở đây là con trỏ và b là biến
    int c = 7;
    int* ptr2 = NULL;// null không trỏ vào đâu
    int* ptr3 ;
    ptr3 = &b;
    //In ra giá trị và in địa chị của biến c
    printf("Gia tri cua c=%d\n", c);
    printf("địa chỉ của biến c có kiểu dữ liệu là HEX= %p\n",&c);
    // printf("địa chỉ của biến c có kiểu dữ liệu là HEX= %x",&c);
    //%p là để in ra 1 địa chỉ có kiểu HEX

    //lấy giá trị của con trỏ ptr3
     printf("dia chi cua con tro ptr3 dang tro den b:  %p\n",ptr3);
      printf("giá trị cua con tro ptr3 dang tro den b: %d\n",*ptr3);
}
void sizeConTro(){
    printf("Sizeof(char*)=%d\n",sizeof(char*));
    printf("Sizeof(int*)=%d\n",sizeof(int*));
    printf("Sizeof(long*)=%d\n",sizeof(long*));
}

// tìm số lớn hơn trong 2 số a và b
void timSoLonHon(){
    int* ptr;
    int a,b;
    //nếu a>b con trỏ ptr sẽ được gán gtri địa chỉ của biến a
    printf("Nhập a,b=");
    scanf("%d%d",&a,&b);
    if(a>b){
        ptr = &a;
    }else{
        ptr = &b;
    }
    //In ra kết quả 
    printf("số lơn hơn là : %d\n",*ptr);
}


//Tìm số lớn nhát trong 3 số
int timMax(int* a, int* b , int* c){
int max = *a;
if(*b>max){
max = *b;
}
if (*c>max){
   max = *c;
}
return max;
}


//Thuat toan BubbleSort
//ham hoa doan 2 gia tri a,b
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    //hoan vi
}


void bubbleSort(int* arr, int n){
    //sap xep
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i ; j++)
        {
           if(arr[j] > arr[j+1]){
             swap(&arr[j], &arr[j+1]);

           }
        }   
    }
for (int i = 0; i < n; i++)
{
    printf("%d\t ", arr[i]);
}
}


int main() {
    int arr[]= {6,43,8,4,3,-9};
    int n = sizeof(arr)/sizeof(arr[0]);//so luong phan tu cua mang
    bubbleSort(arr,n);
    KhaiBaoBien();
    sizeConTro();
    timSoLonHon();
    int a,b,c;
    printf("Nhap abc =");
    scanf("%d%d%d",&a,&b,&c);
    printf("Gia tri lon nhat: %d\n",timMax(&a,&b,&c));
        return 0;
   
}