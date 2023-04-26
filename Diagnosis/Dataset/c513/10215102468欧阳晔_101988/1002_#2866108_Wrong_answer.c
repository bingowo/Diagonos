#include <stdio.h>
#include <string.h>

int main()
{
    char a[10];
    long long int b=0;
    scanf("%s",a);
    int i;
    for(i = 0;i<strlen(a);i++){
        if(a[i]>='0'&&a[i]<='9')
        b=(a[i]-48)+b*16;
        if(a[i]>='A'&&a[i]<='F')
        b=(a[i]-55)+b*16;
        if(a[i]>='a'&&a[i]<='f')
        b=(a[i]-87)+b*16;
    }
     printf("%lld",b);
    return 0;
}

