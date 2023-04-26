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
    while(i>=0)
    {
    if(s[i]=='I'){ans+=1;i--;}
    else if(s[i]=='X'){
        if(i>=1&&s[i-1]=='I')
        {
            ans+=9;
            i-=2;
        }
        else{ans+=10;i--;}
    }
    else if(s[i]=='C'){
        if(i>=1&&s[i-1]=='X')
        {
            ans+=90;
            i-=2;
        }
        else{ans+=100;i--;}
    }
    else if(s[i]=='V'){ans+=5;i--;}
    else if(s[i]=='L'){ans+=50;i--;}
        else if(s[i]=='D'){ans+=500;i--;}
        else if(s[i]=='M'){ans+=1000;i--;}
    }
    
printf("%lld\n",ans);


}
