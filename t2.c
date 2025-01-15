
//d30
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// CÂU A
int validate_string(char *str) {
    int len = strlen(str);
    int has_upper = 0;
    int has_digit = 0;

    if (len < 6) {
        return 0;
    }

    if (str[0] != 'P' && str[0] != 'p') {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            has_upper = 1;
        }
        if (isdigit(str[i])) {
            has_digit = 1;
        }
    }

    return has_upper && has_digit;
}

//Câu B
void count_characters(char *str, int *num_letters, int *num_digits) {
    *num_letters = 0;
    *num_digits = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            (*num_letters)++;
        }
        if (isdigit(str[i])) {
            (*num_digits)++;
        }
    }
}

//Câu C
void remove_special_characters(char *str) {
    int len = strlen(str);
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';
}

int main() {
    char input[100];
    int num_letters, num_digits;

    printf("Nhap chuoi: ");
    scanf("%s", input);

    while (!validate_string(input)) {
        printf("Khong thoa man hay nhap lai: ");
        scanf("%s", input);
    }

    count_characters(input, &num_letters, &num_digits);
    printf("Chuoi vua nhap co %d ki tu la chu cai và %d ki tu la so.\n", num_letters, num_digits);

    remove_special_characters(input);
    printf("Chuoi sau khi xoa ki tu dac biet: %s\n", input);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char tenSanPham[11]; // Tên sản phẩm tối đa 10 ký tự
    int soLuong;
    char size[4];
    float giaBan;
} SanPham;

// Hàm nhập thông tin sản phẩm
void nhapSanPham(SanPham sp[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho san pham thu %d:\n", i + 1);
        printf("Ten san pham: ");
        fflush(stdin);
        fgets(sp[i].tenSanPham, sizeof(sp[i].tenSanPham), stdin);
        sp[i].tenSanPham[strcspn(sp[i].tenSanPham, "\n")] = '\0'; // Xóa ký tự xuống dòng
        
        printf("So luong: ");
        scanf("%d", &sp[i].soLuong);
        
        printf("Chon size (1-S, 2-M, 3-L, 4-XL, 5-2XL): ");
        int chon;
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                strcpy(sp[i].size, "S");
                break;
            case 2:
                strcpy(sp[i].size, "M");
                break;
            case 3:
                strcpy(sp[i].size, "L");
                break;
            case 4:
                strcpy(sp[i].size, "XL");
                break;
            case 5:
                strcpy(sp[i].size, "2XL");
                break;
            default:
                strcpy(sp[i].size, "S");
                break;
        }
        
        printf("Gia ban: ");
        scanf("%f", &sp[i].giaBan);
    }
}

// Hàm in danh sách sản phẩm
void inDanhSach(SanPham sp[], int n) {
    printf("+-----+-------------+------------+------------+------------+\n");
    printf("| STT | Ten san pham| So luong   | Size       | Gia ban    |\n");
    printf("+-----+-------------+------------+------------+------------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %-11s | %10d | %-10s | %10.2f |\n", i + 1, sp[i].tenSanPham, sp[i].soLuong, sp[i].size, sp[i].giaBan);
    }
    printf("+-----+-------------+------------+------------+------------+\n");
}

// Hàm sắp xếp sản phẩm theo số lượng tồn kho giảm dần
void sapXepSanPham(SanPham sp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sp[i].soLuong < sp[j].soLuong) {
                SanPham temp = sp[i];
                sp[i] = sp[j];
                sp[j] = temp;
            }
        }
    }
}

// Hàm tính tổng giá trị các sản phẩm tồn kho
float tinhTongGiaTri(SanPham sp[], int n) {
    float tong = 0;
    for (int i = 0; i < n; i++) {
        tong += sp[i].soLuong * sp[i].giaBan;
    }
    return tong;
}

// Hàm tìm kiếm sản phẩm theo size và khoảng giá
void timKiemSanPham(SanPham sp[], int n, char size[], float giaTu, float giaDen) {
    int found = 0;
    printf("+-----+-------------+------------+------------+------------+\n");
    printf("| STT | Ten san pham| So luong   | Size       | Gia ban    |\n");
    printf("+-----+-------------+------------+------------+------------+\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(sp[i].size, size) == 0 && sp[i].giaBan >= giaTu && sp[i].giaBan <= giaDen) {
            printf("| %3d | %-11s | %10d | %-10s | %10.2f |\n", i + 1, sp[i].tenSanPham, sp[i].soLuong, sp[i].size, sp[i].giaBan);
            found = 1;
        }
    }
    printf("+-----+-------------+------------+------------+------------+\n");
    if (!found) {
        printf("Khong co san pham nao thoa man dieu kien tim kiem.\n");
    }
}

int main() {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);

    SanPham sp[n];
    nhapSanPham(sp, n);
    
    printf("\nDanh sach san pham:\n");
    inDanhSach(sp, n);
    
    sapXepSanPham(sp, n);
    
    printf("\nDanh sach san pham sau khi sap xep giam dan theo so luong:\n");
    inDanhSach(sp, n);
    
    float tongGiaTri = tinhTongGiaTri(sp, n);
    printf("\nTong gia tri cac san pham ton kho: %.2f\n", tongGiaTri);
    
    char size[4];
    float giaTu, giaDen;
    
    printf("\nNhap size can tim (S, M, L, XL, 2XL): ");
    scanf("%s", size);
    printf("Nhap khoang gia (tu - den): ");
    scanf("%f %f", &giaTu, &giaDen);
    
    printf("\nDanh sach san pham theo size %s va khoang gia %.2f - %.2f:\n", size, giaTu, giaDen);
    timKiemSanPham(sp, n, size, giaTu, giaDen);

    return 0;
}
//d1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm chuyển đổi ký tự số thành ký tự chữ cái
char soThanhChuCai(char so) {
    return 'A' + (so - '0');
}

// Hàm kiểm tra xem chuỗi có hợp lệ hay không
int validateString(char str[]) {
    if (strlen(str) < 10) {
        return 0;  // Chuỗi ít hơn 10 ký tự
    }
    
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;  // Tìm thấy ký tự không phải là chữ số
        }
    }
    return 1;  // Chuỗi hợp lệ
}

// Hàm biến đổi chuỗi số thành chuỗi ký tự chữ cái
void bienDoiChuoi(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            str[i] = soThanhChuCai(str[i]);
        }
    }
}

int main() {
    char chuoi[100];

    // Yêu cầu người dùng nhập vào chuỗi hợp lệ
    while (1) {
        printf("Nhap vao chuoi so (it nhat 10 ky tu): ");
        scanf("%s", chuoi);

        if (validateString(chuoi)) {
            break;
        } else {
            printf("Chuoi khong hop le. Vui long nhap lai.\n");
        }
    }

    // Biến đổi chuỗi số thành chuỗi ký tự chữ cái
    bienDoiChuoi(chuoi);

    // In ra chuỗi đã được mã hóa
    printf("Chuoi da ma hoa: %s\n", chuoi);

    return 0;
}

