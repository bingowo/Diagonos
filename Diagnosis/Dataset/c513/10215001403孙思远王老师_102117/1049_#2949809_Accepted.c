#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    char *p1,*p2;
    p1=(char *)a;
    p2=(char *)b;
    if(strcmp(p1,p2)>0)
        return 1;
    else
        return -1;
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        char s[501],c[501][501],d[501];
        int i,i2,flag,j,n=0;
        gets(s);
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            j=0;
            flag=1;
            while(s[i]!=' '&&s[i]!=','&&s[i]!='?'&&s[i]!='.'&&s[i]!='!')
            {
                d[j]=s[i];
                j++;
                i++;
            }
            if(j>0)
                d[j]='\0';
            for(i2=0;i2<n;i2++)
            {
                if(strcmp(c[i2],d)==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                strcpy(c[n],d);
                n++;
            }
        }
        qsort(c,n,sizeof(c[0]),cmp);
        for(i=0;i<n;i++)
        {
            printf("%s",c[i]);
            if(i<n-1)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}
