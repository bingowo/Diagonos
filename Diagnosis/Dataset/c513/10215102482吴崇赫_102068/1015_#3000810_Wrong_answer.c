#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 105

int Prime[35]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,59,61,67,71,73,79,83,89,97,101,103,107};

void reverse(int *a,int n)
{
    int temp;
    for(int i=0,j=n-1;i<j;++i,--j){
        temp=a[i];a[i]=a[j];a[j]=temp;
    }
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char input1[N]={0},input2[N]={0};
        char s[N/2][3],t[N/2][3];
        for(int i=0;i<N/2;++i){
            for(int j=0;j<3;++j)s[i][j]=t[i][j]=0;
        }
        scanf("%s%s",input1,input2);
        int prm1[N],prm2[N],p1=0,p2=0;
        int ret[N];
        for(int i=0;i<N;++i)ret[i]=prm1[i]=prm2[i]=0;

        int ti=0,tj=0,si=0,sj=0;
        for(int i=0;i<strlen(input1);++i){
            if(input1[i]!=',')s[si][sj++]=input1[i];
            else{si++;sj=0;}
        }
        for(int i=0;i<strlen(input2);++i){
            if(input2[i]!=',')t[ti][tj++]=input2[i];
            else{ti++;tj=0;}
        }
        for(int i=0;i<=si;++i)prm1[p1++]=atoi(s[i]);
        for(int i=0;i<=ti;++i)prm2[p2++]=atoi(t[i]);
        reverse(prm1,p1);reverse(prm2,p2);
        //printa(prm1,p1);

        int max=p1>p2?p1+2:p2+2;
        for(int i=0;i<=max;++i){
            int sum=prm1[i]+prm2[i]+ret[i];
            if(sum<Prime[i]){
                ret[i]=sum;
            }
            else{
                ret[i+1]+=sum/Prime[i];
                ret[i]=sum%Prime[i];
            }
        }
        printf("case #%d:\n",x++);
        while(ret[max]==0)max--;
        for(int k=max;k>0;--k)printf("%d,",ret[k]);
        printf("%d\n",ret[0]);
    }


    return 0;
}