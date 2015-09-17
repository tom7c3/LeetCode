#pragma once

#include <map>

using std::map;

class LRUCache
{
  public:

    LRUCache( int capacity ) : capacity(capacity) {}

    void set( int key, int value )
    {
        auto it = cache.find(key);
        if ( it == cache.end() )
        {
            if ( cache.size() == capacity )
            {
                removeTail();
            }

            addNode( key, value );
        }
        else
        {
            moveNodeToHead( it->second );
            it->second->value = value;
        }
    }

    int get( int key )
    {
        auto it = cache.find(key);
        if ( it != cache.end() )
        {
            moveNodeToHead( it->second );
            return it->second->value;
        }

        return -1;
    }

  private:

    struct Node
    {
        Node( int key, int value ) : key(key), value(value) {}
        int key;
        int value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    void moveNodeToHead( Node* node )
    {
        if ( isHead( node ) )
        {
            return;
        }
        else if ( isTail( node ) )
        {
            node->next->prev = nullptr;
            tail = node->next;
            head->next = node;
            node->prev = head;
            head = node;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            head->next = node;
            node->prev = head;
            head = node;
        }
    }

    void removeTail()
    {
        Node* node = tail;
        cache.erase( node->key );
        if ( node->next )
            tail = node->next;
        tail->prev = nullptr;
        delete node;
    }

    void addNode( int key, int value )
    {
        Node* node = new Node( key, value );
        if ( head )
        {
            head->next = node;
            node->prev = head;
            head = node;
        }
        else
        {
            head = tail = node;
        }

        cache[key] = node;
    }

    bool isHead( Node* node ) { return head == node; }
    bool isTail( Node* node ) { return tail == node; }

    int capacity;
    map<int, Node*> cache;
    Node* tail = nullptr;
    Node* head = nullptr;
};
