# MergeSort

**归并排序**
==========

**1.问题分析**
-------------
归并排序就是采用分治的策略，讲一个大问题分成很多小问题，在解决小问题在通过小问题解决大问题。由于排序问题给定的是一个无序序列，可以把两个规模大致相等的子序列。如果不易解决，再将子序列继续分解，直到子序列中包含的元素个数为1。因为单个元素的序列本身是有序的，此时便可以进行合并，从而得到一个完整的有序数列。

**2.算法设计**
-------------
过程大致分为：
1.分解——将待排序的元素分成大小大致相同的两个子序列
2.治理——对两个子序列进行合并排序
3.合并——将排好序的有序子序列进行合并，得到最终的有序序列

**3.算法图解**
-------------
![合并排序.png](https://i.loli.net/2020/02/14/DscuETNSe7zO1b2.png)
**4.算法代码**
-------------

```C++
Linklist merge(Linklist node1, Linklist node2)
{
    Linklist dummy = new Node;
    Linklist node = dummy;
    while (node1 && node2)
    {
        if (node1->val < node2->val)
        {
            node->next = node1;
            node1 = node1->next;
        }
        else
        {
            node->next = node2;
            node2 = node2->next;
        }
        node = node->next;
    }
    if (node1)
        node->next = node1;
    if (node2)
        node->next = node2;
    return dummy->next;
}
//上面是合并部分，建立一个新的链表，
//按照大小分别把元素加入新链表
Linklist MergeSort(Linklist head)
{
    if (!head || !head->next)
        return head;
    Linklist slow = head, fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Linklist left, right;
    left = head;
    right = slow->next;
    slow->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);

    return merge(left, right);
}
//利用快慢指针把一个链表分成两份
```