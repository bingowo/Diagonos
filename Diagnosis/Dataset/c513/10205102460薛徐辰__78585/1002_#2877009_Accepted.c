#include<stdio.h>
long long findg(char* s){
    char f[61];
    int i=1,j;
    long long ans=0;
    f[0]=s[0];
    for(j=1;s[j];j++){
        int flag=1;
        for(int z=0;z<i;z++){if(s[j]==f[z])flag=0;}
        if(flag){f[i]=s[j];i++;}
    }
    if(i==1)i=2;
    long long c[61];
    for(int k=0;k<j;k++){
        if(s[k]==f[0])c[k]=1;
        else if(s[k]==f[1])c[k]=0;
        else{
            for(int m=2;m<i;m++){
                if(s[k]==f[m])c[k]=m;
            }
        }
    }
    long long g=1;
    for(int z=0;z<j;z++){
        ans+=c[j-1-z]*g;
        g=g*i;
    }
    return ans; 
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        char s[61];
        scanf("%s",s);
        long long a=findg(s);
        printf("case #%d:\n%lld\n",i,a);
    }
    return 0;
}