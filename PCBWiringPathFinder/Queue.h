#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
#include <stdexcept> // For exception handling

template <typename T>
class Queue {
private:
    std::vector<T> elements; // Vector to hold the queue elements

public:
    // Adds an element to the queue
    void enqueue(T element);

    // Removes the front element from the queue
    void dequeue();

    // Returns the front element of the queue
    T front();

    // Checks if the queue is empty
    bool isEmpty();
};

template<typename T>
void Queue<T>::enqueue(T element)
{
    elements.push_back(element);
}

template<typename T>
void Queue<T>::dequeue()
{
    if (!isEmpty()) {
        elements.erase(elements.begin());
    } else {
        std::cerr << "Error: Queue is empty. Cannot dequeue." << std::endl;
    }
}

template<typename T>
T Queue<T>::front()
{
    if (!isEmpty()) {
        return elements[0];
    } else {
        std::cerr << "Error: Queue is empty. Cannot access front element." << std::endl;
        return T(); // Return default constructed object of type T
    }
}

template<typename T>
bool Queue<T>::isEmpty()
{
    return elements.empty();
}

#endif // QUEUE_H