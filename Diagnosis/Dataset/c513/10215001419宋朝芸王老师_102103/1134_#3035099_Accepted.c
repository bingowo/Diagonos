#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char num[12];
    int ave;
    int C;
    int M;
    int E;
}STU;

int cmpA(const void *A, const void *B){
    STU a = *(STU*)A, b = *(STU*)B;
    if(a.ave != b.ave) return b.ave-a.ave;
    else return strcmp(a.num,b.num);
}

int cmpC(const void *A, const void *B){
    STU a = *(STU*)A, b = *(STU*)B;
    if(a.C != b.C) return b.C-a.C;
    else return strcmp(a.num,b.num);
}

int cmpM(const void *A, const void *B){
    STU a = *(STU*)A, b = *(STU*)B;
    if(a.M != b.M) return b.M-a.M;
    else return strcmp(a.num,b.num);
}

int cmpE(const void *A, const void *B){
    STU a = *(STU*)A, b = *(STU*)B;
    if(a.E != b.E) return b.E-a.E;
    else return strcmp(a.num,b.num);
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int n;
        scanf("%d",&n);

        STU* stu = (STU*)malloc(n*sizeof(STU));
        for(int i = 0; i < n; i++){
            int a,b,c;
            scanf("%s%d%d%d",stu[i].num,&a,&b,&c);
            stu[i].ave = (int)((a+b+c)/3.0 + 0.5);
            stu[i].C = a;
            stu[i].M = b;
            stu[i].E = c;
        }

        printf("case #%d:\n",R);

        qsort(stu,n,sizeof(STU),cmpA);
        printf("A:\n");
        for(int i = 0; i < n; i++){
            if(stu[i].ave == stu[0].ave) printf("%s\n",stu[i].num);
            else break;
        }

        qsort(stu,n,sizeof(STU),cmpC);
        printf("C:\n");
        for(int i = 0; i < n; i++){
            if(stu[i].C == stu[0].C) printf("%s\n",stu[i].num);
            else break;
        }

        qsort(stu,n,sizeof(STU),cmpM);
        printf("M:\n");
        for(int i = 0; i < n; i++){
            if(stu[i].M == stu[0].M) printf("%s\n",stu[i].num);
            else break;
        }

        qsort(stu,n,sizeof(STU),cmpE);
        printf("E:\n");
        for(int i = 0; i < n; i++){
            if(stu[i].E == stu[0].E) printf("%s\n",stu[i].num);
            else break;
        }

    }
    return 0;
}
