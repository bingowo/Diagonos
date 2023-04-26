#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{char ch;char s[6];}morse;

morse t[38] = {'A',".-",'B',"-...",'C',"-.-.",'D',"-..",'E',".",'F',"..-.",'G',"--.",'H',"....",'I',"..",'J',".---",'K',"-.-",'L',".-..",'M',"--",'N',"-.",'O',"---",'P',".--.",'Q',"--.-",'R',".-.",'S',"...",'T',"-",'U',"..-",'V',"...-",'W',".--",'X',"-..-",'Y',"-.--",'Z',"--..",'0',"-----",'1',".----",'2',"..---",'3',"...--",'4',"....-",'5',".....",'6',"-....",'7',"--...",'8',"---..",'9',"----.",' ',"///",'.',"/////"};

int main()
{
    int cas,i,j,k,l,h;
    char s[107],ss[107],ans[107];
    scanf("%d",&cas);
    for(i = 0; i < cas; i++)
    {
        memset(ans,0,sizeof(ans));
        memset(ss,0,sizeof(ss));
        scanf("%s",s);
        int len = strlen(s);
        for(j = 0,k = 0,h = 0; j < len; j++)
        {
            if(s[j] != '/'&&j != len-1)ss[k] = s[j],k++;
            else if(s[j] == '/')
            {
                ss[k] = '\0';//一串字符结束；
                for(l = 0; l < 36; l++)
                   {
                       if(strcmp(ss,t[l].s) == 0){ans[h] = t[l].ch;h++;break;}//判断和哪个字符的摩斯密码相同；
                   }
                memset(ss,0,sizeof(ss));//清零；
                for(k = 0; s[j] == '/'; k++,j++)ss[k] = s[j];
                ss[k] = '\0';
                if(k == 1){memset(ss,0,sizeof(ss));j--;k = 0;continue;}//如果只是一个‘/’，就直接扫下一个字符串；
                else
                {
                    for(l = 36; l < 38; l++)if(strcmp(ss,t[l].s) == 0){ans[h] = t[l].ch;h++;}
                    memset(ss,0,sizeof(ss));
                }
                k = 0;
                j--;
            }
            if(j+1 == len)
            {
                ss[k++] = s[j];
                ss[k] = '\0';
                for(l = 0; l < 36; l++)
                   {
                       if(strcmp(ss,t[l].s) == 0){ans[h] = t[l].ch;h++;break;}//判断和哪个字符的摩斯密码相同；
                   }
            }
         }
         ans[h] = '\0';
         printf("case #%d:\n%s\n",i,ans);
  }
    return 0;
}