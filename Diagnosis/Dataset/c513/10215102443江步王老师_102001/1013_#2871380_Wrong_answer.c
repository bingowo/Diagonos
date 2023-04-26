#include<stdio.h>
#include<math.h>


int intcount(char *s);
int numecount(char *s);
int denocount(char *s);
int main()
{
    char s[31];
    int integer;
    char *p=s;
    scanf("%s",s);
    while(*p!='.' && *p!='\0'){
        p++;
    }
    if(*p=='.'){//该平衡三进制数有小数部分
        int numerator,denominator;
        *p='\0';
        integer=intcount(s);
        *p='.';
        p++;
        denominator=denocount(p);
        numerator=numecount(p);
        if (numerator<0 && integer>0){
            numerator=denominator-numerator;
            integer--;
        }
        
        if (integer!=0){
            printf("%d %d %d",integer,numerator,denominator);
        }
        else{
            printf("%d %d",numerator,denominator);
        }
        
    }
    else{//该数没有小数部分
        integer=intcount(s);
        printf("%d",integer);
    }
    return 0;
}

int intcount(char *s)
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

int numecount(char *s)
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

int denocount(char *s)
{
    return pow(3,strlen(s));
}