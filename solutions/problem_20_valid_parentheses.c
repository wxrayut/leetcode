
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool isBracket(char opening, char closing) {

    switch (opening) {
        case '(':
            return closing == ')';
        case '[':
            return closing == ']';
        case '{':
            return closing == '}';
    }

    return false;
}


bool isValid(char *string) {

    int i = -1;
    char brackets[128];

    for (int j = 0; j < strlen(string); j++) {
        char bracket = string[j];
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            brackets[++i] = bracket;
        } else {
            if (!isBracket(brackets[i--], bracket)) {
                return false;
            }
        }
    }

    return i == -1;
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
        printf("Case #%d: %s\n", i, isValid(s) ? "Valid" : "Invalid");
    }

    return EXIT_SUCCESS;
}
