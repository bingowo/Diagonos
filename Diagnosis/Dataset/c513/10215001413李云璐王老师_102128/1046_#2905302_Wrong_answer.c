#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int h=0;h<n;h++)
    {
        char s[110][30];
        int i=0,count=0;
        while((scanf("%s",s[i]))!=EOF)
        {
            int k;
            for(k=0;k<i;k++)
            if(strcmp(s[i],s[k])==0) break;
            if(k=i) count++;
            i++;
        }
        printf("case #%d:\n",h);
        printf("%d\n",count);
    }
    return 0;
}