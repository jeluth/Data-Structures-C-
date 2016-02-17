#include <iostream>
#include "node1.h"

using namespace std;
using namespace main_savitch_5;


void list_print(node * head_ptr);

int main()
{
    node *head;
    head = new node(23.5);

    list_insert(head, 45.6);
    node *point = list_locate(head, 2);

    list_insert(point, 67.7);
    point = list_locate(head, 3);

    list_insert(point, 89.8);
    point = list_locate(head, 4);

    list_insert(point, 12.9);

    list_print(head);

    node *head2 = new node(1);
    node *tail = head2;

    list_insert(head2, 2);
    tail = list_locate(head2, 2);

    list_insert(tail, 3);
    tail = list_locate(head2, 3);

    list_insert(tail, 4);
    tail = list_locate(head2, 4);

    list_insert(list_locate(head2, 2), 23.5);

    tail = list_locate(head2, 5);

    list_insert(tail, 45.6);
    tail = list_locate(head2, 6);

    list_insert(tail, 67.7);
    tail = list_locate(head2, 7);

    list_insert(tail, -123.5);
    tail = list_locate(head2, 8);

    list_insert(tail, 89.9);
    tail = list_locate(head2, 9);

    list_insert(tail, 12);
    tail = list_locate(head2, 10);

    list_print(head2);





    cout << "Hello world!" << endl;
    return 0;
}

void list_print(node * head_ptr)
{
    const node *cursor;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        cout << cursor->data() << " ";

    cout << " " << endl;
}
