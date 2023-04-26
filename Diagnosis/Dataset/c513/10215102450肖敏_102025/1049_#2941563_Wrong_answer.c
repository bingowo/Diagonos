#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int cmp(const void *a,const void *b)
{
    char *s1 ,*s2;
    s1=*(char (*)[10])a;s2=*(char (*)[10])b;
    return strcmp(s1,s2);
}
int main() {
    int T;
    scanf("%d",&T);
    getchar();

    for(int i=0;i<T;i++)
    {
        char s[200][20],t[501];
        memset(s[0],0,sizeof(s[0])*20);
        int j,k,z;
        gets(t);
        for(j=0 ,k =0,z=0;t[z] != '\0';z++)
        {
            if(!isalpha(t[z]) && isalpha(t[z-1]))
            {
                s[j][k] ='\0';
                j++;
                k=0;
            }
            else if(!isalpha(t[z]))
                ;
            else
            {
                s[j][k] = t[z];
                k++;
            }
        }
        s[j][k] = '\0';
        qsort(s,j,sizeof (s[0]),cmp);
        printf("case #%d:\n",i);
        for(int x=0;x<j;x++)
        {

            if(strcmp(s[x],s[x+1]) == 0)
                continue;
            else
                printf("%s ",s[x]);
        }
        printf("\n");
    }
    return 0;
}
