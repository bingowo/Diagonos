#include<stdio.h>
int main(int argc,char *argv[]){
    int state=0;//初始状态；
    char pre,ch;
    while((ch=getchar())!=EOF){
        switch (state)
        {
        case 0://初始状态
            if(ch=='/')state=1;//单行或多行注释半状态
            else if(ch=='\''||ch=='"'){//字符串状态
                putchar(ch);
                pre=ch;
                state=6;
            }
            else putchar(ch);
            break;
        case 1:
            if(ch=='/')state=2;//确定单行注释状态；
            else if(ch=='*')state=4;//确定多行注释状态；
            else{//其他情况
                putchar('/');
                putchar(ch);
                state=0;
            }
            break;
        case 2:
            if(ch=='\\'){//若ch=='\\',为注释状态下的单行注释继续符
                state=3;
            }
            else if(ch=='\n'){//遇到换行符表示结束
                putchar('\n');
                state=0;//回到初始状态
            }
        case 3:
            if(ch!='\\'){//直到不为单行注释符才转状态2
                state=2;
            }
            break;
        case 4:
            if(ch=='*')state=5;
            break;
        case 5:
            if(ch=='/')state=0;
            else if(ch!='*')state=4;
            break;
        case 6:
            if(ch=='\\'){
                putchar(ch);
                state=7;
            }
            else if(ch==pre){
                putchar(ch);
                state=0;
            }
            else putchar(ch);
            break;
        case 7:
            putchar(ch);
            state=6;
            break;
        default:
            break;
        }
    }
    return 0;
}