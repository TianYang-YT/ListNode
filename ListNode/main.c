//
//  main.c
//  数据结构
//
//  Created by T_Yang on 2020/3/11.
//  Copyright © 2020 T_Yang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

static int size = 0;
//得有一个头节点 不然添加不进去第0个

//链表
typedef struct node_s {
    int age;
    struct node_s *next;
} LinkNode;

/// 创建链表
/// @param n 节点个数
LinkNode *start(int n) {
    if (n <= 0) return NULL;
    
    LinkNode *head, *node, *end;
    head = (LinkNode *)malloc(sizeof(LinkNode));
    end = head;
    for (int i = 1; i < n; i++) {
        node = (LinkNode *)malloc(sizeof(LinkNode));
        node->age = i;
        //刚开始尾结点就是头结点 创建一个node后 头结点(尾结点)的next就是创建的这个
        end->next = node;
        //然后把尾结点后置一个 相当于记录了lastNode
        end = node;
    }
    end->next = NULL;
    size = n;
    return head;
}

/// 获取第index个节点
/// @param head 头结点
/// @param index 位置索引
LinkNode *getNode(LinkNode *head, int index) {
    if (index >= size) return NULL;
    
    LinkNode *node = head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node;
}

/// 增加节点
/// @param head 头结点
/// @param index 位置索引
/// @param age 内容
void addNode(LinkNode *head, int index, int age) {
    if (index > size) return;
    
    if (index == 0) {
        LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
        newNode->age = head->age;
        head->age = age;
        
        newNode->next = head->next;
        head->next = newNode;
    }else {
        LinkNode *node = getNode(head, index - 1);
        LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
        newNode->age = age;
        newNode->next = node->next;
        node->next = newNode;
    }
    size++;
}

/// 删除节点
/// @param head 头结点
/// @param index 位置索引
void deleteNode(LinkNode *head, int index) {
    if (index > size) return;
    //warning 如果删除第0个节点 也需要将第1个节点的复制到0节点 然后删除第1个节点
    if (index == 0) {
        struct node_s *next = head->next;
        if (next) {
            head->age = next->age;
            head->next = next->next;
        }else {
            //只有头结点无法删除
        }
    }else {
        LinkNode *node = getNode(head, index);
        node->next = node->next->next;
    }
    size--;
}

/// 打印链表
/// @param head 头结点
void printList(LinkNode *head) {
    if (head == NULL) return;
    
    LinkNode *node = head;
    int i = 0;
    while (node) {
        printf("第%d个age=%d\n", i, node->age);
        node = node->next;
        i++;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    //创建
    LinkNode *head = start(2);
    printList(head);
    
    //增加节点
//    addNode(head, 0, 77);
    
    //打印节点
//    printList(head);
    deleteNode(head, 0);
    printList(head);
    
    
    
//    printf("链表长度:%d\n", size);
    
    int s = 11;
    
    return 0;
}
