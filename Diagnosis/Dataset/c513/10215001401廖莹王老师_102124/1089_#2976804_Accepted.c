#include <stdio.h>
#include <stdlib.h>
int n=0;
void chengji(int re[15],int p[15])
{
    int gd[100][100],sd[10000];
    memset(gd,0,sizeof(gd[0])*100);
     memset(sd,0,sizeof(sd[0])*10000);
    int i=0,j=0,k=0,h=0,m=0;
    for(i=0;i<n;i++){for(j=0;j<n;j++)gd[i][j]=re[i]*p[j];}
    for(i=0;i<(2*n-1);i++)
    {     for(j=0;j<=i;j++)
        {   k=abs(i-j);sd[i]=sd[i]+gd[j][k];}
    }
    for(i=0;i<n;i++)
    {   h=(m+sd[2*n-2-i])/10;
        re[n-1-i]=sd[2*n-2-i]+m-h*10;
        m=h;
    }
    return;
}
void jisuan(int h)
{
    int b=0,j=0,i=0,k=0,m=0;
    int p[15],re[15];
    char a[100]={0};
    memset(p,0,sizeof(p[0])*15);
    memset(re,0,sizeof(p[0])*15);
    scanf("%s %d %d",a,&b,&n);
    j=strlen(a);
    for(i=0;i<n;i++){if(j-i-1<0){p[n-i-1]=0;re[n-i-1]=0;}else {p[n-i-1]=a[j-i-1]-'0';re[n-i-1]=a[j-i-1]-'0';}}
    for(i=0;i<b-1;i++)
    {
        chengji(re,p);
    }
    printf("case #%d:\n",h);
    for(i=0;i<n;i++)printf("%d",re[i]);
    printf("\n");
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)jisuan(h);
}
