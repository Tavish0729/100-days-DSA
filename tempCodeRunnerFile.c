#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

void display(Employee A) {
    printf("Name: %s\n", A.name);
    printf("Age: %d\n", A.age);
    printf("Salary: %.2f\n", A.salary);
}

int main() {

    Employee a = {"Tavish Mahajan", 18, 10000};
    display(a);
    return 0;
}
