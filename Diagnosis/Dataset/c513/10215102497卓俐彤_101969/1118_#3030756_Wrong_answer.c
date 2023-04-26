#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ML 201

int main(){
    int wid,hei,degree;
    char c;
    scanf("%d %d %d %c",&wid,&hei,&degree,&c);
    int photo[hei][wid];
    for(int i=0;i<hei;i++){
        for(int j=0;j<wid;j++){
            scanf("%d",&photo[i][j]);
        }
    }
    int d=0;
    if(c=='R'){
        d=degree%360;
    }else if(c=='L'){
        d=(360-degree%360)%360;
    }else{printf("error.\n");}
    int h,w;
    if(d==0){
        h=hei;w=wid;
        printf("%d %d\n",w,h);
        for(int i=0;i<hei;i++){
            for(int j=0;j<wid;j++)
                printf("%d%c",photo[i][j],j==wid-1?'\n':' ');
        }
    }else if(d==90){
        h=wid;w=hei;
        printf("%d %d\n",w,h);
        for(int i=0;i<wid;i++){
            for(int j=hei-1;j>=0;j--)
                printf("%d%c",photo[j][i],j==0?'\n':' ');
        }
    }else if(d==180){
        h=hei;w=wid;
        printf("%d %d\n",w,h);
        for(int i=hei-1;i>=0;i--){
            for(int j=wid-1;j>=0;j--)
                printf("%d%c",photo[i][j],j==0?'\n':' ');
        }
    }else{
        h=hei;w=wid;
        printf("%d %d\n",w,h);
        for(int i=wid-1;i>=0;i--){
            for(int j=0;j<hei;j++)
                printf("%d%c",photo[j][i],j==hei-1?'\n':' ');
        }
    }
    return 0;
}
