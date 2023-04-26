#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 100

int strnumcmp(const void* A,const void* B)
{
    //(char**)A:input   *(char**)A:input[L];    **(char**)A:input[100][L]
    char* a = (char**)A;
    char* b = (char**)B;

    int a1=0,b1=0;//numbers
    int an=0,bn=0;//value

    for (int i=0;i<L&&a[i]!='\0';i++)
    {
        if (a[i]>='0'&&a[i]<='9')
        {
            an=an*10+a[i]-'0';
            a1=1;
        }
    }
    for (int i=0;i<L&&b[i]!='\0';i++)
    {
        if (b[i]>='0'&&b[i]<='9')
        {
            bn=bn*10+b[i]-'0';
            b1=1;
        }
    }

    if (a1*b1==1)
        if (an==bn)return strcmp(a,b);
        else return an-bn;
    else
        if(a1>b1)return 1;
        else if(a1<b1)return -1;
        else return strcmp(a,b);
    return 0;
}

int main()
{
    char input[100][L];
    char (*p)[L]=input;
    int count=0;
    while (~scanf("%s",p+count))count++;
    //qsort(input,count,sizeof(char(*)[L]),strnumcmp);

    for (char i=0;i<count;i++)
    {
        printf("%s",p++);
        if (i!=count-1)printf(" ");
    }
    printf("\n");
    return 0;
}
