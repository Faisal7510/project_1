#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    int id;
    double basic_salary;
} Employee;


double calculate_tax(double gross_salary) {
    if (gross_salary <= 25000) {
        return 0; 
    } else if (gross_salary <= 50000) {
        return gross_salary * 0.10; 
    } else {
        return gross_salary * 0.20; 
    }
}

int main() {
    Employee emp;

    printf("Enter employee name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0; 

   printf("Enter employee ID: ");
    if (scanf("%d", &emp.id) != 1) {
        printf("Error: Invalid input for employee ID.\n");
        return 1;
    }

     printf("Enter basic salary: ");
    if (scanf("%lf", &emp.basic_salary) != 1) {
        printf("Error: Invalid input for basic salary.\n");
        return 1;
    }

    const double HRA_PERCENT = 0.20; 
    const double DA_PERCENT = 0.50;  
    const double PF_PERCENT = 0.12;  

    
    double hra = emp.basic_salary * HRA_PERCENT;
    double da = emp.basic_salary * DA_PERCENT;
    double pf = emp.basic_salary * PF_PERCENT;


    double gross_salary = emp.basic_salary + hra + da;
    double tax = calculate_tax(gross_salary);
    double net_salary = gross_salary - pf - tax;

    
    printf("\n========== SALARY SLIP ==========");
    printf("\nEmployee Name: %s", emp.name);
    printf("\nEmployee ID: %d", emp.id);
    printf("\nBasic Salary: %.2lf", emp.basic_salary);
    printf("\nHRA: %.2lf", hra);
    printf("\nDA: %.2lf", da);
    printf("\nPF: %.2lf", pf);
    printf("\nTax: %.2lf", tax);
    printf("\nGross Salary: %.2lf", gross_salary);
    printf("\nNet Salary: %.2lf", net_salary);
    printf("\n=================================\n");

    
    
    FILE *file = fopen("salary_slip.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return 1;
    }
    fprintf(file, "========== SALARY SLIP =========="
                   "\nEmployee Name: %s"
                   "\nEmployee ID: %d"
                   "\nBasic Salary: %.2lf"
                   "\nHRA: %.2lf"
                   "\nDA: %.2lf"
                   "\nPF: %.2lf"
                   "\nTax: %.2lf"
                   "\nGross Salary: %.2lf"
                   "\nNet Salary: %.2lf"
                   "\n=================================\n",
            emp.name, emp.id, emp.basic_salary, hra, da, pf, tax, gross_salary, net_salary);
    fclose(file);

    printf("\nSalary slip saved to 'salary_slip.txt'\n");

    return 0;
}