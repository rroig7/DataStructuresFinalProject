//
// Created by rroig on 4/18/2024.
//

#ifndef DATASTRUCTURESFINALPROJECT_HASHMAP_H
#define DATASTRUCTURESFINALPROJECT_HASHMAP_H
#include "HashNode.h"

// TODO: CHANGE THIS CLASS AROUND



template <typename K, typename V>
class HashMap {
    // hash element array
    HashNode<K, V>** arr;
    int capacity;
    // current size
    int size;
    // dummy node
    HashNode<K, V>* dummy;

public:
    HashMap();
    // This implements hash function to find index
    // for a key
    int hashCode(K key);

    
    // Function to add key value pair
    void insertNode(K key, V value);

    // Function to delete a key value pair an return the value
    V deleteNode(int key);

    // Function to search the value for a given key
    V search(int key);

    // Return current size
    int sizeofMap();

    // Return true if size is 0
    bool isEmpty();

    // Function to display the stored key value pairs
    void display();
};




#endif //DATASTRUCTURESFINALPROJECT_HASHMAP_H
