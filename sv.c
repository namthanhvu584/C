
/*
Xay dung chuong trinh quan ly thong tin sinh vien.
Nguoi dung nhap thong tin cho moi sinh vien voi cac truong thong tin sau:
- Ho va ten: khong qua 30 ki tu, chi chua chu cai
- MSSV: co dung 8 ki tu la cac chu so, bat dau bang 22 (nam nhap hoc)
- SDT: co dung 10 ki tu la cac chu so, bat dau bang 03 hoac 09
- Email ca nhan: khong qua 30 ki tu, khong chua dau cach, ket thuc bang @gmail.com

1/ Viet chuong trinh con nhap vao danh sach n sinh vien sao cho:
a/ Kiem tra tinh dung dan cua 4 truong thong tin tren, neu nguoi dung nhap sai, yeu cau nhap lai
b/ Sau khi nhap 4 truong thong tin tren cho moi sinh vien, 
chuong trinh tu dong sinh ra mot truong thong tin moi:
- Email Phenikaa: bat dau bang MSSV, ket thuc la @st.phenikaa-uni.edu.vn
2/ Viet chuong trinh con in ra danh sach sinh vien duoi dang bang.
Trong do, SDT bi che 3 chu so cuoi bang "***" va email ca nhan duoc che 3 ki tu truoc @ bang "***".
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	char ten[31];
	char mssv[9];
	char sdt[11];
	char email_cn[31];
	char email_pka[32];
}sinh_vien;

int check_ten(char *a){
	if(strlen(a) > 30) return 0;
	else{
		int i;
		for(i = 0; i < strlen(a); i++){
			if(isalpha(a[i]) == 0 && isspace(a[i]) == 0) return 0;
		}
	}
	return 1;
}

int check_mssv(char *a){
	if(strlen(a) != 8) return 0;
	else{
		int i;
		if(a[0] != '2') return 0;
		if(a[1] != '2') return 0;
		for(i = 2; i < strlen(a); i++){
			if(isdigit(a[i]) == 0) return 0;
		}
	}
	return 1;
}

int check_sdt(char *a){
	if(strlen(a) != 10) return 0;
	else{
		int i;
		if(a[0] != '0') return 0;
		if(a[1] != '3' && a[1] != '9') return 0;
		for(i = 2; i < strlen(a); i++){
			if(isdigit(a[i]) == 0) return 0;
		}
	}
	return 1;
}

int check_email(char *a){
	if(strlen(a) > 30 || strlen(a) < 11) return 0;
	else{
		int i, j;
		char c[11];
		for(i = 0; i < 11; i++){
			c[i] = a[strlen(a) - 10 + i];
		}
		if(strcmp(c,"@gmail.com") != 0) return 0;
		for(i = 0; i < strlen(a) - 10; i++){
			if(isspace(a[i]) != 0) return 0;
		}
	}
	return 1;
}

void input(sinh_vien s[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("Nhap ten: ");
		fflush(stdin);
		gets(s[i].ten);
		while(check_ten(s[i].ten) == 0){
			printf("Ten sai dinh dang. Nhap lai ten: ");
			fflush(stdin);
			gets(s[i].ten);
		}
		printf("Nhap MSSV: ");
		fflush(stdin);
		gets(s[i].mssv);
		while(check_mssv(s[i].mssv) == 0){
			printf("MSSV sai dinh dang. Nhap lai MSSV: ");
			fflush(stdin);
			gets(s[i].mssv);
		}
		printf("Nhap SDT: ");
		fflush(stdin);
		gets(s[i].sdt);
		while(check_sdt(s[i].sdt) == 0){
			printf("SDT sai dinh dang. Nhap lai SDT: ");
			fflush(stdin);
			gets(s[i].sdt);
		}
		printf("Nhap Email: ");
		fflush(stdin);
		gets(s[i].email_cn);
		while(check_email(s[i].email_cn) == 0){
			printf("Email sai dinh dang. Nhap lai Email: ");
			fflush(stdin);
			gets(s[i].email_cn);
		}
		printf("Email Phenikaa: ");
		strcat(s[i].email_pka, s[i].mssv);
		strcat(s[i].email_pka, "@st.phenikaa-uni.edu.vn");
		printf("%s\n", s[i].email_pka);
	}
}

void display(sinh_vien s[], int n){
	printf("|%3s|%8s|%-30s|%10s|%-30s|%-31s|\n", "STT", "MSSV", "Ho va ten", "SDT", "Email ca nhan", "Email Phenikaa");
	int i;
	for(i = 0; i < n; i++){
		printf("|%3d|%8s|%-30s|", i+1, s[i].mssv, s[i].ten);
		char c[7];
		int j;
		for(j = 0; j < 7; j++){
			c[j] = s[i].sdt[j];
		}
		char d[100];
		strcpy(d, s[i].email_cn);
		d[strlen(d) - 11] = '*';
		d[strlen(d) - 12] = '*';
		d[strlen(d) - 13] = '*';
		printf("%s***|%-30s|", c, d);
		printf("%-31s|\n", s[i].email_pka);
	}
}

int main(){
	sinh_vien s[1000];
	input(s, 1);
	display(s, 1);
}
1
Đang hiển thị download.