#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
struct Book {
    char code[20];
    char title[100];
    char author[50];
    float price;
    char category[50];
};
void nhapBook(struct Book *b) {
    printf("Ma sach: ");
    fgets(b->code, sizeof(b->code), stdin);
    b->code[strcspn(b->code, "\n")] = '\0';
    printf("Ten sach: ");
    fgets(b->title, sizeof(b->title), stdin);
    b->title[strcspn(b->title, "\n")] = '\0';
    printf("Tac gia: ");
    fgets(b->author, sizeof(b->author), stdin);
    b->author[strcspn(b->author, "\n")] = '\0';
    printf("Gia tien: ");
    scanf("%f", &b->price);
    getchar(); 
    printf("The loai: ");
    fgets(b->category, sizeof(b->category), stdin);
    b->category[strcspn(b->category, "\n")] = '\0';
}
void hienThiBook(struct Book b) {
    printf("\nMa sach: %s\n", b.code);
    printf("Ten sach: %s\n", b.title);
    printf("Tac gia: %s\n", b.author);
    printf("Gia tien: %.2f\n", b.price);
    printf("The loai: %s\n", b.category);
}
void hienThiTatCa(struct Book books[], int n) {
    if(n==0){
        printf("Danh sach sach rong.\n");
        return;
    }
    for(int i = 0; i < n; i++) {
        printf("\n--- Sach %d ---\n", i + 1);
        hienThiBook(books[i]);
    }
}
void themBook(struct Book books[], int *n) {
    if(*n >= MAX) {
        printf("Danh sach da day, khong the them.\n");
        return;
    }
    int pos;
    printf("Nhap vi tri can them (1-%d): ", *n+1);
    scanf("%d", &pos);
    getchar();
    if(pos < 1 || pos > *n+1) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for(int i = *n; i >= pos; i--) {
        books[i] = books[i-1];
    }
    printf("Nhap thong tin sach moi:\n");
    nhapBook(&books[pos-1]);
    (*n)++;
    printf("Them thanh cong.\n");
}
void xoaBook(struct Book books[], int *n) {
    char code[20];
    printf("Nhap ma sach can xoa: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';
    int found = 0;
    for(int i = 0; i < *n; i++) {
        if(strcmp(books[i].code, code) == 0) {
            found = 1;
            for(int j = i; j < *n-1; j++) {
                books[j] = books[j+1];
            }
            (*n)--;
            printf("Xoa thanh cong.\n");
            break;
        }
    }
    if(!found) printf("Khong tim thay ma sach.\n");
}
void capNhatBook(struct Book books[], int n) {
    char code[20];
    printf("Nhap ma sach can cap nhat: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';

    int found = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp(books[i].code, code) == 0) {
            found = 1;
            printf("Nhap thong tin moi cho sach:\n");
            nhapBook(&books[i]);
            printf("Cap nhat thanh cong.\n");
            break;
        }
    }
    if(!found) printf("Khong tim thay ma sach.\n");
}
void sapXepBook(struct Book books[], int n) {
    int choice;
    printf("Chon kieu sap xep theo gia:\n1. Tang dan\n2. Giam dan\nLua chon: ");
    scanf("%d", &choice);
    getchar();
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int swap = 0;
            if(choice == 1 && books[i].price > books[j].price) swap = 1;
            if(choice == 2 && books[i].price < books[j].price) swap = 1;
            if(swap) {
                struct Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep xong.\n");
}
void timKiemBook(struct Book books[], int n) {
    char title[100];
    printf("Nhap ten sach can tim: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(strstr(books[i].title, title) != NULL) { 
            hienThiBook(books[i]);
            found = 1;
        }
    }
    if(!found) printf("Khong tim thay sach.\n");
}
int main() {
    struct Book books[MAX];
    int n = 0;
    int choice;
    do {
        printf("\n--- MENU QUAN LY SACH ---\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma\n");
        printf("5. Cap nhat thong tin sach theo ma\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 
        switch(choice) {
            case 1: {
                printf("Nhap so luong sach: ");
                scanf("%d", &n);
                getchar();
                if(n > MAX) n = MAX;
                for(int i = 0; i < n; i++) {
                    printf("\nNhap thong tin sach thu %d:\n", i+1);
                    nhapBook(&books[i]);
                }
                break;
            }
            case 2: 
			    hienThiTatCa(books, n); 
				break;
            case 3: 
			    themBook(books, &n); 
				break;
            case 4: 
			    xoaBook(books, &n);
				break;
            case 5: 
			    capNhatBook(books, n); 
				break;
            case 6: 
			    sapXepBook(books, n); 
				break;
            case 7: 
			    timKiemBook(books, n); 
			    break;
            case 8: 
			    printf("Thoat chuong trinh.\n"); 
				break;
            default: 
			    printf("Lua chon khong hop le.\n");
        }
    } while(choice != 8);
}
