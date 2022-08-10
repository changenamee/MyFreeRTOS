#pragma once

#include "portmacro.h"

/* 初始化链表节点拥有者 */
#define listSET_LIST_ITEM_OWNER(pxListItem, pxList) \
        ((pxListItem -> pxOwner) = (void*)(pxList))

/* 获取节点拥有者 */
#define listGET_LIST_ITEM_OWNER(pxListItem) \
        ((pxListItem) -> pxOwner)

/* 初始化节点排序辅助值 */
#define listSET_LIST_ITEM_VALUE(pxListItem, xValue) \
        ((pxListItem) -> xItemValue = (xValue))
        
/* 获取节点排序辅助值 */
#define listGET_LIST_ITEM_VALUE(pxListItem) \
        ((pxListItem) -> xItemValue)

/* 获取链表根节点排序辅助值 */
#define listGET_ITEM_VALUE_OF_HEAD_ENTRY(pxList) \
        (((pxList) -> xListEnd).pxNext -> xItemValue)

/* 获取链表入口节点 */
#define listGET_HEAD_ENTRY(pxList) \
        (((pxList) -> xListEnd).pxNext)

/* 获取下一个节点 */
#define listGET_NEXT(pxListItem) \
        ((pxListItem) -> pxNext)

/* 获取链表最后一个节点 */
#define listGET_END_MARKER(pxList) \
        ((const * pxListItem) (& ((pxList) -> xListEnd)))

/* 判断链表是否为空 */
#define listLIST_IS_EMPTY(pxList) \
        ((BaseType_t)(pxList) -> uxNumsOfItems == (UBaseType_t)0)

/* 获取链表节点数 */
#define listCURRENT_LIST_LENGTH(pxList) \
        ((UBaseType_t) ((pxList) -> uxNumsOfItems))

/* 获取链表第一个节点的owner */
#define listGET_OWNER_OF_NEXT_ENTRY(pxTCB, pxList) \
        pList_t const pxConstList = pxList; \
        (pxConstList) -> pxIndex = (pxConstList) -> pxIndex -> pxNext; \
        if ((void*) (pxConstList) -> pxIndex == (void *) &((pxConstList) -> xListEnd)) { \
            (pxConstList) -> pxIndex = (pxConstList) -> pxIndex -> pxNext; \
        } \
        pxTCB = (pxConstList) -> pxIndex -> pvOwner;

// 链表节点
typedef struct xLIST_ITEM {
    TickType_t xItemValue;
    struct xLIST_ITEM *pxNext;
    struct xLIST_ITEM *pxPrev;
    void *pvOwner;
    void *pvContainer;
} ListItem_t, *pListItem_t;

// 精简节点
typedef struct xMINI_LIST_ITEM {
    UBaseType_t xItemValue;
    struct xLIST_ITEM *pxNext;
    struct xLIST_ITEM *pxPrev;
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
void vListInsertEnd(List_t * const pxList, ListItem_t * const pxListItem);

/**
 * @brief 按辅助值升序插入
 * 
 * @param pxList 链表根节点
 * @param pxListItem 节点
 */
void vListInsert(List_t * const pxList, ListItem_t * const pxListItem);

/**
 * @brief 删除节点
 * 
 * @param pxListItem 
 * @return UBaseType_t 链表节点数目
 */
UBaseType_t uxListRemove(ListItem_t * const pxListItem);