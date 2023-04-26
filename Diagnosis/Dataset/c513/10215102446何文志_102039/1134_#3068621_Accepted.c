#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student{
    char s[12];
    int C;
    int M;
    int E;
    int A;
}student;

int cmpA(const void *a, const void *b){
    student *a1 = (student*)a, *b1 = (student*)b;
    if(a1->A == b1->A){
        return strcmp(a1->s, b1->s);
    }
    return b1->A - a1->A;
}
int cmpC(const void *a, const void *b){
    student *a1 = (student*)a, *b1 = (student*)b;
    if(a1->C == b1->C){
        return strcmp(a1->s, b1->s);
    }
    return b1->C - a1->C;
}
int cmpM(const void *a, const void *b){
    student *a1 = (student*)a, *b1 = (student*)b;
    if(a1->M == b1->M){
        return strcmp(a1->s, b1->s);
    }
    return b1->M - a1->M;
}
int cmpE(const void *a, const void *b){
    student *a1 = (student*)a, *b1 = (student*)b;
    if(a1->E == b1->E){
        return strcmp(a1->s, b1->s);
    }
    return b1->E - a1->E;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int problem = 0;problem<T;++problem){
        int n = 0;
        scanf("%d",&n);
        student *students = (student*)calloc(n, sizeof(student));
        for(int stu = 0;stu<n;++stu){
            scanf("%s%d%d%d",students[stu].s, &students[stu].C, &students[stu].M, &students[stu].E);
            students[stu].A = (int)(((double)students[stu].C + (double)students[stu].M + (double)students[stu].E)
                                    /3.0 + 0.5);
        }

        printf("case #%d:\n",problem);

        qsort(students, n, sizeof(student), cmpA);
        int Amax = students[0].A;
        printf("A:\n");
        for(int i = 0;i<n;++i){
            if(students[i].A < Amax){
                break;
            }
            printf("%s\n",students[i].s);
        }

        qsort(students, n, sizeof(student), cmpC);
        int Cmax = students[0].C;
        printf("C:\n");
        for(int i = 0;i<n;++i){
            if(students[i].C < Cmax){
                break;
            }
            printf("%s\n",students[i].s);
        }

        qsort(students, n, sizeof(student), cmpM);
        int Mmax = students[0].M;
        printf("M:\n");
        for(int i = 0;i<n;++i){
            if(students[i].M < Mmax){
                break;
            }
            printf("%s\n",students[i].s);
        }

        qsort(students, n, sizeof(student), cmpE);
        int Emax = students[0].E;
        printf("E:\n");
        for(int i = 0;i<n;++i){
            if(students[i].E < Emax){
                break;
            }
            printf("%s\n",students[i].s);
        }
        free(students);
    }
    return 0;
}
