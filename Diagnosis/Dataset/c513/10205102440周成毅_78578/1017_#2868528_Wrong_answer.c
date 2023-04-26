#include <stdio.h>
#include <string.h>

int trans(char s) {
    int a;
    switch (s) {
        case 'I':
            a = 1;
            break;
        case 'V':
            a = 5;
            break;
        case 'X':
            a = 10;
            break;
        case 'L':
            a = 50;
            break;
        case 'C':
            a = 100;
            break;
        case 'D':
            a = 500;
            break;
        case 'M':
            a = 1000;
            break;
        default:
            a = -1;
    }
    return a;
}

int main() {
    char s[51];
    int sum=0,right=0,left=0,tmp=0,a;
    for (int i = 0; i < 51; i++) {
        s[i] = '\0';
    }
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0;i<len;i++){
        int res = trans(s[i]);
        if(i==len-1||res>= trans(s[i+1]))
            sum+=res;
        else
            sum-=res;
//        if(s[i]==')'){right++;i++;break;}
//        if(s[i]=='('){
//            tmp*=1000;
//            left++;
//            if(left==right){
//                sum+=tmp;
//                tmp=0;
//                left=0;
//                right=0;
//            }
//            break;
//        } else{
//
//        }
    }
    printf("%d\n",sum);
    return 0;
}
