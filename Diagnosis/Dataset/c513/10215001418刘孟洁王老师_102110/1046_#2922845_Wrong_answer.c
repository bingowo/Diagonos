#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[12][4] = {"the","a","an","of","for","and","The","A","An","Of","For","And"};

int main()
{
    int n,words,i,j,k,h,l;
    char t[103],word[31];
    scanf("%d",&n);
    gets(t);
    for(i = 0; i < n; i++)
    {
        gets(t);
        for(j = 0,words = 0,k = 0; t[j] != '\0'; j++)
        {
            if(t[j+1] != ' '&&t[j+1] != '\0')word[k] = t[j],k++;
            else if(t[j+1] == ' ')
            {
                word[k] = t[j],k++;
                word[k] = '\0';
                for(l = 0,h = 0; l < 12; l++)
                    {if(!strcmp(word,s[l])){h++;break;}}
                if(h == 0)words++;
                for(l = 0; l < k; l++){word[l] = '\0';}
                k = 0;
                j++;
            }
            else if(t[j+1] == '\0')
            {
                word[k] = t[j],k++;
                word[k] = '\0';
                for(l = 0,h = 0; l < 12; l++)
                    {if(!strcmp(word,s[l])){h++;break;}}
                if(h == 0)words++;
                for(l = 0; l < k; l++){word[l] = '\0';}
                k = 0;
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",words);
    }
    return 0;
}