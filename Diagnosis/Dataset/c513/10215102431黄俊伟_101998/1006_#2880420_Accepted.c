#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,N=0,len,j=0;
    char str[30];
    char table[50]={0};
    table[49]=1;table[45]=-1;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",str);
        len=strlen(str);
        while(j<len)
        {
            N=N*3+table[str[j]];
            j++;
        }
        printf("case #%d:\n%d\n",i,N);
        j=N=0;
    }
    system("pause");
    return 0;
}