#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,n=0;
    char a[50];
    scanf("%d %s %d",&A,a,&B);
    int i=0;
    do
    {
        if(A<=10)
        n=(a[i]-'0'+n)*A;
        else
        {
            if(a[i]>='a') n=(a[i]-'a'+10+n)*A;
            else n=(a[i]-'A'+10+n)*A;
        }
        i++;
    }
    while(a[i]!='\0');
    n=n/A;
    i=0;
    do{
        if((n%B)>=10)
        {
            a[i]=(n%B)-10+'A';
        }
        else a[i]=n%B+'0';
        n=n/B;
        i++;
    }
    while(n>0);
    for(i=i-1;i>=0;i--)
    {printf("%c",a[i]);}
    return 0;
}


