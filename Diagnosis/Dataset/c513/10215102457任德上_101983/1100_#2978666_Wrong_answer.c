#include<stdio.h>
int main(){
    char s[101],*s1;
    scanf("%s",s);
    int x1=0,y1=0;
    s1=s;
    while(*s1){
        if(*s1=='U')y1++;
        else if(*s1=='D')y1--;
        else if(*s1=='L')x1--;
        else x1++;
        s1++;
    }
    int times;
    scanf("%d",&times);
    for(int i=0;i<times;i++){
        int x,y,x2=0,y2=0,flag=0;
        scanf("%d%d",&x,&y);
        s1=s;
        do{
            if(x==x2&&y==y2){
                flag=1;
                break;
            }
            if(*s1=='U')y2++;
            else if(*s1=='D')y2--;
            else if(*s1=='L')x2--;
            else x2++;
            s1++;
        }while(*s1);
        s1=s;
        if(flag==1){
            printf("Yes\n");
            continue;
        }
        if(x*x1<0||y*y1<0||(x*x1==0&&(x+x1)!=0)||(y*y1==0&&(y+y1)!=0)){
            printf("No\n");
            continue;
        }
        int x3=0,y3=0;
        if(x1!=0)x3=x/x1;
        if(y1!=0)y3=y/y1;
        x2=0,y2=0;
        if(x3>y3&&y3!=0){
            x3=y3;
        }
        else if(y3>x3&&x3==0){
            x3=y3;
        }
        x2+=x3*x1,y2+=x3*y1;
        do{
            if(x==x2&&y==y2){
                flag=1;
                break;
            }
            if(*s1=='U')y2++;
            else if(*s1=='D')y2--;
            else if(*s1=='L')x2--;
            else x2++;
            s1++;
        }while(*s1);
        if(flag==1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}