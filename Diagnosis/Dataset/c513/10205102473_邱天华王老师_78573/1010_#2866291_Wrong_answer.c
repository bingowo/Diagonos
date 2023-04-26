#include<stdio.h>
int tranf3(int n)
{
    int i=0;
    int t=n;
    int s[10]={0};
    while(t!=0)
    {
       s[i]=t%2;
       t/=2;
       i++;
    }
    if(n<1000&&n>=100)
    {
        for(int j=9;j>=0;j--)printf("%d",s[j]);
    }
    else if(n<100&&n>=10)
    {
         for(int j=6;j>=0;j--)printf("%d",s[j]);

    }
    else
         for(int j=3;j>=0;j--)printf("%d",s[j]);
    return 0;
}
int main()
{
    char le[501];
    char tem[4];
    int len,tmp;
    int tranf3(int n);
    gets(le);
    len=strlen(le);
    for(int i=0;i<=len;i+=3)
    {
        tem[0]=le[i];
        tem[1]=le[i+1];
        tem[2]=le[i+2];
        tmp=atoi(tem);
        printf("%d\n",tmp);
        tranf3(tmp);
    }
    
    return 0;

}
