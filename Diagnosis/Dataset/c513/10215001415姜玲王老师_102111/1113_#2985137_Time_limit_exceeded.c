#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void plus(char*a,char*b)
{
    for(int i=0;i<strlen(a)||i<strlen(b);i++)
    {
        if(a[i]>='0'){a[i]-='0';}
        if(b[i]>='0'){b[i]-='0';}
        if(a[i]+b[i]>10){a[i]=a[i]+b[i]-10+'0';a[i+1]+=(a[i]+b[i])/10;}
        else a[i]=a[i]+b[i]+'0';
    }
}
int main()
{
int k,n,i,j;
char a[10][100]={0};
char ans[100];
a[9][0]='1';
a[8][0]='0';
scanf("%d %d",&k,&n);
if(n==1) {printf("0");return 0;}
if(n==2) {printf("1");return 0;}
for(i=3;i<=n;i++)
{

    for(j=0;j<k;i++)
        plus(ans,a[9-k]);
    for(j=0;j<9;j++)
    {
        strcpy(a[j],a[j+1]);
        strcpy(a[j],ans);
    }

}
for(i=100;ans[i]==0;i--);
for(;i>=0;i--)
    printf("%c",ans[i]);


}
