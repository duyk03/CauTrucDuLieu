#include <stdio.h>

/*
    Trong khoa học máy tính, một ngăn xếp (còn gọi là bộ xếp chồng, tiếng Anh: Stack)
    là một cấu trúc dữ liệu trừu tượng hoạt động theo nguyên lý “vào sau ra trước”
    (Last In First Out (LIFO). 
    Tức là, phần tử cuối cùng được chèn vào ngăn xếp sẽ là phần tử đầu tiên được lấy ra khỏi ngăn xếp.
    Push: Thêm một phần tử vào đỉnh của ngăn xếp, số phần tử của ngăn xếp tăng lên 1.
    Pop: Xóa bỏ phần tử đầu tiên ở đỉnh của ngăn xếp, số phần tử của ngăn xếp giảm đi 1.
    Top: Lấy giá trị của phần tử đầu tiên ở đỉnh của ngăn xếp, số phần tử của ngăn xếp không thay đổi.
    IsEmpty: Kiểm tra ngăn xếp trống hay không. Ngăn xếp trống là ngăn xếp không có phần tử nào.
    IsFull: Kiểm tra ngăn xếp đã đầy hay chưa. Thao tác này không phải lúc nào cũng có.
    Size: Lấy số lượng phần tử stack đang
*/

 int top = -1;


void push(int stack[],int value,int capacity){
    if(top >= capacity - 1){
        //Neu stack day => khong push duoc
        //Ngược lại thêm vào đỉnh ++top
        printf("Ham doi day"); 
        return;
    }else{
        ++top;
        stack[top] = value;
    }
}

void pop(int stack[], int value){
    if(top == -1){
        printf("Ham doi rong");
        return;
    }else{
        int value = stack[top];
        top--;    
    }
     
}

void display(int stack[]) {
    if (top == -1) {
        printf("Ham doi rong\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int timKiemSo(int arr[], int n, int value) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == value) {
            return i; 
        }
    }
    return -1; 
}

 

int main(){
    int capacity = 3; 
    int top = -1; 
    int stack[capacity];
    
    push(stack, 5, capacity); 
    push(stack, 6, capacity); 
    push(stack, 7, capacity); 
    display(stack);
    pop(stack, 6);
    return 0;
}