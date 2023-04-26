#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int shu;
    int weizhi;
}PAIR;

int cmp1(const void* p3,const void* p4)
{
    PAIR* p1=(PAIR* )p3;
    PAIR* p2=(PAIR* )p4;
    if((p1->weizhi)>(p2->weizhi)) return 1;
    else return -1;
}

int cmp2(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if(*p1>*p2) return 1;
    else return -1;
}

int main()
{
    int m=0,n=0,x=0,num1=0,num2=0;
    scanf("%d",&m);
    int* A=(int* )malloc(m*sizeof(int));
    for(int i=0;i<m;i++) scanf("%d",(A+i));
    scanf("%d",&n);
    PAIR* B1=(PAIR* )malloc(n*sizeof(PAIR));
    int* B2=(int* )malloc(n*sizeof(int));
    for(int j=0;j<n;j++){
        scanf("%d",&x);
        int jj=0;
        for(;jj<m;jj++){
            if((*(A+jj))==x){
                (B1+num1)->shu=x;
                (B1+num1)->weizhi=jj;
                num1++;
                break;
            }
        }
        if(jj==m) {
            *(B2+num2)=x;
            num2++;
        }
    }
    if(num1!=0) qsort(B1,num1,sizeof(PAIR),cmp1);
    if(num2!=0) qsort(B2,num2,sizeof(int),cmp2);
    for(int k=0;k<num1;k++) printf("%d ",(B1+k)->shu);
    for(int kk=0;kk<num2;kk++) printf("%d ",*(B2+kk));
    free(A);
    free(B1);
    free(B2);
    return 0;
}
