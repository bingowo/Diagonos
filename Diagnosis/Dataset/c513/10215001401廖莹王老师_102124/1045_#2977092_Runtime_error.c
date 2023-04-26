#include <stdio.h>
#include <stdlib.h>
#define N 1000
typedef struct
{
    int ct;
    char c;
}point;
int n;
 point p[N][100];
int jilu(char s[100],point p[100])
{
    int i=0,k=1,j=0;
    p[0].c=s[0];
    for(i=1;s[i];i++)
    {
        if(s[i]!=s[i-1]){p[j].ct=k;k=1;j++;p[j].c=s[i];}
        else {k++;}
    }
    p[j].ct=k;
    return j+1;
}
int cmp(const void *a,const void *b)
{
   return  *(int*)a-*(int*)b;
}
int jisuan(int k)
{
    int a[N]={0},j=0,sum=0,i=0,s=0;
    for(i=0;i<n;i++)a[i]=p[i][k].ct;
    qsort(a,n,sizeof(a[0]),cmp);
    s=n/2;
    j=a[s];
    for(i=0;i<n;i++)sum=sum+abs(a[i]-j);
    return sum;
}
int main()
{
    int i=0,m=0,j=0;
    int sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   char s[100]={0};
        scanf("%s",s);
        if(i==0)m=jilu(s,p[i]);
        else jilu(s,p[i]);
    }
    for(i=0;i<m;i++)
    {
        for(j=1;j<n;j++){if(p[j][i].c!='\0' && p[j][i].c==p[j-1][i].c);else{printf("-1\n");return 0;}}
    }
    for(i=0;i<m;i++)
    {
        sum=sum+jisuan(i);
    }
    printf("%d",sum);
    return 0;
}
