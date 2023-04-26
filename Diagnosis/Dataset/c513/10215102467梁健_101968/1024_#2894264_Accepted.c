#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stu
{
    char num[12];
    int sco;
}STU;
int cmp1(const void *a,const void *b)
{
    STU a1=*(STU *)a;
    STU b1=*(STU *)b;
    int sco1=a1.sco;
    int sco2=b1.sco;
    long num1,num2;
    num1=atol(a1.num);
    num2=atol(b1.num);
    if(sco1!=sco2)return sco2-sco1;
    else return(num1>num2)?1:-1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        STU *a=NULL;
        int n,m,g;
        scanf("%d %d %d",&n,&m,&g);
        int score[m];
        for(int zo=0;zo<m;zo++){scanf("%d",&score[zo]);}
        a=(STU*)malloc(sizeof(STU)*n);
        for(int i=0;i<n;i++){
            //printf("i=%d\n",i);
            int lim=0;
            a[i].sco=0;
            scanf("%s %d",&a[i].num,&lim);
            int sol[lim];
            for(int t=0;t<lim;t++){
                    scanf("%d",&sol[t]);
                    a[i].sco+=score[sol[t]-1];
            }
        }
        qsort(a,n,sizeof(STU),cmp1);
        int ps=0;
        for(int q=0;q<n;q++){
            if(a[q].sco>=g)ps++;
        }
        printf("%d\n",ps);
        for(int q=0;q<n;q++){
            if (a[q].sco>=g)printf("%s %d\n",a[q].num,a[q].sco);
        }
        free(a);
    }
    return 0;
}
