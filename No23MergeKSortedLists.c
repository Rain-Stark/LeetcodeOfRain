/** 
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
*/ 
struct ListNode* divideAndConquer(struct ListNode**, int, int);
struct ListNode* merge(struct ListNode*, struct ListNode*);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    return divideAndConquer(lists, 0, listsSize);
}

// int main(void)
// {
//	 struct ListNode* lists[3];
//	 //可自行初始化lists后进行Debug 
//	 mergeKLists(lists, 3);
//	 return 0;
// }

struct ListNode* divideAndConquer(struct ListNode** lists, int index_l,
                                 int index_r)
{
    if (index_l == index_r)
        return lists[index_l];
    
    if (index_l + 1 == index_r)
        return merge(lists[index_l], lists[index_r]);
    
    int mid = (index_l + index_r) / 2;
    return merge(divideAndConquer(lists, index_l, mid), divideAndConquer(lists,
                                            mid + 1, index_r));
}

struct ListNode* merge(struct ListNode* i, struct ListNode* j)
{
    if (i == NULL && j == NULL)
        return NULL;
    else if (i == NULL)
        return j;
    else if (j == NULL)
        return i;
    
    struct ListNode* list;
    struct ListNode* node;
    struct ListNode* pre;
    pre = NULL;
    list = NULL;
    while(i != NULL && j != NULL)
    {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node -> next = NULL;
        if (i -> val <= j -> val)
        {
            node -> val = i -> val;
            i = i -> next;
        }
        else
        {
            node -> val = j -> val;
            j = j -> next;
        }
        if (list == NULL)
        {
            list = node;
        }
        else
        {
            pre -> next = node;
        }
        pre = node;
    }
    if (i != NULL)
        pre -> next = i;
    else if (j != NULL)
        pre -> next = j;
    return list;
}
