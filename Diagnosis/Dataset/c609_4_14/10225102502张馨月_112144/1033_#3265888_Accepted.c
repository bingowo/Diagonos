#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char table[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

int main()
{
    int T;
    scanf("%d",&T);
    int len,*num,temp,sum,count;
    for(int k=0;k<T;k++)
    {
        char s[101];
        scanf("%s",&s);
        len=strlen(s);
        printf("case #%d:\n",k);
        for(int i=0;i<len/3;i++){            //三个一组
            num=(int*)calloc(24,sizeof(int));//要分配的元素数量，元素大小  分配内存并初始化为0
            for(int j=0;j<3;j++){
                temp=(int)s[i*3+j];          //遍历每一个数，每个count都定为1
                count=1;
                while(temp!=0){
                    if(temp%2==1) num[(j+1)*8-count]=1;//转变成二进制
                    count++;
                    temp/=2;
                }
            }
            for(int j=0;j<4;j++){           //待编码数据是三的倍数
                sum=0;
                for(int t=0;t<6;t++){
                    sum=sum*2+num[j*6+t];
                }
                printf("%c",table[sum]);
            }
            free(num);

        }
        num=(int*)calloc(24,sizeof(int));
        if(len%3!=0){                       //待编码数不是三的倍数
            for(int i=0;i<len%3;i++){
                temp=(int)s[len/3*3+i];
                count=1;
                while(temp!=0){
                    if(temp%2==1) num[(i+1)*8-count]=1;
                    count++;
                    temp/=2;
                }
            }
            for(int i=0;i<len%3+1;i++){
                sum=0;
                for(int j=0;j<6;j++){
                    sum=sum*2+num[i*6+j];
                }
                printf("%c",table[sum]);
            }
            for(int i=0;i<3-len%3;i++) printf("%c",'=');
        }
        printf("%c",'\n');
        free(num);
    }
    return 0;
}
