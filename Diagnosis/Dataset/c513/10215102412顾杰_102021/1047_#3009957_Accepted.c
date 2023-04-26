#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"

int main()
{

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        char s[501];
        scanf("%s",s);
        int p=0;
        while(s[p])
        {
            int t=0;
            for(;t<254&&s[p]==s[p+1];p++,t++);
            printf("%d%c",t+1,s[p]);
            p++;
        }
        printf("\n");
    }

}
