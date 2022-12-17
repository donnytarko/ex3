
#ifndef QUEUE
#define QUEUE

const int initialSize = 0;

template<class T>
class Queue {
    int dataSize;
    T* data;
    template<class Condition>
    friend Queue<T> filter(const Queue<T>& queue, Condition c);
    template<class Transformation>
    friend void transform(const Queue<T>& queue, Transformation f);

    public:
    Queue();
    Queue(const Queue& otherQueue);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& otherQueue);
    void pushBack(T element);
    T& front() const;
    void popFront();
    int size() const;
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
    delete[] data;
}


template<class T>
void Queue<T>::pushBack(T element) {
    T* newData = new T[dataSize + 1];
    newData[0] = element;
    for (int i = 1; i < dataSize + 1; i++) {
        newData[i] = data[i - 1];
    }
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

template<class T, class Condition>
Queue<T> filter(const Queue<T>& queue, Condition c) {
    Queue<T> filteredQueue;
    for (int i = 0; i < queue.dataSize; i++) {
        if (c(queue.data[i])) {
            filteredQueue.pushBack(queue.data[i]);
        }
    }
    return filteredQueue;
}

template<class T, class Transformation>
void transform(const Queue<T>& queue, Transformation f) {
    Queue<T> transformedQueue;
    for (int i = 0; i < queue.dataSize; i++) {
        transformedQueue.pushBack(f(queue.data[i]));
    }
    delete[] queue.data;
    queue.data = transformedQueue.data;
}

#endif //QUEUE