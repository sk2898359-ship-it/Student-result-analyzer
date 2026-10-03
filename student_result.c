#include <stdio.h>

char getGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 40) return 'D';
    else return 'F';
}

int main() {
    int students, subjects;
    float marks, total, avg;

    printf("Enter number of students: ");
    scanf("%d", &students);

    printf("Enter number of subjects: ");
    scanf("%d", &subjects);

    FILE *fp = fopen("student_results.csv", "w");
    fprintf(fp, "Student,Total,Average,Grade\n");

    for (int s = 1; s <= students; s++) {
        total = 0;
        printf("\nEntering marks for Student %d:\n", s);

        for (int i = 1; i <= subjects; i++) {
            printf("Enter marks of subject %d: ", i);
            scanf("%f", &marks);
            total += marks;
        }

        avg = total / subjects;
        char grade = getGrade(avg);

        fprintf(fp, "Student %d,%.2f,%.2f,%c\n", s, total, avg, grade);
        printf("Student %d Result Saved.\n", s);
    }

    fclose(fp);

    printf("\nAll results saved to student_results.csv\n");
    printf("Now run: python analyze_results.py\n");

    return 0;
}