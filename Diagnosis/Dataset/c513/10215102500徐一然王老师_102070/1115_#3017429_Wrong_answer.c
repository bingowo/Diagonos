#include <stdio.h>
#include <string.h>

int main()
{
    int count,count1;
    scanf("%d",&count);
    count1=count;
    char S[30];
    while(count--)
    {
        scanf("%s",S);
        int len=strlen(S);
        int flag=0;
        printf("case #%d:\n",count1-count-1);
        for(int i=0;i<len-1;i++)
        {
            if(S[i]<S[i+1]){flag=1;break;}
        }
        if(flag==0)
        {
            for(int i=len-1;i>=0;i--)
        {
            if(i==len-2)printf("0");
            printf("%c",S[i]);

        }printf("\n");
        }
        else if(flag==1)
        {
            int i;int j;
            for(i=len-1;i>0;i--)
            {
                if(S[i]>S[i-1])break;
            }
            for(j=len-1;j>=i;j--)
            {
                if(S[j]>S[i-1])break;
            }
            for(int k=0;k<i-1;k++)
            {
                printf("%c",S[k]);
            }
            printf("%c",S[j]);
            for(int k=len-1;k>=i;k--)
            {
                if(k==j){printf("%c",S[i-1]);continue;}
                printf("%c",S[k]);
            }
            printf("\n");
        }
    }
}
