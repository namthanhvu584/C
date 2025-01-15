#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct{
	char brand[21];
	int ram;
	char chip[3];
	double price;
	char id[31];
}laptop;

int check_brand(char *a){
	if(strlen(a) > 20) return 0;
	else{
		int i;
		for(i = 0; i < strlen(a); i++){
			if(isspace(a[i]) != 0) return 0; 
		}
	}
	return 1;
}

char* get_ram(int i){
	switch(i){
		case 1: return "M1";
		case 2: return "M2";
		case 3: return "i3";
		case 5: return "i5";
		case 7: return "i7";
		default: return "";
	}
}

void input(laptop l[], int n){
    int i;
    char buffer[100]; // Dùng để xóa bộ nhớ đệm sau mỗi lần nhập
    for(i = 0; i < n; i++){
        printf("Nhap hang: ");
        fgets(buffer, sizeof(buffer), stdin); // Đọc bỏ kí tự new line còn tồn đọng trong bộ nhớ đệm
        fgets(l[i].brand, sizeof(l[i].brand), stdin); // Đọc tên hãng
        l[i].brand[strcspn(l[i].brand, "\n")] = '\0'; // Xóa kí tự new line cuối cùng
        while(check_brand(l[i].brand) == 0){ // Kiểm tra hãng vừa nhập
            printf("Nhap hang: ");
            fgets(buffer, sizeof(buffer), stdin); // Đọc bỏ kí tự new line còn tồn đọng trong bộ nhớ đệm
            fgets(l[i].brand, sizeof(l[i].brand), stdin); // Đọc tên hãng
            l[i].brand[strcspn(l[i].brand, "\n")] = '\0'; // Xóa kí tự new line cuối cùng
        }
        printf("Nhap RAM: ");
        scanf("%d", &l[i].ram);
        while(l[i].ram <= 0 || l[i].ram % 4 != 0){
            printf("Nhap lai RAM: ");
            scanf("%d", &l[i].ram);
        }
        printf("Chon chip:\n");
        printf("1 - M1\n2 - M2\n3 - i3\n5 - i5\n7 - i7\n");
        printf("Lua chon cua ban: ");
        int c;
        scanf("%d", &c);
        while(strlen(get_ram(c)) == 0){
            printf("Hay chon lai: ");
            scanf("%d", &c);
        }
        strcpy(l[i].chip, get_ram(c));
        printf("Nhap gia: ");
        scanf("%lf", &l[i].price);
        while(l[i].price <= 0){
            printf("Nhap lai gia: ");
            scanf("%lf", &l[i].price);
        }
    }
}


void create_id(laptop l[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        l[i].id[0] = '\0';
        strcat(l[i].id, l[i].brand);
        strcat(l[i].id, "-");
        char c[20]; // Đủ để chứa một số nguyên
        sprintf(c, "%d", l[i].ram); // Chuyển đổi số nguyên thành chuỗi ký tự
        strcat(l[i].id, c);
        strcat(l[i].id, "-");
        strcat(l[i].id, l[i].chip);
    }
}

void display(laptop l[], int n){
	printf("|%3s|%-20s|%3s|%4s|%-30s|%5s|\n","STT","Hang","RAM","Chip","Ma san pham","Gia");
	int i;
	for(i = 0; i < n; i++){
		printf("|%3d|%-20s|%3d|%4s|%-30s|%5.2lf|\n",i+1,l[i].brand,l[i].ram,l[i].chip,l[i].id,l[i].price);
	}
}

void sort_price(laptop l[], int n){
	int i,j;
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(l[j].price > l[j+1].price){
				laptop c = l[j];
				l[j] = l[j+1];
				l[j+1] = c;
			}
		}
	}
}

void search(laptop l[], int n){
	printf("|%3s|%-20s|%3s|%4s|%-30s|%5s|\n","STT","Hang","RAM","Chip","Ma san pham","Gia");
	int i, count = 1;
	for(i = 0; i < n; i++){
		if(l[i].ram > 8 && strcmp(l[i].chip, "i7") == 0){
			printf("|%3d|%-20s|%3d|%4s|%-30s|%5.2lf|\n",count,l[i].brand,l[i].ram,l[i].chip,l[i].id,l[i].price);
			count++;
		}
	}
}

int main(){
	laptop l[100];
	input(l, 3);
	create_id(l, 3);
	printf("\nDanh sach laptop\n");
	display(l, 3);
	sort_price(l, 3);
	printf("\nSap xep theo gia tang dan\n");
	display(l, 3);
	printf("\nTim kiem\n");
	search(l, 3);
}

