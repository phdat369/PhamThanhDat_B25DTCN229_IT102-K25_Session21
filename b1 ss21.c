#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct Car {
    char model[100];   
    int year;          
    float price;       
};

int main() {
    struct Car myCar;
    strcpy(myCar.model, "Xe bo");
    myCar.year = 2000;
    myCar.price = 850000000;  
    printf("Thong tin xe:\n");
    printf("Mau xe: %s\n", myCar.model);
    printf("Nam san xuat: %d\n", myCar.year);
    printf("Gia xe: %.0f VND\n", myCar.price);
}
