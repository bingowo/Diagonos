#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
char s[200005],a[2000];
int l,n;
int main()
{
    int cnt1=0,cnt2=0,pos;
    while(gets(s)!=NULL)
    {
        if(s[0]==0&&cnt1==0) puts("");
        cnt2=0;
        l=strlen(s);
        for(pos=l-1;pos>=0;pos--)
        {
            if(s[pos]=='"'&&s[pos+1]!='\''&&s[pos-1]!='\'') break;
        }
        for(int i=0;i<l;i++)
        {
            if(cnt1>0)
            {
                if(s[i]=='*'&&s[i+1]=='/')
                {
                    i++;
                    cnt1--;
                }
            }
            else if(s[i]=='/')
            {
                if(s[i+1]=='/'&&cnt2==0)
                {
                    puts(" ");
                    break;
                }
                else if(s[i+1]=='*'&&cnt2==0) cnt1++,i++;
                else putchar(s[i]);
            }
            else
            {
                if(s[i]=='\'')
                {
                    for(int j=0;j<2;j++) putchar(s[i+j]);
                    i+=3;
                }
                else if(s[i]=='"'&&cnt2==0) cnt2++;
                else if(s[i]=='"'&&cnt2==1&&i==pos) cnt2--;
                putchar(s[i]);
            }
            if(i>=l-1&&cnt1==0) puts("");
        }
    }
    return 0;
}
