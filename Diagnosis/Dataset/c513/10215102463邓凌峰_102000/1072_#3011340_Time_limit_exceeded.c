#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 110
#define BigNUm 1000000007
#define Max 1000000

typedef long long lli;

int findIt=0;

lli x=0,y=0;
char E[2]="E";
char W[2]="W";
char N[2]="N";
char S[2]="S";



lli llabs(lli x){
    return x>0?x:-1*x;
}

lli distance(lli x,lli y){
    return llabs(x)+llabs(y);
}

void myStrcpy(char* to,char *from){
    int len=strlen(from);
    int cnt=0;
    for(;cnt<len;cnt++){
        to[cnt]=from[cnt];
    }
}

void move(int now,int cnt,lli step,lli x0,lli y0,char *way){
    if(findIt) return;
    else if(now==cnt){
        if(x0==x && y0==y){
            findIt=1;
            printf("%s",way);
        }
        return;
    }

    else{
        for(int k=0;k<4;k++){
            if(k==0){
                char tmpWay[50]={0};
                strcpy(tmpWay,way);
                move(now+1,cnt,step*2,x0+step,y0,strcat(tmpWay,E));
            }
            else if(k==1){
                char tmpWay[50]={0};
                strcpy(tmpWay,way);
                move(now+1,cnt,step*2,x0-step,y0,strcat(tmpWay,W));
            }
            else if(k==2) {
                char tmpWay[50]={0};
                strcpy(tmpWay,way);
                move(now+1,cnt,step*2,x0,y0+step,strcat(tmpWay,N));
            }
            else if(k==3) {
                char tmpWay[50]={0};
                strcpy(tmpWay,way);
                move(now+1,cnt,step*2,x0,y0-step,strcat(tmpWay,S));
            }
        }
    }
}

int main() {
    scanf("%lld%lld",&x,&y);
    lli dis=distance(x,y);

    if(dis%2==0 &&dis!=0) printf("-1");
    else if(dis==0) printf("0");
    else{
        int cnt=0;
        while(dis){
        cnt++;
        dis/=2;
        }
        printf("%d\n",cnt);
        char way[50]={0};
        move(0,cnt,1,0,0,way);
    }

    return 0;
}
