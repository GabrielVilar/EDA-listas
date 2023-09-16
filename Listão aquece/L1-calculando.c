#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERANDS 100
#define MAX_EXPRESSION_SIZE 1000

typedef struct {
    int operands[MAX_OPERANDS];
    char operators[MAX_OPERANDS-1];
    int num_operands;
} Expression;

void read_expression(Expression* expr) {
    scanf("%d", &(expr->num_operands));
    for(int i=0; i<expr->num_operands; i++) {
        scanf("%d", &(expr->operands[i]));
        if(i != expr->num_operands-1) {
            scanf(" %c", &(expr->operators[i]));
        }
    }
}

int evaluate_expression(Expression* expr) {
    int result = expr->operands[0];
    for(int i=1; i<expr->num_operands; i++) {
        if(expr->operators[i-1] == '+') {
            result += expr->operands[i];
        }
        else {
            result -= expr->operands[i];
        }
    }
    return result;
}

int main() {
    int test_num = 1;
    while(1) {
        Expression expr;
        read_expression(&expr);
        if(expr.num_operands == 0) {
            break;
        }
        int result = evaluate_expression(&expr);
        printf("Teste %d\n", test_num++);
        printf("%d\n\n", result);
    }
    return 0;
}

