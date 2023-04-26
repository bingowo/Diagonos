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
        printf("case #%d:\n",i);
        for(int x=0;x<j;x++)
        {
            if(strcmp(s[x],s[x+1]) ==0)
            {
                printf("%s ",s[x]);
                x++;
            }
            else
                printf("%s ",s[x]);

        }
        printf("\n");
    }
    return 0;
}
