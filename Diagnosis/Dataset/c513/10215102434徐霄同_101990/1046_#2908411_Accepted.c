#include <stdio.h>
#include <string.h>

int main()
{
    char no[6][4]={"the","a","an","of","for","and"};
    char s[101],c[101];
    int t,i,j,k,p,l,n,f;
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(s);
        l=strlen(s);
        n=0;
        memset(c,0,sizeof(c));
        k=0;
        for(j=0;j<=l;j++){
            if(j<l && s[j]>='A' && s[j]<='Z')
                s[j]=s[j]-'A'+'a';
            if(j<l && s[j]!=' '){
                c[k]=s[j];
                k++;
            }
            else{
                f=0;
                for(p=0;p<6;p++)
                    if(strcmp(no[p],c)==0)
                        f=1;
                if(f==0)
                    n++;
                k=0;
                memset(c,0,sizeof(c));
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",n);
    }
    return 0;
}
