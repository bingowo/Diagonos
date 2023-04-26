#include <stdio.h>
#include <string.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[101][20];
        char s1[] = "the",s2[] ="a",s3[]="an",s4[]="of",s5[]="for",s6[] = "and";
        int j,k;
        char c;
        for(j=0, k =0;(c = getchar() )!= EOF;k++)
        {
            if(c == ' ')
            {
                s[j][k] = '\0';
                j++;
            }
            else
                s[j][k] =c;
        }
        int count = j;
        for(int x=0;x<j;x++)
        {
            if(strcmp(s[x],s1)==0 || strcmp(s[x],s2)==0 || strcmp(s[x],s3)==0 || strcmp(s[x],s4)==0 || strcmp(s[x],s5)==0 || strcmp(s[x],s6)==0)
                    count --;
        }
        printf("case #%d:\n%d\n",i,count);
    }

    return 0;
}
