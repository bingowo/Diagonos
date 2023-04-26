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
        int num=0;
        while(scanf("%s",&s[num])!=EOF)
        {
            scanf("%s",&s[num])；
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
