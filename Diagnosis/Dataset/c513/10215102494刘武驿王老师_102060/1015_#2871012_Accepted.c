#include <stdio.h>
#include <string.h>
void multi(int *a,int b,int* res,int lena,int lenres)
{
    int next=0,tmp,i;
    for(i=0;i<lena;i++)
    {
        tmp=a[lena-i-1]*b;
        tmp+=next;
        res[lenres-i-1]=tmp%10;
        next=tmp/10;
    }
}
void plus(int *a,int*b,int* res,int len)
{
    int next=0,tmp,i;
    for(i=0;i<len;i++)
    {
        tmp=a[len-i-1]+b[len-i-1]+next;
        res[len-i-1]=tmp%10;
        next=tmp/10;
    }
}
int main()
{
    int T, I, weight[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int ten[25],ten1[25],sum;
    scanf("%d",&sum);
    char wait=getchar();
    for(int l=0;l<sum;l++)
    {
    for(int i=0;i<25;i++)
    {
        ten[i]=0;
        ten1[i]=0;
    }
    char c;
    scanf("%d",&ten[24]);
    int i=23;
    while((c=getchar())!=' ') scanf("%d",&ten[i--]);
    int trans[25];
    for(int j=0;j<=i;j++) trans[j]=ten[j];
    for(int j=i+1;j<25;j++) trans[j]=ten[25+i-j];
    for(int j=0;j<25;j++) ten[j]=trans[j];
    scanf("%d",&ten1[24]);
    i=23;
    while((c=getchar())!='\n') scanf("%d",&ten1[i--]);
    for(int j=0;j<=i;j++) trans[j]=ten1[j];
    for(int j=i+1;j<25;j++) trans[j]=ten1[25+i-j];
    for(int j=0;j<25;j++) ten1[j]=trans[j];
    int next=0;
    int res[26];
    for(i=0;i<26;i++) res[i]=0;
    int tmp;
    for(i=24;i>=0;i--)
    {
        tmp=ten[i]+ten1[i]+next;
        next=tmp/weight[24-i];
        res[i+1]=tmp%weight[24-i];
    }
    if (next!=0) res[0]=next;
    int flag=0;
    printf("case #%d:\n",l);
    for(i=0;i<26;i++)
    {
        if(res[i]!=0) flag=1;
        if(flag==1)
        {
            printf("%d",res[i]);
            if(i<25) printf(",");
            else printf("\n");
        }
    }
    if(flag==0) printf("0\n");

    }
}
