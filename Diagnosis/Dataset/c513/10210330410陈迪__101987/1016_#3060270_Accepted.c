#include<stdio.h>
#include<string.h>
int main()
{
    char tochar[21]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
    int n,r;
    scanf("%d %d",&n,&r);
    char s[30]={'0'}; char* p=s;
    while(n){
        if(n%r<0){
            *(p++) = tochar[n-(n/r+1)*r];
            n = n/r+1;
        }
        else{
            *(p++) = tochar[n%r];
            n/=r;
        }
    }
    char* q=s; p--;
    while(p>q){
        char tmp=*p;
        *p-- = *q;
        *q++ =tmp;
    }
    printf("%s",s);
    return 0;
}
