#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union DOUBLE{
    double num;
    unsigned char nums[8];
};
int main(){
    char *s, *ans;
    int num1, flag=1;
    union DOUBLE num2;
    s = (char*)malloc(sizeof(char)*100);
    ans = (char*)malloc(sizeof(char)*100);
    while(scanf("%s" ,s)!=EOF){
        if(!strchr(s,'.'))  num1 = atoi(s); 
        else{
            num2.num = atof(s);
            flag = 2;
        }
        if(flag==1){
            sprintf(ans,"%08x", num1);
            for(int i=6; i>=0; i-=2)
                printf("%c%c ", ans[i], ans[i+1]);
        }else{
            for(int i=0; i<8; i++)
                printf("%02x ",num2.nums[i]);
        }
        printf("%c", '\n');
    }
    free(s);
    free(ans);
    return 0;
}