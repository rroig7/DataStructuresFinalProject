//
// Created by rroig on 4/18/2024.
//

#include "HashNode.h"

// TODO: CHANGE THIS CLASS AROUND


template<typename K, typename V>
HashNode<K, V>::HashNode(K key, V value) {
    this->key = key;
    this->value = value;
}