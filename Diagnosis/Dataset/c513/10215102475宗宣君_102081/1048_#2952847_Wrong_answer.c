#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
int m;
int n;
int c;
}record;
int cmp(const void *a,const void*b)
{
    record A = *(record*)a,B=*(record *)b;
    return B.n-A.n;
}
int trans(char *a,record *A)
{
    int i,j = 0;
    for(i =0;i<strlen(a);i++)
    {
        if(a[i]=='x')
        {
            if(i==0) {A[j].m = 1;A[j].c = 1;}
            else if(isdigit(a[i-1]))
            {A[j].m = a[i-1] - '0';
            if(a[i-2]=='-') A[j].c = -1;
            else A[j].c = 1;}
            if(a[i+1]=='^') A[j].n = a[i+2]-'0';
            else A[j].n = 1;
            j++;
        }
    }
    if(isdigit(a[strlen(a)-1])&&(a[strlen(a)-2]!='^'||strlen(a)==1))
       {
           A[j].m = a[strlen(a)-1] - '0';
           A[j].n = 0;
           if(a[strlen(a)-2]=='-') A[j].c = -1;
           else A[j].c = 1;
           j++;
       }
       return j;
}
int main()
{
    char a[101],b[101];
    int i,j,k;
    while(scanf("%s %s",a,b)!=EOF)
    {
        k = 0;
        record p[50],q[50],res[50];
        int ans[50] = {0};
        int M= trans(a,p),N= trans(b,q);
        for(i = 0;i<M;i++)
        {for(j = 0;j<N;j++)
            {res[k].m = p[i].m*q[j].m;
            res[k].n = p[i].n+q[j].n;
            res[k].c = p[i].c*q[j].c;
            k++;}
            }
        qsort(res,k,sizeof(record),cmp);
        j = 0;
        for(i = 0;i<k-1;i++)
        {
            ans[j] = ans[j]+res[i].m*res[i].c;
            if(res[i].n!=res[i+1].n) j++;
        }
        for(i= 0;i<j;i++)
            if(ans[i]) printf("%d ",ans[i]);
        if(res[k-1].m) printf("%d",res[k-1].m*res[k-1].c);
        printf("\n");
    }
    return 0;
}
