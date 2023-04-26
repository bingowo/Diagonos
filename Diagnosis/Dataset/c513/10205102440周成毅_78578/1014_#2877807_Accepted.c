#include <stdio.h>

void myprint(char *s,int left, int right)
{
    for(int i=left;i<=25;i++){
        if(s[i]=='/')
            printf("2");
        else
            printf("%c",s[i]);
    }
    if(right>25){
        printf(".");
        for(int i=26;i<=right;i++){
            if(s[i]=='/')
                printf("2");
            else
                printf("%c",s[i]);
        }
    }
}

int main() {
    long long zi, mu, integer;
    scanf("%lld %lld", &zi, &mu);
    integer = zi / mu;
    zi -= integer * mu;
    int left, right;
    char result[51];
    for(int i=0;i<51;i++) result[i]='0';
    for (int i = 25; i >= 0; i--) {
        result[i] = integer % 3 + '0';
        integer /= 3;
        if (integer == 0) {
            left = i;
            break;
        }
    }
    for (int i = 26; i < 51; i++) {
        if(zi==0){
            i--;
            right=i;
            break;
        }
        result[i]=3*zi/mu+'0';
        zi=3*zi-(result[i]-'0')*mu;
    }
    for(int i=right;i>=left;i--){
        result[i-1]=result[i-1]+(result[i]-'0'+1)/3;
        result[i]=((result[i]-'0'+1)%3)+'0';
    }
    if(result[left-1]=='1') { left -= 1;result[left]+=1; }
    for(int i=left;i<=right;i++)
        result[i]-=1;
    myprint(result,left,right);
    return 0;
}
