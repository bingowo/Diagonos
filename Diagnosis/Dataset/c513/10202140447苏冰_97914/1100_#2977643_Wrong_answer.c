#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int q;
    scanf("%d",&q);
    int a,b;
    for(int cas=0;cas<q;cas++)
    {
        scanf("%d %d",&a,&b);
        int x=0,y=0;
        int flag=0;int cnt=0;int temp1=0,temp2=0;
        for(int i=0;i<strlen(s) && !(a==0 && b==0);i++)
        {
            if(s[i]=='U')
            {
                y++;
            }
            else if(s[i]=='D')
            {
                y--;
            }
            else if(s[i]=='L')
            {
                x--;
            }
            else if(s[i]=='R')
            {
                x++;
            }
            if(x==a && y==b)
            {
                flag=1;
                break;
            }
            if(i==strlen(s)-1 && flag==0)
            {
                i=-1;
                cnt++;
                if(cnt==1) temp1=abs(x-a)+abs(y-b);
                else if(cnt==2)
                {
                    temp2=abs(x-a)+abs(y-b);
                    if(temp2>=temp1)
                    {
                        flag=0;break;
                    }
                }
                else
                {
                    temp1=temp2;
                    temp2=abs(x-a)+abs(y-b);
                    if(temp2>=temp1)
                    {
                        flag=0;break;
                    }
                }
            }
        }
        if(flag==1 || (a==0 && b==0))  printf("Yes\n");
        else  printf("No\n");
    }
    return 0;
}
