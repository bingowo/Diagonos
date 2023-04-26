#include <stdio.h>
#include <string.h>

int main() {
    char cmd[5];
    char s[20];
    int data;
    char reg1[5], reg2[5], reg3[5];
    int registers[26] = {0};
    while (~scanf("%s", cmd)) {
        scanf("%s", s);
        int m = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == ',') {
                s[i] = ' ';
                m++;
            }
        }//用空格替换逗号
        switch (cmd[0]) {
            case 'I':
                sscanf(s, "%s%d", reg1, &data);
                registers[reg1[0] - 'A'] = data;
                break;
            case 'O':
                if (!strcmp(cmd, "OUT")) {
                    sscanf(s, "%s", reg1);
                    printf("%d\n", registers[reg1[0] - 'A']);
                } else if (!strcmp(cmd, "OR")) {
                    if (m == 1) {
                        sscanf(s, "%s%s", reg1, reg2);
                        registers[reg1[0] - 'A'] = registers[reg1[0] - 'A'] | registers[reg2[0] - 'A'];
                    } else if (m == 2) {
                        sscanf(s, "%s%s%s", reg1, reg2, reg3);
                        registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'] | registers[reg3[0] - 'A'];
                    }
                }
                break;
            case 'A':
                if (m == 1) {
                    sscanf(s, "%s%s", reg1, reg2);
                    if (!strcmp(cmd, "ADD"))
                        registers[reg1[0] - 'A'] = registers[reg1[0] - 'A'] + registers[reg2[0] - 'A'];
                    else
                        registers[reg1[0] - 'A'] = registers[reg1[0] - 'A'] & registers[reg2[0] - 'A'];
                } else if (m == 2) {
                    sscanf(s, "%s%s%s", reg1, reg2, reg3);
                    if (!strcmp(cmd, "ADD"))
                        registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'] + registers[reg3[0] - 'A'];
                    else
                        registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'] & registers[reg3[0] - 'A'];
                }
                break;
            case 'S':
                if (m == 1) {
                    sscanf(s, "%s%s", reg1, reg2);
                    registers[reg1[0] - 'A'] = registers[reg1[0] - 'A'] - registers[reg2[0] - 'A'];
                } else if (m == 2) {
                    sscanf(s, "%s%s%s", reg1, reg2, reg3);
                    registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'] - registers[reg3[0] - 'A'];
                }
                break;
            case 'D':
                if (m == 1) {
                    sscanf(s, "%s%s", reg1, reg2);
                    registers[reg1[0] - 'A'] = registers[reg1[0] - 'A'] / registers[reg2[0] - 'A'];
                } else if (m == 2) {
                    sscanf(s, "%s%s%s", reg1, reg2, reg3);
                    registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'] / registers[reg3[0] - 'A'];
                }
                break;
            case 'M':
                if (!strcmp(cmd, "MOV")) {
                    sscanf(s, "%s%s", reg1, reg2);
                    registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'];
                } else if (!strcmp(cmd, "MUL")) {
                    if (m == 1) {
                        sscanf(s, "%s%s", reg1, reg2);
                        registers[reg1[0] - 'A'] = registers[reg1[0] - 'A'] * registers[reg2[0] - 'A'];
                    } else if (m == 2) {
                        sscanf(s, "%s%s%s", reg1, reg2, reg3);
                        registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'] * registers[reg3[0] - 'A'];
                    }
                } else if (!strcmp(cmd, "MOD")) {
                    if (m == 1) {
                        sscanf(s, "%s%s", reg1, reg2);
                        registers[reg1[0] - 'A'] = registers[reg1[0] - 'A'] % registers[reg2[0] - 'A'];
                    } else if (m == 2) {
                        sscanf(s, "%s%s%s", reg1, reg2, reg3);
                        registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'] % registers[reg3[0] - 'A'];
                    }
                }
                break;
            case 'X':
                if (!strcmp(cmd, "XCHG")) {
                    sscanf(s, "%s%s", reg1, reg2);
                    int temp = registers[reg1[0] - 'A'];
                    registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'];
                    registers[reg2[0] - 'A'] = temp;
                } else if (!strcmp(cmd, "XOR")) {
                    if (m == 1) {
                        sscanf(s, "%s%s", reg1, reg2);
                        registers[reg1[0] - 'A'] = registers[reg1[0] - 'A'] ^ registers[reg2[0] - 'A'];
                    } else if (m == 2) {
                        sscanf(s, "%s%s%s", reg1, reg2, reg3);
                        registers[reg1[0] - 'A'] = registers[reg2[0] - 'A'] ^ registers[reg3[0] - 'A'];
                    }
                }
                break;
        }
    }
    return 0;
}