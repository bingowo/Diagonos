#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[501],*s1,k1[200];
        int k2[200];
        scanf("%s",s);
        s1=s;
        int num=1,p=0;
        s1++;
        while(*s1){
            if(*s1==*(s1-1)){
                if(num<255)num++;
                else {
                    k1[p]=*s1;
                    k2[p]=num;
                    num=1;
                    p++;

                }
            }
            else{
                k1[p]=*(s1-1);
                k2[p]=num;
                num=1;
                p++;
            }
            s1++;
        }
        k1[p]=*(s1-1);
        k2[p]=num;
        printf("case #%d:\n",i);
        for(int b=0;b<p;b++)printf("%d%c",k2[b],k1[b]);
        printf("%d%c\n",k2[p],k1[p]);
    }
    return 0;
}