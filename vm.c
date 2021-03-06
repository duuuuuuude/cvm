#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct OBJECT_t {
   luint8_t type;
    union {
        uint8_t u8;
        int8_t i8;
        uint32_t u32;
        int32_t i32;
        void *ptr;
    };
} OBJECT;

// all of the basic instructions that's executed within a VM, operate on a stack
typedef struct STACK_t {
    int top;
    int size;
    OBJECT *stack;
} STACK;

STACK stack_new(int size) {
    STACK s;
    s.top = 0;
    s.size = size;
    s.stack = (OBJECT *)malloc(sizeof(OBJECT) * size);
    return s;
}

int stack_push(STACK *s, OBJECT o) {
    s->stack[s->top++] = o;
    return s->top;
}

OBJECT stack_pop(STACK *s) {
    return s->stack[--(s->top)];
}
OBJECT stack_peek(STACK *s) {
    return s->stack[--(s->top)];
}

OBJECT stack_pop(STACK *s) {
    return s->stack[s->top - 1];
}

int main(int argc, char *argv[]) {

    return 0;
}
