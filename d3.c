#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Hàm kiểm tra chuỗi nhập vào có thoả mãn điều kiện hay không
int validateString(char str[]) {
    int length = strlen(str);
    int hasUpper = 0, hasDigit = 0;

    // Kiểm tra độ dài chuỗi
    if (length < 6) return 0;

    // Kiểm tra ký tự đầu tiên
    if (str[0] != 'P' && str[0] != 'p') return 0;

    // Kiểm tra có ít nhất 1 ký tự viết hoa và 1 ký tự số
    for (int i = 0; i < length; i++) {
        if (isupper(str[i])) hasUpper = 1;
        if (isdigit(str[i])) hasDigit = 1;
    }

    return hasUpper && hasDigit;
}

// Hàm thống kê số lượng ký tự số và ký tự chữ cái
void countCharacters(char str[], int *numDigits, int *numLetters) {
    *numDigits = 0;
    *numLetters = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) (*numDigits)++;
        if (isalpha(str[i])) (*numLetters)++;
    }
}

int main() {
    char input[100];
    int numDigits, numLetters;

    while (1) {
        printf("Nhập vào chuỗi: ");
        scanf("%s", input);

        if (validateString(input)) break;

        printf("Chuỗi không thoả mãn điều kiện. Vui lòng nhập lại.\n");
    }

    countCharacters(input, &numDigits, &numLetters);

    printf("Chuỗi vừa nhập có %d ký tự số và %d ký tự chữ cái.\n", numDigits, numLetters);

    return 0;
}
