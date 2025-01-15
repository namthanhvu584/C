//15. tam giac can
// #include <stdio.h>
// int main() {
//     int rows;

//     printf("Nhap so hang cua tam giac: ");
//     scanf("%d", &rows);

//     for (int i = 1; i <= rows; i++) {
//         // In khoảng trắng để căn lề trái
//         for (int j = 1; j <= rows - i; j++) {
//             printf(" ");
//         }
//         for (int j = 1; j <= 2 * i - 1; j++) {
//             printf("*");
//         }
//         printf("\n");
//     }

//     return 0;
// }
// //3. diem trung binh
// #include <stdio.h>

// int main() {
//     int numTests = 5;
//     int totalScore = 0;

//     printf("Nhap diem cua 5 bai kiem tra: \n");

//     for (int i = 1; i <= numTests; i++) {
//         int score;
//         printf("Diem bai kiem tra %d: ", i);
//         scanf("%d", &score);
//         totalScore += score;
//     }

//     double averageScore = (double)totalScore / numTests;

//     printf("Diem kiem tra trung binh: %.2f\n", averageScore);

//     return 0;
// }

//phim
// #include <stdio.h>
// #include <string.h>
// // Khai báo hằng số
// #define GIA_VE_NGUOI_LON 10.00
// #define GIA_VE_TRE_EM 6.00
// #define TY_LE_LOI_NHUAN_PHONG_VE 0.2
// // Khai báo cấu trúc thông tin về bộ phim
// struct BoPhim {
//     char ten[100];
//     int soLuongVeNguoiLon;
//     int soLuongVeTreEm;
// };
// // Hàm nhập thông tin về bộ phim từ người dùng
// void nhap_thong_tin(struct BoPhim phim) {
//     char ten[100];
//     printf("Nhập tên bộ phim: ");
//     fgets(ten, sizeof(ten), stdin);
//     ten[strcspn(ten, "\n")] = '\0';
//     printf("Nhập số lượng vé người lớn đã bán: ");
//     scanf("%d", &phim.soLuongVeNguoiLon);
//     printf("Nhập số lượng vé trẻ em đã bán: ");
//     scanf("%d", &phim.soLuongVeTreEm);
// }

// // Hàm tính tổng doanh thu phòng vé
// float tinh_doanh_thu(struct BoPhim phim) {
//     float doanhThu = phim.soLuongVeNguoiLon * GIA_VE_NGUOI_LON + phim.soLuongVeTreEm * GIA_VE_TRE_EM;
//     return doanhThu;
// }
// // Hàm tính lợi nhuận ròng của phòng vé
// float tinh_loi_nhuan_rong(float doanhThu) {
//     float loiNhuuanGop = doanhThu * TY_LE_LOI_NHUAN_PHONG_VE;
//     float loiNhuuanRong = doanhThu - loiNhuuanGop;
//     return loiNhuuanRong;
// }
// // Hàm hiển thị thông tin về doanh thu và lợi nhuận
// void hien_thi_thong_tin(struct BoPhim phim, float doanhThu, float loiNhuuanRong) {
//     float loiNhuuanGop = doanhThu * TY_LE_LOI_NHUAN_PHONG_VE;
//     float soTienTraChoNhaPhanPhoi = doanhThu - loiNhuuanRong;
//     printf("\nTên bộ phim: %s\n", phim.ten);
//     printf("Số lượng vé người lớn đã bán: %d\n", phim.soLuongVeNguoiLon);
//     printf("Số lượng vé trẻ em đã bán: %d\n", phim.soLuongVeTreEm);
//     printf("Lợi nhuận gộp của phòng vé là: $%.2f\n", loiNhuuanGop);
//     printf("Lợi nhuận ròng của phòng vé là: $%.2f\n", loiNhuuanRong);
//     printf("Số tiền trả cho nhà phân phối: $%.2f\n", soTienTraChoNhaPhanPhoi);
// }
// // Hàm main
// int main() {
//     struct BoPhim phim;
//     // Nhập thông tin và tính toán
//     nhap_thong_tin(phim);
//     float doanhThu = tinh_doanh_thu(phim);
//     float loiNhuuanRong = tinh_loi_nhuan_rong(doanhThu);
//     // Hiển thị thông tin
//     hien_thi_thong_tin(phim, doanhThu, loiNhuuanRong);
//     return 0;
// }

//struct_sinhvien
// #include <stdio.h>

// // Định nghĩa cấu trúc sinh viên
// struct SinhVien {
//     char ten[50];
//     int mssv;
//     float diemToan;
//     float diemVan;
//     float diemAnh;
// };
// // Hàm in thông tin của một sinh viên
// void in_thong_tin_sinh_vien(struct SinhVien sv) {
//     printf("Tên: %s\n", sv.ten);
//     printf("MSSV: %d\n", sv.mssv);
//     printf("Điểm Toán: %.2f\n", sv.diemToan);
//     printf("Điểm Văn: %.2f\n", sv.diemVan);
//     printf("Điểm Anh: %.2f\n", sv.diemAnh);
// }
// int main() {
//     // Khai báo một biến kiểu SinhVien
//     struct SinhVien sv1;
//     // Gán giá trị cho biến sinh viên
//     strcpy(sv1.ten, "Nguyen Van A");
//     sv1.mssv = 12345;
//     sv1.diemToan = 8.5;
//     sv1.diemVan = 7.0;
//     sv1.diemAnh = 6.5;
//     // Gọi hàm in_thong_tin_sinh_vien và truyền biến sinh viên vào
//     in_thong_tin_sinh_vien(sv1);
//     return 0;
// }

//11. chi phi van hanh oto
#include<stdio.h>

struct ChiPhi
{
    float khoanVay;
    float baoHiem;
    float gas;
    float dau;
    float lop;
    float baoTri;
};

void nhapChiPhi(struct ChiPhi chiphi){
    printf("Nhap chi phi Khoan Vay: ");
    scanf("%f", &chiphi.khoanVay);
    printf("Nhap chi phi bao hiem: ");
    scanf("%f", &chiphi.baoHiem);
    printf("Nhap chi phi gas: ");
    scanf("%f", &chiphi.gas);
    printf("Nhap chi phi dau: ");
    scanf("%f", &chiphi.dau);
    printf("Nhap chi phi lop: ");
    scanf("%f", &chiphi.lop);
    printf("Nhap chi phi bao tri: ");
    scanf("%f", &chiphi.baoTri);
}
float tongTien(struct ChiPhi chiphi){
    float tien1Thang= (float) chiphi.khoanVay + chiphi.baoHiem + chiphi.gas + chiphi.dau + chiphi.lop + chiphi.baoTri ; 
    return tien1Thang;
}


void hienThi(struct ChiPhi chiphi, float tien1Thang){
    float tien1Thang = (float) chiphi.khoanVay + chiphi.baoHiem + chiphi.gas + chiphi.dau + chiphi.lop + chiphi.baoTri ; 
    float tien1Nam = tien1Thang * 12;
    printf("Chi phi 1 thang la: %.2f", tien1Thang );
    printf("Chi phi 1 nam la: %.2f",tien1Nam );
}

int main(){
    struct ChiPhi chiphi;
    nhapChiPhi(chiphi);
    float tien1Thang = (float) chiphi.khoanVay + chiphi.baoHiem + chiphi.gas + chiphi.dau + chiphi.lop + chiphi.baoTri ; 
    float tien1Nam = tien1Thang * 12;
    hienThi(chiphi, tien1Thang, tien1Nam);
    return 0;
}



