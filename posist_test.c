#include <bits/stdc++.h>
#include<queue>
usnig namespace std;
struct node{
    struct node* nextnode;
    struct node** childnode;
    string timestamp;
    data my_tree;
    int nodenum;
    string node_id;
    string ref_id;
    string child_ref_id;
    string gen;
};
enum data{owner_id,val,name};

void create_genesis_node(node* genesis,int data){   // 1st part
    queue <pair<node* ,int>>q1;
    queue <pair<node*,int>> q2;
    struct node* temp;
    temp->val = data;
    temp->nextnode = nullptr;
    temp->childnode = nullptr;
    int valid = 0;  //to check whether the node can be inserted or not
    if(genesis == nullptr)
     {
         genesis->nextnode = temp;
     }
     else if(genesis->nextnode == nullptr){
        if(data < genesis->data)
            genesis->childnode = temp;
        else
            cout<<"the node cannot be inserted";
     }
    else{
        q1.push(<pair<&whereto->temp,&whereto->data>>);
        while(!q1.empty()){                               //doing level order traversing on the genesis tree
            valid+=q1.front(&whereto->value);
            q2.push(q1.pop());
        }
        if(valid<genesis->data)
            genesis->childnode = temp;
        else
            cout<<"The node cannot be inserted \n";
    }
}
void create_child_set(node* genesis){  //2nd part
    cout<<"Enter the values \n";
    int validate = 0;
    queue <int> q;
    while(1){
            int n;
        cin>>n;
        if(validate+n < genesis->data){
            validate+=n;
            q.push(n);
        }
    }
    while(!q.empty()){
        cout<<q.front()<<" "; //printing the set of child nodes
        q.pop();
    }
    cout<<endl;
}

void create_part_child_node(node* genesis){              // 3rd part
    queue <pair<node* ,int>>q1;
    queue <pair<node*,int>> q2;
    struct node* temp;
    temp->val = data;
    temp->nextnode = nullptr;
    temp->childnode = nullptr;
    int valid = 0;  //to check whether the node can be inserted or not
    if(genesis == nullptr)
     {
         genesis->nextnode = temp;
     }
     else if(genesis->nextnode == nullptr){
        if(data < genesis->data)
            genesis->childnode = temp;
        else
            cout<<"the node cannot be inserted";
     }
    else{
        q1.push(<pair<&whereto->temp,&whereto->data>>);
        while(!q1.empty()){                               //doing level order traversing on the genesis tree
            valid+=q1.front(&whereto->value);
            q2.push(q1.pop());
        }
        if(valid<genesis->data)
            genesis->childnode = temp;
        else
            cout<<"The node cannot be inserted \n";
    }
}
void check_encryption(int id,int v,string na){
    int count = 0;           // assuming that the original values are already stored
    if(id == owner_id)
        count++;
    if(v == val) count++;
    if(na == name) count++;
    if(count == 3)
        cout<<"Correct user \n";
    else cout<<"Wrong user \n";
}

void edit_my_node(node* genesis){   //6th part
    int n;
    cout<<"Enter the node you want to change";
    cin>>n;
    //searching the element in the tree
    queue <int> q;
    q.push(genesis); // pushing the root node
    while(!q.empt()){
        if(q.front != n){
            q.pop();
            q.push(genesis->childnode->data)     // pushing all the child nodes in the queue to access them one by one
        }
        else break;
    }
    if(q.empty()) cout<<"Element not found \n";
    else{
        cout<<"Enter the element you want to insert instead of this element";
        int ele; cin>>ele; node* temp; temp->data = ele; node* p;
        if(ele<n){
            while(p->childnode->data != n)
                p = p->childnode;
            p->childnode = temp;
        }
        else{
            int validate = 0;
            while(1)
            validate+= genesis->nextnode->data;
            node* p;
            if(validate<genesis->data) p->childnode = temp;
            else cout<<"The value cannot be changed";
        }
    }
}
int longest_genesis(node* genesis){
    if(genesis == nullptr)
        return 1;
    else return max(1+longest_genesis(genesis->nextnode),1+longest_genesis(genesis->childnode));
}

int longest_chain(node* genesis){
    if(genesis == nullptr)
        return 1;
    else return max(1+longest_genesis(genesis->nextnode),1+longest_genesis(genesis->childnode));
int main(){
    struct node* genesis;
    int data;
    cin>>data;
    create_genesis_node(genesis,data);      // 1st part, this will be done in a loop as multiple entries will be present
    create_child_set(genesis);         //  2nd part
    create_part_child_node(genesis);      //      3rd part
    int owner_id,val; string name;
    cin>>id<<v<<na;
    check_encryption(id,v,na); // 4th part
    edit_my_node(genesis); //6th part
    cout<< longest_genesis(genesis) <<endl; // 8th part
    cout<<longest_chain(genesis)<<endl;
    return 0;
}
