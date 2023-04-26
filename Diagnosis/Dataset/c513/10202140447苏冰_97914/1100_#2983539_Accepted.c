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
int solve(int t,int r)
{
    if (t==0 && r!=0) return -2;
    if (t==0 && r==0) return -1;
    if (r%t!=0||r/t<0) return -2;
    return r/t;
}
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
                 for(int j=0; j<k; j++)
                {
                    int m1=solve(-pos[k-1].a,pos[j].a-a);
                    int m2=solve(-pos[k-1].b,pos[j].b-b);
                    if (m1 == -2||m2 == -2) continue;
                    if (m1 == -1||m2 == -1||m1 == m2)
                    {
                        flag=1; break;
                    }
                }
            }
        }
        if(flag==1 || (a==0 && b==0)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
