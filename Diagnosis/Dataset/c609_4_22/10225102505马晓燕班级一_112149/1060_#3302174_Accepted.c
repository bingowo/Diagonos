#include <stdio.h>
#include <string.h>
#define N 100
char* R(char* s)
{
    if(*s!=0)//未结束是否为空串
    {
        char t[2*N+1];
        if(strcmp((*t=*(t+1)=*s,strcpy(t+2,R(s+1))-2),s)<0)
            strcpy(s,t);//更新s
    }
    return s;
}
/*AAB 
从最后一位开始*t=*(t+1)=*s重复该位，strcpy(t+2,s)-2==t ->"\0" t->"BB\0"
与s->"B"相比 >0 所以不更新 return "B"
s->"AB",t->"AAB" <0 更新 return "AAB"
s->"AAB",t->"AAAAB" 更新 return "AAAAB"
结束*/

int main()
{
    char s[2*N+1];
    scanf("%s",s);
    printf("%s\n",R(s));
    return 0;
}