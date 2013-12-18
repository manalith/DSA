#include "priority_queue.h"
#include <stdlib.h>
#include "SLList.h"
#include "customType.h"

void* createQueue(){
    List* queue = calloc(1,sizeof(List));
    queue->head = NULL;
    return queue;
};
element* createNode(void* data, size_t priority ){
    element* node = calloc(1, sizeof(element));
    node->data = data;
    node->priority = priority;
    return node;
};

int enqueue(void* queueAddress,void* data, size_t priority,compare* compare){
     List* queue = queueAddress;
    element* node = createNode(data,priority);
    element *previous,*next,*temp;
    int result;
    temp = node->data;
    if(queue->length == 0)
        return insertNode(queue, queue->length, node);
    if(compare(&node->priority,&temp->priority) < 0)
        return insertNode(queue,0, node);
    while(temp != NULL){
        previous = temp->data;
        temp->data = queue->head->next;
        if(node->priority < next->priority){
                previous->data = node;
                    return ++queue->length;
        }
    };
    return 0;
};
void* dequeue(void* queueAddress){
    List* queue = queueAddress;
    element* head = queue->head->data;

    if(queue->length == 0) return NULL;
    queue->head = queue->head->next;
    queue->length--;
    return head->data;
};