#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
struct SinhVien {
    char hoTen[50];
    int tuoi;
    char soDienThoai[15];
    char email[50];
};
struct DanhSachSinhVien {
    struct SinhVien students[MAX_STUDENTS];
    int soLuong;
};
void nhapThongTin(struct SinhVien *sv) {
    printf("Nhap ho va ten: ");
    scanf(" %[^\n]", sv->hoTen);
    printf("Nhap tuoi: ");
    scanf("%d", &(sv->tuoi));
    printf("Nhap so dien thoai: ");
    scanf("%14s", sv->soDienThoai);
    printf("Nhap email: ");
    scanf("%49s", sv->email);
}
void inThongTin(const struct SinhVien *sv) {
    printf("Ho va ten: %s\n", sv->hoTen);
    printf("Tuoi: %d\n", sv->tuoi);
    printf("So dien thoai: %s\n", sv->soDienThoai);
    printf("Email: %s\n", sv->email);
}
void inDanhSach(const struct DanhSachSinhVien *danhSach) {
    printf("\nThong tin sinh vien:\n");
    for (int i = 0; i < danhSach->soLuong; i++) {
        printf("Thong tin sinh vien %d:\n", i + 1);
        inThongTin(&(danhSach->students[i]));
        printf("\n");
    }
}
void themSinhVien(struct DanhSachSinhVien *danhSach, const struct SinhVien *sv, int viTri) {
    if (danhSach->soLuong < MAX_STUDENTS && viTri >= 0 && viTri <= danhSach->soLuong) {
        for (int i = danhSach->soLuong; i > viTri; i--) {
            danhSach->students[i] = danhSach->students[i - 1];
        }
        danhSach->students[viTri] = *sv;
        danhSach->soLuong++;

        printf("Da them sinh vien vao vi tri %d.\n", viTri + 1);
    } else {
        printf("Khong the them sinh vien vao vi tri %d.\n", viTri + 1);
    }
}
void suaSinhVien(struct DanhSachSinhVien *danhSach, const struct SinhVien *sv, int viTri) {
    if (viTri >= 0 && viTri < danhSach->soLuong) {
        danhSach->students[viTri] = *sv;
        printf("Da sua thong tin sinh vien tai vi tri %d.\n", viTri + 1);
    } else {
        printf("Khong the sua thong tin sinh vien tai vi tri %d.\n", viTri + 1);
    }
}
void xoaSinhVien(struct DanhSachSinhVien *danhSach, int viTri) {
    if (viTri >= 0 && viTri < danhSach->soLuong) {
        for (int i = viTri; i < danhSach->soLuong - 1; i++) {
            danhSach->students[i] = danhSach->students[i + 1];
        }

        danhSach->soLuong--;

        printf("Da xoa sinh vien tai vi tri %d.\n", viTri + 1);
    } else {
        printf("Khong the xoa sinh vien tai vi tri %d.\n", viTri + 1);
    }
}
int main() {
    struct DanhSachSinhVien danhSach;
    danhSach.soLuong = 0;
    int luaChon;
    int viTri;
    do {
        printf("\nMENU:\n");
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. In danh sach sinh vien\n");
        printf("3. Them sinh vien\n");
        printf("4. Sua thong tin sinh vien\n");
        printf("5. Xoa sinh vien\n");
        printf("0. Thoat\n");

        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &danhSach.soLuong);
                for (int i = 0; i < danhSach.soLuong; i++) {
                    printf("Nhap thong tin cho sinh vien thu %d:\n", i + 1);
                    nhapThongTin(&(danhSach.students[i]));
                }
                break;
            case 2:
                inDanhSach(&danhSach);
                break;
            case 3:
                printf("Nhap vi tri can them: ");
                scanf("%d", &viTri);
                nhapThongTin(&(danhSach.students[danhSach.soLuong]));
                themSinhVien(&danhSach, &(danhSach.students[danhSach.soLuong]), viTri - 1);
                break;
            case 4:
                printf("Nhap vi tri can sua: ");
                scanf("%d", &viTri);
                nhapThongTin(&(danhSach.students[viTri - 1]));
                suaSinhVien(&danhSach, &(danhSach.students[viTri - 1]), viTri - 1);
                break;
            case 5:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &viTri);
                xoaSinhVien(&danhSach, viTri - 1);
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (luaChon != 0);
    return 0;
}

