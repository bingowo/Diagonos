#include <stdio.h>
#include <string.h>
void trans(char *n)
{int sum=0;
    for(int i=0;i<strlen(n);i++)
    {if(n[i]=='-')
    sum=sum*3-1;
    else
    sum=sum*3+(n[i]-'0');}
    printf("%d",sum);
}

int main() {
    int T;
    char n[33];
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {printf("case #%d:\n",j);
    scanf("%s",n);
    trans(n);
    printf("\n");
    }
    return 0;
}