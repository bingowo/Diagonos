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
    for(int i=0;i<len+1;i++){
        path[i][0]=X;path[i][1]=Y;
        if(s[i]=='U')Y++;
        else if(s[i]=='D')Y--;
        else if(s[i]=='L')X--;
        else if(s[i]=='R')X++;
    }
    int fX=0,fY=0;
    if(X>=0)fX=1;
    else fX=-1;
    if(Y>=0)fY=1;
    else fY=-1;
    for(int i=0;i<q;i++){
        int a,b,fa=0,fb=0,cnt=0;scanf("%d %d",&a,&b);
        if(a>=0)fa=1;
        else fa=-1;
        if(b>=0)fb=1;
        else fb=-1;
        for(int k=0;k<len;k++){
            int ta=0,tb=0;
            if(X!=0&&Y!=0){
                if((a-path[k][0])%X==0&&(b-path[k][1])%Y==0){
                    ta=(a-path[k][0])/X;
                    tb=(b-path[k][1])/Y;
                    if(ta==tb)cnt=1;break;
                }
            }
            else if(X==0&&Y!=0){
                if(a==path[k][0]){
                    if(fb==fY){
                        if(b%Y==0){
                            cnt=1;
                            break;
                        }
                    }
                }
            }
            else if(X!=0&&Y==0){
                if(b==path[k][1]){
                    if(fa==fX){
                        if(a%X==0){
                            cnt=1;
                            break;
                        }
                    }
                }
            }
            else if(X==0&&Y==0){
                if(a==path[k][0]&&b==path[k][1]){
                    cnt=1;
                    break;
                }
            }
            if(a==path[k][0]&&b==path[k][1]){
                    cnt=1;
                    break;
                }

        }
        if(cnt)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
