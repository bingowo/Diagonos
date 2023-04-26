#include<stdio.h>
#include<string.h>
char b[32];
void change(int a,char A[])
{
    int i=0;
    while(a>0)
    {
        A[i]='0'+a%2;
        a=a/2;
        i++;
    }
}
int main()
{
    int T,n;
    scanf("%d",&T);
    for(n=0;n<T;n++)
    {
        for(int k=0;k<32;k++)b[k]='2';
        int num;
        scanf("%d",&num);
        change(num,b);
        int t=1,t1=1,j;
        if(num==1)printf("case #%d:\n%d\n",n,t1);
        else
        {
            for(j=1;j<strlen(b);j++)
            {
                if(b[j]=='2')break;
                else
                {
                    if(t>t1)t1=t;
                    if(b[j]!=b[j-1])t++;
                    else t=1;
                }
            }
            if(b[strlen(b)]!=b[strlen(b)-1]&&t>t1)t1++;
            printf("case #%d:\n%d\n",n,t1);
        }
    }
    return 0;
}
