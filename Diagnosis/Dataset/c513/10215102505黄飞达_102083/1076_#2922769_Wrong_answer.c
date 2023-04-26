#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        char s[105] = {0};
        gets(s);
        int big=0, mid=0, small=0, sbig=0,smid=0,ssmall=0;
        int slen = strlen(s), flag = 0;
        for (int i = 0; i < slen; i++){
            if (big==0||small==0||mid==0){
                int temp = s[i];
                switch(temp){
                    case '{':sbig++;break;
                    case '[':smid++;break;
                    case '(':ssmall++;break;
                }
                i++;
            }
    
            int temp = s[i];
            switch(temp){
                case '{':big++;break;
                case '[':mid++;break;
                case '(':small++;break;
                case '}':big--;break;
                case ']':mid--;break;
                case ')':small--;break;
                default:printf("???\n");break;
            }      
            if (big==0||small==0||mid==0) i++;
            if (mid==0 && small==big) {flag=1;printf("No\n");break;}
        }
        if (flag==0) printf("Yes\n");
    }
 
    return 0;

}