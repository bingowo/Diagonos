#include<stdio.h>
#include<stdlib.h>
int main()
{
    int T,out,i;
    scanf("%d",&T);

    for(i = 0;i < T;i++){
        char in[20];
        char *test = in;
        int three = 1;
        out = 0;
        scanf("%s",in);
        while(*test != '\0') test++;
        for(;(test-in) >= 0;test--){
            switch(*test){
                case '1':out += 1*three;
                          three *= 3;
                          break;
                case '-':out -= 1*three;
                          three *= 3;
                          break;
                case '0':three *= 3;
                          break;
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",out);
    }
    return 0;
}
