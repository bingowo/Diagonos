#include<stdio.h>

const char str[35][3]=
{"the","The","tHe","thE","THe","ThE","tHE","THE",
"a","A",
"an","An","aN","AN",
"of","Of","oF","OF",
"for","For","fOr","foR","FOr","FoR","fOR","FOF",
"and","And","aNd","anD","ANd","AnD","aND","AND"};

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++)
    {
        char s[100][31]={0};
        gets(s);
        int count=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            char a[31]={0};
            while(s[i]!=' '&&i<len)
            {
                a[i++]=s[i++];
            }
            int flag=1;
            for(int j=0;j<34;j++)
            {
                if(a==str[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                count++;
            }
        }
        printf("case #%d:\n",t);
        printf("%d\n",count);
    }
    return 0;
}
