#include <stdio.h>
#include <string.h>

char* strrev(char* s)
{
    /* h指向s的头部 */
    char* h = s;    
    char* t = s;
    char ch;
 
    /* t指向s的尾部 */
    while(*t++){};
    t--;    /* 与t++抵消 */
    t--;    /* 回跳过结束符'\0' */
 
    /* 当h和t未重合时，交换它们所指向的字符 */
    while(h < t)
    {
        ch = *h;
        *h++ = *t;    /* h向尾部移动 */
        *t-- = ch;    /* t向头部移动 */
    }
 
    return(s);
}



int ishuiwenshu(int n){
    char s1[100]={'\0'};
    char s2[100]={'\0'};
    itoa(n,s,10);
    s2=strrev(s1);
    if(!strcmp(s1,s2)) return 1;
    else return 0;
}
void f(int n){
    int cnt=0;
    while(!ishuiwenshu(n)){
        char str[100]={'\0'};
        char revstr[100]={'\0'};
        itoa(n,str,10);
        revstr=strrev(str);
        m=atoi(revstr);
        n=n+m;
        cnt++
    }
}



int main(){
    int n;
    scanf("%d/n",&n);
    f(n);
    return 0;
}