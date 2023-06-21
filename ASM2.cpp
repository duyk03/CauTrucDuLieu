#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
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

// --  Nhap ngay thang nam  --//
void nhapNgayThang(date &ntn){
    do{
        printf("\nNhap vao ngay: ");
        scanf("%d", &ntn.ngay);
    }while(ntn.ngay < 0 || ntn.ngay >31);
    do{
        printf("\nNhap vao thang: ");
        scanf("%d", &ntn.thang);
    }while(ntn.thang < 0 || ntn.thang >12);
    do{
        printf("\nNhap vao nam: ");
        scanf("%d", &ntn.nam);
    }while(ntn.nam<0 || ntn.nam>2023);
}

// --  Nhap nhan vien  --//
void nhapNhanVien(nhanvien &nv){
    printf("\nNhap vao MSNV: ");
    scanf("%d", &nv.msnv);
    printf("\nNhap vao ho: ");
    fflush(stdin);
    gets(nv.ho);
    printf("\nNhap vao ten: ");
    fflush(stdin);
    gets(nv.ten);
    printf("\nNhap nam sinh ");
    nhapNgayThang(nv.namSinh);
    printf("\nNhap vao noi sinh: ");
    fflush(stdin);
    gets(nv.noiSinh);
    printf("\nNhap vao dia chi: ");
    fflush(stdin);
    gets(nv.diaChi);
    printf("\nNhap vao luong: ");
    fflush(stdin);
    scanf("%f", &nv.luong);
    printf("\nNhap nam vao ");
    nhapNgayThang(nv.ngayvao);
}
// --  Nhap danh sach  --//
void nhapDanhSach(danhsach &ds){
    printf("\nNhap so luong nhan vien: ");
    scanf("%d", &ds.n);
    printf("\n\t\tNhap vao thong tin nhan vien");
    for (int i = 0; i< ds.n ; i++)
    {
        printf("\n\t\tNhan vien thu %d", i+1);
        nhapNhanVien(ds.nv[i]);
    }
    
}
// --  Xuat ngay thang nam  --//
void xuatNgayThang(date ntn){
    printf("%d/", ntn.ngay);
    printf("%d/", ntn.thang);
    printf("%d", ntn.nam);
}
// --  Xuat nhan vien  --//
void xuatNhanVien(nhanvien nv){
    printf("\nMa so nhan vien: %d", nv.msnv);
    printf("\nHo va ten: %s %s ", nv.ho,nv.ten);
    printf("\nNam sinh: ");
    xuatNgayThang(nv.namSinh);
    printf("\nNoi sinh: %s", nv.noiSinh);
    printf("\nDia chi: %s", nv.diaChi);
    printf("\nLuong: %.2f", nv.luong);
    printf("\nNam vao: ");
    xuatNgayThang(nv.ngayvao);
}
// --  Xuat danh sach  --//
void xuatDanhSach(danhsach &ds){
    printf("\n\t\tDanh sach nhan vien");
    for (int i = 0; i < ds.n; i++)
    {
        printf("\n\t\tNhan vien thu %d", i + 1);
        xuatNhanVien(ds.nv[i]);
    }
}
// --  Them nhan vien  --//
void themNv(danhsach &ds, nhanvien nv, int k){
     if (ds.n >= k) {
     printf("Danh sach nhan vien da day khong the them nhan vien");
     return;
     }
     ds.nv[ds.n] = nv;
     ds.n++;
}

// --  Tim theo ma  --//
int timMsnv(danhsach ds, int d){
    for(int i=0; i < ds.n; i++) {
        if(ds.nv[i].msnv == d){
            return i;
            break;
        }
    }
    return -1;
}
// --  Tim theo ten  --//
int timTheoTen(danhsach ds, char *c){
    for (int i = 0; i< ds.n; i++)
    {
       if(strcasecmp(ds.nv[i].ten, c) == 0){
        return i;
        break;
       }  
    }
    return -1;
}
// --  Sap xep luong giam dan  --//
void sapXep(danhsach ds){
    for (int i = 0; i < ds.n-1; i++) {
        for (int j = i+1; j < ds.n; j++) {
            if (ds.nv[i].luong < ds.nv[j].luong) {
                nhanvien temp = ds.nv[i];
                ds.nv[i] = ds.nv[j];
                ds.nv[j] = temp;
            }
        }
    }
    xuatDanhSach(ds);
}

// --  Xoa nhan vien  --//
void xoa(danhsach ds, int &d){
    int vt=timMsnv(ds,d);
    if(vt==-1){
        printf("\nKhong tim thay masv %d muon xoa",d);
    }else{
        for (int i=vt;i<ds.n-1;i++)
        {
            ds.nv[i]=ds.nv[i+1];
            ds.n--;
        }
        printf("Xoa thanh cong");
        xuatDanhSach(ds);
    }
}

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
                printf("\n\tVi tri them: ");
                scanf("%d", &k);
                nhapNhanVien(nv);
                themNv(ds,nv,k);
                printf("\n\t\t\tDanh sach sau khi them: ");
                xuatDanhSach(ds);
                break;
            }
        case 2: 
            {
                printf("\n\tNhap ma so can tim: ");
                scanf("%d", &d);
                int i = timMsnv(ds, d);
                if(i == -1){
                    printf("\nKhong tim thay Msnv %d", d);
                }else{
                    printf("\nTim thay nhan vien thu %d", i+1);
                    break;
                }
                break;
            }
        case 3: 
            {
                char c[20];
                printf("\nNhap ten can tim: ");
                fflush(stdin);
                gets(c);
                int i = timTheoTen(ds, c);
                if(i == -1){
                    printf("\nKhong tim thay nhan vien %s", c);
                }else{
                    printf("\nTim thay nhan vien");
                    xuatDanhSach(ds);
                    break;
                }
                break;
            }
        case 4: 
            {
                printf("\nDanh sach nhan vien sau khi sap xep");
                sapXep(ds);
                break;
            }
        case 5: 
            {
                 printf("\nNhap msnv can xoa: ");
                scanf("%d",&d);
                printf("\n\t\tDanh sach sau khi xoa");
                xoa(ds,d);
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
