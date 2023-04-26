#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct image {
    long long real;
    long long fake;
};

long long mypow(long long a, long long b)
{
    long long sum=1;
    for(int i=0;i<b;i++)
        sum*=a;
    return sum;
}

int main() {
    char s[100];
    int result[10001];
    scanf("%s",s);
    int len= strlen(s);
    struct image imagenumber={0,0};
    struct image bit={1,1};
    int cet=0,tag=0,r;
    long long tmp=0,qr,qf;
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
        if((imagenumber.real+imagenumber.fake)%2==0)
            r=0;
        else
            r=1;
        qr=(imagenumber.real-r-imagenumber.fake)/(-2);
        qf=(imagenumber.real+imagenumber.fake-r)/(-2);
        imagenumber.real=qr;
        imagenumber.fake=qf;
        result[count++]=r;
    }
    if(count==0)
        printf("0\n");
    for(;count>0;count--){
        printf("%d",result[count-1]);
    }
    printf("\n");
    return 0;
}
