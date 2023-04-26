#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,n=0;
    char a[50];
    scanf("%d %s %d",&A,a,&B);
    int i=0;



   do {
        if(A<=10)
            n=n*A+a[i]-'0';
        else
        {
            if(a[i]>='a') n=n*A+a[i]-'a'+10;
            else if(a[i]>='0'&&a[i]<='9')  n=n*A+a[i]-'0';
            else n=n*A+a[i]-'A'+10;
        }
        i++;
    }
   while(a[i]!='\0');
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

