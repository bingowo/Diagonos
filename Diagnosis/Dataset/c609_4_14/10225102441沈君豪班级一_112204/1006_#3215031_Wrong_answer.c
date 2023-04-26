#include <stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    int i,a,j;
    for(i=0;i<T;i++){
        char s[60];
        int t[60];
        int min;
        scanf("%s",s);
        a=strlen(s);
        int b=2,k;
        if(a==2){
            if(s[0]!=s[1])
                 min=2;
            else
                min=3;
        }
        else {
            t[0]=1;
            j=1;
            for(;j<a;j++){
                if(s[j]==s[0]){
                    t[j]=t[0];

                }else{
                     t[j]=0;
                     break;}
            }
            min=0;
            for(j=j+1;j<a;j++){
                for(k=0;k<j;k++){
                    if(s[k]==s[j]){
                        t[j]=t[k];
                        break;
                    }
                    if(k==(j-1)){
                        t[j]=b;
                        b++;
                    }
                }
            }
            for(int m=0;m<a;m++){
                min=min*b+t[m];}

        }
        printf("case #%d:\n",i);
        printf("%d\n",min);



    }
    return 0;

}
