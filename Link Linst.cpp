#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
// create, print, reverse recursion, reverse iterative , dupli
// merge recursion, merge sort, insertion sort
Node* createLL(int t)
{
    Node* head=NULL;
    Node* tail=NULL;
    while(t--)
    {
        int a;
        cin>>a;
        Node* curnode=new Node(a);
        if(head==NULL)
        {
            head=curnode;
            tail=curnode;
        }
        else
        {
            tail->next=curnode;
            tail=tail->next;
        }
    }
    return head;
}
void printLL(Node* head)
{
    Node* cn=head;
    while(cn)
    {
        cout<<cn->data<<" ";
        cn=cn->next;
    }
    cout<<endl;
}
Node* delet(Node* head,int q)
{
    Node* cur=head;
    for(int i=0;i<q-1;i++)
    {
        cur=cur->next;
    }
    if(q==0)
    {
        head=head->next;
    }
    else
    {
    cur->next=cur->next->next;
    }
    return head;
}
void kth(int k,Node* head)
{
    Node* forw=head;
    Node* backw=head;
    for(int i=0;i<k-1;i++)
    {
        forw=forw->next;
    }
    while(forw->next)
    {
        backw=backw->next;
        forw=forw->next;
    }
        cout<<backw->data;
}
Node* reversrecursion(Node* cur,Node* prev)
{
    if(cur==NULL)
    {
     return prev;
    }
    {
        Node* ahead=cur->next;
        cur->next=prev;
        prev=cur;
        reversrecursion(ahead,prev);
    }
}
Node* revers(Node* head)
{
    Node* cur=head;
    Node* prev=NULL;
    while(cur)
    {
        Node* ahead=cur->next;
        cur->next=prev;
        prev=cur;
        cur=ahead;
    }
    return prev;
}
Node* kreverse(Node* head)
{
    Node* cur=head;
}
void intersection(Node* head,Node* head2,int t,int n)
{
    Node* cur1=head;
    Node* cur2=head2;
    Node* here=head;
    int m=0;
    while(cur1)
    {
        while(cur2)
        {
            if(cur1->data==cur2->data)
            {
                int h=0;
                Node* now=cur1;
                while(cur1!=NULL | cur2!=NULL)
                {
                     if(cur1->data!=cur2->data)
                     {
                         m++;
                         cout<<m<<"m";
                     }
                     h++;
                 cur1=cur1->next;
                 cur2=cur2->next;
                }
                if(m==0|m==h)
                {
                    cout<<now->data;
                    exit(0);
                }
            }
            cur2=cur2->next;
        }
        cur1=cur1->next;
        cur2=head2;
    }
    cout<<"-1";

}
Node* dupli(Node* head)
{
    Node* cur1=head;
    Node* cur2=head->next;
    int m=0,h=0;
    while(cur1&&cur2)
    {
        m=h;
        while(cur2)
        {
            if(cur1->data==cur2->data)
            {
              head=delet(head,m);
              printLL(head);
            }
            m++;
            cur2=cur2->next;
        }
        cur1=cur1->next;
        cur2=cur1->next;
        h++;
    }
    printLL(head);
}
Node* findeven(Node *head)
{
    Node* cur=head;
    Node* prev=head;
    while(cur&&cur->next){
    if(cur->next->data%2==0)
    {
         return cur;
    }
    cur=cur->next;
    }
   return head;

}
Node* oddeven(Node *head)
{
    Node* prev=findeven(head);
    Node* even=prev->next;
    Node *cur=even->next;
    Node* cprev=even;
    Node* cprevv;
    while(cur)
    {
        Node* ahead=cur->next;
        if(cur->data%2!=0)
        {
            cprevv=cprev;
            cprevv->next=cur->next;
            prev->next=cur;
            prev=cur;
            cur->next=even;

        }
        else
        {
         cprev=cprev->next;
        }
        cur=ahead;
    }
    return head;

}
Node* kr(Node* head,int n)
{
    Node* sp=head;
    Node* fp=head;
    while(n--)
    {
        fp=fp->next;
    }
    cout<<fp->data;

    {
    Node* cur=head;
    Node* prev=fp;
    while(cur)
    {
        Node* ahead=cur->next;
        cur->next=prev;
        prev=cur;
        cur=ahead;
    }
    return prev;
    }


}
Node* bubble(Node* head)
{
    int swp=0;
    Node* cur=head;
    while(1)
    {
        cur=head;
        swp=0;
    while(cur->next&&cur)
    {
        if(cur->data > cur->next->data)
        {
            swap(cur->data,cur->next->data);
            swp++;
        }
        cur=cur->next;
    }
    if(swp==0)
        {
            break;
        }
    }
    return head;
}
Node* mrge(Node* head1,Node* head2)
{
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    if(head1->data<head2->data)
    {
        head1->next=mrge(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next=mrge(head1,head2->next);
        return head2;
    }

}
Node* mergeLL(Node* a, Node* b){
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data < b->data){
        a->next = mergeLL(a->next, b);
        return a;
    }
    else {
        b->next = mergeLL(a, b->next);
        return b;
    }
}
Node* insertsort(Node* head)
{
    Node* cur=head;
    Node* cur1=head->next;
    Node* prev=head;
    int q=1;
    while(cur)
    {
        while(cur1)
        {
        if(cur1->data<cur->data)
        {
            Node* curnode=new Node(cur1->data);
            curnode->next=cur;
            cout<<cur->data<<cur1->data<<prev->data<<q<<endl;
            head=curnode;
            delet(head,q);
            printLL(head);
            break;
        }
        cur1=cur1->next;
        q++;
        }
        prev=cur;
        cur=cur->next;
        cur1=head;
        q=0;
    }
    return head;
}
Node* midPoint(Node* head){
    Node* slow = head;   // SET
    Node* fast = head;

    // GO
    while(slow && fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* mergeSort(Node* a){
    if (a == NULL || a->next == NULL) return a;
    Node* midNode = midPoint(a);
    Node* b = midNode->next;
    midNode->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);
    Node* ans = mergeLL(a, b);
    return ans;
}
int main()
{
    int h;
    {
    int t,n;
    cin>>t;
    Node *head=createLL(t);
    head=mergeSort(head);
    printLL(head);
    }
}
