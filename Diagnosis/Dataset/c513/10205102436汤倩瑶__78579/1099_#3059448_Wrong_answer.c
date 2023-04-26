#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    char s[1001];
    char *a[36]= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    for(int i=0; i<T; i++)
    {
        printf("case #%d:\n",i);
        gets(s);
        int t=0;
        char ans[1000];
        int cnt=0;
        while(s[t])
        {
            char code[6]= {0};
            int p=0;
            while(s[t]=='.'||s[t]=='-')
            {
                code[p++]=s[t++];
            }
            code[p]='\0';
            for(int k=0; k<36; k++)
            {
                if(strcmp(a[k],code)==0)
                {
                    if(k<26)ans[cnt++]='A'+k;
                    else ans[cnt++]=k-26+'0';
                    break;
                }
            }

            int flag=0;
            while(s[t]=='/')
            {
                flag++;
                t++;
            }
            if(flag==3)ans[cnt++]=' ';
            if(flag==5)ans[cnt++]='.';

        }
        ans[cnt]='\0';
        printf("%s\n",ans);

    }



}
