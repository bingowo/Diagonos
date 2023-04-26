#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[32];
    for(int i = 0;i < 32;i++)str[i] = 3;
    gets(str);
    int l = strlen(str);
    long long i,j,ans1=0,ans2=0,len = 1,flag = 0;
    for(i = 0;i < 30;i++){
        if(str[i] == '.'){flag++;i++;break;}
        if(str[i] == 3 || str[i] == '\0')break;
        if(str[i] >= '0' && str[i] <= '1')str[i] = str[i] - '0';
        if(str[i] == '2')str[i] = -1;
        ans1 = ans1 * 3 + str[i];
        //printf("ans1 = %d",ans1);
    }
    //int len2 = l - i;
    /*printf("i = %d\n",i);
    printf("strlen = %d",strlen(str));
    printf("len2 = %d\n",len2);*/
    for(j = i;j < l;j++){
        //printf("j = %d\n",j);
        if(str[j] == 3 || str[j] == '\0')break;
        else{
            if(str[j] >= '0' && str[j] <= '1')str[j] = str[j] - '0';
            if(str[j] == '2')str[j] = -1;
            ans2 = 3 * ans2 + str[j];
            len *= 3;
        }
    }
    if(ans1>0 && ans2<0){ans1--;ans2 = len + ans2;}
    else if(ans1 < 0 && ans2 > 0){
        ans1++;
        ans2 = len - ans2;
    }
    //else if(ans1 < 0 && ans2 < 0)
    if(ans1 ==0 && flag == 0)printf("%lld ",ans1);
    if(ans1 != 0)printf("%lld ",ans1);
    if(flag == 1){
        printf("%lld %lld",ans2,len);
    }

    return 0;
}
