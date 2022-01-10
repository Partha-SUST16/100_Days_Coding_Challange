#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x): val(x),next(nullptr) {}
    ListNode(int x, ListNode *next): val(x),next(next) {}
};

void PrintNode(ListNode* head)
{

    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
///Task1: Remove Duplicates from Sorted List: I/O: 1->1->2->2->3, Output: 1->2->3

ListNode* DeleteAllDuplicate(ListNode *head)
{
    if(!head) return head;
    ListNode *pre = head, *current = head->next;
    int currentValue = head->val;
    while(current)
    {
        if(currentValue != current->val)
        {
            pre->next = current;
            currentValue = current->val;
            pre = pre->next;
            // cout<<pre->val<<endl;
        }
        current = current->next;
    }
    pre->next = NULL;
    return   head;
}

///Task2 : Remove Duplicates from Sorted List II(Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.)
/// Given 1->2->3->3->4->4->5, return 1->2->5.

ListNode* DeleteDuplicates(ListNode *head)
{
    if(!head) return head;
    if(!head->next) return head;
    int currentValue = head->val;
    ListNode* currentNode = head->next;
    if(currentNode->val!=currentValue)
    {
        head->next = DeleteDuplicates(currentNode);
        return head;
    }
    else
    {
        while(currentNode&& currentNode->val==currentValue)
        {
            currentNode= currentNode->next;
        }
        return DeleteDuplicates(currentNode);
    }
}


/// Task3: Given a singly linked list, determine if it is a palindrome.

bool isPallindromeUsingList(ListNode* head)
{
    //first way: push every value to a vector and determine the vector is palindrome or not
    vector<int>values;
    if(!head) return true;

    while(head)
    {
        values.push_back(head->val);
        head = head->next;
    }
    int left = 0, right = values.size() - 1;
    for (; left<right; left++,right--)
    {
        if(values[left]!=values[right]) return false;
    }
    return true;
}

bool IsPallindromeUsingLinkedList(ListNode * head)
{
    if(!head || !head->next) return true;
    //split the array into two half
    ListNode *first = head, *second = head->next;
    while(second && second->next)
    {
        first = first->next;
        second = second->next->next;
    }
    second = first->next;
    first->next = NULL;
    // PrintNode(first);
    //PrintNode(second);
    ///reverse the linked list for second
    ListNode *next = NULL, *prev=NULL, *current = second;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    second = prev;
    PrintNode(second);
    while(second)
    {
        if(second->val != head->val)
        {
            return false;
        }
        second = second->next, head = head->next;
    }
    return true;
}
//Task4: Given a list, rotate the list to the right by k places
ListNode* RotateRight(ListNode* head,int k)
{
    if(!head) return head;
    int length = 1;
    ListNode* temp = head;
    while(temp->next)
    {
        length++,temp=temp->next;
    }
    temp->next = head;
    //PrintNode(temp);
    if(k%=length)
    {
        for(int i = 0; i < length-k; i++, temp = temp->next);
    }
    //PrintNode(temp);
    ListNode* newHead = temp->next;
    temp->next =NULL;
    //PrintNode(temp);
    return newHead;
}

///Task5: Add two linked list
ListNode* AddTwoNumber(ListNode* firstHead, ListNode* secondHead)
{
    int carry = 0;
    ListNode *ans = new ListNode(0), *r = ans;
    while(firstHead || secondHead || carry)
    {
        carry = carry + (firstHead?firstHead->val : 0) + (secondHead?secondHead->val:0);
        ans->next = new ListNode(carry%10);
        ans = ans->next;
        //cout<<ans->val<<endl;
        carry/=10;
        if(firstHead) firstHead = firstHead->next;
        if(secondHead) secondHead = secondHead->next;
    }
    return r->next;
}

///TODO:: Task 6: Reverse a linked list from position m to n ( 1 based index)

ListNode* ReverseLinkedList(ListNode* head, int m, int n)
{
    ListNode newNode(0);
    newNode.next = head;
    int cnt = 1;
    ListNode* pre = &newNode, *curr = head, *next = NULL;

    while(cnt<n)
    {
        if(cnt<m)
        {
            pre = curr;
            curr = curr->next;
        }
        else
        {
            next = curr->next;
            curr->next = curr->next->next;
            next->next = pre->next;
            pre->next = next;
        }
        cnt++;
    }
    return newNode.next;
}

///Task: Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
ListNode* DetectCycle(ListNode* head)
{
    ListNode* slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }
    if(slow!=fast) return NULL;
    fast = head;
    PrintNode(slow);
    while(fast && fast->next)
    {
        if(slow==fast) return slow;
        slow = slow->next;
        fast = fast->next;
    }
    return NULL;
}
///Task: Reverse Nodes in k-Group
ListNode* ReverseKGroup(ListNode* head, int k)
{
    if(!head || !head->next) return head;
    ListNode newNode(0);
    ListNode *pre = &newNode, *cur = head, *next = NULL;
    newNode.next = head;
    int len = 0;
    for(ListNode* p = head; p ; p = p->next)len++;
    int times = len/k;
    while(times)
    {
        for(int i = 1 ; i < k ; i++)
        {
            next = cur->next;
            cur->next = cur->next->next;
            next->next = pre->next;
            pre->next = next;
            if(i==k-1)
            {
                pre = cur;
                cur = cur->next;
            }
        }
        times--;
    }
    return newNode.next;
}
int main()
{
    ListNode *a = new ListNode(5);
    ListNode *b = new ListNode(6,a);
    ListNode *c = new ListNode(15,b);
    ListNode *d = new ListNode(7,c);
    ListNode *e = new ListNode(8,d);
    ListNode *f = new ListNode(1,e);

    ListNode *g = new ListNode(5);
    ListNode * h= new ListNode(6,g);
    ListNode *ans= ReverseKGroup(f,2);
    PrintNode(ans);
    return 0;
}
