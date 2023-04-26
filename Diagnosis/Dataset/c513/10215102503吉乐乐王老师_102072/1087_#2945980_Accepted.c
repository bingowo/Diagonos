#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void stoi(char s[],int a[]){
    char *p=s;int i=0;
    while(*p){
        a[i]=*p-'0';
        p++;i++;
    }
}
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        char s[101];
        scanf("%s",s);getchar();
        int n=strlen(s);
        if(n==1){
            printf("case #%d:\n%d\n",cas++,(s[0]-'0')+1);
        }
        else{
            int a[101];
            stoi(s,a);
            int carry=0;
            a[n-1]+=1;
            for(int i=n-1;i>0;i--){
                a[i-1]+=a[i]/10;
                a[i]%=10;
            }
            carry+=a[0]/10;
            a[0]%=10;
            int pre=a[0];
            int i=1;
            while(i!=n){
                if(a[i]==pre){
                    for(int j=i+1;j<n;j++){
                        a[j]=0;
                    }
                    a[i]+=1;
                    for(int j=i;j>0;j--){
                        a[j-1]+=a[j]/10;
                        a[j]%=10;
                    }
                    carry+=a[0]/10;
                    a[0]%=10;
                    pre=a[0];i=1;continue;
                }
                else {
                    pre=a[i];i++;
                }
            }
            printf("case #%d:\n",cas++);
            if(carry)printf("%d",carry);
            for(int i=0;i<n;i++){
                printf("%d",a[i]);
            }
            putchar('\n');
        }
    }
}