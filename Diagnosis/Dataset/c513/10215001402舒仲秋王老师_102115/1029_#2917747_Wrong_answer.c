#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int cmp(const void* a,const void* b)
{
    char d1,d2;
    int t=0;
    d1=*((char*)a),d2=*((char*)b);
    if(d1==' '||d2==' ');
    else if(d1>='A'&&d1<='Z'&&d2>='A'&&d2<='Z')
        t=d1-d2;
    return t;
}

int main()
{
    int N,i;
    scanf("%d\n",&N);
    for(i=0;i<N;i++)
    {
        char str[500];
        gets(str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
    return 0;
}
