/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
// utility function to insert node at the end of the list
void insertNode(Node *&head, int val)
{
  Node *newNode = new Node(val);
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
  return;
}
void printList(Node *head)
{
  while (head->next != NULL)
  {
    cout << head->val << "->";
    head = head->next;
  }
  cout << head->val << endl;
  return;
}
Node *copyRandomList(Node *head)
{
  Node *iter = head;
  Node *front = head;

  // First round: make copy of each node,
  // and link them together side-by-side in a single list.
  while (iter != NULL)
  {
    front = iter->next;

    Node *copy = new Node(iter->val);
    iter->next = copy;
    copy->next = front;

    iter = front;
  }

  // Second round: assign random pointers for the copy nodes.
  iter = head;
  while (iter != NULL)
  {
    if (iter->random != NULL)
    {
      iter->next->random = iter->random->next;
    }
    iter = iter->next->next;
  }

  // Third round: restore the original list, and extract the copy list.
  iter = head;
  Node *pseudoHead = new Node(0);
  Node *copy = pseudoHead;

  while (iter != NULL)
  {
    front = iter->next->next;

    // extract the copy
    copy->next = iter->next;

    // restore the original list
    iter->next = front;

    copy = copy->next;
    iter = front;
  }

  return pseudoHead->next;
}
int main()
{
  printf("Hello World");
  Node *head = NULL;
  // inserting Node
  insertNode(head, 1);
  insertNode(head, 2);
  insertNode(head, 3);
  insertNode(head, 4);
  insertNode(head, 5);

  cout << "Original list: ";
  printList(head);
  Node *newHead = copyRandomList(head); // calling function for rotating right of
  // the nodes by k times

  // cout<<"After "<<k<<" iterations: ";
  printList(newHead); // list after rotating nodes
  return 0;
}
