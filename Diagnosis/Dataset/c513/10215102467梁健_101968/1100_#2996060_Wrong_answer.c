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
    int fX=0,fY=0;
    if(X>0)fX=1;
    if(X<0)fX=-1;
    if(Y>0)fY=1;
    if(Y<0)fY=-1;
    for(int i=0;i<q;i++){
        int a,b;scanf("%d %d",&a,&b);
        int fa=0,fb=0;
        if(a>0)fa=1;
        if(a<0)fa=-1;
        if(b>0)fb=1;
        if(b<0)fb=-1;
        int cnt=0;
        if(X!=0&&fa==fX)a%=X;
        if(Y!=0&&fb==fY)b%=Y;
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
