#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct employee {
    char name[50];
    int id;
    float salary;
    char title[50];
};

struct employee employees[MAX_EMPLOYEES];
int num_employees = 0;

void add_employee();
void print_employees();

int main() {
    int choice;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Print Employees\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                print_employees();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void add_employee() {
    struct employee emp;

    printf("\nEnter employee name: ");
    scanf("%s", emp.name);
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    printf("Enter employee job title: ");
    scanf("%s", emp.title);

    employees[num_employees++] = emp;
    printf("\nEmployee added successfully\n");
}

void print_employees() {
    if (num_employees == 0) {
        printf("\nNo employees to display\n");
        return;
    }

    printf("\nEmployees:\n");
    printf("%-20s %-10s %-10s %-20s\n", "Name", "ID", "Salary", "Job Title");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < num_employees; i++) {
        printf("%-20s %-10d %-10.2f %-20s\n", employees[i].name, employees[i].id, employees[i].salary, employees[i].title);
    }
}
