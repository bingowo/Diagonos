#include <stdio.h>
#include <stdlib.h>

struct light
{
    char s[5];
    int L[4];
};

int main()
{
    int T,cnt = 0;
    scanf("%d",&T);
    while(T-->0){
        //存放小彩灯的字符串
        char s[100];
        scanf("%s",s);
        int num[4] = {0};
        //p0指向第一个，p是变动的，p1是对每个！的临时的
        char *p0 = s,*p = s;
        while(*p){
            if(*p == '!'){
                struct light RR = {"RBYG",{-1,-1,-1,-1}};
                //如果说前面有超过三个灯，那就看前面
                if(p - p0 >= 3){
                    char *p1 = p-3;
                    while(p1 < p){
                    //出现的字母对应的位置标为1，未出现的是-1
                    switch(*p1){
                        case 'R':RR.L[0] = 1;break;
                        case 'B':RR.L[1] = 1;break;
                        case 'Y':RR.L[2] = 1;break;
                        case 'G':RR.L[3] = 1;break;
                    }
                    p1++;
                    }
                    for(int i = 0;i<4;i++){
                        if(RR.L[i] == -1) {
                                *p = RR.s[i];
                                num[i]++;
                                break;
                        }
                    }
                }
                //如果前面的灯不够的话，就也要往后看
                else if(p - p0 < 3){
                    //往后看也要分两种情况，因为不能确定后面的一定是字母
                    if(*(p+1) == '!'){
                    char *p1 = p;
                    while(*p1 == '!'){
                        //如果是叹号的话就继续往后加
                        p1++;
                    }
                    //此时p1指向了第一个不是！的字母
                    char *p2 = p1;
                    while(p2 <= p2+3){
                        switch(*p2){
                        case 'R':RR.L[0] = 1;break;
                        case 'B':RR.L[1] = 1;break;
                        case 'Y':RR.L[2] = 1;break;
                        case 'G':RR.L[3] = 1;break;
                    }
                    p2++;
                    }
                    for(int i = 0;i<4;i++){
                        if(RR.L[i] == -1){
                            *p = RR.s[i];
                            num[i]++;
                            break;
                }
                    }
                    }
                else{
                    //记录前面的字符个数
                    int fro = p-p0;
                    int aft = 3-fro;
                    //这时p1指向第一个字符
                    char *p1 = p0;
                    while(p1 <= p+aft){
                    switch(*p1){
                        case 'R':RR.L[0] = 1;break;
                        case 'B':RR.L[1] = 1;break;
                        case 'Y':RR.L[2] = 1;break;
                        case 'G':RR.L[3] = 1;break;
                    }
                    p1++;
                    }
                    for(int i = 0;i<4;i++){
                        if(RR.L[i] == -1){
                            *p = RR.s[i];
                            num[i]++;
                            break;
                        }
                    }
                }
            }
        }
        p++;
        }
        printf("case #%d:\n",cnt);
        for(int i = 0;i<3;i++){
            printf("%d ",num[i]);
        }
        printf("%d\n",num[3]);
        cnt++;
}
}