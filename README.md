# DoublyLinkedList-Implementation
Implemented an ordered doubly linked list (with keys in increasing order). Code contains a templated Node class and a templated LinkedList class.
The list nodes contain a data field, which doubles as key, and pointers to next node and previous node.

Functions in LinkedList.h:
1) Constructor of a linked list containing two elements: a minimum value and a maximum value (corresponding to -∞ and +∞) of the given type.
2) Destructor of a linked list.
3) search – Accepts ‘location’, a pointer to a node in the linked list to start a forward
search from (such as the head of the linked list, if we are to search the entire list),
and ‘data’ to search for. Tests if ‘data’ is contained in the linked list, starting from
the provided location. If so, it returns a pointer to the node containing ‘data’,
otherwise, it returns a pointer to the node preceding the location where a new
node containing ‘data’ would be inserted.
3) insert – Accepts ‘location’, a pointer to a node in the linked list, and ‘data’ to be
inserted. Creates and inserts a node containing ‘data’ directly after the node in the
specified ‘location’, and returns pointer to the new node. Search will
generally be called first, return the specified location for inserting the new node,
and then insert will be called. We assume that the provided location is the correct position to
insert ‘data’, but if this is not the case (i.e. the resulting list is not sorted), then
the new node will not be inserted, and the function should return NULL.
4) printData – Prints the content of the linked list
5) print – Print the entire content of the linked list (including nodes’ addresses and
pointers), may be used for debugging purposes
