#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int num,len,n;
    int sum = 0;
    int a = 0;
    int b = 0;
    char s[1000];
    scanf("%d",&num);
    while(num>0)
    {
        scanf("%s",s);
        len = strlen(s);

        for(n=0;len>0;n++,len--)
        {
            if(s[n]=='-') a=-1;
            else if(s[n]=='1') a=1;
            else a = 0;
            sum=sum+(a*(pow(3,len-1)));
        }

        printf("case #%d:\n",b);
        printf("%d\n",sum);
        sum = 0;
        num--;
        b++;
    }

    return 0;
}
