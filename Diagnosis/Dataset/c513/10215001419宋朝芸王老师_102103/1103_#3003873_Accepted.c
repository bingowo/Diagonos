#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1 in  //2 mov //3 add //4 sub
//5 mul //6 div //7 out

void cal(char s[], int num[], int len){
    int command = 0, sub1 = 0, sub2 = 0;
    int index[255] = {0};
    index['A'] = 1, index['B'] = 2;
    index['C'] = 3, index['D'] = 4;

    int i = 0;
    if(command == 0){
        if(s[i] == 'I'){command = 1; i+=3;}
        else if(s[i+1] == 'O'){command = 2; i+=4;}
        else if(s[i] == 'A'){command = 3; i+=4;}
        else if(s[i] == 'S'){command = 4; i+=4;}
        else if(s[i] == 'M'){command = 5; i+=4;}
        else if(s[i] == 'D'){command = 6; i+=4;}
        else if(s[i] == 'O'){command = 7; i+=4;}
    }

    if(command != 0){
        if(command == 1){
            int temp = 0, flag = 1;

            sub1 = index[s[i]];
            i += 3;
            if(s[i] == '-'){flag = -1;i++;}
            if(s[i] == '+') i++;
            while(i < len){
                temp = temp * 10 + s[i++] - '0';
            }
            num[sub1] = temp*flag;
        }
        else if(command == 2){
            sub1 = index[s[i]];
            i += 3;
            sub2 = index[s[i]];
            num[sub1] = num[sub2];
        }
        else if(command == 3){
            sub1 = index[s[i]];
            i += 3;
            sub2 = index[s[i]];
            num[sub1] += num[sub2];
        }
        else if(command == 4){
            sub1 = index[s[i]];
            i += 3;
            sub2 = index[s[i]];
            num[sub1] = num[sub1] - num[sub2];
        }
        else if(command == 5){
            sub1 = index[s[i]];
            i += 3;
            sub2 = index[s[i]];
            num[sub1] *= num[sub2];
        }
        else if(command == 6){
            sub1 = index[s[i]];
            i += 3;
            sub2 = index[s[i]];
            if(num[sub2] == 0) num[sub1] = 0;
            else num[sub1] /= num[sub2];
        }
        else if(command == 7){
            sub1 = index[s[i]];
            printf("%d\n",num[sub1]);
        }
    }
}

int main()
{
    char s[100] = {0};
    int num[5] = {0};
    while(gets(s)){
        cal(s,num,strlen(s));
        memset(s,0,20);
    }
    return 0;
}
