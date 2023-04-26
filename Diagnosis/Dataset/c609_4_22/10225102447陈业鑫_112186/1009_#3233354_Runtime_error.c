#include<stdio.h>
#include<string.h>
int main(){
    char Inp[10][120] = {'\0'};
    int num = 0;
    int num1 = 0;
    int size = 0;
    int cha = 0;
    scanf("%d", &num);
    for(int i = 0;i<num;i++){
        scanf("%s", &Inp[i]);
    }
    for(int i = 0;i<num;i++){
        size = strlen(Inp[i])*sizeof(char)*8;
        for(int j = 0;j<size;j++){
            cha = Inp[i][j];//字符的整数型
            while(cha>0){
                if(cha%2==1)num1++;
                cha /= 2;
            }
        }
        int tep = 0;
        while(num1!=1&&size%num1==0){//不是最简
            tep = size/num1;
            num1 /= tep;
            size /= tep;
        }
        printf("%d/%d", num1, size);
        printf("\n");
        num1 = 0;
    }
    return 0;
}