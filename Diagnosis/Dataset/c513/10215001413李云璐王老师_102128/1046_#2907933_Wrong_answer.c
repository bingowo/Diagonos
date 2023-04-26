#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int paichu(char*s)
{
    int flag=1;
    char a[34][4]={"the","a","an","of","for","and","THE","A","AN","OF","FOR","AND"
        ,"The","An","Of","For","And","tHe","tHE","thE","THe","ThE","aN","oF","fOR","FOr","FoR",
        "foR","fOr","ANd","AnD","aND","anD","aNd"};
    
    for(int i=0;i<33;i++)
    if(strcmp(s,a[i])==0) flag=0;
    return flag;
    
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int h=0;h<n;h++)
    {
        char s[110][30],c;
        int i=0,l=0,count=0;
        while((c=getchar())!='\n')
        {  
            if(c!=' ')
            {s[i][l]=c;l++;}
            else {i++;l=0;}
            
        }
            int k;
            for(int g=0;g<i;g++)
           { for(k=g-1;k>=0;k--)
            if(strcmp(s[g],s[k])==0) break;
            if(k==-1&&(paichu(s[g]))==1) count++;
           }
        
        printf("case #%d:\n",h);
        printf("%d\n",count);
    }
    return 0;
}