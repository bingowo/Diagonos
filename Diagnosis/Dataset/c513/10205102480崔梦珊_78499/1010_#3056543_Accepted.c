#include<stdio.h>

void f1(a)
{
    int ans[10]={0};
    int yu;
    int i=9;
    while(a!=0)
    {
        ans[i]=a%2;
        i--;
        a=a/2;
    }
    for(int j=0;j<10;j++)
    {
        printf("%d",ans[j]);
    }

}
void f2(a)
{
    int ans[4]={0};
    int yu;
    int i=3;
    while(a!=0)
    {
        ans[i]=a%2;
        i--;
        a=a/2;
    }
    for(int j=0;j<4;j++)
    {
        printf("%d",ans[j]);
    }

}

void f3(a)
{
    int ans[7]={0};
    int yu;
    int i=6;
    while(a!=0)
    {
        ans[i]=a%2;
        i--;
        a=a/2;
    }
    for(int j=0;j<7;j++)
    {
        printf("%d",ans[j]);
    }

}






int main()
{
    char s[501]={'\0'};
    char c;
    int num=0;
    while((c=getchar())!='\n')
    {
        s[num]=c;
        num++;
    }
    printf("0001");
    f1(num);
    if(num%3==0)
    {
        int z=num/3;
        int res[200][3];
        int k=0;
        int ans[200];
        for(int j=0;j<z;j++)
        {
            res[j][0]=s[k]-48;
            k++;
            res[j][1]=s[k]-48;
            k++;
            res[j][2]=s[k]-48;
            k++;
            ans[j]=(res[j][0]*10+res[j][1])*10+res[j][2];
            f1(ans[j]);
        }

    }
    if(num%3==1)
    {
        int z=num/3;
        int res[200][3];
        int k=0;
        int ans[200];
        for(int j=0;j<z;j++)
        {
            res[j][0]=s[k]-48;
            k++;
            res[j][1]=s[k]-48;
            k++;
            res[j][2]=s[k]-48;
            k++;
            ans[j]=(res[j][0]*10+res[j][1])*10+res[j][2];
            f1(ans[j]);
        }
        int m=s[3*z]-48;
        f2(m);

    }
    if(num%3==2)
    {
        int z=num/3;
        int res[200][3];
        int k=0;
        int ans[200];
        for(int j=0;j<z;j++)
        {
            res[j][0]=s[k]-48;
            k++;
            res[j][1]=s[k]-48;
            k++;
            res[j][2]=s[k]-48;
            k++;
            ans[j]=(res[j][0]*10+res[j][1])*10+res[j][2];
            f1(ans[j]);
        }
        int m=s[3*z]-48;
        int n=s[3*z+1]-48;
        f3(m*10+n);

    }
    return 0;

}
