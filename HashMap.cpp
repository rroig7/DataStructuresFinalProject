//
// Created by rroig on 4/18/2024.
//

#include "HashMap.h"
#include <iostream>

// TODO: CHANGE THIS CLASS AROUND


template<typename K, typename V>
HashMap<K, V>::HashMap() {
    // Initial capacity of hash array
    capacity = 7;
    size = 0;
    arr = new HashNode<K, V>*[capacity];

    // Initialise all elements of array as NULL
    for (int i = 0; i < capacity; i++)
        arr[i] = nullptr;

    // dummy node with value and key -1
    dummy = new HashNode<K, V>(-1, -1);
}

template<typename K, typename V>
int HashMap<K, V>::hashCode(K key) {
    return key % capacity;
}

template<typename K, typename V>
void HashMap<K, V>::insertNode(K key, V value) {
    HashNode<K, V>* temp = new HashNode<K, V>(key, value);

    // Apply hash function to find index for given key
    int hashIndex = hashCode(key);

    // find next free space
    while (arr[hashIndex] != nullptr
           && arr[hashIndex]->key != key
           && arr[hashIndex]->key != -1) {
        hashIndex++;
        hashIndex %= capacity;
    }

    // if new node to be inserted
    // increase the current size
    if (arr[hashIndex] == nullptr
        || arr[hashIndex]->key == -1)
        size++;
    arr[hashIndex] = temp;
}

template<typename K, typename V>
V HashMap<K, V>::deleteNode(int key) {
    // Apply hash function
    // to find index for given key
    int hashIndex = hashCode(key);

    // finding the node with given key
    while (arr[hashIndex] != nullptr) {
        // if node found
        if (arr[hashIndex]->key == key) {
            HashNode<K, V>* temp = arr[hashIndex];

            // Insert dummy node here for further use
            arr[hashIndex] = dummy;

            // Reduce size
            size--;
            return temp->value;
        }
        hashIndex++;
        hashIndex %= capacity;
    }

    // If not found return -1
    return -1;
}

template<typename K, typename V>
V HashMap<K, V>::search(int key) {
    // Apply hash function to find index for given key
    int hashIndex = hashCode(key);
    int counter = 0;

    // finding the node with given key
    while (arr[hashIndex] != nullptr) { // int counter =0; // BUG!

        if (counter++ > capacity) // to avoid infinite loop
            return -1;

        // if node found return its value
        if (arr[hashIndex]->key == key)
            return arr[hashIndex]->value;
        hashIndex++;
        hashIndex %= capacity;
    }

    // If not found return -1
    return -1;
}

template<typename K, typename V>
int HashMap<K, V>::sizeofMap() {
    return size;
}

template<typename K, typename V>
bool HashMap<K, V>::isEmpty() {
    return size == 0;
}

template<typename K, typename V>
void HashMap<K, V>::display() {
    for (int i = 0; i < capacity; i++) {
        if (arr[i] != nullptr && arr[i]->key != -1)
            std::cout << "index "<<i<<" key = " << arr[i]->key
                 << " value = "
                 << arr[i]->value << std::endl;
    }
}