#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 500500
#define BigNUm 10007

typedef struct{
    int x;
    int y;
}P;

int myPow(int a,int b){
    int ans=a;
    if(b==0)ans=1;
    else for(int k=1;k<b;k++){
        ans*=a;
    }
    return ans;
}


int main()
{
    char f[50];
    while(scanf("%s",f)!=EOF){
        int XS[4]={0},exp[4]={0};
        int i=5,cntx=0,cnte=0;
        while(f[i]){
            int sign=1;
            if(f[i]=='-'){sign=-1;i++;}
            if(f[i]=='+') i++;
            if(isdigit(f[i])){
                int tmp=0;
                if(isdigit(f[i])){
                    while(isdigit(f[i])) tmp=tmp*10+f[i++]-'0';
                }
                if(!isalnum(f[i])){
                    XS[cntx++]=sign*tmp;
                }
                if(f[i]=='x'){
                    XS[cntx++]=sign*tmp;
                    i++;
                    if(f[i]=='^'){
                        i++;
                        exp[cnte++]=f[i++]-'0';
                    }
                    else if(!isdigit(f[i])) exp[cnte++]=1;
                }
            }
            if(isalpha(f[i])){
                if(sign==1) XS[cntx++]=1;
                if(sign==-1) XS[cntx++]=-1;
                i++;
                if(f[i]!='^') exp[cnte++]=1;
                if(f[i]=='^'){
                    i++;
                    exp[cnte++]=f[i++]-'0';
                }
            }
        }

        P points[41];
        for(int i=0,cnt=-20;i<41;i++,cnt++){
            points[i].x=cnt;
        }

        for(int j=0;j<41;j++){
            int f=0;
            for(int c=0;c<4;c++){
                f+=XS[c]*(myPow(points[j].x,exp[c]));
            }
            points[j].y=f;

        }

        for(int row=20;row>=-20;row--){
            for(int col=-20;col<=20;col++){
                if(points[col+20].y==row) printf("*");
                else{
                    if(col==0 && row==0) printf("+");
                    else if(col==0){
                        if(row==20) printf("^");
                        else printf("|");
                    }
                    else if(row==0){
                        if(col==20)printf(">");
                        else printf("-");
                    }
                    else printf(".");
                }
                if(col==20) printf("\n");
            }
        }



        printf("\n");
    }

    return 0;
}
