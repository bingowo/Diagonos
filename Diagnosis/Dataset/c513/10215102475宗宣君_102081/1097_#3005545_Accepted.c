#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    char s[81];
    while(scanf("%s",s)!=EOF)
    {
        char a[161][81];
        int i,j;
        for(i = 0;i<161;i++)
        {
            for(j = 0;j<80;j++)
                a[i][j] = ' ';
            a[i][j] = '\0';
        }
        int m = 80,b[100],k = 0;
        a[m][0] = s[0];b[k++] = 80;
        for(i = 0;i<strlen(s)-1;i++)
        {
            if(s[i+1]>s[i]) a[--m][i+1] = s[i+1];
            else if(s[i+1]==s[i]) a[m][i+1] = s[i+1];
            else a[++m][i+1] = s[i+1];
            b[k++] = m;
            //printf("%d ",m);
        }
        qsort(b,k,sizeof(int),cmp);
        //printf("%d %d ",b[0],b[k-1]);
        for(i = b[0];i<=b[k-1];i++)
            {printf("%s\n",a[i]);}

    }
    return 0;
}
