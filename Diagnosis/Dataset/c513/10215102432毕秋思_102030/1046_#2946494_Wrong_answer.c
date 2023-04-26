#include<stdio.h>
#include<string.h>

const char str[35][3]=
{"the","The","tHe","thE","THe","ThE","tHE","THE","a","A","an","An","aN","AN","of","Of","oF","OF","for","For","fOr","foR","FOr","FoR","fOR","FOF","and","And","aNd","anD","ANd","AnD","aND","AND"};

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int t=0;t<T;t++)
    {
        char s[100]={0};
        gets(s);
        int count=1;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==' '&&s[i+1]!=' ') count++;
        }
        char a[31]={0};
        int space=-1;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]!=' ')
            {
                a[i-space-1]=s[i];
            }
            else if(s[i]==' '||s[i]=='\0'||s[i]=='\n')
            {
                for(int j=0;j<34;++j)
                {
                    if(strcmp(a,str[j])==0)
                    {
                        count--;
                        break;
                    }
                }
                char a[31]={0};
                space=i;
            }
        }
        printf("case #%d:\n",t);
        printf("%d\n",count);
    }
    return 0;
}
