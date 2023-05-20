
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
这种有间隔的链表，大多数都是双指针。
先形成环后断开

          if (head == nullptr || head->next == nullptr || k == 0 )  return NULL;
// if(!head || !head->next || k == 0)
            return head;

        ListNode *p = head, *q;
        int n = 1;
        while(p){//找节点的个数。
            p=p->next;
		n++;
        }

 for(auto p=head;p;p=p->next) n++;
        k %= n;//为了k大于n的情况

 p=head;//再次遍历，找到尾节点，然后让尾节点的next指向头结点，让链表成环。

        if(k)
        {
            for(int i = 0; i < len - k; ++i) //新链表的最后一个节点是原链表的第len - k个
                tail = tail->next;
        }
        newHead = tail->next;   //确定新的头结点
        tail->next = NULL;      //断开环
        return newHead;
    }
};

        auto first=head,second=head;
        while(k--){
            first=first->next;
        }//先让快指针走 k 个位置
        while(first->next){
            first=first->next;
            second=second->next;
        }//然后两个指针一起走完整个链表。
        first->next=head; //first->next 指向 head，完成旋转（当然还没完事）；
        head=second->next; //	•	head 指向 second->next，头结点指向确认； 
        second->next=NULL; //	•	second->next 指向空节点，尾结点指向确认；

        return head;