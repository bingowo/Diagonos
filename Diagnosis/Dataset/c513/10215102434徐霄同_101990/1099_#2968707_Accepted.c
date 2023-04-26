#include <stdio.h>
#include <string.h>
char m[36][6]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char zm(char s[])
{
    char i;
    for(i=0;i<10;i++)
        if(strcmp(s,m[i])==0)
            return i+'0';
    for(i=10;i<37;i++)
        if(strcmp(s,m[i])==0)
            return i-10+'A';
}
int main()
{
    char s[1001];
    char s0[1000][6];
    int f[1000];
    int t,i,j,k,n,p,l;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        l=strlen(s);
        memset(s0,0,sizeof(s0));
        n=0;
        k=0;
        j=0;
        while(j<l){
            if(s[j]=='-'||s[j]=='.'){
                s0[n][k]=s[j];
                k++;
                j++;
                if(j==l){
                    f[n]=1;
                    n++;
                }
            }
            else{
                p=0;
                while(s[j]=='/'){
                    j++;
                    p++;
                }
                f[n]=p;
                n++;
                k=0;
            }
        }
        printf("case #%d:\n",i);
        for(j=0;j<n;j++){
            printf("%c",zm(s0[j]));
            if(f[j]==3)
                printf(" ");
            else if(f[j]==5)
                printf(".");
            if(j==n-1)
                printf("\n");
        }
    }
    return 0;
}
