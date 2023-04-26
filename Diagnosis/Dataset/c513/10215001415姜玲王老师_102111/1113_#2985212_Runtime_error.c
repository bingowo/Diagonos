#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void plus(char*a,char*b)
{   int i,d;
    char c[100]={0};
    for(i=0;i<100;i++)
    {
        if(a[i]==0){a[i]='0';}
        if(b[i]==0){b[i]='0';}
        d=(a[i]+b[i]-2*'0'+c[i])/10;
        c[i]=(a[i]+b[i]-2*'0'+c[i])%10;
        c[i+1]+=d;

    }
    if(c[i]) c[i]+='0';
    strcpy(a,c);
}
int main()
{
int k,n,i,j;
char a[10][100]={0};
char ans[100]={0};
a[9][0]='1';
a[8][0]='0';
scanf("%d %d",&k,&n);
if(n==1) {printf("0");return 0;}
if(n==2) {printf("1");return 0;}
for(i=3;i<=n;i++)
{   memset(ans,0,sizeof(char)*100);
    for(j=0;j<k;j++)
        plus(ans,a[9-k]);
    for(j=0;j<9;j++)
    {strcpy(a[j],a[j+1]);}
    strcpy(a[j],ans);

}
for(i=100;ans[i]==0||ans[i]=='0';i--);
for(;i>=0;i--)
 printf("%c",ans[i]);


}
