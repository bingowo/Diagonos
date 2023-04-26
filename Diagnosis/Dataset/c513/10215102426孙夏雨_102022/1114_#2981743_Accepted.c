#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int cmp(const void* p3,const void* p4)
{
    int* p1=(int* )p3;
    int* p2=(int* )p4;
    if(p1[0]>p2[0]) return 1;
    else if(p1[0]<p2[0]) return -1;
    else {
        if(p1[1]>p2[1]) return 1;
        else return -1;
    }
}

int main()
{
    char s[50];
    scanf("%s",s);
    int len=strlen(s);
    int a=0,b=0,c=0,i=0,sig=1,xi=0;
    int ans[2][2]={0};
    int a1=0,a2=0,c1=0,c2=0;
    while(i<len){
        if(isdigit(s[i])){
            xi=xi*10+s[i]-'0';
            i++;
        }
        if(s[i]=='x'){
            i++;
            if(s[i]=='^'){
                i+=2;
                a=xi*sig;
                if(a==0) a=sig;
                xi=0,sig=1;
            }
            else {
                b=xi*sig;
                if(b==0) b=sig;
                xi=0,sig=1;
            }
        }
        if(s[i]=='+'||s[i]=='-'){
            sig= s[i]=='+' ? 1:-1;
            i++;
        }
    }
    if(xi!=0) c=xi*sig;
    //printf("%d %d %d\n",a,b,c);
    if(b==0){
        if(a*c>0) printf("No Answer!\n");
        else{
            if(a>0){
                a1=sqrt(a);
                if(a1*a1!=a) printf("No Answer!\n");
                else {
                    a2=a1;
                    c1=sqrt((-1)*c);
                    if(c1*c1!=(-1)*c) printf("No Answer!\n");
                    else {
                        c2=(-1)*c1;
                        printf("%d %d %d %d\n",a2,c2,a1,c1);
                    }
                }
            }
        }
    }
    else if(c==0){
        ans[0][0]=1;
        ans[0][1]=0;
        ans[1][0]=a;
        ans[1][1]=b;
        qsort(ans,2,sizeof(int* ),cmp);
        printf("%d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
    }
    else{
        if(a>0&&c>0){
            int aq=sqrt(a);
            int cq=sqrt(c);
            int you=0;
            a1=1;
            for(;a1<=aq&&you==0;a1++){
                if(a%a1==0){
                    a2=a/a1;
                    c1=1;
                    for(;c1<=cq;c1++){
                        if(c%c1==0){
                            c2=c/c1;
                            if(a1*c2+a2*c1==b){
                                ans[0][0]=a1;
                                ans[0][1]=c1;
                                ans[1][0]=a2;
                                ans[1][1]=c2;
                                you=1;
                                break;
                            }
                            else if(a1*c1+a2*c2==b){
                                ans[0][0]=a1;
                                ans[0][1]=c2;
                                ans[1][0]=a2;
                                ans[1][1]=c1;
                                you=1;
                                break;
                            }
                            else if((-1)*a1*c1+(-1)*a2*c2==b){
                                ans[0][0]=a1;
                                ans[0][1]=(-1)*c2;
                                ans[1][0]=a2;
                                ans[1][1]=(-1)*c1;
                                you=1;
                                break;
                            }
                            else if((-1)*a1*c2+(-1)*a2*c1==b){
                                ans[0][0]=a1;
                                ans[0][1]=(-1)*c1;
                                ans[1][0]=a2;
                                ans[1][1]=(-1)*c2;
                                you=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(you==0) printf("No Answer!\n");
            else {
                qsort(ans,2,sizeof(int* ),cmp);
                printf("%d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
            }
        }
        else if(a>0&&c<0){
            int aq=sqrt(a);
            int cq=sqrt((-1)*c);
            int you=0;
            a1=1;
            for(;a1<=aq&&you==0;a1++){
                if(a%a1==0){
                    a2=a/a1;
                    c1=1;
                    for(;c1<=cq;c1++){
                        if((-1)*c%c1==0){
                            c2=c/c1;
                            if(a1*c2+a2*c1==b){
                                ans[0][0]=a1;
                                ans[0][1]=c1;
                                ans[1][0]=a2;
                                ans[1][1]=c2;
                                you=1;
                                break;
                            }
                            else if((-1)*a1*c2+(-1)*a2*c1==b){
                                ans[0][0]=a1;
                                ans[0][1]=(-1)*c1;
                                ans[1][0]=a2;
                                ans[1][1]=(-1)*c2;
                                you=1;
                                break;
                            }
                            else if(a1*c1+a2*c2==b){
                                ans[0][0]=a1;
                                ans[0][1]=c2;
                                ans[1][0]=a2;
                                ans[1][1]=c1;
                                you=1;
                                break;
                            }
                            else if((-1)*a1*c1+(-1)*a2*c2==b){
                                ans[0][0]=a1;
                                ans[0][1]=(-1)*c2;
                                ans[1][0]=a2;
                                ans[1][1]=(-1)*c1;
                                you=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(you==0) printf("No Answer!\n");
            else {
                qsort(ans,2,sizeof(int* ),cmp);
                printf("%d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
            }
        }
        else if(a<0&&c>0){
            int aq=sqrt((-1)*a);
            int cq=sqrt(c);
            int you=0;
            a1=1;
            for(;a1<=aq&&you==0;a1++){
                if((-1)*a%a1==0){
                    a2=a/a1;
                    c1=1;
                    for(;c1<=cq;c1++){
                        if(c%c1==0){
                            c2=c/c1;
                            if(a1*c2+a2*c1==b){
                                ans[0][0]=a1;
                                ans[0][1]=c1;
                                ans[1][0]=a2;
                                ans[1][1]=c2;
                                you=1;
                                break;
                            }
                            else if((-1)*a1*c2+(-1)*a2*c1==b){
                                ans[0][0]=(-1)*a1;
                                ans[0][1]=c1;
                                ans[1][0]=(-1)*a2;
                                ans[1][1]=c2;
                                you=1;
                                break;
                            }
                            else if(a1*c1+a2*c2==b){
                                ans[0][0]=a1;
                                ans[0][1]=c2;
                                ans[1][0]=a2;
                                ans[1][1]=c1;
                                you=1;
                                break;
                            }
                            else if((-1)*a1*c1+(-1)*a2*c2==b){
                                ans[0][0]=(-1)*a1;
                                ans[0][1]=c2;
                                ans[1][0]=(-1)*a2;
                                ans[1][1]=c1;
                                you=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(you==0) printf("No Answer!\n");
            else {
                qsort(ans,2,sizeof(int* ),cmp);
                printf("%d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
            }
        }
        if(a<0&&c<0){
            int aq=sqrt((-1)*a);
            int cq=sqrt((-1)*c);
            int you=0;
            a1=1;
            for(;a1<=aq&&you==0;a1++){
                if((-1)*a%a1==0){
                    a2=a/a1;
                    c1=1;
                    for(;c1<=cq;c1++){
                        if((-1)*c%c1==0){
                            c2=c/c1;
                            if(a1*c2+a2*c1==b){
                                ans[0][0]=a1;
                                ans[0][1]=c1;
                                ans[1][0]=a2;
                                ans[1][1]=c2;
                                you=1;
                                break;
                            }
                            else if((-1)*a1*c2+(-1)*a2*c1==b){
                                ans[0][0]=(-1)*a1;
                                ans[0][1]=c1;
                                ans[1][0]=(-1)*a2;
                                ans[1][1]=c2;
                                you=1;
                                break;
                            }
                            else if(a1*c1+a2*c2==b){
                                ans[0][0]=a1;
                                ans[0][1]=c2;
                                ans[1][0]=a2;
                                ans[1][1]=c1;
                                you=1;
                                break;
                            }
                            else if((-1)*a1*c1+(-1)*a2*c2==b){
                                ans[0][0]=(-1)*a1;
                                ans[0][1]=c2;
                                ans[1][0]=(-1)*a2;
                                ans[1][1]=c1;
                                you=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(you==0) printf("No Answer!\n");
            else {
                qsort(ans,2,sizeof(int* ),cmp);
                printf("%d %d %d %d\n",ans[0][0],ans[0][1],ans[1][0],ans[1][1]);
            }
        }
    }
    return 0;
}
