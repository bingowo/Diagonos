#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N=0,len,j=0,n1,n2;
    char str[30];
    char table[51]={0};
    table[49]=1;table[50]=-1;
    scanf("%s",str);
    len=strlen(str);
    if(strchr(str,'.')==NULL)
    {
    while(j<len)
        {
            N=N*3+table[str[j]];
            j++;
        }  
        printf("%d\n",N);  
    }
    else
    {
        int n=strchr(str,'.')-str;
        while(j<n)
            {
                N=N*3+table[str[j]];
                j++;
            }
        printf("%d ",N);
        for(j=1;j<len-n;j++)
        {
            n1=n1*3+table[str[j]];
        }
        printf("%d ",n1);
        for(j=1;j<len-n;j++)
        {
            n2*=3;
        }
        printf("%d",n2);
    }
    system("pause");
    return 0;
}