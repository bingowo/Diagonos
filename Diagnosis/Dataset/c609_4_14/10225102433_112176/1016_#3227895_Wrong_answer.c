#include <stdio.h>
#include <string.h>
#define N 100000


int main()
{
    int ans = 0;
    int f[N] = {0};
    char s[100] = {0};
    long long a,b;
    int sig = 0,sigi = 0;
    scanf("%s",s);
    unsigned len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        if(s[i] == 'i'){
            sig = 1;
            a = 0;
            sscanf(s,"%lldi",&b);
            break;
        }
        if(s[i] == '+'){
            sig = 1;
            if(s[i+1] == 'i'){
                b = 1;
                sscanf(s,"%lld+i",&a);
                break;
            }
            else{
                sscanf(s,"%lld+%lldi",&a,&b);
                break;
            }
        }
        if(s[i] == '-' && i != 0){
            sig = 1;
            if(s[i+1] == 'i'){
                b = -1;
                sscanf(s,"%lld-i",&a);
                break;
            }
            else{
                sscanf(s,"%lld-%lldi",&a,&b);
                b = -b;
                break;
            }
        }
    }
    if(sig == 0){
        b = 0;
        sscanf(s,"%lld",&a);
    }
    int k = 0;
    if(a == 0 && b == 0){
        printf("0");
        return 0;
    }
    while(a != 0 || b != 0)
    {
        k = (a+b)%2==0 ? 0 : 1;
        f[ans++] = k;
        long long ra = a;
        long long rb = b;
        a = (k+rb-ra)/2;
        b = a-rb;
    }
    for(int i = ans-1;i >= 0;i--) printf("%d",f[i]);

    return 0;
}