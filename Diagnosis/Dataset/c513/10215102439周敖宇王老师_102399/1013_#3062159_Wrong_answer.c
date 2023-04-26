#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    int i,j,l,A,B,C,flagA,flagB;
    A=0;
    B=0;
    C=1;
    scanf("%s",s);
    l=strlen(s);
    i=0;
    for(;i<l;i++)
    {
        if(s[i]=='.')  break;
        A*=3;
        if(s[i]=='1')  A++;
        if(s[i]=='2')  A--;
    }
    i++;
    for(;i<l;i++)
    {
        C*=3;
        B*=3;
        if(s[i]=='1')  B++;
        if(s[i]=='2')  B--;
    }
    if(A<0)
    {
        flagA=-1;
        A=-A;
    }  
    else  flagA=1;
    if(B<0)
    {
        flagB=-1;
        B=-B;
    }  
    else  flagB=1;
    while(B%3==0 && B!=0)
    {
        B/=3;
        C/=3;
    }
    if(B==0)
    {
        printf("%d",flagA*A);
    }
    else
    {
        if(A==0)  printf("%d %d",flagB*B,C);
        else
        {
            if(flagA==flagB)
            {
                if(flagA==-1)  printf("-");
                printf("%d %d %d",A,B,C);
            }
            else
            {
                if(flagA==-1)  printf("-");
                printf("%d %d %d",A-1,C-B,C);
            } 
        }
    }
    return 0;
}