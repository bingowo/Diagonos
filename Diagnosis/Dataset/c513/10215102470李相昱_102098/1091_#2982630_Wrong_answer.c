#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct {
    int num[3000];
    int len;
    int sign;
}bigint;
bigint trasfer(int n){
    bigint n2={0};
    int len=0,i=0;
    while (n){
        n2.num[i]=n%10;
        n=n/10;
        i++;
        len++;
    }
    n2.len=len;
    n2.sign=n<0?-1:1;
    return n2;
}
bigint Add(bigint a,bigint b){
    int l=a.len>b.len?a.len:b.len;
    bigint c={0};
    int carry=0;
    int i=0;
    for(;i<l;i++){
        c.num[i] = a.num[i]+b.num[i]+carry;
        carry=c.num[i]/10;
        c.num[i]=c.num[i]%10;
    }
    c.len=l;
    if(carry){
        c.num[i]=carry;
        c.len++;
    }
    c.sign=a.sign;
    return c;
}
bigint Minus(bigint a,bigint b){
    bigint c={0};
    if(a.len==b.len){
        int m=a.len-1;
        while (a.num[m]==b.num[m]){
            m--;
        }
        if(a.num[a.len-1]<b.num[b.len-1]){
            c= Minus(b,a);
            c.sign=b.sign;
            return c;
        }
    }if(a.len<b.len){
        c=Minus(b,a);
        c.sign=b.sign;
        return c;
    }
    int l=a.len;
    int i=0;
    for(;i<l;i++){
        if(a.num[i]<b.num[i]){
            a.num[i+1]--;
            a.num[i]+=10;
        }
        c.num[i] = a.num[i]-b.num[i];
    }
    i--;
    while (c.num[i]==0){
        i--;
    }
    c.len=i+1;
    c.sign=a.sign;
    return c;
}
bigint Mul(bigint a,bigint b){
    bigint ret={0};
    int carry=0;
    int i=0,j=0;
    for(;i<a.len;i++){
        j=0;
        for(;j<b.len;j++){
            ret.num[i+j]=ret.num[i+j]+a.num[i]*b.num[j]+carry;
            carry = ret.num[i+j]/10;
            ret.num[i+j] = ret.num[i+j]%10;
        }
        if(carry){
            ret.num[i+j]=carry;
        }
    }
    ret.len = i+j-1;
    if(ret.num[i+j-1]){
        ret.len++;
    }
    if(a.sign==b.sign){
        ret.sign=1;
    }
    if(a.sign!=b.sign){
        ret.sign=-1;
    }
    return ret;
}
int main() {
    char s[15];
    int n;
    scanf("%s%d",s,&n);
    int a=0,b=0,flag=1;
    int len = strlen(s);
    int num=0;
    for(int i=0;i<len;i++){
        if(s[i]=='-') {
            if(num){
                a=num*flag;
                num=0;
            }
            flag=-1;
        }if(s[i]=='+'){
            if(num){
                a=num*flag;
                num=0;
            }
            flag =1;
        }if(isdigit(s[i])){
            num = num*10+s[i]-'0';
        }
        if(s[i]=='i'){
            if(num==0){
                b = flag;
            }else{
                b= num*flag;
                num=0;
            }
        }
    }
    if(num){
        a=num*flag;
    }
    if(b==0){
        if(a<0&&(n%2==1)){
            printf("-");
        }
        bigint ret= trasfer(a);
        bigint aa= trasfer(a);
        for(int m=0;m<n-1;m++){
            ret= Mul(aa,ret);
        }
        for(int j=ret.len-1;j>=0;j--){
            printf("%d",ret.num[j]);
        }

    }else if(a==0){
        if(n%4==2||n%4==3){
            printf("-");
        }
        bigint ret= trasfer(b);
        bigint aa= trasfer(b);
        for(int m=0;m<n-1;m++){
            ret= Mul(aa,ret);
        }
        for(int j=ret.len-1;j>=0;j--){
            printf("%d",ret.num[j]);
        }
        if(n%4==3||n%4==1){
            printf("i");
        }
    }else{
        bigint a1= trasfer(a);
        bigint b1= trasfer(b);
        bigint a2 = a1;
        bigint b2= b1;
        for(int p=0;p<n-1;p++){
            bigint a3 = Minus(Mul(a2,a1), Mul(b2,b1));
            b2 = Add(Mul(a1,b2), Mul(a2,b1));
            a2 = a3;
        }
        if(a2.len!=1||(a2.num[0]!=0)){
            if(a2.sign==-1){
                printf("-");
            }
            for(int t=a2.len-1;t>=0;t--){
                printf("%d",a2.num[t]);
            }
            if(b2.len==1&&(b2.num[0]==0)){
                printf("0");
            }else if(b2.len==1&&(b2.num[0]==1)){
                if(b2.sign==-1){
                    printf("-i");
                } else{
                    printf("+i");
                }
            }else{
                if(b2.sign==-1){
                    printf("-");
                } else{
                    printf("+");
                }
                for(int t=b2.len-1;t>=0;t--){
                    printf("%d",b2.num[t]);
                }
                printf("i");
            }
        }else{
            if(b2.len==1&&(b2.num[0]==1)){
                if(b2.sign==-1){
                    printf("-i");
                } else{
                    printf("i");
                }
            }
            else if(b2.len!=1||(b2.num[0]!=0)){
                for(int t=a2.len-1;t>=0;t--){
                    printf("%d",a2.num[t]);
                }
                printf("i");
            }
        }
    }
    return 0;
}