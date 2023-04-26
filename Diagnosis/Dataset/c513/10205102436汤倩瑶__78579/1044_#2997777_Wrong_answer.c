#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int main()
{
    char s[100005];
    scanf("%s",s);
    int i=0;
    int l=strlen(s);
    int cnt=0;
    while(i<l)
    {
        if(s[i]=='0'&&s[i+1]=='x')
        {
            long long int sum=0;
            int cnt2=0;
            int j=i+2;
            while(j<l)
            {
                if(s[j]>='g'&&s[j]<='z')break;
              /*  else if(s[j]=='0'&&s[j+1]=='x')
                {
                    break;
                }*/

                else
                {
                    if(s[j]>='a'&&s[j]<='f')
                    {
                        sum=sum*16+s[j]-'a'+10;
                        cnt2++;
                    }

                    if(s[j]>='0'&&s[j]<='9')
                    {
                        if(s[j]=='0'&&s[j+1]=='x')
                    {
                        sum=sum*16;printf("tqy\n");
                        cnt2++;
                    }
                      else{sum=sum*16+s[j]-'0';
                        cnt2++;}
                    }
                    j++;
                }

            }
            if(cnt2!=0)
            {
                printf("%lld ",sum);
                cnt++;
            }
            i=j;
        }
        else i++;


    }
    if(cnt==0)printf("-1");
    return 0;
}
