#include "list.h"

void vListInitialiseItem(ListItem_t * const pxListItem)
{
    pxListItem->pvContainer = NULL;
}

void vListInitialise(List_t * const pxList)
{
    pxList->pxIndex = (pListItem_t) &(pxList->xListEnd);

    pxList->xListEnd.xItemValue = portMAX_DELAY;

    pxList->xListEnd.next = (pListItem_t) &(pxList->xListEnd);
    pxList->xListEnd.prev = (pListItem_t) &(pxList->xListEnd);

    pxList->uxNumsOfItems = (UBaseType_t) 0U;
}

void vListInsertEnd(List_t * const pxList, ListItem_t * pxListItem)
{
    ListItem_t * pxIndex = pxList->pxIndex;

    pxListItem->next = pxIndex;
    pxListItem->prev = pxIndex->prev;

    pxIndex->prev->next = pxListItem;
    pxIndex->prev = pxListItem;

    pxListItem->pvContainer = (void*) pxList;

    (pxList->uxNumsOfItems)++;
}