#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stu
{
    long num;
    int sco;
}STU;
int cmp1(const void *a,const void *b)
{
    STU a1=*(STU *)a;
    STU b1=*(STU *)b;
    int sco1=a1.sco;
    int sco2=b1.sco;
    long num1,num2;
    num1=atoi(a1.num);
    num2=atoi(b1.num);
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
        char score[m];
        for(int i=0;i<m;i++)scanf("%d",&score[i]);
        a=(STU*)malloc(sizeof(STU)*n);
        char sol[m+1];
        for(int i=0;i<n;i++){
            for(int p=0;p<m;p++)sol[p]=0;
            scanf("%d",&a[i].num);
            int t=0,lim;
            scanf("%d",&lim);
            for(t=0;t<lim;t++)scanf("%d",&sol[t++]);
            for(int st=0;st<sol[0];st++){
                a[i].sco=0;
                a[i].sco+=score[sol[st]-1];
            }
        }
        qsort(a,n,sizeof(STU),cmp1);
        for(int q=0;q<n;q++){
            if (a[q].sco>=g)printf("%s %d\n",a[q].num,a[q].sco);
        }
    }
    return 0;
}
