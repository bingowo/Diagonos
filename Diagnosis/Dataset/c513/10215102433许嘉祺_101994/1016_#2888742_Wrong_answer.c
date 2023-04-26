#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char  c[100];
    int i=0;
    scanf("%d%d",&a,&b);
    while (a!=0)
    if(a>0) {
        if (a%(-b)>=10)
        c[i]=a%(-b)-10+'A';
        else c[i]=a%(-b)+'0';
        a=(a-a%(-b))/b;
        i=i+1;
    }
    else {
        int n=((-b)-(-a)%(-b))%(-b);
        if(n>=10) c[i]=n-10+'A';
        else c[i]=n+'0';
        i++;
        a=(a-n)/b;

    }
    for (int j=i-1;j>=0;j--) printf("%c",c[j]);    return 0;
}