#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ini[110];
char temp[110];

void add_new(int j,int length,char f){
    for(int i = length;i >=j;i--){
        temp[i+1] = ini[i];//从第i位开始整体往后移动
    }
    temp[j] = f;
    for(int i = 0; i < j;i++){
        temp[i] = ini[i];
    }
}
int upload_newlength(){
    int length = strlen(temp);
    char conti ;
    int flag_con = 0;
    for(int i = 0;i < length;i++){
        if(temp[i] == temp[i+1]){
            conti = temp[i];
            temp[i] = '1';
            flag_con = 1;
        }else if(flag_con == 1 && temp[i] == conti){
            temp[i] ='1';
        }else if(flag_con == 1 && temp[i]!=conti ) {
            flag_con = 0;
        }else if( flag_con == 1 &&temp[i]!=temp[i+1]){
            temp[i] ='1';
            flag_con = 0;
        }else if(flag_con == 0 && temp[i]!=temp[i+1]){
            ;
        }
    }
    int k = 0;
    char temp_new[110];
    for(int i = 0 ;i < 110;i++){
        temp_new[i] = '\0';
    }
    for(int i = 0;i < length;i++){
        if(temp[i] == '1'){
            ;
        }else{
            temp_new[k] = temp[i];
            k++;
        }
    }
    strcpy(temp,temp_new);
    //printf("%s\n",temp);
    //printf("%d\n", strlen((temp_new)));
    return strlen(temp_new);
}

int main(){
    int round = 0;
    scanf("%d",&round);
    for(int i = 0 ;i < round;i++) {
        scanf("%s", ini);
        int length = strlen(ini);
        int min = 9999999;
        for (int j = 0; j < length; j++) {//长度
            strcpy(temp,ini);
            add_new(j, length, 'A');
            //printf("%d %c\n",j,'A');
            int up = upload_newlength();
            while(1){
                int up_new = upload_newlength();
                if(up ==up_new){
                    break;
                }else{
                    up =up_new;
                }
            }

            if(up < min){
                min = up;
            }
        }
        //printf("****************************");
        for (int j = 0; j < length; j++) {//长度
            strcpy(temp,ini);
            add_new(j, length, 'B');
            //printf("%d %c\n",j,'B');
            int up = upload_newlength();
            while(1){
                int up_new = upload_newlength();
                if(up ==up_new){
                    break;
                }else{
                    up =up_new;
                }
            }
            if(up < min){
                min = up;
            }
        }

        //printf("****************************");
        for (int j = 0; j < length; j++) {//长度
            strcpy(temp,ini);
            add_new(j, length, 'C');
//            printf("%d %c\n",j,'C');
            int up = upload_newlength();
            while(1){
                int up_new = upload_newlength();
                if(up ==up_new){
                    break;
                }else{
                    up =up_new;
                }
            }
            if(up < min){
                min = up;
            }
        }


        printf("case #%d:\n", i);
        printf("%d\n", length-min+1);
    }

}