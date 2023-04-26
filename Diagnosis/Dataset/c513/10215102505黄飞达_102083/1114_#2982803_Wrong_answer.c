#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    char s[30]={};
    gets(s);
    int cal[3]={0};
    int slen = strlen(s), temp=0, fuhao=1;
    for (int i=0; i<slen; i++){
        if ('0'<=s[i] && s[i]<='9') temp = temp*10 + s[i]-'0';
        else {
            if (s[i]=='x'){
                if (temp==0) temp=1;
                if(i+1<slen && s[i+1]=='^') {cal[s[i+2]-'0']=temp*fuhao;i+=2;}
                else cal[1]=temp*fuhao;
                temp=0;
            }
            else if (s[i]=='+') fuhao=1;
            else if (s[i]=='-') fuhao=-1;
        }
        
    }
    if (temp!=0) cal[0]=temp*fuhao;
    if (cal[0]==0){
        int c1=0, c2=cal[1];
        if (c1>c2){int temp=c1; c1=c2; c2=temp;}
        printf("1 %d %d %d\n", c1, cal[2], c2);
        return 0;
    }

    int sa = sqrt(cal[2]), a1=1, a2=1, flag=0;
    if (sa*sa!=cal[2]){
        for (;a1<=sa; a1++){
            if (cal[2]%a1==0) a2=cal[2]/a1;
            else continue;
            int c1temp = cal[0]>0?cal[0]:-cal[0];
            int c1=-c1temp,c2=-1;
            for(;c1<=c1temp; c1++){
                if (c1!=0&&cal[0]%c1==0) c2=cal[0]/c1;
                else continue;
                if (a1*c2+a2*c1==cal[1]){
                    printf("%d %d %d %d\n", a1, c1, a2, c2);
                    flag=1;
                    break;
                }
            }
        }        
    }
    if (flag==0){
        if (sa*sa==cal[2]){
            int c1temp=cal[0]>0?cal[0]:-cal[0];
            int c1=-c1temp,c2=0, sc=sqrt((double)c1temp);
            for(;c1<=sc; c1++){
                if (c1!=0&&cal[0]%c1==0) c2=cal[0]/c1;
                else continue;
                if (sa*(c1+c2)==cal[1]){
                    printf("%d %d %d %d\n", sa, c1, sa, c2);
                    flag=1;
                    break;
                }
            }
        }
        if (flag==0) printf("No Answer!\n");
    }
    return 0;
}