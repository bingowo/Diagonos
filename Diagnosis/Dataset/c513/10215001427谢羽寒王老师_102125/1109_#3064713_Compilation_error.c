#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i,j,first;
    scanf("%d",&T);
    for(i=0;i<T;i++){
            first=8；
        printf("case #%d:\n",i);
        int s[9];
        for(j=0;j<9;j++){
            scanf("%d",&s[j]);              //输入
        }
        for(j=0;j<8;j++){
            if(s[j]!=0){first=j;break;}        //寻找首项
        }
        if(first==8){printf("%d",s[8]);}
        else if(first==7){
            if(s[7]==1){printf("x");}
            else if(s[7]==-1){printf("-x");}
            else{printf("%dx",s[7]);}
            if(s[8]>0){printf("+%d",s[8]);}
            if(s[8]<0){printf("%d",s[8]);}
        }
        else{
            for(j=first;j<7;j++){

                if(s[j]==0){continue;}
                if(s[j]==1 && first==j){printf("x^%d",8-j);continue;}
                if(s[j]==1){printf("+x^%d",8-j);continue;}
                if(s[j]==-1){printf("-x^%d",8-j);continue;}
                if(s[j]>0&&first!=j){printf("+");}
                printf("%d",s[j]);
                printf("x^%d",8-j);
            }
            if(s[7]<0){if(s[7]==-1){printf("-x");}
                       else{printf("%dx",s[7]);}}
            if(s[7]>0){
                    if(s[7]==1){printf("+x");}
                    else{printf("+%dx",s[7]);}}
            if(s[8]<0){printf("%d",s[8]);}
            if(s[8]>0){printf("+%d",s[8]);}

        }

         printf("\n");
         

    }




}
