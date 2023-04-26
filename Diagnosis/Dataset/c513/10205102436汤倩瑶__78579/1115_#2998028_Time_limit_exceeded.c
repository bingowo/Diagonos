#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
            char s[50];

    for(int i=0; i<T; i++)
    {

        scanf("%s",s);
        int l=strlen(s);
       int j=l-1;
        while(j>=1)
        {
            if(s[j]>s[j-1])break;
        }
        if(j!=0)
        {
             char c=s[j];
        s[j]=s[j-1];
        s[j-1]=c;
        printf("case #%d:\n%s\n",i,s);
        }


    }

    return 0;
}
