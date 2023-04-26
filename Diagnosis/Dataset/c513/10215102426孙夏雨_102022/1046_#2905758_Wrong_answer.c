#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    char* basic[]={"the","a","an","of","for","and"};
    for(int t=0;t<T;t++){
        char** p=(char** )malloc(100*sizeof(char*));
        char* p1;
        int num=0;
        char s[100],c;
        do{
            scanf("%s",s);
            int i=0,len=strlen(s);
            for(;i<6;i++){
                int k=strcmp(basic[i],s);
                if(k==0) break;
            }
            if(i==6){
                    p1=(char* )malloc((len+1)*sizeof(char));
                    strcpy(p1,s);
                    *(p+num)=p1;
                    num++;
            }
        }while((c=getchar())!='\n');
        printf("case #%d:\n",t);
        printf("%d\n",num);
        for(int jj=0;jj<num;jj++){
            p1=p[jj];
            free(p1);
        }
        free(p);
    }
    return 0;
}
