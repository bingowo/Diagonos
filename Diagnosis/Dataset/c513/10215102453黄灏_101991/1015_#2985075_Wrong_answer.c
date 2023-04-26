#include <stdio.h>
#include <string.h>

int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

void read(char *s, int *a){
    int n= strlen(s),t=25,ans=0;
    for(int i=0;i<26;i++) a[i]=0;
    char temp[3];

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<3;j++) s[j]='0';
        int k=2;
        while (s[i]!=',' && i>=0){
            s[k--] =s[i--];
        }
        ans = (s[1]-'0')*10+s[2]-'0';
        a[t--]=ans;
    }
}

void add(int *a,int *b,int *ans){
    int i=25,carry=0;
    for(int i=0;i<26;i++) ans[i]=0;
    while (i>=0){
        ans[i] = (a[i]+b[i]+carry)% prime[i];
        carry = (a[i]+b[i]+carry) / prime[i];
        i--;
    }
    ans[i] = carry;
}

void out(int *ans){
    int i=0;
    while(!ans[i])
    {
        i++;
        if(i==26)
        {
            printf("0\n");
            break;
        }
    }
    while(i<26)
    {
        printf("%d%c",ans[i],i==25?'\n':',');
        i++;
    }
}

int main(){
    int n;
    int a[26]={0},b[26]={0},ans[26]={0};
    char s[100];
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        printf("case #%d:\n",i);
        scanf("%s",s);
        read(s,a);
        scanf("%s",s);
        read(s,b);
        add(a,b,ans);
        out(ans);
    }
    return 0;
}