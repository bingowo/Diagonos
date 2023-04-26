#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>


jl(int b,int c,int m,int n)
{
    return abs(b-m)+abs(c-n);
}



int main()
{
    char s[110];
    scanf("%s",s);
    int len=strlen(s);
    int q;
    scanf("%d",&q);
    typedef struct{int x;int y;}point;
    point*a;
    a=(point*)malloc(q*sizeof(point));
    for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
            int b=0,c=0,flag=1,dis=jl(a[i].x,a[i].y,b,c);
            while(b!=a[i].x||c!=a[i].y)
            {
                for(int k=0;k<len;k++)
                {
                    if(s[k]=='U') c++;
                    else if(s[k]=='D') c--;
                    else if(s[k]=='L') b--;
                    else b++;
                    if(b==a[i].x&&c==a[i].y) break;
                   
                }
                int f=jl(a[i].x,a[i].y,b,c)
                if(f>dis) {flag=0;break;}
                else dis=f;



            }
            if(flag==0) printf("No\n");
            if(flag==1) printf("Yes\n");
        }
        return 0;

}
