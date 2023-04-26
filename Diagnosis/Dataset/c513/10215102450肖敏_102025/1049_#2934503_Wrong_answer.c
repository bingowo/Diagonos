#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int cmp(const void *a,const void *b)
{
    char *s1 ,*s2;
    s1=*(char (*)[10])a;s2=*(char (*)[10])b;
    if(strcmp(s1,s2) >0)
        return 1;
    return -1;
}
int main() {
    int T;
    scanf("%d",&T);
    getchar();
    char s[200][10],t[501];
    for(int i=0;i<T;i++)
    {
        int j,k,z;
        gets(t);
        for(j=0 ,k =0,z=0;t[z] != '\0';z++)
        {
            if(!isalpha(t[z]))
            {
                s[j][k] = '\0';
                j++;
                k=0;
            }
            else
            {
                s[j][k] = t[z];
                k++;
            }
        }
        qsort(s,j+1,sizeof (s[0]),cmp);
        int flag = 0;
        printf("case #%d:\n",i);
        for(int x=0;x<j;x++)
        {
           for(int y=0;s[x][y] != '\0';y++)
           {
               if(s[x][y] != s[x+1][y])
               {
                   flag = 1;
               }
           }
           if(flag == 1)
           {
               printf("%s ",s[x]);
           }
           flag = 0;
        }
        printf("%s\n",s[j-1]);
    }
    return 0;
}
