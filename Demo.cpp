#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define sl 100

struct Date
{
    int ngay;
    int thang;
    int nam;
};
typedef Date date;

struct NhanVien{
    int msnv;
    char ho[20];
    char ten[20];
    date namSinh;
    char noiSinh[100];
    char diaChi[200];
    float luong;
    date ngayvao;
};
typedef NhanVien nhanvien;

struct DanhSach{
    nhanvien nv[sl];
    int n;
};
typedef DanhSach danhsach;

// --Nhap ngay thang nam-- //
void nhapNgayThang(date &ntn){
    printf("\nNhap ngay:");
    scanf("%d", &ntn.ngay);
    printf("\nNhap thang:");
    scanf("%d", &ntn.thang);
    printf("\nNhap nam:");
    scanf("%d", &ntn.nam);
}

// --Nhap nhan vien-- //
void nhapNhanVien(nhanvien &nv){
    printf("\nNhap vao Msnv: ");
    scanf("%d", &nv.msnv);
    printf("\nNhap vao ho: ");
    fflush(stdin);
    gets(nv.ho);
    printf("\nNhap vao ten: ");
    fflush(stdin);
    gets(nv.ten);
    printf("\nNhap nam sinh");
    nhapNgayThang(nv.namSinh);
    printf("\nNhap vao noi sinh: ");
    fflush(stdin);
    gets(nv.noiSinh);
    printf("\nNhap vao dia chi: ");
    fflush(stdin);
    gets(nv.diaChi);
    printf("\nNhap vao luong: ");
    fflush(stdin);
    scanf("%f", nv.luong);
    printf("\nNhap nam vao ");
    nhapNgayThang(nv.ngayvao);
}

// --Nhap danh sach-- //
void nhapDanhSach(danhsach &ds){
    printf("\nNhap vao so nhan vien");
    scanf("%d", &ds.n);
    printf("\n\tNhap vao thong tin nhan vien");
    for (int i = 0; i < ds.n ; i++)
    {
        printf("\n\n\tNhan vien thu %d", i + 1);
        nhapNhanVien(ds.nv[i]);
    }
}

// --Xuat ngay thang nam-- //
void xuatNgayThang(date ntn){
    printf("%d-", ntn.ngay);
     printf("%d-", ntn.thang);
      printf("%d", ntn.nam);
}

// --Xuat nhan vien-- //
void xuatNhanVien(nhanvien nv){
    printf("\nMa so nhan vien: %d", nv.msnv);
    printf("\nHo: %s", nv.ho);
    printf("\nTen: %s", nv.ten);
    printf("Nam sinh: ");
    xuatNgayThang(nv.namSinh);
    printf("Noi sinh: %s", nv.noiSinh);
    printf("\nDia chi: %s", nv.diaChi);
    printf("\nLuong: %.2f", nv.luong);
    printf("\nNam vao: ");
    xuatNgayThang(nv.ngayvao);
}

// --Xuat danh sach--
void xuatDanhSach(danhsach &ds){
    printf("\n\t\tDanh sach nhan vien");
    for (int i = 0; i < ds.n; i++)
    {
        printf("\n\t\tNhan vien thu %d", i + 1);
        xuatNhanVien(ds.nv[i]);
    }
}

// --Them nhan vien-- //
 void themNhanVien(danhsach &ds, nhanvien nv, int k){
    for (int i = ds.n; i >= k; i--)
    {
        ds.nv[i] = ds.nv[i-1];
    }
    ds.nv[k] = nv;
    ds.n--;
 }

// --Tim theo ma --
 int timTheoMa(danhsach ds, int d){
    for (int i = 0; i < ds.n; i++)
    {
        if(ds.nv[i].msnv == d){
            return i;
        }
    }
    return -1; 
 }

// --Tim theo ten --

void timTheoTen(danhsach ds, char *c){
    for (int i = 0; i < ds.n; i++)
    {
        if (strcasecmp(ds.nv[i].ten, c) == 0)
        {
             printf("Ho ten la: %s", ds.nv[i].ten);
        }
    }
}
 

// --Sap xep luong giam dan --

 

// --Xoa nhan vien --

 

void menu(){
    int index;
    int d, k;
    danhsach ds;
    nhanvien nv;
    nhapDanhSach(ds);
    xuatDanhSach(ds);
    do{
        printf("\n|==================MENU===============|");
        printf("\n|1. Them nhan vien                    |");
        printf("\n|2. Tim nhan vien theo ma so          |");
        printf("\n|3. Tim nhan vien theo ten            |");
        printf("\n|4. Bang luong cua nhan vien giam dan |");
        printf("\n|5. Xoa nhan vien                     |");
        printf("\n|=====================================|");
        printf("\nHay chon 1 chuc nang: ");
        scanf("%d", &index);
        switch (index)
        {
        case 1:
            {
                 
            }
        case 2: 
            {
                  
                break;
            }
        case 3: 
            {
                
                break;
            }
        case 4: 
            {
                 
                break;
            }
        case 5: 
            {
                
                break;
            }
        default: printf("Ban chon sai chuc nang vui long chon lai!");
        break;
        }
    }while(index != 5);
}

int main(){
    menu();
    getch();
}
