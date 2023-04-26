#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>



int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        int rp=0,bp=0,yp=0,gp=0,judge=0;
        char s[101];scanf("%s",s);
        int res[5];
        for(int i=0;i<4;i++)res[i]=0;
        for(int i=0;i<strlen(s)&&judge<4;i++){
                if(s[i]=='R'){
                    if(rp==0){
                        rp=i;
                        judge++;
                    }
                }
                if(s[i]=='B'){
                    if(bp==0){
                        bp=i;
                        judge++;
                    }
                }
                if(s[i]=='Y'){
                    if(yp==0){
                        yp=i;
                        judge++;
                    }
                }
                if(s[i]=='G'){
                    if(gp==0){
                        gp=i;
                        judge++;
                    }
                }
            }
        if(rp==0)rp=6-(bp+yp+gp);
        if(bp==0)bp=6-(rp+yp+gp);
        if(yp==0)yp=6-(rp+bp+gp);
        if(gp==0)gp=6-(rp+bp+yp);
        rp%=4;bp%=4;yp%=4;gp%=4;
        //printf("%d %d %d %d\n",rp,bp,yp,gp);
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='!'){
                if(i%4==rp)res[0]++;
                if(i%4==bp)res[1]++;
                if(i%4==yp)res[2]++;
                if(i%4==gp)res[3]++;
            }
        }
        printf("%d %d %d %d\n",res[0],res[1],res[2],res[3]);
    }
    return 0;
}
