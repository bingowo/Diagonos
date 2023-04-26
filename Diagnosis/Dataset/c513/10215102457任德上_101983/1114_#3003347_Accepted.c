#include<stdio.h>
#include<string.h>
#include<ctype.h>
void read(char *s,int *a){
    while(*s){
        int flag=1,i=1,c=1;
        if(*s=='+')s++;
        if(*s=='-'){flag=-1;s++;}
        if(isdigit(*s))c=0;
        while(isdigit(*s)){
            c=c*10+*s-'0';
            s++;
        }
        if(*s!='x'){
            a[0]=flag*c;
            return;
        }
        s++;
        if(*s=='^'){
            s++;
            i=*s-'0';
            a[i]=flag*c;
            s+=1;
        }
        else{
            a[i]=flag*c;
        }
        continue;
    }
}
int main(){
    char s[100];
    int a[3]={0},q1,q2,p1,p2,flag=0;
    scanf("%s",s);
    read(s,a);
    int a5[15]={0},c[401]={0},a1=a[2],c1=a[0],b1=a[1];
    for(int i=0;i<15;i++){
        if(a1%(i+1)==0){
            a5[i]=a1/(i+1);
        }
        else a5[i]=201;
    }
    if(c1==0)c[0]=0;
    else c[0]=201;
    for(int i=1;i<=200;i++){
        if(c1%i==0){
            c[i]=c1/i;
        }
        else c[i]=201;
    }
    for(int i=201;i<401;i++){
        if(c1%(200-i)==0){
            c[i]=c1/(200-i);
        }
        else c[i]=201;
    }
    for(int i=0;i<15;i++){
        if(a5[i]==201)continue;
        for(int j=0;j<=200;j++){
            if(c[j]==201)continue;
            if((a5[i]*c[j]+(i+1)*j)==b1){
                q1=a5[i],q2=i+1,p1=j,p2=c[j];
                flag=1;
                break;
            }
            else if((a5[i]*j+(i+1)*c[j])==b1){
                q1=a5[i],q2=i+1,p1=c[j],p2=j;
                flag=1;
                break;
            }
        }
        if(flag)break;
    }
    if(!flag)for(int i=0;i<15;i++){
        if(a5[i]==201)continue;
        for(int j=201;j<=400;j++){
            if(c[j]==201)continue;
            if((a5[i]*c[j]+(i+1)*(200-j))==b1){
                q1=a5[i],q2=i+1,p1=(200-j),p2=c[j];
                flag=1;
                break;
            }
            else if((a5[i]*(200-j)+(i+1)*c[j])==b1){
                q1=a5[i],q2=i+1,p1=c[j],p2=(200-j);
                flag=1;
                break;
            }
        }
        if(flag)break;
    }
    if(q2==q1){
        if(p1<p2){
            int u=p1;
            p1=p2;
            p2=u;
        }
    }
    if(flag)printf("%d %d %d %d",q2,p2,q1,p1);
    else printf("No Answer!");
    return 0;
}