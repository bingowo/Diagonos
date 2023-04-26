#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    while(scanf("%s",s)!=EOF)
    {
        //printf("%s\n",s);
        int l=strlen(s);
        int hang,lie=l,pos=0,max=0,min=0;
        for(int i=1;i<l;i++)
        {
            if(s[i]>s[i-1]){
                    pos++;
                    if(pos>max) max=pos;
                    if(pos<min) min=pos;
            }
            else if(s[i]<s[i-1]){
                    pos--;
                    if(pos>max) max=pos;
                    if(pos<min) min=pos;
            }
            else if(s[i]==s[i-1]){
            }
        }//得到了max和min max为正数 min为负数
        // printf("o%d %do",max,min);
        min=-min;
        int high=max+min+1,st=max;//第一个在第max行开始
        char ans[100][100];
        for(int k=0;k<100;k++)
            for(int j=0;j<100;j++) ans[k][j]=' ';
        ans[st][0]=s[0];
        int cntx=0,cnty=st;
        for(int i=1;i<l;i++)
        {
            if(s[i]>s[i-1])
            {
                cnty--;
                cntx++;
                ans[cnty][cntx]=s[i];
            }
            else if(s[i]<s[i-1])
            {
                cnty++;
                cntx++;
                ans[cnty][cntx]=s[i];
            }
            else if(s[i]==s[i-1])
            {
                cntx++;
                ans[cnty][cntx]=s[i];
            }
        }
        for(int i=0;i<high;i++)
        {
            for(int j=0;j<l;j++) printf("%c",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
