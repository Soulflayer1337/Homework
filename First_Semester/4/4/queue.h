#pragma once

template <typename T>
struct QueueElement
{
    QueueElement<T> *next;
    T value;
};

template <typename T>
struct Queue
{
    QueueElement<T> *front;
    QueueElement<T> *back;
};

template <typename T>
bool isEmpty(Queue<T> *queue)
{
    return (queue->front == nullptr);
}

template <typename T>
void push_back(Queue<T> *queue, T value)
{
    QueueElement<T> *Node = new QueueElement<T>;
    Node->next = nullptr;
    Node->value = value;

    if (isEmpty(queue))
        queue->back = queue->front = Node;
    else
    {
        queue->back->next = Node;
        queue->back = queue->back->next;
    }
}

template <typename T>
T pop(Queue<T> *queue, T sample = T())
{
    QueueElement<T> *Node = queue->front;
    T value = sample;

    if (Node != nullptr)
    {
        queue->front = queue->front->next;
        value = Node->value;
        delete Node;

        if (queue->front == nullptr)
            queue->back = nullptr;
    }

    return value;
}

template <typename T>
T frontElement(Queue<T> *queue, T sample = T())
{
    return (isEmpty(queue) ? sample : queue->front->value);
}

template <typename T>
Queue<T> *createQueue()
{
    Queue<T> *queue = new Queue<T>;
    queue->front = queue->back = nullptr;
    return queue;
}

template <typename T>
void deleteQueue(Queue<T> *queue)
{
    while (!isEmpty(queue))
        pop(queue);

    delete queue;
}
