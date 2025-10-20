#include "stack.h"
#include <ctype.h>
#include <stdio.h>

int rpn(char *s);

int main() {
  printf("Final result: %d\n", rpn("6 5 2 3 + 8 * + 3 + *"));
  return 0;
}

int rpn(char *s) {
  Stack stack = createStack();
  int op1, op2, result;

  for (; *s != '\0'; ++s) {
    if (*s == ' ')
      continue;
    if (isdigit(*s)) {
      push(stack, *s - '0');
    } else {
      switch (*s) {
      case '+':
        op2 = top(stack);
        pop(stack);
        op1 = top(stack);
        pop(stack);
        push(stack, op1 + op2);
        break;
      case '-':
        op2 = top(stack);
        pop(stack);
        op1 = top(stack);
        pop(stack);
        push(stack, op1 - op2);
        break;
      case '*':
        op2 = top(stack);
        pop(stack);
        op1 = top(stack);
        pop(stack);
        push(stack, op1 * op2);
        break;
      case '/':
        op2 = top(stack);
        pop(stack);
        op1 = top(stack);
        pop(stack);
        if (op2 == 0) {
          printf("Cannot divide by 0\n");
          disposeStack(stack);
          return 1;
        }
        push(stack, op1 / op2);
        break;
      default:
        break;
      }
    }
    displayStack(stack);
  }

  result = top(stack);
  disposeStack(stack);
  return result;
}
