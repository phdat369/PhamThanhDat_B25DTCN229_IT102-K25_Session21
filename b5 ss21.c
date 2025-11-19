#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct Product {
    char name[50];   
    float price;     
    int quantity;    
};

int main() {
    struct Product products[5];
    float totalValue = 0;
    for (int i = 0; i < 5; i++) {
        printf("\nNhap thong tin san pham thu %d:\n", i + 1);
        printf("Ten san pham: ");
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0';
        printf("Gia (VND): ");
        scanf("%f", &products[i].price);
        printf("So luong: ");
        scanf("%d", &products[i].quantity);
        getchar(); 
    }
    for (int i = 0; i < 5; i++) {
        totalValue += products[i].price * products[i].quantity;
    }
    printf("\n=== Tong gia tri tat ca san pham ===\n");
    printf("Tong gia tri: %.2f VND\n", totalValue);
}
