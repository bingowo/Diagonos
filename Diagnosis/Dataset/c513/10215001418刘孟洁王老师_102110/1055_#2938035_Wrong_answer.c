#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char s[1000007];
void rd()
{
	char ch=getchar();
	//处理空格或回车 
	while(ch==' ' || ch=='\n' || ch=='\r')
	{
		ch=getchar(); 
	}
	//读入
	int po=0;
	while(ch!=' ' && ch!='\n' && ch!='\r')
	{
		s[po++] = ch;
		ch=getchar();
	 }
}

int main()
{
    int i,k,len = 0,start;
    int p[128];
    for(i = 0; i < 128; i++)p[i] = -1;
    k = 0;
    rd();
    for(i = 0;i < strlen(s); i++)
    {
        if(p[s[i]] >= k)
        {
            k = p[s[i]];//如果出现了重复字母，直接从出现重复字母的下一个开始算（因为start到第一个重复字母之间开始的字符串必定比start开始的短）
            p[s[i]] = i;//把位置换成这次出现的位置
        }
        else
        {
            p[s[i]] = i;//记录字母出现的位置
            if(len < i-k+1)
            {
                start = k;//如果下一个字符串更长那个则换掉start字母；
                len = i-k+1;

            }
        }
    }
    for(i = 0; i < len; i++)printf("%c",s[start+i]);
    return 0;
}