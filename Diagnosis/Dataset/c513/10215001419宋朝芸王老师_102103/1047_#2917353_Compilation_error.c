#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(int i){
    int res = 0;
    while(i / 10 > 0){
        res++;
        i = i / 10;
    }
    return res;
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        /***input***/
        char ans[500] = {'\0'}, in[501] = {'\0'};
        scanf("%s",in);

        /***process***/
        char *pi = in;
        char tempChar = in[0];
        int tempInt = 0, cnt = 0;
        while(*pi){
            if(*pi == tempChar) {tempInt++;pi++}
            else if(*pi != tempChar && tempInt <= 255){
                input(pi,ans,tempChar,tempInt,cnt);
                /*if(count(tempInt) == 1) ans[cnt++] = tempInt + '0';
                else if(count(tempInt) == 2){
                    ans[cnt++] = tempInt / 10 + '0';
                    ans[cnt++] = tempInt % 10 + '0';
                }
                else if(count(tempInt) == 2){
                    ans[cnt++] = tempInt / 100 + '0';
                    ans[cnt++] = (tempInt - tempInt / 100 * 100) / 10 + '0';
                    ans[cnt++] = tempInt % 100 + '0';
                }
                ans[cnt++] = tempChar;
                tempInt = 0;
                tempChar = *pi;*/
            }
            pi++;
        }
        input(pi,ans,tempChar,tempInt,cnt);
        

        /***output***/
        printf("case #%d:\n%s",R,ans);

    }




    return 0;
}
