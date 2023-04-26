#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[100000];
    gets(s);
    int i,flag=0;
    int l=strlen(s);


    unsigned int ans=0;
    for(i=0;i<l&&ans!=-10000;)
    {
        int st;
        ans=-10000;
        if(s[i]=='0') flag=1;
        while(s[i]=='0')
        {
           i++;
        }

        if(flag==1&&s[i]=='x')
        {
            st=i+1;
            int len=0,flag1=0;
            for(;i<l;)
            {
                int c=0;
                if(s[i]=='0') flag1=1;
                while(s[i]=='0')
                {
                    i++;
                    c++;
                }
                if(flag1==1&&s[i]=='x') {i=i-c;break;}

                i++;

                len++;
                flag1=0;
            }
            int sq=0;
            for(int z=st;z<st+len;z++)
            {
                if((s[z]>='0'&&s[z]<='9')||(s[z]>='a'&&s[z]<='f'))  sq++;
                else break;
            }
            for(int z=st+sq-1,j=0;z>=st;z--,j++)
            {
                if(z==st+sq-1)
                {
                    if(s[z]>='0'&&s[z]<='9')
                    ans+=s[z]-'0';
                    else ans+=s[z]-'a'+10;
                }
                else
                {
                    if(s[z]>='0'&&s[z]<='9')
                    ans+=(unsigned int)(s[z]-'0')*pow(16,j);
                    else if(s[z]>='a'&&s[z]<='f')
                    ans+=(unsigned int)(s[z]-'a'+10)*pow(16,j);
                }
            }
        }
        if(ans==-10000) printf("-1");
        else printf("%d ",ans+10000);
        flag=0;
    }
    return 0;
}


