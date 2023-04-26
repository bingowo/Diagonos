#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[51];
    scanf("%s",s);
    int i=1;
    int Maxlen=1,count=1;
    while(s[i])
    {
        if(s[i]==s[i-1])
        {
            if(count>Maxlen) Maxlen=count;
            count=1;
        }
        else count++;
        i=i+1;
    }
    if(count>Maxlen) Maxlen=count;
    printf("%d\n",Maxlen);
    return 0;
}
