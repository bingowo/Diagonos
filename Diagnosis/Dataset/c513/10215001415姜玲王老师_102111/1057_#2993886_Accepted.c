#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
void move(char*a)
{int j;
for(j=strlen(a)-1;j>=0;j--)
{a[j+1]=a[j];

}
}
int main()
{
    int i;
    char a[1001],b[1000];
    scanf("%s",a);
    for(i=0;i<strlen(a);i++)
    {
        a[i]=toupper(a[i]);
    }
    b[0]=a[0];
    for(i=1;i<strlen(a);i++)
    {if(a[i]>=b[0]){move(b),b[0]=a[i];}
    else{b[i]=a[i];}

    }
    b[i]=0;
    printf("%s",b);
}
