#include <stdio.h>
#include <string.h>
int main()
{
    int T,i;
    scanf("%d",&T);
    getchar();
    char* p[] = {"A","a","THE","The","tHE","the","thE","tHe","AN","An","an","aN","oF","of","Of","OF","FOR","For","FOr","foR","for","fOR","and","And","AND","anD","ANd","aND"};
    for(i = 0;i<T;i++)
    {
        char s[1000];
        char *a;int n = 0,j;
        gets(s);
        a = strtok(s," ");
        while(a!=NULL)
        {
            for(j =0;j<28;j++)
                if(strcmp(a,p[j])==0) break;
            if(j==28) n++;
            a = strtok(NULL," ");
        }
        printf("case #%d:\n%d\n",i,n);
    }
    return 0;
}
