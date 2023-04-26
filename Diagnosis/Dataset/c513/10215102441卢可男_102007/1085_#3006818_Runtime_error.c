#include<stdio.h>
#include<string.h>
#define L 500
void input(int*a,char*s);
int compare(int*a,int*b);
void sub(int*a,int*b,int r);
void sub_0(int*a,int*b);
void output(int*a,int r);
int main()
{
    int a[L]={0};
    int b[L]={0};
    char s1[L]={0};
    char s2[L]={0};
    int r;
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        input(a,s1);
        input(b,s2);
        r=compare(a,b);
        sub(a,b,r);
        output(a,r);
        return 0;
    }
}
void input(int*a,char*s)
{
    int i,j;
    for(j=L-1,i=strlen(s)-1;i>=0;i--,j--)
    {
        a[j]=s[i]-'0';
    }
}
int compare(int*a,int*b)
{
    int i,j;
    int r=1;
    for(i=0;i<L;i++)
    {
        if(a[i]>b[i])
        {
            r=1;
            break;
        }
        if(a[i]<b[i])
        {
            r=-1;
            break;
        }
        return r;
    }

}
void sub(int*a,int*b,int r)
{
    r==1?sub_0 (a,b):sub_0 (b,a);
}
void sub_0(int*a,int*b)
{
    int i,j,k;
    for(i=L-1;i>=0;i--)
    {
        if(a[i]<b[i])
        {
            for(j=i-1;j>=0;j--)
            {
                if(a[j]>0)break;
            }
            a[j]-=1;
            for(k=j+1;k<i;k++)
            {
                a[k]=9;
            }
            a[i]+=10;
        }
        a[i]-=b[i];
    }
}
void output(int*a,int r )
{
    int i=0;
    int j;
    if(r==-1)printf("-");
   while(a[i]==0&&i<L)i++;
   if(i>=L)printf("0");
   for(j=i;j<L;j++)
   {
       printf("%d",a[j]);
   }printf("\n");


}
