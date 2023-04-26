#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char s[51],*c,yet,*c1,*c2;
    int n[127]={0};
    n['I']=1;n['V']=5;n['X']=10;n['L']=50;n['C']=100;n['D']=500;n['M']=1000;
    long long int num=0,p[2]={0};
    int mul=1;
    scanf("%s",s);
    c=strchr(s,'(')!=NULL?strchr(s,'('):s;
    yet=*c;
    c++;
    c2=strrchr(s,')')!=NULL?strrchr(s,')'):s+strlen(s);
    while(c<c2){
        if(*c==yet){
            mul++;
        }
        else if(n[*c]<n[yet]){
            p[1]+=mul*n[yet];
            mul=1;
        }
        else{
            p[1]-=n[yet];
            mul=1;
        }
        yet=*c;
        c++;
        if(*c==')')p[1]*=1000;
    }
    p[1]+=mul*n[*(c-1)];
    if(strchr(s,'(')!=NULL){
        if (strchr(s,'(')!=s){
            c1=s,c=strchr(s,'(');
            yet=*s;
            while(c1<c){
                if(*c1==yet){
                    mul++;
                }
                else if(n[*c1]<n[yet]){
                    p[0]+=mul*n[yet];
                    mul=1;
                }
                else{
                    p[0]-=n[yet];
                    mul=1;
                }
                yet=*c1;
                c1++;
            }
        }
        else{
            c1=strchr(s,')')+1,c=s+strlen(s);
            yet=*c1;
            while(c1<c){
                if(*c1==yet){
                    mul++;
                }
                else if(n[*c1]<n[yet]){
                    p[0]+=mul*n[yet];
                    mul=1;
                }
                else{
                    p[0]-=n[yet];
                    mul=1;
                }
                yet=*c1;
                c1++;
            }
            
            
        }
        
        
    }
    num=p[0]+p[1];
    printf("%lld",num);
    return 0;
}