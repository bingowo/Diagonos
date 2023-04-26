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
        switch(d){
            case 0:
                for(int i=0;i<h;i++){
                    for(int j=0;j<w;j++)printf("%d ",p[i][j]);
                    if(j==w-1)printf("\n");
                    else printf(" ");
                }
                break;
            case 1:
                for(int j=0;j<w;j++){
                    for(int i=h-1;i>=0;i--)printf("%d",p[i][j]);
                    if(i==0)printf("\n");
                    else printf(" ");
                }
                break;
            case 2:
                for(int i=h-1;i>=0;i--){
                    for(int j=w-1;j>=0;j--)printf("%d ",p[i][j]);
                    if(j==0)printf("\n");
                    else printf(" ");
                }
                break;
            case 3:
                for(int j=w-1;j>=0;j--){
                    for(int i=0;i<h;i++)printf("%d",p[i][j]);
                    if(i==h-1)printf("\n");
                    else printf(" ");
                }
                break;
        }
    }
    else{
        switch(d){
            case 0:
                for(int i=0;i<h;i++){
                    for(int j=0;j<w;j++)printf("%d ",p[i][j]);
                    if(j==w-1)printf("\n");
                    else printf(" ");
                }
                break;
            case 1:
                for(int j=w-1;j>=0;j--){
                    for(int i=0;i<h;i++)printf("%d",p[i][j]);
                    if(i==h-1)printf("\n");
                    else printf(" ");
                }
                break;
            case 2:
                for(int i=h-1;i>=0;i--){
                    for(int j=w-1;j>=0;j--)printf("%d ",p[i][j]);
                    if(j==0)printf("\n");
                    else printf(" ");
                }
                break;
            case 3:
                for(int j=0;j<w;j++){
                    for(int i=h-1;i>=0;i--)printf("%d",p[i][j]);
                    if(i==0)printf("\n");
                    else printf(" ");
                }
                break;
        }
    }
}