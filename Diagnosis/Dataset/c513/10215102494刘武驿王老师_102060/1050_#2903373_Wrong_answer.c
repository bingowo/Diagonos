#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char w=getchar();
    for(int i=0;i<n;i++)
    {
        char w1[200],w2[200],s[200];
        scanf("%s%s%s",w1,w2,s);
        int min1,min2,max1,max2,max;
        if(strlen(w1)>=strlen(s)||strlen(w2)>=strlen(s))
        {
            printf("case #%d:\n0\n",i);
            continue;
        }
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
