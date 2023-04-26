#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct
{
    int a,b;
}sss;
sss pos[200];
int main()
{
    char s[200];
    int q,a,b;
    scanf("%s",s);
    scanf("%d",&q);
    for(int cas=0;cas<q;cas++)
    {
        scanf("%d %d",&a,&b);
        int x=0,y=0,k=0;
        int flag=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='U') y++;
            else if(s[i]=='D') y--;
            else if(s[i]=='L') x--;
            else if(s[i]=='R') x++;
            pos[k].a=x;pos[k].b=y;k++;
            if(x==a && y==b)
            {
                flag=1;break;
            }
            if(i==strlen(s)-1)
            {
                int x0=x;int y0=y;
                if(x0==0 && y0==0)
                {
                    flag=0;
                }
                else
                {
                    for(int j=0;j<k;j++)
                    {
                        int m1=-1,m2=-1;
                        if(x0!=0) m1=(a-pos[j].a)/x0;
                        if(y0!=0) m2=(b-pos[j].b)/y0;
                        if( x0!=0 && y0!=0 && m1==m2 && m1>=0)
                        {
                            flag=1;break;
                        }
                        else
                        {
                           if(x0==0 && a==pos[j].a  && m2>=0)
                           {
                               flag=1;break;
                           }
                           if(y0==0 && b==pos[j].b && m1>=0)
                           {
                               flag=1;break;
                           }
                        }
                    }
                }

            }
        }
        if(flag==1 || (a==0 && b==0)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
