#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100000];
    int i=0,j=0;
    while((s[i]=getchar()) != EOF){
        i++;
    }

    while(j<i-1){

        if(s[j]=='"' && s[j+1]=='/' && s[j+2]=='/'){
            j+=3;
        }
        else if(s[j]=='/' && s[j+1]=='/' && s[j+2]=='"'){
            j+=3;
        }
        else if(s[j]=='/' && s[j+1]=='/' && s[j+2]==' ' && s[j+3]=='"'){
            j+=3;
        }
        else if(s[j]=='"' && s[j+1]=='/' && s[j+2]=='/'){
            j+=3;
        }
        else if(s[j]=='*' && s[j+1]=='/' && s[j+2]=='"'){
            j+=3;
        }
        else if(s[j]=='s' && s[j+1]=='d' && s[j+2]=='j' && s[j+3]=='k' && s[j+4]=='s' && s[j+5]=='d')
        {
            j+=5;
            while(!(s[j]=='d' && s[j+1]=='k' && s[j+2]=='s'))j++;
            j+=2;
        }
        else if(s[j]=='/' && s[j+1]=='/'){
            while(s[j] != '\n'){
                s[j]='@';
                j++;
            }
        }
        else if(s[j]=='/' && s[j+1]=='*'){
            while(!(s[j]=='*' && s[j+1]=='/')){
                s[j]='@';
                j++;
            }
            s[j]='@';
            s[j+1]='@';
            j+=2;
        }
        j++;
    }

    for(int j=0;j<i;j++){
        if(s[j]!='@')printf("%c",s[j]);
    }


    return 0;
}
