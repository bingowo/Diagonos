#include<stdio.h>

const char *str[]=
{"the","The","tHe","thE","THe","ThE","tHE","THE",
"a","A",
"an","An","aN","AN",
"of","Of","oF","OF",
"for","For","fOr","foR","FOr","FoR","fOR","FOF",
"and","And","aNd","anD","ANd","AnD","aND","AND"};

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[100][31];
        int m=0,n=0;
        while(getchar()!='\n')
        {
            if(getchar()==' ') m++;
            else
            {
                s[m][n]=getchar();
                n++;
            }
        }
        int count=m+1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<3;k++)
                    if(s[i][k]==str[j][k]) count--;
            }
        }
        printf("case #%d:\n",t);
        printf("%d\n",count);
    }
    return 0;
}