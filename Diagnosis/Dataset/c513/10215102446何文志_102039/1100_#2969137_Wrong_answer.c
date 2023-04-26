#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBOUND 2147483647
typedef struct Point{
    int x;
    int y;
}pt;
int myabs(int a,int b){
    return a>b? a-b:b-a;
}

int ManhatanDistance(pt a,pt b){
    int res = myabs(a.x,b.x)+myabs(a.y,b.y);
    return res;
}

int main()
{
    char s[110];memset(s,0,110*sizeof(char));
    scanf("%s",s);
    int len = strlen(s);
    int q = 0;
    scanf("%d",&q);
    for(int i = 0;i<q;i++){
        pt origin;origin.x = 0;origin.y = 0;
        pt p;
        scanf("%d%d",&p.x,&p.y);
        if((p.x==0)&&(p.y==0)){
            printf("Yes\n");
            continue;
        }
        int res = 0;
        int beforeDistance = ManhatanDistance(origin,p);
        //printf("before:%d\n",beforeDistance);
        for(int j = 0;j<len;j++){

            if(s[j]=='U'){
                origin.y++;
            }
            else if(s[j]=='D'){
                origin.y--;
            }
            else if(s[j]=='L'){
                origin.x--;
            }
            else if(s[j]=='R'){
                origin.x++;
            }
            //if((origin.x<-100000)||(origin.x>100000)||
            //(origin.y>100000)||(origin.y<-1*100000)){//边界，防止无限循环
            //    res = 0;
            //    break;
            //}
            //printf("j = %d, dis = %d\n",j,ManhatanDistance(origin,p));
            if((origin.x==p.x)&&(origin.y==p.y)){
                res = 1;
                break;
            }
            if(j==len-1){

                if(ManhatanDistance(p,origin)>=beforeDistance){//如果执行完一组循环后距离比原来更大则不可能到达
                    res = 0;
                    //printf("mantan,%d ,before:%d\n",ManhatanDistance(p,origin),beforeDistance);

                    break;
                }

                j = -1;//j之后还会加一
                beforeDistance = ManhatanDistance(origin,p);
                //printf("j = %d,mantan,%d ,before:%d\n",j,ManhatanDistance(p,origin),beforeDistance);
            }
        }
        if(res == 1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}
