
#ifndef QUEUE
#define QUEUE
#include <iostream>

const int initialSize = 0;

template<class T>
class Queue {
    int dataSize;
    T* data;
    template<class T2, class Condition>
    friend Queue<T2> filter(const Queue<T2>& queue, Condition c);
    template<class T2, class Transformation>
    friend void transform(const Queue<T2>& queue, Transformation f);

    public:
    Queue();
    Queue(const Queue& otherQueue);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& otherQueue);
    void pushBack(T element);
    T& front() const;
    void popFront();
    int size() const;
    class Iterator;
    Iterator begin() const;
    Iterator end() const; 

    enum EmptyQueue { Bad };
};

template<class T>
Queue<T>::Queue() {
    dataSize = initialSize;
    data = new T[initialSize];
}

template<class T>
Queue<T>::Queue(const Queue& otherQueue) {
    data = new T[otherQueue.dataSize];
    dataSize = otherQueue.dataSize;
    for (int i = 0; i < dataSize; ++i) {
        data[i] = otherQueue.data[i];
    }
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& otherQueue) {
    if (this == &otherQueue) {
        return *this;
    }
    std::cout << "deleting stuff now = operator" << std::endl;

    delete[] data;
    data = new T[otherQueue.dataSize];
    dataSize = otherQueue.dataSize;
    for (int i = 0; i < dataSize; ++i) {
        data[i] = otherQueue.data[i];
    }
    return *this;
}

template<class T>
Queue<T>::~Queue() {
    std::cout << "deleting stuff now in deleting thingy" << std::endl;
    delete[] data;
}


template<class T>
void Queue<T>::pushBack(T element) {
    T* newData = new T[dataSize + 1];
    newData[0] = element;
    for (int i = 1; i < dataSize + 1; i++) {
        newData[i] = data[i - 1];
    }
    std::cout << "deleting stuff now in pushback" << std::endl;
    delete[] data;
    data = newData;
    dataSize += 1;
}


template<class T>
T& Queue<T>::front() const {
    return data[dataSize - 1];
}


template<class T>
void Queue<T>::popFront() {
    dataSize --;
}

template<class T>
int Queue<T>::size() const {
    return dataSize;
}

template<class T2, class Condition>
Queue<T2> filter(const Queue<T2>& queue, Condition c) {
    Queue<T2> *filteredQueue = new Queue<T2>();
    for ( T2 iteration : queue) {
        if (c(iteration)) {
            filteredQueue->pushBack(iteration);
        }
    }
    return *filteredQueue;
}

template<class T2, class Transformation>
void transform(const Queue<T2>& queue, Transformation f) {
    const Queue<T2> transformedQueue;
    for (typename Queue<T2>::Iterator it = queue.begin(); it != queue.end(); it++) {
        transformedQueue.pushBack(f(it));
    }
    queue = transformedQueue;
}


template<class T>
class Queue<T>::Iterator {
    const Queue<T>* queue;
    int index;
    Iterator(const Queue<T>* queue, int index);
    friend class Queue<T>;

    public:
    const T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& iterator) const;
    bool operator!=(const Iterator& iterator) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    enum InvalidOperation { Bad };
};

template<class T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(this, 0);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(this, dataSize);
}

template<class T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue, int index) :
    queue(queue), index(index)
{}

template<class T>
const T& Queue<T>::Iterator::operator*() const {
    return queue->data[index];
} 

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    ++index;
    return *this;
}

template<class T>
bool Queue<T>::Iterator::operator==(const Iterator& i) const {
    return index == i.index;
} 

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const {
    return !(*this == i);
}

#endif //QUEUE