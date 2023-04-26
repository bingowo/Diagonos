#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define inf 1005

long long f(long long a,long long b){
    if(a<b) return b-a;
    else return a-b;
}

int main(){

    int w,h,d,c;
    scanf("%d%d%d %c",&w,&h,&d,&c);
    int sign = c=='R'?1:-1;
    d=(d/90)%4;
    if(sign<0)d=(-1*d+4)%4;
    int tab[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%d",&tab[i][j]);
        }
    }


    switch(d){
        case(0):{
            printf("%d %d\n",w,h);
            for(int i=0;i<h;i++){
                for(int j=0;j<w-1;j++){
                    printf("%d ",tab[i][j]);
                }
                printf("%d\n",tab[i][w-1]);
            }
            break;
        }

        case(2):{
            printf("%d %d\n",w,h);
            for(int i=h-1;i>=0;i--){
                for(int j=w-1;j>0;j--){
                    printf("%d ",tab[i][j]);
                }
                printf("%d\n",tab[i][0]);
            }
            break;
        }

        case(1):{
            printf("%d %d\n",h,w);
            for(int i=0;i<w;i++){
                for(int j=h-1;j>0;j--){
                    printf("%d ",tab[j][i]);
                }
                printf("%d\n",tab[0][i]);
            }
            break;
        }

        case(3):{
            printf("%d %d\n",h,w);
            for(int i=w-1;i>=0;i--){
                for(int j=0;j<h-1;j++){
                    printf("%d ",tab[j][i]);
                }
                printf("%d\n",tab[h-1][i]);
            }
            break;
        }
    }
    return 0;
}
