#include <stdio.h>
#include <ctype.h>
#include <string.h>
int atoi(char s[])
{
    int v,i,s1;
    i=0;
    s1=(s[i]=='-')?-1:1;
    if (s[i]=='-')
        i=1;
    for(v=0;isdigit(s[i]);i++)
        v=10*v+(s[i]-'0');
    v=s1*v;
    return v;
}
double atof(char s[])
{
    double v,p;
    int i,s1;
    i=0;
    s1=(s[i]=='-')?-1:1;
    if (s[i]=='-')
        i=1;
    for(v=0.0;isdigit(s[i]);i++)
        v=10.0*v+(s[i]-'0');
    if (s[i]=='.')
        i++;
    for(p=1.0;isdigit(s[i]);i++){
        v=10.0*v+(s[i]-'0');
        p*=10.0;
    }
    v=s1*v/p;
    return v;
}

int main() {
    char s[100];
    int a[64];
    int i,l,xi,t,t0,n,c;
    double xd,m,m0;
    while(scanf("%s",s)!=EOF){
        l=strlen(s);
        for(i=0;s[i]!='.'&&i<l;i++)
            ;
        if(i==l){
            t=0;
            xi=atoi(s);
        }
        else{
            t=1;
            xd=atof(s);
        }
        if(t==0){
            if(xi<0){
                t0=1;
                xi=-xi-1;
            }
            else
                t0=0;
            for(i=0;i<32;i++)
                a[i]=0;
            i=31;
            while(xi>0){
                a[i]=xi%2;
                xi=xi/2;
                i--;
            }
            if(t0==1){
                for(i=0;i<32;i++)
                    if(a[i]==0)
                        a[i]=1;
                    else
                        a[i]=0;
            }
            for(i=24;i>=0;i=i-8){
                n=a[i]*8+a[i+1]*4+a[i+2]*2+a[i+3];
                printf("%0x",n);
                n=a[i+4]*8+a[i+5]*4+a[i+6]*2+a[i+7];
                printf("%0x",n);
                if(i==0)
                    printf("\n");
                else
                    printf(" ");
            }
        }
        else{
            if(xd<0){
                t0=1;
                xd=-xd;
            }
            else
                t0=0;
            for(i=1;i<64;i++)
                a[i]=0;
            a[0]=t0;
            if(xd>=1){
                c=0;
                m=1.0;
                while(xd/m>=2){
                    c++;
                    m=m*2;
                }
                m=xd/m;
            }
            else{
                c=-1;
                m=0.5;
                while(xd/m<1){
                    c--;
                    m=m/2;
                }
                m=xd/m;
            }
            c=c+1023;
            i=11;
            while(c<0){
                a[i]=c%2;
                c=c/2;
                i--;
            }
            m=(m-1)*8192;
            i=12;
            m0=4096;
            while(i<64 || m!=0){
                if(m>=m0){
                    a[i]=1;
                    m=m-m0;
                }
                i++;
                m0=m0/2;
            }
            for(i=56;i>=0;i=i-8){
                n=a[i]*8+a[i+1]*4+a[i+2]*2+a[i+3];
                printf("%0x",n);
                n=a[i+4]*8+a[i+5]*4+a[i+6]*2+a[i+7];
                printf("%0x",n);
                if(i==0)
                    printf("\n");
                else
                    printf(" ");
            }
        }
    }
    return 0;
}