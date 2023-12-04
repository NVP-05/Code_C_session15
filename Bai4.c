#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
struct Book {
    int maSach;
    char tenSach[50];
    char tacGia[50];
    float giaTien;
    char theLoai[50];
};
struct Library {
    struct Book books[MAX_BOOKS];
    int soLuong;
};
void nhapThongTinSach(struct Book *book) {
    printf("Nhap ma sach: ");
    scanf("%d", &book->maSach);
    printf("Nhap ten sach: ");
    scanf(" %[^\n]", book->tenSach);
    printf("Nhap tac gia: ");
    scanf(" %[^\n]", book->tacGia);
    printf("Nhap gia tien: ");
    scanf("%f", &book->giaTien);
    printf("Nhap the loai: ");
    scanf(" %[^\n]", book->theLoai);
}
void hienThiThongTinSach(const struct Book *book) {
    printf("Ma sach: %d\n", book->maSach);
    printf("Ten sach: %s\n", book->tenSach);
    printf("Tac gia: %s\n", book->tacGia);
    printf("Gia tien: %.2f\n", book->giaTien);
    printf("The loai: %s\n", book->theLoai);
}
void hienThiDanhSach(const struct Library *library) {
    printf("\nDanh sach cac sach:\n");
    for (int i = 0; i < library->soLuong; i++) {
        printf("Sach %d:\n", i + 1);
        hienThiThongTinSach(&(library->books[i]));
        printf("\n");
    }
}
void themSach(struct Library *library) {
    if (library->soLuong < MAX_BOOKS) {
        nhapThongTinSach(&(library->books[library->soLuong]));
        library->soLuong++;
        printf("Da them sach.\n");
    } else {
        printf("Thu vien da day, khong the them sach moi.\n");
    }
}
int main() {
    struct Library thuVien;
    thuVien.soLuong = 0;
    int luaChon;
    do {
        printf("\nMENU:\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Tim kiem sach theo khoang gia\n");
        printf("0. Thoat\n");

        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        switch (luaChon) {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &thuVien.soLuong);
                for (int i = 0; i < thuVien.soLuong; i++) {
                    printf("Nhap thong tin cho sach thu %d:\n", i + 1);
                    nhapThongTinSach(&(thuVien.books[i]));
                }
                break;
            case 2:
                hienThiDanhSach(&thuVien);
                break;
            case 3:
                themSach(&thuVien);
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
