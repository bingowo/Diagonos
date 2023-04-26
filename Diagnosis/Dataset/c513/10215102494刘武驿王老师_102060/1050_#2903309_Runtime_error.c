#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char w=getchar();
    char w1[100],w2[100],s[100];
    for(int i=0;i<n;i++)
    {
        scanf("%s",w1);
        scanf("%s",w2);
        scanf("%s",s);
        int min1,min2,max1,max2,max;
        for(int x=0;x<strlen(s)-strlen(w1)+1;x++)
        {
            int test=1;
            for(int j=0;j<strlen(w1);j++) if(s[x+j]!=w1[j]) test=0;
            if(test==1)
            {
                min1=x;
                break;
            }
        }
        for(int x=0;x<strlen(s)-strlen(w2)+1;x++)
        {
            int test=1;
            for(int j=0;j<strlen(w2);j++) if(s[x+j]!=w2[j]) test=0;
            if(test==1)
            {
                min2=x;
                break;
            }
        }
        for(int x=0;x<strlen(s)-strlen(w1)+1;x++)
        {
            int test=1;
            for(int j=0;j<strlen(w1);j++) if(s[x+j]!=w1[j]) test=0;
            if(test==1) max1=x;
        }
        for(int x=0;x<strlen(s)-strlen(w2)+1;x++)
        {
            int test=1;
            for(int j=0;j<strlen(w2);j++) if(s[x+j]!=w2[j]) test=0;
            if(test==1) max2=x;
        }
        if(max2-min1<max1-min2) max=max1-min2-strlen(w2);
        else max=max2-min1-strlen(w1);
        printf("case #%d:\n%d\n",i,max);
    }
}