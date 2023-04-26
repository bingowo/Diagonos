#include <stdio.h>
#include <string.h>
int main()
{
    char s[5000];
    scanf("%s",s);
    int flag=0;
    unsigned int num=0;
    int i=0;
    for(i=0;i<(int)strlen(s);i++)
    {
        if(s[i]=='0' && s[i+1]=='x'){flag=1;i+=2;}
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
            }
            if(num!=0) printf("%u ",num);
            flag=0;
            num=0;
        }
    }
    if(i==0) printf("-1");
    return 0;
}