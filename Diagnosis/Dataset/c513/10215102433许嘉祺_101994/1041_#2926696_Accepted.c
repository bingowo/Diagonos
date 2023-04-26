#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int main()
{

    char a[51];
    gets(a);
    int len=0;
    for (int i=0;i<strlen(a);i++){
        int j=0;
        while(a[i+j]!=a[i+j+1]&&i+j!=strlen(a)-1) j++;
        if(len<j+1) len=j+1;
    }
    printf("%d",len);

    return 0;
}
