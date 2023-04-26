#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float frequecy[58];
int cmp(const void* p1, const void* p2)
{
    char a = *(char*)p1;
    char b = *(char*)p2;
    if(frequecy[a-65]==frequecy[b-65])
        return a-b;
    else
        return frequecy[a-65] - frequecy[b-65];
}

int main(void)
{
    int T;
    char s[101];
    scanf("%d",&T);getchar();
    for(int i=0;i<T;++i)
    {   
        int j=0;
        printf("case #%d:\n",i);
        while(scanf("%f",&frequecy[j])!='\n'){frequecy[j+32]=frequecy[j];};
        gets(s);
        qsort(s,strlen(s),sizeof(char),cmp);
        puts(s);
    }

    system("pause");
    return 0;
}