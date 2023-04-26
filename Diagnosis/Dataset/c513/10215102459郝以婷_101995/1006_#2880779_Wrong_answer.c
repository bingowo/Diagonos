#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,len,j,k,result[10],b[50];
    char a[50];
    scanf("%d ",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",a);
        len=strlen(a);
        for(j=0;j<len;j++)
        {
            if(a[j]=='0')
                b[j]=0;
            if(a[j]=='1')
                b[j]=1;
            if(a[j]=='-')
                b[j]=-1;
        }
        //printf("%s\n",b);
        if(len=1)
        {
            result[i]=3*b[0];
            continue;
        }
        result[i]=3*b[0]+b[1];
        for(j=2;j<len;j++)
        {
            result[i]=3*result[i]+b[j];
        }
    }
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        printf("%d\n",result[i]);
    }
    return 0;
}
