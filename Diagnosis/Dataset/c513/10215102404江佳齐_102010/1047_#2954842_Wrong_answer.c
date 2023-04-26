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
        int count3=count1%255;
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
        int k=len-count1,count2=0;
        if(count3!=0)
        {
            while(k<len-count3)
            {
                while(s[k]==temp1)
                {
                    if(count2==255) break;
                    k++;count2++;
                }
                printf("%d%c",count2,s[m]);
            }
            printf("%d%c\n",count3,s[len-1]);
        }
        else
        {
            while(k<len-255)
            {
                while(s[k]==temp1)
                {
                    if(count2==255) break;
                    k++;count2++;
                }
                printf("%d%c",count2,s[m]);
            }
            printf("255%c\n",s[len-1]);
        }
    }
    return 0;
}
