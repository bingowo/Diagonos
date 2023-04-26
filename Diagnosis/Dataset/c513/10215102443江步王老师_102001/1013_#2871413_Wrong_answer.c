#include<stdio.h>
#include<math.h>


long long int intcount(char *s);
long long int numecount(char *s);
long long int denocount(char *s);
int main()
{
    char s[31];
    long long int integer;
    char *p=s;
    scanf("%s",s);
    while(*p!='.' && *p!='\0'){
        p++;
    }
    if(*p=='.'){//该平衡三进制数有小数部分
        long long int numerator,denominator;
        *p='\0';
        integer=intcount(s);
        *p='.';
        p++;
        denominator=denocount(p);
        numerator=numecount(p);
        if (numerator<0 && integer>0){
            numerator=denominator+numerator;
            integer--;
        }
        else if(numerator>0 && integer<0){
            numerator=denominator-numerator;
            integer++;
        }
        if (integer!=0){
            printf("%lld %lld %lld",integer,numerator,denominator);
        }
        else{
            printf("%lld %lld",numerator,denominator);
        }
        
    }
    else{//该数没有小数部分
        integer=intcount(s);
        printf("%lld",integer);
    }
    return 0;
}

long long int intcount(char *s)
{
    int res=0;
    int temp;
    char *p=s;
    while(*p!='\0'){
        if (*p=='2')
            temp=-1;
        else 
            temp=*p-'0';
        res=res*3+temp;
        p++;
    }
    return res;
}

long long int numecount(char *s)
{
    int res=0;
    int temp;
    char *p=s;
    while(*p!='\0'){
        if (*p=='2')
            temp=-1;
        else 
            temp=*p-'0';
        res=res*3+temp;
        p++;
    }
    return res;
}

long long int denocount(char *s)
{
    return pow(3,strlen(s));
}