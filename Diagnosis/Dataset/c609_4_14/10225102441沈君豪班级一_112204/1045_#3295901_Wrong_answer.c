//#include <iostream>
//#include <fstream>
#include <stdio.h>
#include <stdlib.h>

//using namespace std;


//0 是读到正常字符   1是读到了引号 2表示在注释内部

int main()
{
    //std::ifstream from(argv[1]);
    //std::ofstream out(argv[2]);
    char c;
    int k=0;         //用于辅助判断状态
    while((c=getchar())!=EOF){
        if(k==0){
            if(c=='/'){                          //转义字符 第一个斜无实际意义
                char g;
                g=getchar();
                if(g=='/'){
                    k=2;                        //接下来是第一种注释
                }else if(g=='*'){
                    k=3;                          // 第二种注释
                }else{
                    printf("%c%c",c,g);
                }
            }else if(c=='\"'){
                k=1;          //读到了“接下来是引号内部的内容
                printf("%c",c);
            }else{
                printf("%c",c);
            }
        }else if(k==1){
            if(c=='\"'){
                k=0;             //"结束
            }
            printf("%c",c);
        }else if(k==2){
            if(c=='\n'){
                printf("%c",c);
                k=0;
            }
        }else if(k==3){
            if(c=='*'){
                char g;
                g=getchar();
                if(g=='/'){
                    k=0;
                }
            }
        }
    }
    //from.close();
    //out.close();
    return 0;
}
