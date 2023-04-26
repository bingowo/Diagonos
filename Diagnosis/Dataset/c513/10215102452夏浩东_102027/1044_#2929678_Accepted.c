#include <stdio.h>
#include <string.h>
char s[5000000];
int main()
{
    scanf("%s",s);
    int flag=0;
    unsigned int num=0;
    int i=0;
    int jr=0,jj=0;
    for(i=0;i<(int)strlen(s);)
    {
        if(s[i]=='0' && s[i+1]=='x'){flag=1;i+=2;}
        else i++;
        if(flag==1){
            while((s[i]<='9'&&s[i]>='0') || (s[i]>='a'&&s[i]<='f'))
            {
                if(num==0 && s[i]=='0') i++;
                else
                {
                    if(s[i]<='9'&&s[i]>='0') num=num*16+s[i]-'0';
                    else num=num*16+s[i]-'a'+10;
                    i++;
                }
                jr=1;
                jj=1;
            }
            if(jr==1) printf("%u ",num);
            flag=0;
            num=0;
            jr=0;
        }
    }
    if(jj==0) printf("-1");
    return 0;
}