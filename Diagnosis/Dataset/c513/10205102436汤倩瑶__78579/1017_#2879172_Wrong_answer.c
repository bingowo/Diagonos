#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{

    //IVXLCDM

    char s[60];
    scanf("%s",s);
    int l=strlen(s);
    long long int ans=0;
    int i=l-1;
    int p=1;
    int flag=0;
    int tmp=0;
    int tmpp;
    while(i>=0)
    {
    if(s[i]=='I'){if(flag==0)ans+=1;else tmp+=1;i--;}
    else if(s[i]=='X'){if(flag==0){
        if(i>=1&&s[i-1]=='I')
        {
            ans+=9;
            i-=2;
        }
        else{ans+=10;i--;}}
        else{ if(i>=1&&s[i-1]=='I')
        {
            tmp+=9;
            i-=2;
        }
        else{tmp+=10;i--;}}
    }
    else if(s[i]=='C'){
            if(flag==0){
        if(i>=1&&s[i-1]=='X')
        {
            ans+=90;
            i-=2;
        }
        else{ans+=100;i--;}}
        else{if(i>=1&&s[i-1]=='X')
        {
            tmp+=90;
            i-=2;
        }
        else{tmp+=100;i--;}
        }
    }
    else if(s[i]=='M'){
            if(flag==0){
        if(i>=1&&s[i-1]=='C')
        {
            ans+=900;
            i-=2;
        }
        else{ans+=1000;i--;}}
        else{if(i>=1&&s[i-1]=='C')
        {
            tmp+=900;
            i-=2;
        }
        else{tmp+=1000;i--;}
        }
    }
    else if(s[i]=='V'){if(flag==0)ans+=5;else tmp+=5;i--;}
    else if(s[i]=='L'){if(flag==0)ans+=50;else tmp+=50;i--;}
    else if(s[i]=='D'){if(flag==0)ans+=500;else tmp+=500;i--;}
    else if(s[i]=='M'){if(flag==0)ans+=1000;else tmp+=1000;i--;}
    else if(s[i]==')'){flag=1;p*=1000;i--;}
    else if(s[i]=='('){if(flag==1){ans+=tmp*p;tmpp=tmp*p;}flag=0;p/=1000;
    if(p==1){
        if(i>=1&&s[i-1]=='M'&&tmpp>1000){ans-=1000;i-=2;}
        else if(i>=1&&s[i-1]=='C'&&tmpp>100){ans-=100;i-=2;}
        else if(i>=1&&s[i-1]=='X'&&tmpp>10){ans-=10;i-=2;}
        else if(i>=1&&s[i-1]=='I'&&tmpp>1){ans-=1;i-=2;}
    }
       else i--;}

    }


printf("%lld\n",ans);


}
