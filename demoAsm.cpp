#include<stdio.h>
#include<string.h>

struct SinhVien{
    char hoTen[25];
    char nganh[50];
    int ngay;
    int thang; 
    int nam;
};
 
void nhapSinhVien(SinhVien sv[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nhap vao ho ten: ");
        fflush(stdin);
        gets(sv[i].hoTen);
        printf("Nhap vao nganh:");
        gets(sv[i].nganh);
        printf("Nhap vao ngay/thang/nam:");
        scanf("%d/%d/%d", &sv[i].ngay,&sv[i].thang,&sv[i].nam);
    }
}

void xuat(SinhVien sv[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Ho ten la: %s", sv[i].hoTen);
        printf("Nganh la: %s", sv[i].nganh);
        printf("Ngay/thang/nam: %d/%d/%d", sv[i].ngay, sv[i].thang, sv[i].nam);
    }
}

void timKiemNganh(SinhVien sv[], int n){
    char nganhTim[50];
    printf("Nhap nganh can tim:");
    fflush(stdin);
    gets(nganhTim);
    for (int i = 0; i < n; i++)
    {
        if(strcasecmp(sv[i].nganh, nganhTim) ==0){
            printf("Ho ten la: %s", sv[i].hoTen);
            printf("Nganh la: %s", sv[i].nganh);
        }
    }
    
}

int main(){
    int n;
    SinhVien sv[5];
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    //check số lượng ko vượt qua 5
    nhapSinhVien(sv, n);
    xuat(sv, n);
    printf("\n");
    timKiemNganh(sv, n);
    return 0;
}