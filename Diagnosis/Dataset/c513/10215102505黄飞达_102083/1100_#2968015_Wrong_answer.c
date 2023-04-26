#include<stdio.h>
#include<string.h>

int dis[5][2]={{0,0},{0,1},{0,-1},{-1,0},{1,0}};

int main(){
    char s[105]={0};
    gets(s);
    int num[105]={0};
    int len=strlen(s);
    for (int i=0; i<len; i++){
        if (s[i]=='U') num[i]=1;
        else if (s[i]=='D') num[i]=2;
        else if (s[i]=='L') num[i]=3;
        else if (s[i]=='R') num[i]=4;
    }
    int Q;
    scanf("%d", &Q);
    int sum_x=0, sum_y=0;
    for (int q=0; q<Q; q++){
        int a, b, x0=0, y0=0;
        scanf("%d %d", &a, &b);
        if (a==0&&b==0) {printf("yes\n");continue;}
        for (int i=0;i<1000; i++){
            x0+=dis[num[i%len]][0];
            y0+=dis[num[i%len]][1];
            if (x0==a&&y0==b) {printf("Yes\n");break;}
        }
        if (!(x0==a&&y0==b)) printf("No\n");
        //  {sum_x=x0; sum_y=y0;}

    }
    return 0;
}