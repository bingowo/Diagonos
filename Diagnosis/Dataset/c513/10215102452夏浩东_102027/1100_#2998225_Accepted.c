#include <stdio.h>
#include <string.h>
struct point{
    int x,y;
}; 
int solution(int t,int r)
{
    if(t==0 && r!=0) return -2;
    if(t==0 && r==0) return -1;
    if(r%t!=0 || r/t<0) return -2;
    return r/t;
}
int main()
{
    char s[200];
    struct point P[200];
    scanf("%s",s);
    int len = (int)strlen(s);
    P[0].x=0;
    P[0].y=0;
    for(int i=1;i<=len;i++){
        switch(s[i-1]){
            case 'U': P[i].x=P[i-1].x;P[i].y=P[i-1].y+1;break;
            case 'D': P[i].x=P[i-1].x;P[i].y=P[i-1].y-1;break;
            case 'L': P[i].x=P[i-1].x-1;P[i].y=P[i-1].y;break;
            case 'R': P[i].x=P[i-1].x+1;P[i].y=P[i-1].y;break;
        }
    }
    int q=0;
    scanf("%d",&q);
    for(int i=0; i<q; i++){
        int flag=0;
        int x=0,y=0;
        scanf("%d %d",&x,&y);
        for(int j=0;j<=len;j++){
            int m1 = solution(-P[len].x,P[j].x-x);
            int m2 = solution(-P[len].y,P[j].y-y);
            if(m1==-2 || m2==-2) continue;
            if(m1==-1 || m2==-1 || m1==m2){
                flag=1;
                break;
            }
        }
        if(flag==1) printf("Yes\n");
        else printf("No\n");
    }
}