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
        size = strlen(Inp[i])*8;
        for(int j = 0;j<size/8;j++){
            cha = Inp[i][j];//字符的整数型
            while(cha>0){
                if(cha%2==1)num1++;
                cha /= 2;
            }
        }
        //约分到最简
        for(int k=size;k>=1;k--){
			if((size%k==0)&&(num1%k==0)){
				size /= k;
				num1 /= k;
			}
		}
        printf("%d/%d", num1, size);
        printf("\n");
        num1 = 0;
    }
    return 0;
}