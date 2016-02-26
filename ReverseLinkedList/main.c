//
//  main.c
//  ReverseLinkedList
//
//  Created by chenyufeng on 16/2/26.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  实现链表的逆序输出
 实现算法如下：
 （1）依次遍历原链表（当然首先应该构建原链表，我这里使用尾插法来构建）
 （2）取出节点使用头插法建立一个新链表；
 （3）打印新链表；
 
 核心也就是：遍历+头插法构建链表
 */
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

typedef int elemType;
//构造节点
typedef struct ListNode{
    int element;
    struct ListNode *next;
}Node;

//初始化链表
void initList(Node *pNode){

    pNode = NULL;
    printf("%s函数执行，头结点初始化完成\n",__FUNCTION__);
}

//打印链表
void printList(Node *pNode){
    if (pNode == NULL) {
        printf("%s函数执行，链表为空，打印失败\n",__FUNCTION__);
    }else{
        while (pNode != NULL) {
            printf("%d ",pNode->element);
            pNode = pNode->next;
        }
        printf("\n");
    }
}


//尾插法
Node *TailInsert(Node *pNode){

    Node *pInsert; //要插入的节点
    Node *pMove; //遍历链表的节点
    pInsert = (Node*)malloc(sizeof(Node));
    if (pInsert == NULL) {
        printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);
        return NULL;
    }

    memset(pInsert, 0, sizeof(Node));
    scanf("%d",&(pInsert->element));
    pInsert->next = NULL;

    if (pInsert->element <= 0) {
        printf("%s函数执行，输入数据有误，建立链表失败\n",__FUNCTION__);
        return NULL;
    }

    pMove = pNode;
    while (pInsert->element > 0) {
        if (pNode == NULL) {
            //注意不要忘了修改pMove指针的指向，初始pMove一定要指向头节点
            pNode = pInsert;
            pMove = pNode;
        }else{
            //遍历找到最后一个节点
            while (pMove->next != NULL) {
                pMove = pMove->next;
            }
            pMove->next = pInsert;
        }

        pInsert = (Node*)malloc(sizeof(Node));
        if (pInsert == NULL) {
            printf("%s函数执行，内存分配失败，建立链表失败\n",__FUNCTION__);
            return NULL;
        }

        memset(pInsert, 0, sizeof(Node));
        scanf("%d",&(pInsert->element));
        pInsert->next = NULL;
    }

    printf("%s函数执行，尾插法建立链表成功\n",__FUNCTION__);

    return pNode;
}


Node *pReverseList;

//头插法
void HeadInsert(Node *pInsert){
    if (pReverseList == NULL) {
        pReverseList = pInsert;
    }else{

        pInsert->next = pReverseList;
        pReverseList = pInsert;
    }
}

//遍历链表并使用头插法构建新链表
void scanList(Node *pNode){

    //首先判断原链表是否为空；

    Node *pMove;
    Node *pInsert;  //该节点为新建的插入节点
    pInsert = (Node *)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->next = NULL;

    pMove = pNode;
    while (pMove != NULL) {

        pInsert->element = pMove->element;
        HeadInsert(pInsert);

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->next = NULL;
        pMove = pMove->next;
    }

    printf("%s函数执行，逆序链表完成\n",__FUNCTION__);
}

int main(int argc, const char * argv[]) {

    Node *pList;

    initList(pList);
    printList(pList);

    //尾插法建立链表
    pList = TailInsert(pList);
    printList(pList);

    //开始遍历链表，遍历的过程中构建新链表
    scanList(pList);
    printf("逆序后的链表为：");
    printList(pReverseList);

    return 0;
}













