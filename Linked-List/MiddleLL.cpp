
#include <iostream>
using namespace std;
class Node
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
class LinkedList // User defined data structure
{
public:
    Node *head;
    int size;
    LinkedList() // constructor
    {
        head = NULL;
        size = 0;
    }

Node* middle(int size,Node* head){
Node *temp=head;
for(int i=1;i<=size;i++){
    temp=temp->next;
}
return temp;


}
void insertAtTail(int val)
    {
        Node *t = new Node(val);
        if (size == 0)
        {
            head = t;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < size; i++)
            {
                temp = temp->next;
            }
            temp->next = t;
        }
        size++;
    }

};
void display(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->val << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int count(Node *Head)
{
    int count = 0;
    Node *temp = Head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << endl;
    return count;
}
int main(){
 Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

  display(a);
    LinkedList ll;
        LinkedList ll2;
   int ans=count(a);
    cout<<ans<<endl;
  Node* temp2=ll.middle(ans/2,a);


while(temp2->next!=NULL){
 ll2.insertAtTail(temp2->val);
temp2=temp2->next;
}
  display(a);
    return 0;
}