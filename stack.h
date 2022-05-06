typedef struct _stack stack;

struct _stack* initStack();
void push(struct _stack* st, int val);
void pop(struct _stack* st);
int _top(struct _stack* st);
int isEmpty(struct _stack* st);
void destroy(struct _stack*& st);
void clear(struct _stack* st);
unsigned long size(struct _stack* st);

