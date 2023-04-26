#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int l=strlen(s);
    int a[l];
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
        }
        else{
            a[i]=-1;
        }
    }
    int max=0;
    int t=0;
    int cut=0;
    while(cut<l){
        if(a[cut]<=0){
            cut++;
        }
        else{
            int m=cut;
            for(int i=m;i<l;i++){
                if(a[i]>=0){
                    t++;
                    cut++;
                }
                else{
                    if(max<t){
                        max=t;
                    }
                    t=0;
                    break;
                }
            }
            cut++;
        }
    }
    if(max<t){
        max=t;
    }
    printf("%d\n",max);
    return 0;
}