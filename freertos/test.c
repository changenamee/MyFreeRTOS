#include <stdio.h>

#include "list.h"

// root node
List_t list_test;

// nodes
ListItem_t list_item1;
ListItem_t list_item2;
ListItem_t list_item3;

int main(void)
{
    /* test list */
    {
        vListInitialise(&list_test);

        vListInitialiseItem(&list_item1);
        list_item1.xItemValue = 12;
        vListInitialiseItem(&list_item2);
        list_item2.xItemValue = 21;
        vListInitialiseItem(&list_item3);
        list_item3.xItemValue = 10;

        // listSET_LIST_ITEM_VALUE(&list_item1, 12);
        // listSET_LIST_ITEM_VALUE(&list_item2, 21);
        // listSET_LIST_ITEM_VALUE(&list_item3, 10);

        vListInsert(&list_test, &list_item1);
        vListInsert(&list_test, &list_item2);
        vListInsert(&list_test, &list_item3);

        int list_item_nums = listCURRENT_LIST_LENGTH(&list_test);
        pListItem_t cur = list_test.pxIndex->pxNext;
        for (int i = 0; i < list_item_nums; ++i) {
            printf("cur list item: %p, value: %u\n", cur, cur->xItemValue);
            cur = cur->pxNext;
        }
    }

    return 0;
}
