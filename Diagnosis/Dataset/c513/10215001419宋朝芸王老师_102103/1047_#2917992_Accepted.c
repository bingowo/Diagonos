#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int count(int i){
    int res = 0;
    while(i / 10 > 0){
        res++;
        i = i / 10;
    }
    return res;
}*/

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        /***input***/
        char ans[501] = {'\0'}, in[501] = {'\0'};
        scanf("%s",in);

        /***process***/
        char *pi = in;
        char tempChar = in[0];
        int tempInt = 0, cnt = 0;
        while(*pi){

            if(*pi == tempChar && tempInt < 255) tempInt++;

            else if(*pi != tempChar || tempInt == 255){
                if(tempInt / 100 > 0){
                    ans[cnt++] = tempInt / 100 + '0';
                    ans[cnt++] = tempInt / 10 % 10 + '0';
                    ans[cnt++] = tempInt % 10 + '0';
                }
                else if(tempInt / 10 > 0){
                    ans[cnt++] = tempInt / 10 + '0';
                    ans[cnt++] = tempInt % 10 + '0';
                }
                else if(tempInt > 0){
                    ans[cnt++] = tempInt + '0';
                }
                ans[cnt++] = tempChar;
                /***important***/
                tempInt = 1;
                tempChar = *pi;
            }
            pi++;
        }

        if(tempInt > 0){
            if(tempInt / 100 > 0){
                ans[cnt++] = tempInt / 100 + '0';
                ans[cnt++] = tempInt / 10 % 10 + '0';
                ans[cnt++] = tempInt % 10 + '0';
            }
            else if(tempInt / 10 > 0){
                ans[cnt++] = tempInt / 10 + '0';
                ans[cnt++] = tempInt % 10 + '0';
            }
            else if(tempInt > 0){
                ans[cnt++] = tempInt + '0';
            }
            ans[cnt++] = tempChar;
        }

        ans[cnt++] = '\0';

        /***output***/
        printf("case #%d:\n%s\n",R,ans);

    }




    return 0;
}
