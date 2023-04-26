#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int line,i,table[123],j,m=0,count=0;
    for(i=0;i<123;i++)
        table[i]=-1;
    char a[61];
    long long int result[11];
    scanf("%d ",&line);
    for(i=0;i<line;i++)
    {
        gets(a);
        for(j=0;j<strlen(a);j++)
        {
            if(j==0)
            {
                table[a[j]]=1;
                a[j]='1';
                count++;
            }
            else if(table[a[j]]!=-1)
            {
                a[j]=table[a[j]]+48;
            }
            else if(table[a[j]]==-1)
            {
                table[a[j]]=m;
                a[j]=m+48;
                if(count==1)
                    m=m+2;
                else
                    m++;
                count++;
            }
        }
        if(j>1)
            result[i]=count*(a[0]-48)+a[1]-48;
        else
            result[i]=1;
        j=2;
        while(j<strlen(a))
        {
            result[i]=count*result[i]+(a[j]-48);
            j++;
        }
    }
    for(i=0;i<line;i++)
    {
        printf("case #%d:\n",i);
        printf("%lld\n",result[i]);
    }
    return 0;
}
