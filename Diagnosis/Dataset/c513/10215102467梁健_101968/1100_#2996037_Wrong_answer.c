#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int main()
{
    char s[150];scanf("%s",s);
    int q;scanf("%d",&q);
    int len;
    len=strlen(s);
    int path[len+1][3],X=0,Y=0;
    for(int i=0;i<len;i++){
        path[i][0]=X;path[i][1]=Y;
        if(s[i]=='U')Y++;
        else if(s[i]=='D')Y--;
        else if(s[i]=='L')X--;
        else if(s[i]=='R')X++;
    }
    for(int i=0;i<q;i++){
        int a,b;scanf("%d %d",&a,&b);
        int cnt=0;
        if(X!=0)a%=X;
        if(Y!=0)b%=Y;
        for(int k=0;k<len;k++){
            if(a==path[k][0]&&b==path[k][1]){
                cnt=1;
                break;
            }
        }
        if(cnt==1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
