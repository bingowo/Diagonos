#include<stdio.h>

int main(){
    int w,h,d;
    char c;
    scanf("%d %d %d %c",&w,&h,&d,&c);
    int p[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)scanf("%d",&p[i][j]);
    d/=90;
    if(d%2==1)printf("%d %d\n",h,w);
    else printf("%d %d\n",w,h);
    d%=4;
    if(c=='R'){
        int i,j;
        switch(d){
            case 0:
                for(i=0;i<h;i++)
                    for(j=0;j<w;j++){
                        printf("%d",p[i][j]);
                        if(j==w-1)printf("\n");
                        else printf(" ");
                    }
                break;
            case 1:
                for(j=0;j<w;j++)
                    for(i=h-1;i>=0;i--){
                        printf("%d",p[i][j]);
                        if(i==0)printf("\n");
                        else printf(" ");
                    }
                break;
            case 2:
                for(i=h-1;i>=0;i--)
                    for(j=w-1;j>=0;j--){
                        printf("%d",p[i][j]);
                    if(j==0)printf("\n");
                    else printf(" ");
                    }
                break;
            case 3:
                for(j=w-1;j>=0;j--)
                    for(i=0;i<h;i++){
                        printf("%d",p[i][j]);
                        if(i==h-1)printf("\n");
                        else printf(" ");
                    }
                break;
        }
    }
    else{
        int i,j;
        switch(d){
            case 0:
                for(i=0;i<h;i++)
                    for(j=0;j<w;j++){
                        printf("%d",p[i][j]);
                        if(j==w-1)printf("\n");
                        else printf(" ");
                    }
                break;
            case 1:
                for(j=w-1;j>=0;j--)
                    for(i=0;i<h;i++){
                        printf("%d",p[i][j]);
                        if(i==h-1)printf("\n");
                        else printf(" ");
                    }
                break;
            case 2:
                for(i=h-1;i>=0;i--)
                    for(j=w-1;j>=0;j--){
                        printf("%d",p[i][j]);
                        if(j==0)printf("\n");
                        else printf(" ");
                    }
                break;
            case 3:
                for(j=0;j<w;j++)
                    for(i=h-1;i>=0;i--){
                        printf("%d",p[i][j]);
                        if(i==0)printf("\n");
                        else printf(" ");
                    }
                break;
        }
    }
}