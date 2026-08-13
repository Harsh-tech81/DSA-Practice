#include <iostream>
using namespace std;
class Node // Linked list Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};


int main()
{
    // 10 20 30 40

    //     d->next = NULL;
    // cout<<a->next;
    // Node a(10), b(20), c(30), d(40);
    // // // Forming Linked List by using the next address in the previous address
    // a.next = &b;
    // b.next = &c;
    // c.next = &d;

    // Node *ptr = &b;
    //     cout << ptr->val << endl << (*ptr).val << endl;
    // // ptr->val=30;

    //         cout << ptr->val << endl << (*ptr).val << endl;
    // cout << a.next << endl;
    //      << d.next << endl
    //      << &a;

    // cout<<(*(a.next )).val<<endl;  // in this way also we can easily print the value of the b
    // a.next->val=60;  // value of b is controlled by a
    // cout<<(a.next )->val<<endl<<b.val<<endl;  // using same thing but by using arrow operator in place of pointer

    // cout<<a.val<<endl<<(a.next)->val<<endl<<(b.next)->val<<endl<<(c.next)->val;
    // cout<<(*((*((*(a.next )).next)).next)).val<<endl;   // by using only a we can easily print all the values of the nodes either a or b or c or d

    // Printing the linked list
    //     Node temp=a;    // temp is temporary variable which is at 'a'
    //     while(1){
    //     cout<<temp.val<<"  ";
    //     if(temp.next==NULL) break;
    //     temp=*(temp.next);

    // }

    // Now by using the pointer concept we can do it
 

    // Now print all the elements
    // Node *temp=a;
    // while(temp!=NULL){
    //     cout<<temp->val<<"  ";
    //     temp=temp->next;
    // }

}