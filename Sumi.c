#include <stdio.h>
#include <ctype.h>

typedef struct {
    char name[100];

    int roll;

    float cgpa;
} Student;

void writeStudentToFile(FILE *file, Student student) {
    fprintf(file, "Student info.....\n");

    fprintf(file, "Name: %s\n", student.name);
    fprintf(file, "Roll Number: %d\n", student.roll);
    fprintf(file, "CGPA: %.2f\n\n", student.cgpa);
}

void displayStudentInfo(Student student) {
    printf("Roll Number: %d\n", student.roll);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n\n", student.cgpa);
}

void readStudentFile(const char *filename) {
    FILE *file = fopen(filename, "r");


    int c;
    while ((c = getc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[100];

    for (int i = 0; i < n; i++) {
        printf("Enter information for Student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", students[i].name);

         printf("Enter roll: ");
        scanf("%d", &students[i].roll);


        printf("Enter CGPA: ");
        scanf("%f", &students[i].cgpa);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].cgpa < students[j + 1].cgpa) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Sorted student information\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        displayStudentInfo(students[i]);
    }


    FILE *bonusFile = fopen("bonus.txt", "w");
    FILE *normalFile = fopen("normal.txt", "w");




    for (int i = 0; i < n; i++) {
        if (students[i].cgpa >= 3.5) {
            writeStudentToFile(bonusFile, students[i]);
        } else {
            writeStudentToFile(normalFile, students[i]);
        }
    }


    fclose(bonusFile);
    fclose(normalFile);

    printf("Student information saved to 'bonus.txt' and 'normal.txt'.\n");


    printf("Reading 'bonus.txt':\n");
    readStudentFile("bonus.txt");

    printf("\nReading 'normal.txt':\n");
    readStudentFile("normal.txt");

    return 0;
}
