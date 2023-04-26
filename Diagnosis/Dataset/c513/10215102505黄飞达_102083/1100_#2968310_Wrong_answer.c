#include<stdio.h>
#include<string.h>
#define ll long long
ll dis[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};

int main(){
    char s[105]={0};
    gets(s);
    int num[105]={0};
    int len=strlen(s);
    ll sum_x=0, sum_y=0;
    for (int i=0; i<len; i++){
        if (s[i]=='U') num[i]=1;
        else if (s[i]=='D') num[i]=2;
        else if (s[i]=='L') num[i]=3;
        else if (s[i]=='R') num[i]=4;
        sum_x+=dis[num[i]][0];
        sum_y+=dis[num[i]][1];
    }
    int Q;
    scanf("%d", &Q);
    for (int q=0; q<Q; q++){
        int a, b, x0=0, y0=0, flag=0;
        scanf("%d %d", &a, &b);
        for (ll i=0;i<len; i++){
            if (a==x0&&b==y0) {printf("Yes\n");flag=1;break;}
            if (sum_x==0 && sum_y!=0 && (b-y0)%sum_y==0 && (b>y0&&sum_y>0 || b<y0&&sum_y<0)){
                printf("Yes\n");flag=1;break;
            }
            else if (sum_x!=0 && sum_y==0 && (a-x0)%sum_x==0 && (a>x0&&sum_x>0 || a<x0&&sum_x<0)){
                printf("Yes\n");flag=1;break;
            }
            else if (sum_x!=0&&sum_y!=0){
                if ((a-x0)/sum_x==(b-y0)/sum_y && (a-x0)%sum_y==0 && (b-y0)%sum_y==0) {
                    if ((a>x0&&sum_x>0 || a<x0&&sum_x<0)&&(b>y0&&sum_y>0 || b<y0&&sum_y<0)) {printf("Yes\n");flag=1;break;}
                }       
            }
            x0+=dis[num[i]][0];
            y0+=dis[num[i]][1];
        }
        if (flag==0) printf("No\n");
    }
    return 0;
}