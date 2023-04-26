#include<stdio.h>

const char *str[]={"the","a","an","of","for","and"};

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++)
    {
        char s[100][31]={0};
        int num=0;
        while(scanf("%s",&s[num])!=EOF)
        {
            num++;
        }
        int count=num+1;
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                if(s[i]==str[j]) count--;
            }
        }
        printf("case #%d:\n",t);
        printf("%d\n",count);
    }
    return 0;
}