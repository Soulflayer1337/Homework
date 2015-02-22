#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <typename T>
struct StackElement
{
    StackElement<T> *next;
    T value;
};

template <typename T>
struct Stack
{
    StackElement<T> *top;
};

template <typename T>
bool isEmpty(Stack<T> *stack)
{
    return (stack->top == nullptr);
}

template <typename T>
T topElement(Stack<T> *stack)
{
    return (!isEmpty(stack) ? stack->top->value : T());
}

template <typename T>
Stack<T> *createStack()
{
    Stack<T> *stack = new Stack<T>;
    stack->top = nullptr;
    return stack;
}

template <typename T>
void deleteStack(Stack<T> *stack)
{
    while(!(isEmpty(stack)))
        pop(stack, T());
    delete stack;
}

template <typename T>
void push(Stack<T> *stack, T value)
{
    StackElement<T> *newElement = new StackElement<T>;
    newElement->next = stack->top;
    newElement->value = value;
    stack->top = newElement;
}

template <typename T>
T pop(Stack<T> *stack, T sample = T())
{
    T value = sample;

    if (!isEmpty(stack))
    {
        StackElement<T> *currentElement = stack->top;
        value = currentElement->value;
        stack->top = stack->top->next;
        delete currentElement;
    }

    return value;
}

#endif // STACK_H_INCLUDED
