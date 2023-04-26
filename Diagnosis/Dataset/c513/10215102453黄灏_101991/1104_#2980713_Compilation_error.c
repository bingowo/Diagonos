#include <stdio.h>

char opera[] = {"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};

int main() {
    long long ABCD[30]={0};  //寄存器
    string s;
    while (getline(cin,s)){
        int len=s.length();
        int space = s.find(' ');
        string name = s.substr(0,space);
        int o;
        for(int i=0;i<12;i++){
            if(name == opera[i]) o=i;
        }
        // ep: IN AX,number  获取IN

        int reg1;// register 寄存器A
        int reg2;//寄存器B
        int reg3;//寄存器C
        int flag=0;  long long temp=0;
        switch (o) {
            case 0:
                reg1 = s[space+1]-'A';  //第reg1 个寄存器
                space = s.find(',');
                ABCD[reg1]=0;//初始化寄存器

                while (space<len-1){
                    if(s[space+1]=='-'){
                        flag = 1;
                        space++; continue;
                    }
                    ABCD[reg1] *=10;
                    ABCD[reg1] += s[++space] -'0';
                }
                if(flag) ABCD[reg1] *= -1;
                break;

            case 1:
                reg1 = s[space +1]-'A';
                cout<<ABCD[reg1]<<endl;
                break;

            case 2://MOV AX,BX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                ABCD[reg1]=ABCD[reg2];
                break;

            case 3:  //XCHG AX,BX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                temp = ABCD[reg1];
                ABCD[reg1]=ABCD[reg2];
                ABCD[reg2]=temp;
                break;

            case 4: //ADD AX,BX  或  ADD AX,BX,CX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                space = s.find(',',space+1);//从第space+1的位置开始找
                if(space == s.npos){//ADD AX,BX
                    ABCD[reg1] += ABCD[reg2];
                } else{//ADD AX,BX,CX
                    reg3 = s[space+1]-'A';
                    ABCD[reg1]=ABCD[reg2]+ABCD[reg3];
                }
                break;

            case 5:  //SUB AX,BX 或 SUB AX,BX,CX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                space = s.find(',',space + 1);
                if(space == s.npos){//SUB AX,BX
                    ABCD[reg1] -= ABCD[reg2];
                } else{//SUB AX,BX,CX
                    reg3 = s[space+1]-'A';
                    ABCD[reg1]=ABCD[reg2]-ABCD[reg3];
                }
                break;

            case 6: // MUL AX,BX 或 MUL AX,BX,CX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                space = s.find(',',space + 1);
                if(space == s.npos){//MUL AX,BX
                    ABCD[reg1] *= ABCD[reg2];
                } else{//MUL AX,BX,CX
                    reg3 = s[space+1]-'A';
                    ABCD[reg1]=ABCD[reg2]*ABCD[reg3];
                }
                break;

            case 7: // DIV AX,BX 或 DIV AX,BX,CX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                space = s.find(',',space + 1);
                if(space == s.npos){//MUL AX,BX
                    ABCD[reg1] /= ABCD[reg2];
                } else{//MUL AX,BX,CX
                    reg3 = s[space+1]-'A';
                    ABCD[reg1]=ABCD[reg2]/ABCD[reg3];
                }
                break;

            case 8: // MOD AX,BX 或 MOD AX,BX,CX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                space = s.find(',',space + 1);
                if(space == s.npos){//MOD AX,BX
                    ABCD[reg1] %= ABCD[reg2];
                } else{//MOD AX,BX,CX
                    reg3 = s[space+1]-'A';
                    ABCD[reg1]=ABCD[reg2]%ABCD[reg3];
                }
                break;

            case 9: // AND AX,BX 或 AND AX,BX,CX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                space = s.find(',',space + 1);
                if(space == s.npos){//AND AX,BX
                    ABCD[reg1] &= ABCD[reg2];
                } else{//AND AX,BX,CX
                    reg3 = s[space+1]-'A';
                    ABCD[reg1]=ABCD[reg2]&ABCD[reg3];
                }
                break;

            case 10: // OR AX,BX 或 OR AX,BX,CX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                space = s.find(',',space + 1);
                if(space == s.npos){//OR AX,BX
                    ABCD[reg1] |= ABCD[reg2];
                } else{//OR AX,BX,CX
                    reg3 = s[space+1]-'A';
                    ABCD[reg1]=ABCD[reg2]|ABCD[reg3];
                }
                break;

            case 11: // XOR AX,BX 或 XOR AX,BX,CX
                reg1 = s[space+1]-'A';
                space = s.find(',');
                reg2 = s[space+1]-'A';
                space = s.find(',',space + 1);
                if(space == s.npos){//XOR AX,BX
                    ABCD[reg1] ^= ABCD[reg2];
                } else{//XOR AX,BX,CX
                    reg3 = s[space+1]-'A';
                    ABCD[reg1]=ABCD[reg2]^ABCD[reg3];
                }
                break;



        }
    }
    return 0;
}
