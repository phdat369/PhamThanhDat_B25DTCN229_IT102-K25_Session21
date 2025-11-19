#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct Student {
    char name[50];
    int age;
    float grade;
};
void timKiemStudent(struct Student students[], int size, char searchName[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("\n=== Tim thay hoc sinh ===\n");
            printf("Ten: %s\n", students[i].name);
            printf("Tuoi: %d\n", students[i].age);
            printf("Diem trung binh: %.2f\n", students[i].grade);
            return;
        }
    }
    printf("\nKhong tim thay hoc sinh co ten '%s'\n", searchName);
}
int main() {
    struct Student students[5];
    char searchName[50];
    for (int i = 0; i < 5; i++) {
        printf("\nNhap thong tin hoc sinh thu %d:\n", i + 1);
        printf("Ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        printf("Diem trung binh: ");
        scanf("%f", &students[i].grade);
        getchar(); 
    }
    printf("\nNhap ten hoc sinh muon tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    timKiemStudent(students, 5, searchName);
}
