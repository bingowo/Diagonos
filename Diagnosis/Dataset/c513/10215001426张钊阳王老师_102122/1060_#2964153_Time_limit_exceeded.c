#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[120];
    scanf("%s",s);
    int l=strlen(s);
    int i,count=0,max=0;
    for(i=0;i<l;i++)
    {
        while((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) i++;

        while(s[i]=='0') i++;

        while(s[i]>='0'&&s[i]<='9')
        {
            count++;
        }
        if(count>max) max=count;
        count=0;
    }

    printf("%d",max);

    return 0;
}
