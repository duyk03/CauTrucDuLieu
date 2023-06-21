#include<stdio.h>
/*
- Truyền THAM TRỊ là truyền GIÁ TRỊ của biến (Không phải địa chỉ ô nhớ)
- Giá trị khi thay đổi ở bên trong phương thức hiện hành thì bên ngoài giá trị không bị thay đổi
- Truyền THAM CHIẾU là truyền ĐỊA CHỈ ô nhớ của biến
- Giá trị khi thay đổi bên trong phương thức hiện hành thì bên ngoài cũng bị thay đổi
*/

void hoanDoiThamTri(int a, int b){
    //Hoán đổi
    int temp = a;
    a = b;
    b = temp;
    printf("Bên trong tham trị a = %d, b = %d\n",a,b);
}

void hoanDoiThamChieu(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
}
int main(){
    int a = 6;
    int b = 21;
    hoanDoiThamTri(a,b);
    printf("Ben ngoai tham tri a = %d, b = %d\n",a,b);
    hoanDoiThamChieu(&a, &b);
    printf("Bên ngoài tham Chieu a= %d, n = %d\n",a,b);

    return 0;
}