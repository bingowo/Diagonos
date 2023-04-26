#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&w,&h,&d,&c);
    int a[h][w],i,j;
    d=d/90;
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(d%4==0){
        printf("%d %d\n",w,h);
        for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    }
    else if(d%4==1){
        printf("%d %d\n",h,w);
        if(c=='R'){
            for(i=0;i<w;i++){
            for(j=h-1;j>=0;j--){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
        }
        if(c=='L'){
            for(i=w-1;i>=0;i--){
            for(j=0;j<h;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
        }
    }
    else if(d%4==2){
        printf("%d %d\n",w,h);
        if(c=='R'){
            for(i=h-1;i>=0;i--){
            for(j=w-1;j>=0;j--){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
        }
        if(c=='L'){
            for(i=h-1;i>=0;i--){
            for(j=w-1;j>=0;j--){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
        }
    }
    else {
        printf("%d %d\n",h,w);
        if(c=='R'){
            for(i=w-1;i>=0;i--){
            for(j=0;j<h;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
        }
        if(c=='L'){
            for(i=0;i<w;i++){
            for(j=h-1;j>=0;j--){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
        }
    }
    return 0;
}
