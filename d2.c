
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapXauSo(char s[]) {
    int hopLe;
    do {
        hopLe = 1;
        printf("Nhap vao mot xau ky tu chi gom cac chu so: ");
        fgets(s, 100, stdin); // Đọc chuỗi, bao gồm cả ký tự '\n'
        s[strcspn(s, "\n")] = '\0'; // Loại bỏ ký tự '\n' nếu có

        for (int i = 0; i < strlen(s); i++) {
            if (!isdigit(s[i])) {
                hopLe = 0;
                printf("Xau chi duoc gom cac chu so. Vui long nhap lai.\n");
                break;
            }
        }
    } while (!hopLe);
}

void timKyTuNhieuNhat(char s[]) {
    int tanSuat[256] = {0};
    int max = 0;
    char kyTuNhieuNhat;

    for (int i = 0; i < strlen(s); i++) {
        tanSuat[(unsigned char)s[i]]++;
        if (tanSuat[(unsigned char)s[i]] > max) {
            max = tanSuat[(unsigned char)s[i]];
            kyTuNhieuNhat = s[i];
        }
    }

    printf("Ky tu '%c' xuat hien nhieu nhat voi %d lan.\n", kyTuNhieuNhat, max);
}

int main() {
    char s[100];

    // Gọi chương trình con nhập xâu kí tự
    nhapXauSo(s);

    // Gọi chương trình con tìm kí tự xuất hiện nhiều nhất
    timKyTuNhieuNhat(s);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Định nghĩa cấu trúc dữ liệu cho cửa hàng
typedef struct {
    char maCH[11];
    char diaChi[31];
    int soNhanVien;
    int doanhSo;
} cuaHang;

// Hàm kiểm tra mã cửa hàng chỉ chứa các ký tự là chữ số và không quá 10 ký tự
int kiemTraMaCH(char *maCH) {
    if (strlen(maCH) > 10) return 0;
    for (int i = 0; i < strlen(maCH); i++) {
        if (!isdigit(maCH[i])) return 0;
    }
    return 1;
}
// Hàm nhập thông tin của một cửa hàng từ bàn phím
void nhapThongTinCuaHang(cuaHang *ch) {
    // Nhập mã cửa hàng
    do {
        printf("Nhap ma cua hang (toi da 10 ky tu, chi gom cac chu so): ");
        fgets(ch->maCH, sizeof(ch->maCH), stdin);
        ch->maCH[strcspn(ch->maCH, "\n")] = '\0'; // Loại bỏ ký tự '\n' nếu có
        if (!kiemTraMaCH(ch->maCH)) {
            printf("Ma cua hang chi duoc gom cac chu so va toi da 10 ky tu. Vui long nhap lai.\n");
        }
    } while (!kiemTraMaCH(ch->maCH));
    
    // Nhập địa chỉ
    do {
        printf("Nhap dia chi (toi da 30 ky tu): ");
        fgets(ch->diaChi, sizeof(ch->diaChi), stdin);
        ch->diaChi[strcspn(ch->diaChi, "\n")] = '\0'; // Loại bỏ ký tự '\n' nếu có
        if (strlen(ch->diaChi) > 30) {
            printf("Dia chi khong duoc qua 30 ky tu. Vui long nhap lai.\n");
        }
    } while (strlen(ch->diaChi) > 30);

    // Nhập số nhân viên
    do {
        printf("Nhap so nhan vien (so nguyen duong): ");
        scanf("%d", &ch->soNhanVien);
        if (ch->soNhanVien <= 0) {
            printf("So nhan vien phai la so nguyen duong. Vui long nhap lai.\n");
        }
    } while (ch->soNhanVien <= 0);

    // Nhập doanh số
    do {
        printf("Nhap doanh so (so nguyen khong am): ");
        scanf("%d", &ch->doanhSo);
        if (ch->doanhSo < 0) {
            printf("Doanh so phai la so nguyen khong am. Vui long nhap lai.\n");
        }
    } while (ch->doanhSo < 0);

    // Xóa bộ đệm sau khi nhập số
    while (getchar() != '\n');
}
// Hàm nhập thông tin danh sách các cửa hàng
void nhapDanhSachCuaHang(cuaHang ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin cua hang thu %d:\n", i + 1);
        nhapThongTinCuaHang(&ds[i]);
    }
}
// Hàm in thông tin danh sách các cửa hàng theo định dạng bảng
void inDanhSachCuaHang(cuaHang ds[], int n) {
    printf("+-----+----------+-------------+------------+------------------------------+\n");
    printf("| STT | MaCH     | So nhan vien| Doanh so   | Dia chi                      |\n");
    printf("+-----+----------+-------------+------------+------------------------------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %-9s| %11d| %10d | %-30s |\n", i + 1, ds[i].maCH, ds[i].soNhanVien, ds[i].doanhSo, ds[i].diaChi);
    }
    printf("+-----+----------+-------------+------------+------------------------------+\n");
}
// Hàm sắp xếp danh sách các cửa hàng theo doanh số giảm dần
void sapXepTheoDoanhSo(cuaHang ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].doanhSo < ds[j + 1].doanhSo) {
                cuaHang temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}
int main() {
    cuaHang ds[100];
    int n;

    printf("Nhap so luong cua hang: ");
    scanf("%d", &n);
    while (getchar() != '\n'); // Xóa bộ đệm sau khi nhập số

    nhapDanhSachCuaHang(ds, n);

    printf("\nDanh sach cua hang vua nhap:\n");
    inDanhSachCuaHang(ds, n);

    sapXepTheoDoanhSo(ds, n);

    printf("\nDanh sach cua hang sau khi sap xep theo doanh so giam dan:\n");
    inDanhSachCuaHang(ds, n);

    return 0;
}
