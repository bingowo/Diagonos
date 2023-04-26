#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        char s[500];
        int count=0;
        scanf("%s",s);
        int len=strlen(s),j=0;
        int temp1=s[len-1],m=len-1,count1=0;
        while(s[m]==temp1)
        {
            count1++;
            m--;
        }
        while(j<len-count1)
        {
            int temp=s[j];
            while(s[j]==temp)
            {
                if(count==255) break;
                j++;count++;
            }
            printf("%d%c",count,s[j-1]);
            count=0;
        }
        printf("%d%c\n",count1,s[len-1]);
    }
    return 0;
}
