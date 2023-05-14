#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 50

typedef struct {
    char name[50];
    int roll_number;
    int marks;
    char grade;
} student;

void add_student(student students[], int *num_students);
void print_students(student students[], int num_students);

int main() {
    student students[MAX_STUDENTS];
    int num_students = 0;
    int option;

    do {
        printf("1. Add student\n");
        printf("2. Print student list\n");
        printf("3. Quit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                print_students(students, num_students);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    } while (option != 3);

    return 0;
}

void add_student(student students[], int *num_students) {
    student new_student;
    printf("Enter name: ");
    scanf("%s", new_student.name);
    printf("Enter roll number: ");
    scanf("%d", &new_student.roll_number);
    printf("Enter marks: ");
    scanf("%d", &new_student.marks);
    if (new_student.marks >= 90) {
        new_student.grade = 'A';
    } else if (new_student.marks >= 80) {
        new_student.grade = 'B';
    } else if (new_student.marks >= 70) {
        new_student.grade = 'C';
    } else if (new_student.marks >= 60) {
        new_student.grade = 'D';
    } else if (new_student.marks >= 50) {
        new_student.grade = 'E';
    } else {
        new_student.grade = 'F';
    }
    students[*num_students] = new_student;
    *num_students += 1;
}

void print_students(student students[], int num_students) {
    int i;
    printf("Name\tRoll Number\tMarks\tGrade\n");
    for (i = 0; i < num_students; i++) {
        printf("%s\t%d\t\t%d\t%c\n", students[i].name, students[i].roll_number, students[i].marks, students[i].grade);
    }
}
