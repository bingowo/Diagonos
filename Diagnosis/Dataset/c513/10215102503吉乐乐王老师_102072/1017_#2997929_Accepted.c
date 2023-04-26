#include<stdio.h>
#include<string.h>
int main(){
    int map[128];
    map['I']=1;map['V']=5;map['X']=10;
    map['L']=50;map['C']=100;
    map['D']=500;map['M']=1000;
    char s[51];
    scanf("%s",s);
    long long int ret=0;
    long long int temp=0;
    for(int i=0;i<strlen(s);i++){
        if(i==0){
            if(s[i]=='('){
                long long int flag=1;
                while(s[i]=='('){
                    flag*=1000;i++;
                }
                while(s[i+1]!=')'){
                    if(map[s[i]]<map[s[i+1]])temp-=map[s[i]];
                    else temp+=map[s[i]];
                    i++;
                }
                temp+=map[s[i]];temp*=flag;
            }
            else if(i+1<strlen(s)&&s[i+1]!='('){
                if(map[s[i]]<map[s[i+1]])temp-=map[s[i]];
                else temp+=map[s[i]];
            }
        }
        else if(s[i]==')')continue;
        else if(s[i]=='('){
            char pre=s[i-1];
            long long int flag=1;
            while(s[i]=='('){
                flag*=1000;i++;
            }
            while(s[i+1]!=')'){
                if(map[s[i]]<map[s[i+1]])temp-=map[s[i]];
                else temp+=map[s[i]];
                i++;
            }
            temp+=map[s[i]];temp*=flag;
            if(map[pre]<temp)temp-=map[pre];
            else temp+=map[pre];
        }
        else if(i+1<strlen(s)&&s[i+1]!='('){
            if(map[s[i]]<map[s[i+1]])temp-=map[s[i]];
            else temp+=map[s[i]];
        }
        ret+=temp;
        temp=0;
    }
    if(s[strlen(s)-1]!=')')ret+=map[s[strlen(s)-1]];
    printf("%lld",ret);
}