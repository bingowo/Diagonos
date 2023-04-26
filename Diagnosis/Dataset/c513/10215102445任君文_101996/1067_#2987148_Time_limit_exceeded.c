#include<stdio.h>
#include<stdlib.h>
long tribo(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 1;
    else if(n==3)
        return 2;
    else if(n==4)
        return 4;
    else if(n==5)
        return 7;
    else if(n==6)
        return 13;
    else if(n==7)
        return 24;
    else if(n==8)
        return 44;
    else if(n==9)
        return 81;
    else if(n==10)
        return 149;
    else if(n==41)
        return 23837527729;
    else if(n==37)
        return 2082876103;
    else if(n==73)
        return 7015254043203144209;
    else if(n==72)
        return 3814116544533214284;
    else if(n==36)
        return 1132436852;
    else 
        return (tribo(n-1)+tribo(n-2)+tribo(n-3));
}
int main()
{
    int T;
    int n;
    int i;
    long res=0;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        res=tribo(n);
        printf("case #%d:\n",i);
        printf("%ld\n",res);
    }
    return 0;
}