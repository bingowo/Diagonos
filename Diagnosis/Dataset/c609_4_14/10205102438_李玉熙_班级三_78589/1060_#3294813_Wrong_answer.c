#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[100];
    char s[200];
    int j=0,d=0;
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++){
        if(a[i]>a[i+1]){
            s[j]=a[i];
            j++;
        }
        if(a[i]==a[i+1]){
            for(d=i;d<strlen(a);d++){
                if(a[d]!=a[d+1]){
                    break;
                }
            }
            if(a[d]>a[d+1]){
                s[j]=a[i];
                j++;
            }
            if(a[d]<a[d+1]){
                s[j]=a[i];
                j++;
                s[j]=a[i];
                j++;
            }
        }
        if(a[i]<a[i+1]){
            s[j]=a[i];
            j++;
            s[j]=a[i];
            j++;
        }
    }
    printf("%s",s);
}
