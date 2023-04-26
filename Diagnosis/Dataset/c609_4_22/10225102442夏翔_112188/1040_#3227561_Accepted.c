#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int coe;
    int power;
}Item;
int main(){
    char s1[101], s2[101], c;
    int count1, count2, ret, flag, pos, temp;//第一、二个表达式的项数，循环内记录系数和幂次
    Item items1[51], items2[51];
    int *powers;
    while(scanf("%s", s1)!=EOF){
        powers = (int*)calloc(50,sizeof(int));
        scanf("%s", s2);
        count1 = 0;
        count2 = 0;
        ret = 0;
        flag = 1;
        for(int i=0; i<strlen(s1);){ //读第一条表达式
            if(s1[i]=='-'){ //若碰到负号
                flag = -1;
            }
            if(s1[i]>='0'&&s1[i]<='9'){
                ret = ret*10+(int)s1[i]-48;
            }
            if(s1[i]=='x'){ //碰到x
                if(ret==0) ret = 1; //x的系数为1
                ret = ret * flag;
                flag = 1;
                items1[count1].coe = ret;//系数
                ret = 0;
                if(s1[i+1]=='^'){  //若有幂符号
                    pos = i+2;
                    while(s1[pos]>='0'&&s1[pos]<='9'){ //循环读次幂
                        ret = ret*10+(int)s1[pos]-48;
                        pos++;
                    }
                    items1[count1++].power = ret;
                    i = pos-1;
                    ret = 0;
                }else{
                    items1[count1++].power = 1;
                }
            } 
            i++;
        }
        if(ret!=0){
            ret = ret * flag;
            items1[count1].coe = ret;//系数
            items1[count1++].power = 0;
        }
        ret = 0;
        flag = 1;
        for(int i=0; i<strlen(s2);){ //读第二条表达式
            if(s2[i]=='-'){ //若碰到负号
                flag = -1;
            }
            if(s2[i]>='0'&&s2[i]<='9'){
                ret = ret*10+(int)s2[i]-48;
            }
            if(s2[i]=='x'){ //碰到x
                if(ret==0) ret = 1; //x的系数为1
                ret = ret * flag;
                flag = 1;
                items2[count2].coe = ret;//系数
                ret = 0;
                if(s2[i+1]=='^'){  //若有幂符号
                    pos = i+2;
                    while(s2[pos]>='0'&&s2[pos]<='9'){ //循环读次幂
                        ret = ret*10+(int)s2[pos]-48;
                        pos++;
                    }
                    items2[count2++].power = ret;
                    i = pos-1;
                    ret = 0;
                }else{
                    items2[count2++].power = 1;
                }
            }
            i++;
        }
        if(ret!=0){
            ret = ret * flag;
            items2[count2].coe = ret;//系数
            items2[count2++].power = 0;
        }
        for(int i=0; i<count1; i++){ //计算结果的系数、对应的幂
            for(int j=0; j<count2; j++){
                powers[items1[i].power+items2[j].power] += items1[i].coe*items2[j].coe;
            }
        }
        for(temp=0; temp<50; temp++){ //最后一个不能输出空格
            if(powers[49-temp]!=0){
                printf("%d", powers[49-temp]);
                break;
            }
        }
        for(temp=temp+1; temp<50; temp++){
            if(powers[49-temp]!=0)
                printf(" %d", powers[49-temp]);
        }
        printf("\n");
        free(powers);
        
    }
    return 0;
}