#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    char s[101];scanf("%s",s);
    int len=strlen(s);
    int D[len][2];
    int x=0,y=0,k=0;
    for(int i=0;i<len;i++){
        if(s[i]=='U')y++;
        else if(s[i]=='D')y--;
        else if(s[i]=='L')x--;
        else if(s[i]=='R')x++;
        D[i][0]=x,D[i][1]=y;
    }
    int T,a,b;scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d %d",&a,&b);
        if(a==0&&b==0)printf("Yes\n");
        else{
            int flag=0;
            if(flag)printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}

