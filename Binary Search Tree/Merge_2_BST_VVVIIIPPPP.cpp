#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class node
{
    public:
    int data;
    node *left,*right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *Create_BST(node *root,int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(root -> data > data)
    root -> left = Create_BST(root -> left,data);

    else
    root -> right = Create_BST(root->right,data);

    return root;
}

void Input_BST(node *&root)
{
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    while(data != -1)
    {
        root = Create_BST(root,data);
        cout<<"Enter the data for insertion: "<<endl;
        cin>>data;
    }
}


void Sorted_DLL(node *root,node*&dummy_pointer)
{
    if(root == NULL)
        return;
    
    Sorted_DLL(root->left,dummy_pointer); // left call
        
    dummy_pointer ->right = root;
    root->left = dummy_pointer;
    dummy_pointer = root;
    Sorted_DLL(root -> right , dummy_pointer); // right call
}

void merge_Linked_List(node *head1,node *head2,node *&merge_List_head,node *&tail)
{

    if(head1 == NULL){
        merge_List_head = head2;
        return;
    }

    if(head2 == NULL)
    {
        merge_List_head = head1;
        return;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data < head2 -> data)
        {
            
            if(merge_List_head == NULL)
            {
                merge_List_head = head1;
                tail = merge_List_head;
                head1 = head1 ->right;
            }
            else{
                head1 -> left = tail;
                tail -> right = head1;
                tail = head1;
                head1 = head1 -> right;
            }
        }
        else{

             if(merge_List_head == NULL)
            {
                merge_List_head = head2;
                tail = merge_List_head;
                head2 = head2 ->right;
            }
            else{
                head2 -> left = tail;
                tail -> right = head2;
                tail = head2;
                head2 = head2 ->right;
            }
        }
    }

    while(head1 != NULL)
    {
        head1 -> left = tail;
        tail -> right = head1;
        tail = head1;
        head1 = head1 -> right;
    }

    while(head2 != NULL)
    {
        head2 -> left = tail;
        tail -> right = head2;
        tail = head2;
        head2 = head2 ->right;
    }
}

int count_nodes(node *root)
{
    int cnt = 0;

    while(root != NULL)
    {
        root = root -> right;
        cnt++;
    }
    return cnt;
}

node *Create_BST(node **head,int nodes_cnt)
{
    if(nodes_cnt <= 0 || head == NULL)
    return NULL;

    node *left_subTree = Create_BST(head,nodes_cnt/2);
    node *root = new node((*head)->data);

    root ->left = left_subTree;
    *head = (*head) ->right;
    root ->right = Create_BST(head,(nodes_cnt-(nodes_cnt/2)-1));

    return root;
}

void inorder(node *root)
{
    if(root == NULL)
    return;

    inorder(root -> left);
    cout << root -> data <<" ";
    inorder(root -> right);
}

int main()
{
    //string 50 40 60 30 45 55 70 80 -1
    //string 2 -> 110 25 120 15 30 115 125 -1
    // step 1 is to flatten the BST into a sorted DLL
    // step 2 merge both the sorted flatten linked list
    // step 3 Create BST From the flatten merge linked list

 /////////////////////////////////////////////////////////////////////////       list 1           //////////////////////////////////////
    node *root1 = NULL;
    Input_BST(root1);

    node* head1 = new node(-1);
    node* dummy_pointer = head1;

    Sorted_DLL(root1,dummy_pointer);
    head1 = head1 -> right;
    head1 ->left = NULL;

 /////////////////////////////////////////////////////////////////////////       list 1           //////////////////////////////////////
    node*root2 = NULL;
    Input_BST(root2);

    node* head2 = new node(-1);
    dummy_pointer = head2;

    Sorted_DLL(root2,dummy_pointer);
    head2 = head2 -> right;
    head2 ->left = NULL;

//////////////////////////////////////////////////////////////////////           merge logic        //////////////////////////////////////////////////


    node *merge_List_head = NULL;
    node *temp_pointer = merge_List_head;

    merge_Linked_List(head1,head2,merge_List_head,temp_pointer);


    // temp_pointer = merge_List_head;
    // while(temp_pointer != NULL)
    // {
    //     cout<< temp_pointer->data <<" ";
    //     temp_pointer = temp_pointer -> right;
    // }

    node *Merge_Head = Create_BST(&merge_List_head,count_nodes(merge_List_head));
    inorder(Merge_Head);

    return 0;
}