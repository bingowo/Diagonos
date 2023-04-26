#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        int flag=0;
        int s[10];
        for(int i=8;i>=0;i--)scanf("%d",&s[i]);
        for(int i=8;i>1;i--){
            if(s[i]==0)continue;
            else{
                if(s[i]==1){
                    if(flag==0)printf("x^%d",i);
                    else printf("+x^%d",i);
                    flag=1;
                }
                else if(s[i]>1){
                    if(flag==0)printf("%dx^%d",s[i],i);
                    else printf("+%dx^%d",s[i],i);
                    flag=1;
                }
                if(s[i]==-1){
                    printf("-x^%d",i);
                    flag=1;
                }
                else if(s[i]<-1){
                    printf("%dx^%d",s[i],i);
                    flag=1;
                }
            }
        }
        if(s[1]==0);
        else{
            if(s[1]<0){
                if(s[1]==-1)printf("-x");
                else printf("%dx",s[1]);
            }
            else{
                if(flag==1){
                    if(s[1]==1)printf("+x");
                    else printf("+%dx",s[1]);
                }
                else{
                    if(s[1]==1)printf("x");
                    else printf("%dx",s[1]);
                }
            }
            flag=1;
        }
        if(flag==0)printf("%d\n",s[0]);
        else{
            if(s[0]>0)printf("+%d\n",s[0]);
            else if(s[0]<0)printf("%d\n",s[0]);
            else printf("\n");
        }
    }
    return 0;
}
