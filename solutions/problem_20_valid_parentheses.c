
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_SIZE 100


typedef struct {
    int index;
    char brackets[MAX_SIZE];
} Stack;


Stack *create_stack() {
    
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->index = -1;

    return stack;
}


void free_stack(Stack *stack) {

    if (stack == NULL) {
        return;
    }

    free(stack);
}


bool isEmpty(Stack *stack) {

    return stack->index < 0;
}


void push(Stack *stack, char value) {
    
    if (stack->index >= MAX_SIZE - 1) {
        return;
    }

    stack->index++;
    stack->brackets[stack->index] = value;
}


char pop(Stack *stack) {
    
    if (isEmpty(stack)) {
        return '\0';
    }

    return stack->brackets[stack->index--];
}


bool isBracket(char open, char close) {

    switch (open) {
        case '(':
            return close == ')';
        case '[':
            return close == ']';
        case '{':
            return close == '}';
    }

    return false;
}


bool solve(char *s) {
    
    Stack *stack = create_stack();

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || 
            s[i] == '[' || 
            s[i] == '{') {
            push(stack, s[i]);
        } else {
            if (!isBracket(pop(stack), s[i])) {
                free_stack(stack);
                return false;
            }
        }
    }

    free_stack(stack);

    return true;
}


int main() {
    // Test cases.
    char *brackets[] = {
        "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]",
        "[][][][][[][][]]",
        "[}{}{}{}}{{}{()([][][])}]",
        "([{}])",
        "{[()()]({})}",
        "{{[(())]}}",
        "[{]",
        "[[[[[]]]]]",
        "(()[{}])",
        "((((((((((((((((((())))))))))))))))))",
        "[{(})]",
        "[{[({})]}]",
        "(){}[]",
        "((()))",
        "[[]]]",
        "{[[(())]]}",
        "(((((((())",
        "[{{[(())]}}]",
        "][[{{}}]]",
        "[{[{[{[{[{({})}]}]}]}]]",
        "[[{[({[({[]})}]})]]]",
        "()",
        "{}",
        "[]",
        "[[{[{[{[({[]}[])}]]]]]]",
        "((((((((((((((((()))))))))))))))))",
        "[[{}[]]",
        "[({[({[}]]}}",
        "([)]",
        "[[{}]{}]",
        "[[{[{[{[{[({[]})]}]]]]]]",
        "([({[{}{}()]})])",
        "{[]()}",
        "{[()()]}",
        "[]{{}}",
        "[[({{{}}})]]",
        "([{{[]}}])",
        "[]{}{}",
        "{[(())]}",
        "[[{[(())]]}]",
        "[{{[{()}]]}}",
        "[[[{{}}]]]",
        "{[}]",
        "[[]",
        "[[{}}]]",
        "{([{}])}",
        "({[({[({[()]})}]})})",
        "{[({[]})]}",
        "{[](){}",
        "([])",
        "({[()]})",
        "([()]])",
        "{[((){})]}",
        "(((())()))",
        "[{[{}()[]]}]",
        "({})",
        "({[]})",
        "[({[]})]",
        "[{{[(())]}}]",
        "({[()()]})",
        "[(])",
        "[[{(([[[]]]))}]]",
        "{[]({})}",
        "[[[]]]",
        "{[{[]}]}",
        "{[(())]}{[()]}",
        "(((((((())))))))",
        "[[[]]]",
        "{[{[{[({[]})]}]]]]",
        "[[[[]]]]{}",
        "[{{{[{}]}}}]",
        "[{{{[{[(())]]}}}]",
        "(((())))",
        "({[()()]})",
        "[({})]",
        "[[{(())}]]",
        "[[{{}}]]",
        "[[[[({})]]]{}",
        "[[{[({[({[]})}]}}]]",
        "{[({[()()]})]}",
        "[[{[{[({[]})}]]]]]",
        "[[{{{{{{}}}}}}]]",
        "[[[[[{{}}]]]]]",
        "[[({[]})]]",
        "{[}{}",
        "{[(])}",
        "[]{}",
        "[({})({})]",
        "[((()()))]",
        "{[(][)]}",
        "[[[({})]]]}",
        "[[({}(()))]]",
        "({[(())]})",
        "[[([{}]])]]",
        "[{([()()])}]",
        "({[({[]})]}))",
        "({[]{{}}})",
        "[({[({[]}())]})]",
        "{[({[()]})()]}",
        "[{{[[(())]]}}]",
    };

    int size = sizeof(brackets) / sizeof(brackets[0]);

    for (int i = 0; i < size; i++) {
        char *s = brackets[i];
        printf("Case #%d: %s\n", i, solve(s) ? "Valid" : "Invalid");
    }

    return EXIT_SUCCESS;
}
