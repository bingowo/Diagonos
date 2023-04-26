#include <stdio.h>
#include <string.h>

int main()
{
    char s[101];
    int xy[101][2];
    int i,j,l,a,b,q,f,a0,b0,a1,b1,a2,b2,fa,fb;
    scanf("%s",s);
    l=strlen(s);
    xy[0][0]=0;
    xy[0][1]=0;
    for(i=1;i<=l;i++)
        if(s[i-1]=='U'){
            xy[i][1]=xy[i-1][1]+1;
            xy[i][0]=xy[i-1][0];
        }
        else if(s[i-1]=='D'){
            xy[i][1]=xy[i-1][1]-1;
            xy[i][0]=xy[i-1][0];
        }
        else if(s[i-1]=='L'){
            xy[i][0]=xy[i-1][0]-1;
            xy[i][1]=xy[i-1][1];
        }
        else{
            xy[i][0]=xy[i-1][0]+1;
            xy[i][1]=xy[i-1][1];
        }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d%d",&a,&b);
        f=0;
        for(j=0;j<=l;j++){
            a0=a-xy[j][0];
            b0=b-xy[j][1];
            if(xy[l][0]==0){
                if(a0==0)
                    fa=0;
                else
                    fa=2;
            }
            else{
                fa=1;
                a1=a0/xy[l][0];
                a2=a0%xy[l][0];
            }
            if(xy[l][1]==0){
                if(b0==0)
                    fb=0;
                else
                    fb=2;
            }
            else{
                fb=1;
                b1=b0/xy[l][1];
                b2=b0%xy[l][1];
            }
            if((fa==0&&fb==0&&a0==0&&b0==0)||(fa==0&&fb==1&&b2==0&&b1>=0)||(fa==1&&fb==0&&a2==0&&a1>=0)||(fa==1&&fb==1&&a2==0&&b2==0&&a1==b1&&a1>=0)){
                f=1;
                break;
            }
        }
        if(f==0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
