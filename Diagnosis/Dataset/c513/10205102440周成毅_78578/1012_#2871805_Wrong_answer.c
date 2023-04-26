#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct image {
    long long real;
    long long fake;
};

struct image multi(struct image a, struct image b) {
    struct image result;
    result.real = a.real * b.real - a.fake * b.fake;
    result.fake = a.real * b.fake + a.fake * b.real;
    return result;
}

struct image plus(struct image a, int b) {
    a.real += b;
    return a;
}

long long mypow(int a, int b)
{
    long long sum=1;
    for(int i=0;i<b;i++)
        sum*=a;
    return sum;
}

int main() {
    char s[50];
    int result[200];
    scanf("%s",s);
    int len= strlen(s);
    struct image imagenumber={0,0};
    struct image bit={1,1};
    int cet=0,tmp=0,tag=0;
    if(s[len-1]!='i'){
        for(;len>0;len--){
            if(isdigit(s[len-1])) { imagenumber.real += (s[len - 1] - '0') * mypow(10, cet);cet++; }
            else
                imagenumber.real*=(-1);
        }
    } else{
        for(;len>0;len--){
            if(isdigit(s[len-1])) { tmp += (s[len - 1] - '0') * mypow(10, cet);cet++; }
            else if(!isdigit(s[len-1]) && s[len-1]=='-' && tag==0){
                if(tmp==0){
                    imagenumber.fake = -1;
                    tag = 1;
                } else{
                    imagenumber.fake=-1*tmp;
                    tmp=0;tag=1;cet=0;
                }
            }
            else if(!isdigit(s[len-1]) && s[len-1]=='+' && tag==0){
                if(tmp==0){
                    imagenumber.fake = 1;
                    tag = 1;
                } else{
                    imagenumber.fake=tmp;
                    tmp=0;tag=1;cet=0;
                }
            }
            else if(!isdigit(s[len-1]) && s[len-1]=='-' && tag==1) { imagenumber.real = -1 * tmp;tmp=0; }
            else if(!isdigit(s[len-1]) && len-1==0){imagenumber.fake=1;}
            else if(isdigit(s[len-1]) && len-1==0 && tag==1)
                imagenumber.real=tmp;
        }
        if(tmp!=0)
            imagenumber.real=tmp;
    }
    int count=0;
    while (imagenumber.real!=0 || imagenumber.fake!=0){
        if((imagenumber.real+imagenumber.fake)%2==0){
            result[count++]=0;
            imagenumber= multi(imagenumber,bit);
            imagenumber.real/=2;imagenumber.fake/=2;
        } else{
            result[count++]=1;
            imagenumber.real-=1;
            imagenumber= multi(imagenumber,bit);
            imagenumber.real/=2;imagenumber.fake/=2;
        }
    }
    printf("Hello, World!\n");
    return 0;
}
