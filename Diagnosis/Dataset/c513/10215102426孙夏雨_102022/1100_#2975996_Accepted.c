#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
}ZB;

int main()
{
    char s[101];
    scanf("%s",s);
    int len=strlen(s);
    ZB* p=(ZB* )malloc((len+1)*sizeof(ZB));
    int x0=0,y0=0;
    p->x=x0,p->y=y0;
    for(int i=0;i<len;i++){
        if(s[i]=='U') y0++;
        else if(s[i]=='D') y0--;
        else if(s[i]=='L') x0--;
        else if(s[i]=='R') x0++;
        (p+i+1)->x=x0;
        (p+i+1)->y=y0;
    }
    int q=0;
    scanf("%d",&q);
    int x1=0,y1=0,xc=0,yc=0;
    for(int t=0;t<q;t++){
        scanf("%d %d",&x1,&y1);
        int j=0;
        for(;j<len+1;j++){
            xc=x1-((p+j)->x);
            yc=y1-((p+j)->y);
            if(x0!=0&&y0!=0){
                if(xc%x0==0&&xc/x0>=0) {
                    int n=xc/x0;
                    if(yc%y0==0&&yc/y0==n){printf("Yes\n");break;}
                }
            }
            else if(x0==0&&y0==0){
                if(xc==0&&yc==0) {printf("Yes\n");break;}
            }
            else if(x0==0){
                if(xc==0){
                    if(yc%y0==0&&yc/y0>=0){printf("Yes\n");break;}
                }
            }
            else{
                if(yc==0){
                    if(xc%x0==0&&xc/x0>=0){printf("Yes\n");break;}
                }
            }
        }
        if(j==len+1) printf("No\n");
    }
    free(p);
    return 0;
}
