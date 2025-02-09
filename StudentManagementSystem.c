#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 1000
#define USERNAME "student"
#define PASSWORD "student"

// Structure for student information
typedef struct {
    int Student_ID;
    char full_name[50];
    char father_name[50];
    char mother_name[50];
    int age;
} StudentInfo;

// Function prototypes
void login();
void addStudentsInfo(StudentInfo Student_DB[], int *StudentCount);
void updateStudentsInfo(StudentInfo Student_DB[], int StudentCount);
void findStudentsInfo(StudentInfo Student_DB[], int StudentCount);
void countStudents(int StudentCount);
void printDB(StudentInfo Student_DB[], int StudentCount);
void ReadDB(FILE *file, StudentInfo Student_DB[], int *StudentCount);
void WriteDB(FILE *file, StudentInfo Student_DB[], int StudentCount);

int main() {
    login();
    StudentInfo Student_DB[MAX_STUDENTS];
    int StudentCount = 0, option;
    FILE *file = fopen("StudentManagement.txt", "r");
    if (file != NULL) {
        ReadDB(file, Student_DB, &StudentCount);
        fclose(file);
    }

    while (1) {
        printf("\n\n1 >> Add Student Info\n");
        printf("2 >> Update Student Info\n");
        printf("3 >> Find Student Info by ID\n");
        printf("4 >> Total Students\n");
        printf("5 >> Print All Students Database\n");
        printf("6 >> Exit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);

        if (option == 6) break;

        switch (option) {
            case 1:
                addStudentsInfo(Student_DB, &StudentCount);
                break;
            case 2:
                updateStudentsInfo(Student_DB, StudentCount);
                break;
            case 3:
                findStudentsInfo(Student_DB, StudentCount);
                break;
            case 4:
                countStudents(StudentCount);
                break;
            case 5:
                printDB(Student_DB, StudentCount);
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    }

    file = fopen("StudentManagement.txt", "w");
    if (file != NULL) {
        WriteDB(file, Student_DB, StudentCount);
        fclose(file);
    }

    return 0;
}

void login() {
    char username[20], password[20];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    
    if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
        printf("\nWelcome! Login Successful!\n");
    } else {
        printf("\nIncorrect username or password. Exiting...\n");
        exit(1);
    }
}

void addStudentsInfo(StudentInfo Student_DB[], int *StudentCount) {
    if (*StudentCount >= MAX_STUDENTS) {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    StudentInfo student;
    printf("Enter Student ID: ");
    scanf("%d", &student.Student_ID);
    getchar();
    
    for (int i = 0; i < *StudentCount; i++) {
        if (Student_DB[i].Student_ID == student.Student_ID) {
            printf("Student ID already exists!\n");
            return;
        }
    }

    printf("Enter Student's Full Name: ");
    fgets(student.full_name, 50, stdin);
    strtok(student.full_name, "\n");
    printf("Enter Father's Name: ");
    fgets(student.father_name, 50, stdin);
    strtok(student.father_name, "\n");
    printf("Enter Mother's Name: ");
    fgets(student.mother_name, 50, stdin);
    strtok(student.mother_name, "\n");
    printf("Enter Age: ");
    scanf("%d", &student.age);

    Student_DB[(*StudentCount)++] = student;
}

void updateStudentsInfo(StudentInfo Student_DB[], int StudentCount) {
    int id, option;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    getchar();
    
    for (int i = 0; i < StudentCount; i++) {
        if (Student_DB[i].Student_ID == id) {
            printf("1 >> Update Name\n2 >> Update Father's Name\n3 >> Update Mother's Name\n4 >> Update Age\n");
            printf("Enter option: ");
            scanf("%d", &option);
            getchar();

            switch (option) {
                case 1:
                    printf("Enter New Name: ");
                    fgets(Student_DB[i].full_name, 50, stdin);
                    strtok(Student_DB[i].full_name, "\n");
                    break;
                case 2:
                    printf("Enter New Father's Name: ");
                    fgets(Student_DB[i].father_name, 50, stdin);
                    strtok(Student_DB[i].father_name, "\n");
                    break;
                case 3:
                    printf("Enter New Mother's Name: ");
                    fgets(Student_DB[i].mother_name, 50, stdin);
                    strtok(Student_DB[i].mother_name, "\n");
                    break;
                case 4:
                    printf("Enter New Age: ");
                    scanf("%d", &Student_DB[i].age);
                    break;
                default:
                    printf("Invalid option!\n");
            }
            return;
        }
    }
    printf("Student ID not found!\n");
}

void findStudentsInfo(StudentInfo Student_DB[], int StudentCount) {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < StudentCount; i++) {
        if (Student_DB[i].Student_ID == id) {
            printf("\nID: %d\nName: %s\nFather: %s\nMother: %s\nAge: %d\n", 
                Student_DB[i].Student_ID, Student_DB[i].full_name, Student_DB[i].father_name, Student_DB[i].mother_name, Student_DB[i].age);
            return;
        }
    }
    printf("Student ID not found!\n");
}

void countStudents(int StudentCount) {
    printf("Total Students: %d\n", StudentCount);
}

void printDB(StudentInfo Student_DB[], int StudentCount) {
    for (int i = 0; i < StudentCount; i++) {
        printf("%d %s %s %s %d\n", Student_DB[i].Student_ID, Student_DB[i].full_name, Student_DB[i].father_name, Student_DB[i].mother_name, Student_DB[i].age);
    }
}

void ReadDB(FILE *file, StudentInfo Student_DB[], int *StudentCount) {
    while (fscanf(file, "%d %49s %49s %49s %d", &Student_DB[*StudentCount].Student_ID, Student_DB[*StudentCount].full_name, Student_DB[*StudentCount].father_name, Student_DB[*StudentCount].mother_name, &Student_DB[*StudentCount].age) == 5) {
        (*StudentCount)++;
    }
}

void WriteDB(FILE *file, StudentInfo Student_DB[], int StudentCount) {
    for (int i = 0; i < StudentCount; i++) {
        fprintf(file, "%d %s %s %s %d\n", Student_DB[i].Student_ID, Student_DB[i].full_name, Student_DB[i].father_name, Student_DB[i].mother_name, Student_DB[i].age);
    }
}
