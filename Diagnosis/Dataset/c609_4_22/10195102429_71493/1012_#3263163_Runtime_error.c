#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[51];
int c[155];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=0;cas<t;cas++){
        scanf("%s",s);
        int len=strlen(s);
        long long int fz=0,fm=1;
        long long int yu,tmp;
        int j=0;
        for(int i=2;i<len;i++){
            fz=fz*8;
            tmp=s[i]-'0';
            fz+=tmp;
            fm=fm*8;
        }
        while(fz<fm){
            fz=fz*10;
            c[j]=0;
            j++;
        }
        while(fz){
            c[j]=fz/fm;
            yu=fz%fm;
            yu=yu*10;
            fz=yu;
            j++;

        }
      printf("case #%d:\n",cas);
      printf("0.");
      for(int k=1;k<j;k++){
        printf("%d",c[k]);
      }
      printf("\n");
    }
    return 0;
}
