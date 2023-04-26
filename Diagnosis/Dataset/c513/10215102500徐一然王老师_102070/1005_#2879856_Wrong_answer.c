#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int count,count1,len;
    long double sum=0;
    int i=0,j=0;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {
        char s[55];
        int S[155];
        for(int k=0;k<155;k++)
        {
            S[k]=0;
        }
        char*p=s;
        scanf("%s",s);
        len=strlen(s);
        p=p+len-1;
        while(*p!='.')
        {
            sum=(sum+(*p-'0'))*1.25;
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
        sum=0;
        i=0;
        j=0;
        p=s;
    }


}