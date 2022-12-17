
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

    private:
    Queue();
    Queue(const Queue& otherQueue);
    ~Queue();
    void pushback(T element);
    T front() const;
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
void Queue<T>::pushback(T element) {
    newData = new T[dataSize + 1];
    for (int i = 0; i < dataSize; i++) {
        newData[i] = data[i];
    }
    newData[dataSize] = element;
    delete[] data;
    data = newData;
    dataSize += 1;
}


template<class T>
T Queue<T>::front() const {
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
            filteredQueue.pushback(queue.data[i]);
        }
    }
    return filteredQueue;
}

template<class T, class Transformation>
void transform(const Queue<T>& queue, Transformation f) {
    Queue<T> transformedQueue;
    for (int i = 0; i < queue.dataSize; i++) {
        transformedQueue.pushback(f(queue.data[i]));
    }
    delete data[];
    data = transformedQueue.data;
}

#endif //QUEUE