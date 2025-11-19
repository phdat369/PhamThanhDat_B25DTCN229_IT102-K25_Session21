#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct Student {
    char name[50];   
    int age;         
    float grade;    
};

int main() {
    struct Student student1;
    printf("Nhap ten hoc sinh: ");
    fgets(student1.name, sizeof(student1.name), stdin);
    student1.name[strcspn(student1.name, "\n")] = '\0'; 
    printf("Nhap tuoi: ");
    scanf("%d", &student1.age);
    printf("Nhap diem trung binh: ");
    scanf("%f", &student1.grade);
    printf("\n--- Thong tin hoc sinh ---\n");
    printf("Ten: %s\n", student1.name);
    printf("Tuoi: %d\n", student1.age);
    printf("Diem trung binh: %.2f\n", student1.grade);
}

