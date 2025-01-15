#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Định nghĩa cấu trúc cho máy tính
typedef struct {
    char hangSanXuat[11];
    char ma[21];
    char chip[3];
    int ram;
    float giaBan;
} MayTinh;

// Hàm kiểm tra hãng sản xuất
int kiemTraHangSanXuat(char *hangSanXuat) {
    return strlen(hangSanXuat) <= 10;
}

// Hàm kiểm tra chip
int kiemTraChip(char *chip) {
    return (strcmp(chip, "i3") == 0 || strcmp(chip, "i5") == 0 || strcmp(chip, "i7") == 0);
}

// Hàm kiểm tra RAM
int kiemTraRam(int ram) {
    return (ram % 4 == 0);
}

// Hàm kiểm tra giá bán
int kiemTraGiaBan(float giaBan) {
    return (giaBan > 0);
}

// Hàm nhập thông tin máy tính
void nhapThongTinMayTinh(MayTinh *mt) {
    // Nhập hãng sản xuất
    do {
        printf("Nhập hãng sản xuất (không quá 10 ký tự): ");
        scanf("%s", mt->hangSanXuat);
    } while (!kiemTraHangSanXuat(mt->hangSanXuat));

    // Nhập chip
    do {
        printf("Nhập chip (i3, i5 hoặc i7): ");
        scanf("%s", mt->chip);
    } while (!kiemTraChip(mt->chip));

    // Nhập RAM
    do {
        printf("Nhập RAM (số tự nhiên chia hết cho 4): ");
        scanf("%d", &mt->ram);
    } while (!kiemTraRam(mt->ram));

    // Nhập giá bán
    do {
        printf("Nhập giá bán (đơn vị triệu VND, số thực dương): ");
        scanf("%f", &mt->giaBan);
    } while (!kiemTraGiaBan(mt->giaBan));
}

// Hàm khởi tạo mã cho máy tính
void khoiTaoMa(MayTinh *mt) {
    sprintf(mt->ma, "%s.%s.%d", mt->hangSanXuat, mt->chip, mt->ram);
}

// Hàm sắp xếp danh sách máy tính theo giá bán tăng dần
void sapXepTheoGia(MayTinh *danhSach, int soLuong) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (danhSach[i].giaBan > danhSach[j].giaBan) {
                MayTinh temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

// Hàm in thông tin máy tính theo cấu hình yêu cầu
void inThongTinMayTinh(MayTinh *danhSach, int soLuong) {
    printf("Các máy tính có cấu hình như sau:\n");
    printf("Stt – Ma – Chip – RAM – Gia\n");
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(danhSach[i].hangSanXuat, "Asus") == 0 && 
            (strcmp(danhSach[i].chip, "i5") == 0 || strcmp(danhSach[i].chip, "i7") == 0) && 
            danhSach[i].ram >= 8 && 
            danhSach[i].giaBan < 25) {
            printf("%d - %s - %s - %d - %.2f\n", i + 1, danhSach[i].ma, danhSach[i].chip, danhSach[i].ram, danhSach[i].giaBan);
        }
    }
}

int main() {
    MayTinh danhSach[100];
    int soLuong = 0;
    char tiepTuc;

    // Nhập thông tin máy tính
    do {
        nhapThongTinMayTinh(&danhSach[soLuong]);
        khoiTaoMa(&danhSach[soLuong]);
        soLuong++;
        printf("Bạn có muốn nhập thông tin một chiếc máy tính khác không? (y/n): ");
        scanf(" %c", &tiepTuc);
    } while (tiepTuc == 'y');

    // Sắp xếp danh sách theo giá
    sapXepTheoGia(danhSach, soLuong);

    // In danh sách máy tính
    printf("\nDanh sách máy tính theo giá tăng dần:\n");
    printf("Stt – Ma – Chip – RAM – Gia\n");
    for (int i = 0; i < soLuong; i++) {
        printf("%d - %s - %s - %d - %.2f\n", i + 1, danhSach[i].ma, danhSach[i].chip, danhSach[i].ram, danhSach[i].giaBan);
    }

    // In thông tin các máy tính có cấu hình yêu cầu
    inThongTinMayTinh(danhSach, soLuong);

    return 0;
}
