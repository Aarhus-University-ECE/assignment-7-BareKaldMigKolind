#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "stack.c"
#include "taylor_sine.c"

void testStack(void) {
    printf("STACK TESTCASES: \n");
    stack s;

    printf("Testcase (A):\n");
    initialize(&s);
    assert(empty(&s));
    printf("Testcase == \033[1;32mTrue\033[0m\n\n");

    printf("Testing testcase (B):\n");
    int x = 5;

    push(x, &s);

    int y = pop(&s);

    assert(x == y && empty(&s));
    printf("Testcase B == \033[1;32mTrue\033[0m\n\n");

    printf("Testing testcase (C):\n");

    int x0 = 5;
    int x1 = 10;

    push(x0, &s);
    push(x1, &s);

    int y0 = pop(&s);
    int y1 = pop(&s);

    assert(y0 == x1 && y1 == x0 && empty(&s));
    printf("Testcase C == \033[1;32mTrue\033[0m\n\n");
}

void testTaylorSine(void) {
    printf("\n\nTAYLOR_SINE TEST:\n");
    printf("Testcase: \nx = 3, n = 6\n");
    printf("Taylor_sine.c: %f\n", taylor_sine(3, 6));
    printf("ANSI sin: %f\n\n", sin(3));

    printf("Testcase: \nx = -3, n = 6\n");
    printf("Taylor_sine.c: %f\n", taylor_sine(-3, 6));
    printf("ANSI sin: %f\n\n", sin(-3));

    printf("Testcase: \nx = 30, n = 60\n");
    printf("Taylor_sine.c: %f\n", taylor_sine(30, 60));
    printf("ANSI sin: %f\n\n", sin(30));

    printf("Testcase: \n-x = -30, n = 60\n");
    printf("Taylor_sine.c: %f\n", taylor_sine(-30, 60));
    printf("ANSI sin: %f\n\n\n", sin(-30));
}
// Add your test cases for Exercise 1b,c) here
int main(int argc, char **argv) {
    testTaylorSine();

    testStack();

    return 0;
}