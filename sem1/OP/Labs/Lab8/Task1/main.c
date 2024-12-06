#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100
#define MARKS_COUNT 5
#define MAX_STUDENTS 6
#define MAX_NAME_SIZE 15

typedef struct student
{
    char surname[10];
    char name[10];
    char birth[10];
    int marks[MARKS_COUNT];
    double average;
} student_struct;

void calculateAverage(student_struct *);
int compare(student_struct *, student_struct *);
int findSummerStudents(FILE *, student_struct *, int); // returns number of students
void printStudents(student_struct *, int);
student_struct readStudent(char[MAX_CHARS]);

int main()
{
    FILE *source = fopen("students.txt", "r");
    if (source == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return EXIT_FAILURE;
    }
    student_struct summerStudents[MAX_STUDENTS + 1];

    int summerStudentsCount = findSummerStudents(source, summerStudents, MAX_STUDENTS + 1);

    qsort(summerStudents, summerStudentsCount, sizeof(student_struct), compare);

    printStudents(summerStudents, summerStudentsCount);
}

void calculateAverage(student_struct *s)
{
    double sum = 0;
    for (int i = 0; i < MARKS_COUNT; i++)
    {
        sum += (double)(s->marks[i]);
    }
    s->average = sum / MARKS_COUNT;
}

int compare(student_struct *s1, student_struct *s2)
{
    return (int)((s1->average - s2->average) * 1000);
}

int findSummerStudents(FILE *source, student_struct *destination, int size)
{
    char line[MAX_CHARS];
    fgets(line, MAX_CHARS, source);

    int studNum = 0;
    for (int i = 0; line && i < size; i++)
    {
        student_struct temp = readStudent(line);

        char buffer[10];
        strcpy(buffer, temp.birth);
        strtok(buffer, ".");
        int month = atoi(strtok(NULL, "."));

        if (month == 6 || month == 7 || month == 8)
        {
            calculateAverage(&temp);
            destination[studNum++] = temp;
        }

        fgets(line, MAX_CHARS, source);
    }

    return studNum;
}

void printStudents(student_struct *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(array[i].surname);
        for (int j = strlen(array[i].surname); j < MAX_NAME_SIZE; j++)
        {
            printf(" ");
        }

        printf(array[i].name);
        for (int j = strlen(array[i].name); j < MAX_NAME_SIZE; j++)
        {
            printf(" ");
        }

        printf(array[i].birth);
        printf("     ");

        printf("%d", array[i].marks[0]);
        for (int j = 1; j < MARKS_COUNT; j++)
        {
            printf(", %d", array[i].marks[j]);
        }
        printf(" - %.2lf\n", array[i].average);
    }
}

student_struct readStudent(char line[MAX_CHARS])
{
    struct student result;

    sscanf(line, "%19[^,], %19[^,], %19[^,], %d, %d, %d, %d, %d",
           result.surname, result.name, result.birth,
           &result.marks[0], &result.marks[1], &result.marks[2],
           &result.marks[3], &result.marks[4]);

    return result;
}