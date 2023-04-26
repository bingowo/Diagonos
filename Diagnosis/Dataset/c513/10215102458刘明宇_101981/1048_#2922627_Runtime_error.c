

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int *xishu(char s[100])
{
    char *p = s;//指针指向第一个元素
    char *p0 = s;
    char *p00 = s;//p00指向第一个元素
    while(*p0){
        p0++;
    }//让p1指向s的最后一个元素
    p0 = p0-1;
    //printf("%c\n",*p0);
    int s0[51];//s0,s1来存放系数
    memset(s0,0,50);
    int cnt = 0;
    while(*p){
        //是最后一个元素且不是X,那么一定是个常数
        if(*p == *p0 && *p != 'x'){
            cnt++;
            char *p1 = p-1;
            int xi = *p -'0';
            if(*p1 == '+'){
                s0[0] = xi;
            }
            if(*p1 == '-'){
                s0[0] = -1 * xi;
            }
        }
        if(*p == 'x'){
            cnt++;
            //如果这是最后一个元素，那么一定是x，只需要看前面的系数
            if(*p == *p0){
                char *p1 = p-1;
                if(*p1 >= '2' && *p1 <='9'){
                    char *p2 = p1-1;
                    if(*p2 == '+'){
                        int xi = *p1 - '0';
                        s0[1] = xi;
                    }
                    if(*p2 == '-'){
                        int xi = (-1*(*p1)) - '0';
                        s0[1] = ((-1)*xi);
                    }
                }
                else if(*p1 == '-'){
                    s0[1] = -1;
                }
                else{
                    s0[1] = 1;
                }
            }
            else if(*p == *p00){
                char *p2 = p+1;
                if(*p2 == '^'){
                    char *p3 = p2+1;
                    int mi = *p3 - '0';
                    s0[mi] = 1;
                }
                else if(*p2 == '+' || *p2 == '-'){
                    s0[1] = 1;
                }
            }
            //============================//
            //如果不是最后一个元素，则说明1.后面还有常数项
            //2.不是X的一次方，所以要对紧接着的下一个元素进行检测
            else{
                char *p2 = p+1;
                //说明这是x,并且后面还有常数项
                if(*p2 == '+' || *p2 == '-'){
                    char *p1 = p-1;
                    if(*p1 >= '2' && *p1 <='9'){
                        char *p2 = p1-1;
                        if(*p2 == '+'){
                            int xi = *p1 - '0';
                            s0[1] = xi;
                        }
                        if(*p2 == '-'){
                            int xi = (-1*(*p1)) - '0';
                            s0[1] = ((-1)*xi);
                        }
                    }
                    else if(*p1 == '-'){
                    s0[1] = -1;
                    }
                    else{
                        s0[1] = 1;
                    }
                }
                //如果后面是^,则说明是x的好几次方
                if(*p2 == '^'){
                    char *p1 = p+2;
                    int mi = *p1 - '0';
                    //指向幂的次数，决定它系数存放的位置
                    char *p2 = p-1;
                    if(*p2 >= '2' && *p2 <='9'){
                        char *p3 = p2-1;
                        if(*p3 == '+'){
                            int xi = *p2 - '0';
                            s0[mi] = xi;
                        }
                        if(*p3 == '-'){
                            int xi = (-1*(*p2)) - '0';
                            s0[mi] = ((-1)*xi);
                        }
                    }
                    else if(*p1 == '-'){
                    s0[mi] = -1;
                    }
                    else{
                        s0[mi] = 1;
                    }}}}
        p++;}
        int *pp = s0;
        return pp;
}

int main()
{
    char s1[100],s2[100];
    scanf("%s",s1);
    int *p1 = xishu(s1);
    int *p2 = xishu(s2);
    int m1[51],m2[51];
    while(*p1){
        int i = 0;
        printf("%d ",*p1);
        m1[i++] = *p1;
        p1++;
    }
    while(*p2){
        int i = 0;
        m2[i++] = *p2;
        p2++;
    }
    //for(int x = 0;x<10;x++){
    //    printf("%d ",m1[x]);
    //}
    int mul[51];
    memset(mul,0,50);
    for(int j = 0;j < 51;j++){
        for(int k = 0;k < 51;k++){
            if(m1[j] != 0 && m2[k] != 0){
                mul[j+k] += m1[j] * m2[k];
            }
        }
    }
    int *ppp = mul;
    int len = 0;
    while(*ppp){
        len++;
        ppp++;
    }
    for(int x = 0;x<len;x++){
        printf("%d ",mul[x]);
    }
    return 0;
}

