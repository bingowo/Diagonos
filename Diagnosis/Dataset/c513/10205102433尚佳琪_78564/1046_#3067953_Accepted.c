#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char h[34][4]={"the","The","tHe","thE","THe","tHE","ThE","THE",
"a","A","an","aN","An","AN",
"and","AND","And","aNd","anD","ANd","aND","AnD",
"OF","of","Of","oF",
"FOR","for","For","fOr","foR","FOr","fOR","FoR"};
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char s[1000];
        gets(s);
        int len=strlen(s);
        int cnt=0;
        char a[50];
        int k=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]!=' '&&s[i]!='\n')
            {
                a[k++]=s[i];
            }
            else
            {
                a[k]='\0';
                int flag=0;
                for(int i=0;i<34;i++)
                {
                    if(strcmp(a,h[i])==0)
                        flag=1;
                }
                if(flag==0)
                {
                    cnt++;
                //    printf("%s ",a);
                }
                if(s[i]=='\n')
                    break;
                k=0;
                a[0]='\0';
            }
        }
        a[k]='\0';
        int flag=0;
        for(int i=0;i<34;i++)
        {
            if(strcmp(a,h[i])==0)
                flag=1;
        }
        if(flag==0)
        {
            cnt++;
           // printf("%s ",a);
        }
        printf("case #%d:\n",i);
       printf("%d\n",cnt);
    }
    return 0;
}
