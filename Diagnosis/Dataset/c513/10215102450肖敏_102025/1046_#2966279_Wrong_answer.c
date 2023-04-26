#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d",&T);
    getchar();

    for(int i=0;i<T;i++)
    {
        char t[101];
        char s[101][20];
        char s1[] = "the",s2[] ="a",s3[]="an",s4[]="of",s5[]="for",s6[] = "and";
        int j,k=0,y;
        gets(t);
        int len=strlen(t);
        for(j=0,y =0;y<len;y++)
        {
            if(t[y] == ' ')
            {
                s[j][k]='\0';
                j++;
                k = 0;
            }
            else if(y == len-1)
            {
                s[j][k]=t[y];
                s[j][k+1] = '\0';
                j++;
            }
            else
            {
                if(t[y] >= 'A' && t[y] <= 'Z')
                {
                    s[j][k] = t[y] +32;
                    k++;
                }
                else
                {
                    s[j][k] = t[y];
                    k++;
                }
            }
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
