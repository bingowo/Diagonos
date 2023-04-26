// This is a C program that solves the problem of sorting students' scores in descending order and printing the number of students who scored above a certain score line.
// We start by including the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We define a structure to hold information about each student
struct student {
    char id[12]; // student ID
    int score; // student score
};

// We define a function to compare two students based on their scores and IDs
int cmp(const void *a, const void *b) {
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;
    if (s1->score != s2->score) {
        return s2->score - s1->score; // sort by score in descending order
    } else {
        return strcmp(s1->id, s2->id); // if scores are equal, sort by ID in ascending order
    }
}

int main() {
    int T; // number of test cases
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int N, M, G; // number of students, number of questions, score line
        scanf("%d %d %d", &N, &M, &G);
        int a[M]; // scores for each question
        for (int i = 0; i < M; i++) {
            scanf("%d", &a[i]);
        }
        struct student students[N]; // array of students
        for (int i = 0; i < N; i++) {
            scanf("%s", students[i].id);
            int S; // number of questions solved by the student
            scanf("%d", &S);
            students[i].score = 0; // initialize score to 0
            for (int j = 0; j < S; j++) {
                int q; // question number
                scanf("%d", &q);
                students[i].score += a[q-1]; // add score for this question to the student's total score
            }
        }
        qsort(students, N, sizeof(struct student), cmp); // sort the students array using the cmp function
        printf("case #%d:\n", t);
        int count = 0; // count of students who scored above the score line
        for (int i = 0; i < N; i++) {
            if (students[i].score >= G) {
                count++;
            } else {
                break; // since the array is sorted in descending order, we can stop counting once we reach a student who scored below the score line
            }
        }
        printf("%d\n", count); // print the count of students who scored above the score line
        for (int i = 0; i < count; i++) {
            printf("%s %d\n", students[i].id, students[i].score); // print the IDs and scores of the top students
        }
    }
    return 0;
}