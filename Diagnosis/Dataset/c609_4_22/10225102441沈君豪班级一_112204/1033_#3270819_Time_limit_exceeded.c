#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[101];
        scanf("%s",s);
        int a;          //存储字符数
        a=strlen(s);
        char t[1000];    //存储二进制字符串
        int m=0;          //每次对字符串补充的位数
        for(int j=0;j<a;j++){
            char c=s[j];
            int x=128;
            for(int k=0;k<8;k++){
                if(c&x){
                    t[m]='1';
                }else{
                    t[m]='0';
                }
                m++;
                x=x>>1;
            }
        }
        int y=m%6;                  //补位
        while(y!=6||y!=0){           //为0表示没有余数  若有余数则补成整数
            t[m]='0';
            m++;
            y++;
        }
        int z=m/6;            //转化后为几位字符
        printf("case #%d:\n",i);
        for(int j=0;j<z;j++){
            int res=0;
            for(int k=j*6;k<(j+1)*6;k++){
                res=res*2+t[k]-'0';
            }
            if(res<=25){
                res+=65;
                printf("%c",(char)res);
            }else if(res<=51){
                res+=71;
                printf("%c",(char)res);
            }else if(res<=61){
                printf("%d",res-52);
            }else if(res==62){
                printf("+");
            }else{
                printf("/");
            }

        }
        int z1 =z%4;       //确保四个四个字符
        while(z1!=4||z1!=0){
            printf("=");
            z1++;
        }
        printf("\n");
    }
    return 0;
}
