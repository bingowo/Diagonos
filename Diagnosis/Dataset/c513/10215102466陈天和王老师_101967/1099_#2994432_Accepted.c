//关键在于切割字符串
#include <stdio.h>
#include <string.h>
char ReadMorese(char s[])
{
    char ret;
    if(strcmp(s, ".-") == 0){
        ret = 'A'; }
    else if(strcmp(s, "-...") == 0){
        ret = 'B'; }
    else if(strcmp(s, "-.-.") == 0){
        ret = 'C'; }
    else if(strcmp(s, "-..") == 0){
        ret = 'D'; }
    else if(strcmp(s, ".") == 0){
        ret = 'E'; }
    else if(strcmp(s, "..-.") == 0){
        ret = 'F'; }
    else if(strcmp(s, "--.") == 0){
        ret = 'G'; }
    else if(strcmp(s, "....") == 0){
        ret = 'H'; }
    else if(strcmp(s, "..") == 0){
        ret = 'I'; }
    else if(strcmp(s, ".---") == 0){
        ret = 'J'; }
    else if(strcmp(s, "-.-") == 0){
        ret = 'K'; }
    else if(strcmp(s, ".-..") == 0){
        ret = 'L'; }
    else if(strcmp(s, "--") == 0){
        ret = 'M'; }
    else if(strcmp(s, "-.") == 0){
        ret = 'N'; }
    else if(strcmp(s, "---") == 0){
        ret = 'O'; }
    else if(strcmp(s, ".--.") == 0){
        ret = 'P'; }
    else if(strcmp(s, "--.-") == 0){
        ret = 'Q'; }
    else if(strcmp(s, ".-.") == 0){
        ret = 'R'; }
    else if(strcmp(s, "...") == 0){
        ret = 'S'; }
    else if(strcmp(s, "-") == 0){
        ret = 'T';
    }else if(strcmp(s, "..-") == 0){
        ret = 'U'; }
    else if(strcmp(s, "...-") == 0){
        ret = 'V'; }
    else if(strcmp(s, ".--") == 0){
        ret = 'W'; }
    else if(strcmp(s, "-..-") == 0){
        ret = 'X'; }
    else if(strcmp(s, "-.--") == 0){
        ret = 'Y'; }
    else if(strcmp(s, "--..") == 0){
        ret = 'Z'; }
    else if(strcmp(s, "-----") == 0){
        ret = '0'; }
    else if(strcmp(s, ".----") == 0){
        ret = '1'; }
    else if(strcmp(s, "..---") == 0){
        ret = '2'; }
    else if(strcmp(s, "...--") == 0){
        ret = '3'; }
    else if(strcmp(s, "....-") == 0){
        ret = '4'; }
    else if(strcmp(s, ".....") == 0){
        ret = '5'; }
    else if(strcmp(s, "-....") == 0){
        ret = '6'; }
    else if(strcmp(s, "--...") == 0){
        ret = '7'; }
    else if(strcmp(s, "---..") == 0){
        ret = '8'; }
    else if(strcmp(s, "----.") == 0){
        ret = '9'; }
    else if(strcmp(s, "/") == 0){
        ret = ' '; }
    else if(strcmp(s, "///") == 0){
        ret = '.'; }
    else ret='^';
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++) {
        char s[1001] = {'\0'};
        char tmp[1001] = {'\0'};
        scanf("%s",s);
        char *p1=s,*p2=s;

        printf("case #%d:\n",t);
        //以下高端双指针
        while(*p2){
            if(*p2!='/') p2++;
            else{
                memmove(tmp,p1,p2-p1);//memmove(tmp,p1,p2-p1);这玩意真好用
                tmp[p2-p1]='\0';
                printf("%c", ReadMorese(tmp));
                p2++;
                p1=p2;
                if(*p2=='/'){
                    while(*p2=='/') {p2++;}
                    p2--;
                }
            }
        }
        //以下为while的尾部处理
        if(*(p2-1)=='/') printf("\n");
        else{
            memmove(tmp,p1,p2-p1);
            tmp[p2-p1]='\0';
            printf("%c", ReadMorese(tmp));
            printf("\n");
        }
    }
    return 0;
}