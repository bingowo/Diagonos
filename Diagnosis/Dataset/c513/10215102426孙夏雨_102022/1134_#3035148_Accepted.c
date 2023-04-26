#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[15];
    int C;
    int M;
    int E;
    int A;
} STU;

int cmpC(const void* p3,const void* p4)
{
    STU* p1=(STU* )p3;
    STU* p2=(STU* )p4;
    if((p1->C)<(p2->C)) return 1;
    else if((p1->C)>(p2->C)) return -1;
    else{ return strcmp(p1->s,p2->s);}
}

int cmpM(const void* p3,const void* p4)
{
    STU* p1=(STU* )p3;
    STU* p2=(STU* )p4;
    if((p1->M)<(p2->M)) return 1;
    else if((p1->M)>(p2->M)) return -1;
    else{ return strcmp(p1->s,p2->s);}
}

int cmpE(const void* p3,const void* p4)
{
    STU* p1=(STU* )p3;
    STU* p2=(STU* )p4;
    if((p1->E)<(p2->E)) return 1;
    else if((p1->E)>(p2->E)) return -1;
    else{ return strcmp(p1->s,p2->s);}
}

int cmpA(const void* p3,const void* p4)
{
    STU* p1=(STU* )p3;
    STU* p2=(STU* )p4;
    if((p1->A)<(p2->A)) return 1;
    else if((p1->A)>(p2->A)) return -1;
    else{ return strcmp(p1->s,p2->s);}
}

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n=0;
        scanf("%d",&n);
        STU* p=(STU* )malloc(n*sizeof(STU));
        for(int i=0;i<n;i++){
            int c=0,m=0,e=0;
            scanf("%s %d %d %d",(p+i)->s,&c,&m,&e);
            (p+i)->C=c;
            (p+i)->M=m;
            (p+i)->E=e;
            double a=0.5+(c+m+e)/3.0;
            (p+i)->A=(int)a;
            //printf("A=%d,a=%f\n",(p+i)->A,a);
        }
        printf("case #%d:\n",t);
        qsort(p,n,sizeof(STU),cmpA);
        printf("A:\n");
        int Am=p->A;
        int k=0;
        while((p+k)->A==Am){
            printf("%s\n",(p+k)->s);
            k++;
        }
        k=0;
        qsort(p,n,sizeof(STU),cmpC);
        printf("C:\n");
        int Cm=p->C;
        while((p+k)->C==Cm){
            printf("%s\n",(p+k)->s);
            k++;
        }
        k=0;
        qsort(p,n,sizeof(STU),cmpM);
        printf("M:\n");
        int Mm=p->M;
        while((p+k)->M==Mm){
            printf("%s\n",(p+k)->s);
            k++;
        }
        k=0;
        qsort(p,n,sizeof(STU),cmpE);
        printf("E:\n");
        int Em=p->E;
        while((p+k)->E==Em){
            printf("%s\n",(p+k)->s);
            k++;
        }
        free(p);
    }
    return 0;
}