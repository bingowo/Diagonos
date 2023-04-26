#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double table[26];

int cmp(const void* a,const void* b);
char toup(char a);

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        printf("case #%d:\n",i);
        for(int j = 0;j < 26;j++){
            scanf("%lf",&table[j]);
        }
        char s[110];
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(s[0]),cmp);
        printf("%s\n",s);
    }
    return 0;
}

int cmp(const void* a,const void* b)
{
    char x = *((char*)a);
    char y = *((char*)b);
    if(toup(x)==toup(y))return (int)(y-x);
    else
        if(table[(int)(toup(y)-'A')]-table[(int)(toup(x)-'A')]>=0)return 1;
        else
            return -1;

}

char toup(char a)
{
    if(a>=97)return a-32;
    else
        return a;
}

