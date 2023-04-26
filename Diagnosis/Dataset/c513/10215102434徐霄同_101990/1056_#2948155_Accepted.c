#include <stdio.h>
#include <string.h>

int main()
{
    char w[4000][15];
    char s[5001];
    char ans[5000][15];
    char s0[15];
    int i,j,k,n,l,ml,n0,f;
    scanf("%d",&n);
    ml=0;
    for(i=0;i<n;i++){
        scanf("%s",w[i]);
        l=strlen(w[i]);
        if(l>ml)
            ml=l;
    }
    scanf("%s",s);
    l=strlen(s);
    i=0;
    n0=0;
    while(i<l){
        if(i+ml>l)
            j=l-1;
        else
            j=i+ml-1;
        for(k=i;k<=j;k++)
            s0[k-i]=s[k];
        s0[j-i+1]=0;
        f=0;
        while(j>i&&f==0){
            for(k=0;k<n;k++)
                if(strcmp(s0,w[k])==0){
                    strcpy(ans[n0],s0);
                    n0++;
                    f=1;
                    break;
                }
            s0[j-i]=0;
            j--;
            if(f==1)
                i=j+2;
        }
        if(j==i&&f==0){
            strcpy(ans[n0],s0);
            n0++;
            i++;
        }
    }
    for(i=0;i<n0;i++){
        printf("%s",ans[i]);
        if(i==n0-1)
            printf("\n");
        else
            printf(" ");
    }
    return 0;
}