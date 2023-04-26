#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[42],m[42],n[42];
    scanf("%s",s);
    long long a,b;
    char *find = strchr(s,'i');
    char *find1 = strchr(s,'+');
    char *find2 = strchr(s,'-');
    if(find==NULL)
    {
        a = atoll(s);b = 0;
    }
    else{
        if(s[0]=='i') {a = 0;b = 1;}
        else if(find1!=NULL) {
            strncpy(m,s,find1-s);
            m[find1-s] = '\0';
            a = atoll(m);
            if(strstr(s,"+i")) b = 1;
            else
            {strncpy(n,find1,find - find1);
            n[find-s] = '\0';
            b = atoll(n);}
            }
        else if(find2==NULL){
            strncpy(m,s,find-s);
            m[find-s] = '\0';
            a = 0;
            b = atoll(m);
        }
        else if(find2!=NULL&&strchr(find2+1,'-')==NULL)
        {
            if(s[0] == '-')
            {if(strlen(s)==2) {a = 0;b = -1;}
            else{strncpy(m,s,find-s);
            m[find-s] = '\0';a = 0;b = atoll(m);}
            }
            else
            {
                strncpy(m,s,find2-s);
                m[find2-s] = '\0';
                a = atoll(m);
                if(strstr(s,"-i")) b = -1;
                else{strncpy(n,find2,find-find2);
                n[find-s] = '\0';
                b = atoll(n);}
            }
        }
        else{
                char *c = strchr(find2+1,'-');
                strncpy(m,s,c-s);
                m[c-s] = '\0';
                a = atoll(m);
                if(strstr(s,"-i")) b = -1;
                else{strncpy(n,c,find-c);
                n[find-s] = '\0';
                b = atoll(n);}
        }
    }
    //printf("%lld %lld ",a,b);
    long long qr,qi,r,res[200]={0},k = 0,i;
    do{
    if((llabs(a)%2)==(llabs(b)%2)) r = 0;
    else r = 1;
    //printf("%lld ",r);
    qi = (a+b-r)/(-2);
    qr = (a-b-r)/(-2);
    //printf("%lld %lld ",a,b);
    a = qr;b = qi;
    res[k++] = r;
    }while(qr!=0||qi!=0);
    for(i = k-1;i>=0;i--)
        printf("%lld",res[i]);
    return 0;
}
