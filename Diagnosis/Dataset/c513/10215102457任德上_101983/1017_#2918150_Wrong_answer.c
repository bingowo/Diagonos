#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(){
    char s[51],*c,yet,*c1,*c2;
    int n[127];
    for(int i=0;i<127;i++)n[i]=0;
    n['I']=1;n['V']=5;n['X']=10;n['L']=50;n['C']=100;n['D']=500;n['M']=1000;
    long long int num=0,inside=0;
    int mul=0;
    scanf("%s",s);
    c=s;
    while(*c){
        if(!isalpha(*c)){
            while(!isalpha(*c)&&*c=='('){mul++;c++;}
            while(isalpha(*c)){
                if(n[*c]<n[*(c+1)])inside-=n[*c];
                else if(n[*c]>=n[*(c+1)])inside+=n[*c];
                c++;
            }
            while(!isalpha(*c))c++;
        }
        if(*c==0)break;
        if(*(c+1)==0)num+=n[*c];
        if(isalpha(*(c+1))){
            if(n[*c]<n[*(c+1)]&&*(c+1)!=0)num-=n[*c];
            else if(n[*c]>=n[*(c+1)]&&*(c+1)!=0)num+=n[*c];
            
        }
        else{
            c1=c+1;
            while(!isalpha(*c1))c1++;
            if(n[*c]<n[*c1]&&*c1!=0)num-=n[*c];
            else if(n[*c]>=n[*c1]&&*c1!=0)num+=n[*c];
        }
        c++;
        
    }
    while(mul-->0)inside*=1000;
    num+=inside;
    printf("%lld",num);
    
    return 0;


}