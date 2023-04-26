#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int count,count1,len;
    double sum=0;
    char s[50];
    int S[150];
    char*p=s;
    int i=0,j=0;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        scanf("%s",s);
        len=strlen(s);
        p=p+len-1;
        while(*p!='.')
        {
            sum=(sum+(*p-'0'))*0.125;
            p--;
        }
        while(sum)
        {
            sum=sum*10;
            S[i]=(int)sum;
            sum=sum-(int)sum;
            i++;
        }
        printf("case #%d:\n",count1-count-1);
        printf("0.");
        while(j<i)
        {
            printf("%d",S[j]);
            j++;
        }
        printf("\n");
    }


}