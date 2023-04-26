#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i,j;
    scanf("%d",&T);
    for(i = 0;i < T;i++){
        int a,b = 1,max = 1;
        static int number = 1;
        scanf("%d",&a);
        int cmp = 1;
        int k = 0;
        for(k = 0; k < 32;k++){
            if(cmp >= a)break;
            else cmp *= 2;
        }
        //printf("k = %d\n",k);
        int flag = (a&b);
        //printf("flag = %d\n",flag);
        for(j = 0;j < k - 1;j++){
                a = a >> 1;
                int temp;
                temp = (a&b);
                //printf("temp = %d\n",temp);
                if(temp != flag){
                        number++;
                        //printf("number = %d",number);
                        if(number > max){max = number;}
                        }

                else{
                    number = 1;
                }
                flag = temp;
                //printf("flag = %d\n",flag);
        }
        if(k == 32)max = max - 1;
        printf("case #%d:\n%d\n",i,max);
        number = 1;
    }
    return 0;
}
