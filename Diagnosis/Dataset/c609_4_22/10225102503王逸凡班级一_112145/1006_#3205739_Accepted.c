#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);//组数
    int i=0;

    for(i=0;i<T;i++){
        char s[50000];
        int R=0;
        scanf("%s",s);//输入数据
        int table[128];
        for(int k=0;k<128;k++){
            table[k]=-1;
        }//初始化数组
        int j=0;
        char *p;
        p=s;//指针赋值
        table[*p]=1;
        while(*++p){
            if(table[*p]==-1){
                table[*p]=R;
                R=R?R+1:2;
            }
        }
        if(R<2){
            R=2;//不可能是1进制
        }
        long long sum=0;
        p=s;
        while(*p){
            sum=sum*R+table[*p];
            p++;
        }
        printf("case #%d:\n%lld\n",i,sum);


    }
    return 0;
}
