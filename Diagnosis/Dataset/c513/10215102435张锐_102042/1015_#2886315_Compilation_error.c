#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int prime(int m)
{
    int i;
    int k=(float)sqrt(m)+0.5;
    if(m<=1) return 0;
    for(i=2;i<=k;i++)
        if(m%i==0) return 0;
    else return 1;
}
void add(char a,char b,int answer,int *last,int l,int *p,int num)
{
    int A=a-'0',B=b-'0';
    int x=A+B+*last;
    if(x>=*(p+num)) {(*last)=1;answer[l]=x-p[num];}
    else {(*last)=0;answer[l]=x-p[num];}
}
int main()
{
    int t;
    scanf("%d",&t);
    int p[30];//质数列表
    for(int i=0,j=2;i<30;j++)
    {
        if(prime(j)) {p[i]=j;i++;}
    }
    for(int i=0;i<t;i++)
    {
        char a[30]={'0'},b[30]={'0'};
        scanf("%s",a);
        scanf("%s",b);
        printf("case #%d:\n",i);
        int answer[30]={'\0'};
        int lena=strlen(a),lenb=strlen(b);
        int last=0;int *la=&last;
        if(lena>lenb)
        {
            int j,num=0;
            for(j=lenb;j<lena;j++)
            {
                answer[j+1]=a[j];num++;
            }
            answer[j]='\0';
            for(int l=lenb-1;l>=0;l--)
            {
                add(a[l],b[l],answer,la,l,p,num);
            }
            answer[0]=last;
        }
        else if(lenb>lena)
        {
            int k;
            for(k=lena;k<lenb;k++)
            {
                answer[k+1]=b[k];
            }
            answer[k]='\0';
            for(int l=lena-1;l>=0;l--)
            {
                add(a[l],b[l],*answer,la,l,p,num);
            }
            answer[0]=last;
        }
        else
        {
            for(int l=lena-1;l>=0;l--)
            {
                add(a[l],b[l],answer,la,l,p,num);
            }
            answer[0]=last;
        }
        int len=strlen(answer);
        for(int o=0;o<len;o++)
        {
            if(o==0&&s[o]==0) continue;
            if(o!=len-1) printf("%d,",s[o]);
            else if(o==len-1) printf("%d",s[o]);
        }
    }
    return 0;
}
