    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <ctype.h>
    #include <assert.h>
    #include <stdlib.h>

    int expressionEval(char *string, int *length)
    {
        if (isdigit(string[0])){
            int value1 = string[0] - '0';
            return value1;
        }
        if (string[0] == '-'){
            int value,sublen;
            value =  -expressionEval(string + 1,&sublen);
            // *length = sublen + 1;
            return value;
        }
        if (string[0] == '('){
            int i = 1;
            while (string[i] != ')' && i < strlen(string)){
                i++;
            }
            if (i == strlen(string)){
                return -2147483648;
            }
            int value,sublen;
            value = expressionEval(string + 1,&sublen);
            *length = sublen + 2;
            assert(string[i] == ')');
            int sublen2;
            int value2 = expressionEval(string + i + 2,&sublen2);
            if (string[i + 1] == '+'){
                return value + value2;
            }
            else if (string[i + 1] == '-'){
                return value - value2;
            }
            else if (string[i + 1] == '*'){
                return value * value2;
            }
            else if (string[i + 1] == '/'){
                if (value2 == 0){
                    return -2147483648;
                }
                return value / value2;
            }
        }
        return -2147483648;
    }

    int expression(char *string){
        if (strlen(string) == 1 && isdigit(string[0])){
            return string[0] - '0';
        }
        if (string[0] == '-'){
            return (expression(string + 1) != -2147483648)? -expression(string + 1): -2147483648;
        }
        /* 檢查加減乘除 */
        if (string[0] == '(' && string[strlen(string) - 1] == ')'){
            char *s = strtok(string + 1,"+-*/");
            char *t = strtok(NULL,"+-*/");
        }
    
    }

    char buf[1<<20];
    int main() {
        int *len;
        while (scanf("%s", buf) == 1) {
            int ret = expressionEval(buf,len);
            printf("%d\n", ret);
        }
        return 0;
    }
