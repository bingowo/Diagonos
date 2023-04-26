#include<stdio.h>

const char *str[]={"the","a","an","of","for","and"};

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[100][31];
        int count=0;
        while(scanf("%s",s[count])!='\n')
        {
            count++;
        }
        count++;
        for(int i=0;i<count-1;i++)
        {
            for(int j=0;j<count-1;j++)
            {
                if(s[i]==str[j]) count--;
            }
        }
        printf("case #%d:\n",t);
    }
}
