#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int comp1(const void *a,const void *b)
{
    char a1=*(char *)a,b1=*(char *)b;
    if(a1<'A'||a1>'Z'||b1<'A'||b1>'Z')return -1;
    else return (a1-b1);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s[201];
        gets(s);
        qsort(s,strlen(s),sizeof(char),comp1);
        printf("%s\n",s);
    }
    return 0;
}
