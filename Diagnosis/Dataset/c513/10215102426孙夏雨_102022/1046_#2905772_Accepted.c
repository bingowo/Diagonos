#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    char* basic[]={"the","a","an","of","for","and"};
    for(int t=0;t<T;t++){
        int num=0;
        char s[100],c;
        do{
            scanf("%s",s);
            int i=0,len=strlen(s);
            for(;i<6;i++){
                for(int j=0;j<len;j++){
                    if(s[j]-'a'<0)  s[j]=s[j]+'a'-'A';
                }
                int k=strcmp(basic[i],s);
                if(k==0) break;
            }
            if(i==6){
                    num++;
            }
        }while((c=getchar())!='\n');
        printf("case #%d:\n",t);
        printf("%d\n",num);
    }
    return 0;
}
