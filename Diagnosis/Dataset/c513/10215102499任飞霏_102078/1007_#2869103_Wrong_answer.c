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
        int flag = (a&b);
        //printf("flag = %d\n",flag);
        for(j = 0;j < 31;j++){
                a = a >> 1;
                int temp;
                temp = (a&b);
                //printf("temp = %d\n",temp);
                if(temp != flag)number++;
                else{
                    if(number > max)max = number;
                    number = 0;
                }
                flag = temp;
        }
        printf("case #%d:\n%d\n",i,max);
    }
    return 0;
}
