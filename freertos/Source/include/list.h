#pragma once

#include "portmacro.h"

// 链表节点
typedef struct xLIST_ITEM {
    TickType_t xItemValue;
    struct xLIST_ITEM *next;
    struct xLIST_ITEM *prev;
    void *pvOwner;
    void *pvContainer;
} ListItem_t, *pListItem_t;

// 精简节点
typedef struct xMINI_LIST_ITEM {
    UBaseType_t xItemValue;
    struct xLIST_ITEM *next;
    struct xLIST_ITEM *prev;
} MiniListItem_t, *pMiniListItem_t;

// 链表根节点
typedef struct xLIST {
    UBaseType_t uxNumsOfItems;  // 链表节点数目
    ListItem_t *pxIndex;        // 链表节点索引指针
    MiniListItem_t xListEnd;    // 链表最后一个节点
} List_t, *pList_t;


/**
 * @brief 链表节点初始化
 * 
 * @param pxListItem 节点
 */
void vListInitialiseItem(ListItem_t * const pxListItem);

/**
 * @brief 链表根节点初始化
 * 
 * @param pxList 根节点
 */
void vListInitialise(List_t * const pxList);

/**
 * @brief 将链表节点插入到链表尾部
 * 
 * @param pxList 链表根节点
 * @param pxListItem 要插入的链表节点
 */
void vListInsertEnd(List_t * const pxList, ListItem_t * pxListItem);