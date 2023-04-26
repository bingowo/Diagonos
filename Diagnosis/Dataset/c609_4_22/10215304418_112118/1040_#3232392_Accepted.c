#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char st[1234];
char st1[1234];
char st2[1234];
int a[1234];
int b[1234];
int ans[3234];

int main(){
    while (scanf("%s %s",st1,st2)!=EOF){
        int i=0;
        for (int k=0;k<=50;k++){
            a[k]=0;
            b[k]=0;
            ans[k]=0;
        }
        while (i<strlen(st1)){
            int f=0;
            if (st1[i]=='-'){
                f=1;
                i++;
            }
            else if (st1[i]=='+'){
                i++;
            }
            int x=0;
            while (st1[i]>='0' && st1[i]<='9'){
                x*=10;
                x+=st1[i]-'0';
                i++;
            }
            if (x==0) x=1;
            if (f==1) x=-x;
            int j=0;
            if (i>=strlen(st1)) {
                a[0]=x;
                break;
            }
            if (st1[i+1]!='^'){
                a[1]=x;
                i++;
                continue;
            }
            i+=2;
            while (st1[i]>='0' && st1[i]<='9'){
                j*=10;
                j+=st1[i]-'0';
                i++;
            }
            a[j]=x;
        }
        i=0;
        while (i<strlen(st2)){
            int f=0;
            if (st2[i]=='-'){
                f=1;
                i++;
            }
            else if (st2[i]=='+'){
                i++;
            }
            int x=0;
            while (st2[i]>='0' && st2[i]<='9'){
                x*=10;
                x+=st2[i]-'0';
                i++;
            }
            if (x==0) x=1;
            if (f==1) x=-x;
            int j=0;
            if (i>=strlen(st2)) {
                b[0]=x;
                break;
            }
            if (st2[i+1]!='^'){
                b[1]=x;
                i++;
                continue;
            }
            i+=2;
            while (st2[i]>='0' && st2[i]<='9'){
                j*=10;
                j+=st2[i]-'0';
                i++;
            }
            b[j]=x;
        }
        for (int i=0;i<=50;i++){
            for (int j=0;j<=50;j++)
                ans[i+j]+=a[i]*b[j];
        }
        for (int i=2500;i>=0;i--)
            if (ans[i]!=0) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
