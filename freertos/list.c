#include "list.h"

void vListInitialiseItem(ListItem_t * const pxListItem)
{
    pxListItem->pvContainer = NULL;
}

void vListInitialise(List_t * const pxList)
{
    pxList->pxIndex = (pListItem_t) &(pxList->xListEnd);

    pxList->xListEnd.xItemValue = portMAX_DELAY;

    pxList->xListEnd.pxNext = (pListItem_t) &(pxList->xListEnd);
    pxList->xListEnd.pxPrev = (pListItem_t) &(pxList->xListEnd);

    pxList->uxNumsOfItems = (UBaseType_t) 0U;
}

void vListInsertEnd(List_t * const pxList, ListItem_t * const pxListItem)
{
    ListItem_t * pxIndex = pxList->pxIndex;

    pxListItem->pxNext = pxIndex;
    pxListItem->pxPrev = pxIndex->pxPrev;

    pxIndex->pxPrev->pxNext = pxListItem;
    pxIndex->pxPrev = pxListItem;

    pxListItem->pvContainer = (void*) pxList;

    (pxList->uxNumsOfItems)++;
}

void vListInsert(List_t * const pxList, ListItem_t * const pxListItem)
{
    ListItem_t *pxIterator;

    const TickType_t xValueOfInsertion = pxListItem->xItemValue;

    if (portMAX_DELAY == xValueOfInsertion) {
        pxIterator = pxList->xListEnd.pxPrev;
    }
    else {
        for (pxIterator = (ListItem_t*) &(pxList->xListEnd);
                pxIterator->pxNext->xItemValue <= xValueOfInsertion;
                pxIterator = pxIterator->pxNext) {

                }
    }

    pxListItem->pxNext = pxIterator->pxNext;
    pxListItem->pxNext->pxPrev = pxListItem;
    pxIterator->pxPrev = pxIterator;
    pxIterator->pxNext = pxListItem;

    pxListItem->pvContainer = (void*)pxList;

    (pxList->uxNumsOfItems)++;
}

UBaseType_t uxListRemove(ListItem_t * const pxListItem)
{
    List_t * const pxList = (List_t *)pxListItem->pvContainer;

    pxListItem->pxNext->pxPrev = pxListItem->pxPrev;
    pxListItem->pxPrev->pxNext = pxListItem->pxNext;

    pxListItem->pvContainer = NULL;

    if (pxList->pxIndex == pxListItem) {
        pxList->pxIndex = pxListItem->pxPrev;
    }

    (pxList->uxNumsOfItems)--;

    return pxList->uxNumsOfItems;
}
