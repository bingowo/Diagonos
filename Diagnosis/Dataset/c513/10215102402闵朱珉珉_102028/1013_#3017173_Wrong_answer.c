#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int GCD(int a,int b)
{
    int max=b;
    int min=a;
    while(max%min)
    {
        int temp=max%min;
        max=min;
        min=temp;
    }
    return min;
}
int main()
{
    char s[32];
    scanf("%s",s);
    int A=0,B=0,C=1,len=strlen(s),i=0;
    for (;i<len;i++)
    {
        if (s[i]=='.') {i++;break;}
        int t=0;
        if (s[i]=='1') t=1;
        else if(s[i]=='2') t=-1;
        A=A*3+t;
    }
    for (;i<len;i++)
    {
        int t=0;
        if (s[i]=='1') t=1;
        else if(s[i]=='2') t=-1;
        B=B*3+t;
        C*=3;
    }
     if(A && B<0)
    {
        A--;
        B=C+B;
    }
    else if(A<0 && B>0)
    {
        A++;
        B=C-B;
        if(A==0) B=-B;
    }
    if(B==0)
    {
        printf("%d\n",A);
    }
    else{
    int t=GCD(abs(B),abs(C));
        if(A!=0)
        {
            printf("%d ",A);
        }
        printf("%d %d\n",B/t,C/t);
    }
    return 0;
}
