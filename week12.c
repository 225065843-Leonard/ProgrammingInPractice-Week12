#include <stdio.h>
#include <string.h>

// Define the structure for Part 3
typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

// --- Function Prototypes ---
void swapSalaries(double *a, double *b);
void giveRaise(double salaries[], int n, double percent);
void updateSalary(Employee *e, double newSalary);

int main() {
    // ==========================================
    // PART 1: Warm-up (Address and Dereference)
    // ==========================================
    printf("--- PART 1: Warm-up ---\n");
    int number = 50;
    int *ptr = &number; // ptr stores the address of number
    
    printf("Original number: %d\n", number);
    printf("Address of number: %p\n", (void*)&number);
    printf("Value at ptr (dereferenced): %d\n", *ptr);
    
    *ptr = 100; // Change the value using the pointer
    printf("Number after changing *ptr: %d\n\n", number);

    // ==========================================
    // PART 2: Pass by Address (Swap Salaries)
    // ==========================================
    printf("--- PART 2: Swapping Salaries ---\n");
    double sal1 = 15000.00;
    double sal2 = 25000.00;
    
    printf("Before swap: Sal1 = %.2f, Sal2 = %.2f\n", sal1, sal2);
    
    // Pass the ADDRESSES using &
    swapSalaries(&sal1, &sal2); 
    
    printf("After swap:  Sal1 = %.2f, Sal2 = %.2f\n\n", sal1, sal2);

    // ==========================================
    // PART 3: Arrays and Pointers (Give Raise)
    // ==========================================
    printf("--- PART 3: Array Modification ---\n");
    double staffSalaries[3] = {10000.00, 12000.00, 14000.00};
    
    printf("Salary of staff[0] before raise: %.2f\n", staffSalaries[0]);
    
    // Pass the array (which is already an address)
    giveRaise(staffSalaries, 3, 10.0); // 10% raise
    
    printf("Salary of staff[0] after raise:  %.2f\n\n", staffSalaries[0]);

    // ==========================================
    // PART 4: Pointers to Structures (->)
    // ==========================================
    printf("--- PART 4: Update Structure via Pointer ---\n");
    Employee emp = {1001, "Maria", 18500.50};
    
    printf("Before update: %s earns %.2f\n", emp.name, emp.salary);
    
    // Pass the ADDRESS of the structure
    updateSalary(&emp, 21000.00);
    
    printf("After update:  %s earns %.2f\n", emp.name, emp.salary);

    return 0;
}

// --- Function Definitions ---

// 1. Swap using pointers (dereferencing with *)
void swapSalaries(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Modify array using a pointer (arrays decay to pointers)
void giveRaise(double salaries[], int n, double percent) {
    for (int i = 0; i < n; i++) {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

// 3. Modify structure using a pointer (arrow operator ->)
void updateSalary(Employee *e, double newSalary) {
    e->salary = newSalary; // Arrow operator is shorthand for (*e).salary
}