#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[50];
    int count[50]={1},i=0,j=0;
    scanf("%s",s);
    while(s[i+1])
    {
        if(s[i]!=s[i+1])
            count[j]++;
        else
        {
            j=1;
            if(count[j] > count[0]) count[0]=count[j];
            count[j]=1;
            
        }
        i++;
    }
    if(count[j] > count[0]) count[0]=count[j];
    printf("%d\n",count[0]);
    return 0;
}