#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 20
using namespace std;
class node 
{
	public:
		int data;
		node *left,*right;
		node()
		{
			data=0;
			left=NULL;
			right=NULL;
		}
		node(int x)
		{
			data=x;
			left=NULL;
			right=NULL;
		}
};
class stack
{
	public:
		node *data[MAX];
		int top;
		stack()
		{
			top=-1;
		}
		int empty()
		{
			if(top==-1)
			{
				return 1;
			}
			return 0;
		}
		int full()
		{
			if(top==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		void push(node *x)
		{
			if(full()==0)
			{
				top++;
				data[top]=x;
			}
			else
			{
				cout<<"\nData is full...";
			}
		}
		node * pop()
		{
			if(empty()==0)
			{
				node *p;
				p=data[top];
				top--;
				return p;
			}
			else
			{
				cout<<"\nData is empty..";
				return NULL;
			}
		}
};
class stacknode
{
	public:
		int flag;
		node *address;
		stacknode()
		{
			flag=0;
			address=NULL;
		}
};
class Stack_postorder
{
	public:
		stacknode data[MAX];
		int top;
		Stack_postorder()
		{
			top=-1;
		}
		int empty()
		{
			if(top==-1)
			{
				return 1;
			}
			return 0;
		}
		int full()
		{
			if(top==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		void push(stacknode p)
		{
			if(full()==0)
			{
				top++;
				data[top]=p;
			}
			else
			{
				cout<<"\nStack is Full..";
			}
		}
		stacknode pop()
		{
			stacknode p;
			if(empty()==0)
			{
				p=data[top];
				top--;
				return p;
			}
			else
			{
				cout<<"\nStack is Empty..";
			}
			return p;
		}
};
class queue
{
	node *data[MAX];
	int front,rear;
	public:
		queue()
		{
			front=rear=-1;
		}
		int full()
		{
			if(rear==MAX-1)
			{
				return 1;
			}
			return 0;
		}
		int empty()
		{
			if(front==-1)
			{
				return 1;
			}
			return 0;
		}
		void enqueue(node *t)
		{
			if(full()==0)
			{
				rear++;
				if(front==-1)
				{
					front=0;
				}
				data[rear]=t;
			}
			else
			{
				cout<<"\nQueue Is Full..";
			}
		}
		node *dequeue()
		{
			if(empty()==0)
			{
				node *p;
				p=data[front];
				if(front==rear)
				{
					front=rear=-1;
				}
				else
				{
					front++;
				}
				return p;
			}
			else
			{
				cout<<"\nQueue is empty..";
				return NULL;
			}
		}
		void init()
		{
			front=rear=-1;
		}
};
class tree
{
	node *root;
	public:
		tree()
		{
			root=NULL;
		}
		node * rec_create();// this fn we cannot directly call because when last stackframe is executed root address is returned which have to store in root
		void create()
		{
			root=rec_create();//recursive
		}
		void rec_preorder(node *p);//recursive
		void rec_inorder(node *p);//recursive
		void rec_postorder(node *p);//recursive
		void display()
		{
			cout<<"\nPreorder is:";
			rec_preorder(root);
			cout<<"\nInorder is:";
			rec_inorder(root);
			cout<<"\nPostorder is:";
			rec_postorder(root);
		}
		void non_rec_preorder();//non recursive
		void non_rec_inorder();//non recursive
		void non_rec_postorder();//non recursive
		void BST_display();//non recursive BFT
		void non_rec_height();//non recursive
		int height_of_every_node(node *p);//non recursive
		void extrafn()
		{
			pre_using_height(root);
		}
		void pre_using_height(node *p)
		{
			if(p==NULL)
			{
				return;
			}
			else
			{
				cout<<"\nHeight Of :"<<p->data<<" Is:"<<height_of_every_node(p);
				pre_using_height(p->left);
				pre_using_height(p->right);
			}
		}
		node * search_using_BFT(node *p,int x);//non recursive
		node * search(int x)//non recursive
		{
			node * y;
			y=search_using_BFT(root,x);
			return y;
		}
		int counttotal(node *p);
		int countleaf(node *p);
		int count1(node *p);
		int count2(node *p);
		void extracountfn(int x)
		{
			if(x==1)
			{
				int y;
				y=counttotal(root);
				cout<<"\nTotal Count Of Node:"<<y;
			}
			else if(x==2)
			{
				int y;
				y=countleaf(root);
				cout<<"\nTotal Count Of Leaf Node Is:"<<y;
			}
			else if(x==3)
			{
				int y;
				y=count1(root);
				cout<<"\nTotal Count Of Node Having 1 Child:"<<y;
			}
			else if(x==4)
			{
				int y;
				y=count2(root);
				cout<<"\nTotal Count Of Node Having 2 Child:"<<y;
			}
		}
		int rec_height(node *p);
		int extrafn_forheight()
		{
			int y;
			y=rec_height(root);
			cout<<" "<<y;
		}
		node *rec_search(node *p,int x);
		void extrafn_search(int x)
		{
			node *t;
			t=rec_search(root,x);
			if(t==NULL)
			{
				cout<<"\nNot Found..";
			}
			else
			{
				cout<<t->data<<" is Found...";
			}
		}
		node *find_leaf(node *p);
		node *delete_rec(node *t,node *p,int done);
		void delete_node(int x)
		{
			node *t,*p;
			t=rec_search(root,x);
			if(t==NULL)
			{
				cout<<"\nData Is Not Found...";
				return;
			}
			p=find_leaf(t);
			t->data=p->data;
			t=delete_rec(t,p,0);
		}
};
int main()
{
	tree obj;
	obj.create();
	obj.display();
	cout<<"\nNon Recursive Preorder:";
	obj.non_rec_preorder();
	cout<<"\nNon Recursive Inorder:";
	obj.non_rec_inorder();
	cout<<"\nNon Recursive Postorder:";
	obj.non_rec_postorder();
	cout<<"\nprint Tree using level :";
	obj.BST_display();
	cout<<"\nHeight Of The Tree Using Non Recursive :";
	obj.non_rec_height();
	cout<<"\nHeight Of Every Node.......\n";
	obj.extrafn();
	int x;
	node *y;
	cout<<"\nEnter data to search:";
	cin>>x;
	y=obj.search(x);
	if(y==NULL)
	{
		cout<<"\nData Is Not Found..";
	}
	else
	{
		cout<<"\nData Is Found..";
	}
	cout<<"\nEnter Data To Found Particular Height of it:";
	cin>>x;
	y=obj.search(x);
	if(y==NULL)
	{
		cout<<"\nData Is Not Found..";
	}
	else
	{
		cout<<"\nHeight of that node is:"<<obj.height_of_every_node(y);
	}
	int z;
	while(1)
	{
		cout<<"\n1.Counttotal\n2.Count 0\n3.Count 1\n4.Count 2\n5.Exit";
		cout<<"\nEnter Choice:";
		cin>>x;
		if(x==5)
		{
			break;
		}
		obj.extracountfn(x);
	}
	cout<<"\nHeight Of Tree Using  Recursive:";
	obj.extrafn_forheight();
	cout<<"\nEnter Data To Search:";
	cin>>z;
	obj.extrafn_search(z);
	cout<<"\nEnter Data To Delete:";
	cin>>x;
	obj.delete_node(x);
	obj.non_rec_inorder();
}
node * tree :: rec_create()
{
	int x;
	char arr[30];
	node *p;
	cout<<"\nEnter -1 to STOP...";
	cout<<"\nEnter Data:";
	cin.getline(arr,30);
	if(strcmp(arr,"-1")==0)
	{
		return NULL;
	}
	else
	{
		x=atoi(arr);
		p=new node(x);
		cout<<"\nEnter Left of:"<<x;
		p->left=rec_create();
		cout<<"\nEnter Right of:"<<x;
		p->right=rec_create();
		return p;
	}
}
void tree :: rec_preorder(node *p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		cout<<p->data<<" ";
		rec_preorder(p->left);
		rec_preorder(p->right);
	}
}
void tree :: rec_inorder(node *p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		rec_inorder(p->left);
		cout<<p->data<<" ";
		rec_inorder(p->right);
	}
}
void tree :: rec_postorder(node *p)
{
	if(p==NULL)
	{
		return;
	}
	else
	{
		rec_postorder(p->left);
		rec_postorder(p->right);
		cout<<p->data<<" ";
	}
}
void tree :: non_rec_preorder()
{
	node *t=root;
	stack s;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		s.push(t);
		t=t->left;
	}
	while(!s.empty())
	{
		t=s.pop();
		t=t->right;
		while(t!=NULL)
		{
			cout<<t->data<<" ";
			s.push(t);
			t=t->left;
		}
	}
}
void tree :: non_rec_inorder()
{
	node *T=root;
	stack S;
	while(T!=NULL)
	{
		S.push(T);
		T=T->left;
	}
	while(!S.empty())
	{
		T=S.pop();
		cout<<T->data<<" ";
		T=T->right;
		while(T!=NULL)
		{
			S.push(T);
			T=T->left;
		}
	}
}
void tree::non_rec_postorder()
{
	node *t=root;
	Stack_postorder s;
	stacknode st;
	while(t!=NULL)
	{
		st.flag=0;
		st.address=t;
		s.push(st);
		t=t->left;
	}
	while(!s.empty())
	{
		st=s.pop();
		t=st.address;
		if(st.flag==0)
		{
			st.flag=1;
			s.push(st);
			t=t->right;
			while(t!=NULL)
			{
				st.flag=0;
				st.address=t;
				s.push(st);
				t=t->left;
			}
		}
		else if(st.flag==1)
		{
			cout<<t->data<<" ";
		}
	}
}
void tree::BST_display()
{
	node *t=root;
	queue q1,q2;
	cout<<t->data<<" ";
	q1.enqueue(t);
	while(1)
	{
		while(q1.empty()==0)
		{
			t=q1.dequeue();
			if(t->left!=NULL)
			{
				cout<<t->left->data<<" ";
				q2.enqueue(t->left);
			}
			if(t->right!=NULL)
			{
				cout<<t->right->data<<" ";
				q2.enqueue(t->right);
			}
		}
		q1=q2;
		q2.init();
		if(q1.empty()==1)
		{
			break;
		}
	}
}
void tree::non_rec_height()
{
	node *t=root;
	int cnt=0;
	queue q1,q2;
	q1.enqueue(t);
	while(1)
	{
		while(q1.empty()==0)
		{
			t=q1.dequeue();
			if(t->left!=NULL)
			{
				q2.enqueue(t->left);
			}
			if(t->right!=NULL)
			{
				q2.enqueue(t->right);
			}
		}
		q1=q2;
		q2.init();
		if(q1.empty()==1)
		{
			break;
		}
		cnt++;
	}
	cout<<cnt;
}
int tree::height_of_every_node(node *p)
{
	node *t=p;
	queue q1,q2;
	int cnt=0;
	q1.enqueue(t);
	while(1)
	{
		while(q1.empty()==0)
		{
			t=q1.dequeue();
			if(t->left!=NULL)
			{
				q2.enqueue(t->left);
			}
			if(t->right!=NULL)
			{
				q2.enqueue(t->right);
			}
		}
		q1=q2;
		q2.init();
		if(q1.empty()==1)
		{
			break;
		}
		cnt++;
	}
	return cnt;
}
node * tree::search_using_BFT(node *p,int x)
{
	node *t=p;
	queue q1,q2;
	if(t->data==x)
	{
		return t;
	}
	q1.enqueue(t);
	while(1)
	{
		while(q1.empty()==0)
		{
			t=q1.dequeue();
			if(t->left!=NULL)
			{
				if(t->left->data==x)
				{
					q1.init();
					q2.init();
					return t->left;
				}
				q2.enqueue(t->left);
			}
			if(t->right!=NULL)
			{
				if(t->right->data==x)
				{
					q1.init();
					q2.init();
					return t->right;
				}
				q2.enqueue(t->right);
			}
		}
		q1=q2;
		q2.init();
		if(q1.empty()==1)
		{
			break;
		}
	}
	return NULL;
}
int tree::counttotal(node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		int lc,rc;
		lc=counttotal(p->left);
		rc=counttotal(p->right);
		return(1+lc+rc);
	}
}
int tree::countleaf(node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	if(p->left==NULL && p->right==NULL)
	{
		return 1;
	}
	if(p->left==NULL)
	{
		return(countleaf(p->right));
	}
	if(p->right==NULL)
	{
		return(countleaf(p->left));
	}
	return(countleaf(p->left)+countleaf(p->right));
}
int tree::count1(node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	if(p->left==NULL && p->right==NULL)
	{
		return 0;
	}
	if(p->left==NULL)
	{
		return(1+count1(p->right));
	}
	if(p->right==NULL)
	{
		return(1+count1(p->left));
	}
	if(p->left!=NULL && p->right!=NULL)
	{
		return(count1(p->left)+count1(p->right));
	}
}
int tree::count2(node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	if(p->left==NULL && p->right==NULL)
	{
		return 0;
	}
	if(p->left==NULL)
	{
		return(count2(p->right));
	}
	if(p->right==NULL)
	{
		return(count2(p->left));
	}
	if(p->left!=NULL && p->right!=NULL)
	{
		return(1+count2(p->left)+count2(p->right));
	}
}
int tree::rec_height(node *p)
{
	if(p==NULL)
	{
		return 0;
	}
	if(p->left==NULL && p->right==NULL)
	{
		return 0;
	}
	int hl,hr;
	hl=rec_height(p->left);
	hr=rec_height(p->right);
	if(hl>hr)
	{
		return (hl+1);
	}
	else
	{
		return(hr+1);
	}
}
node *tree::rec_search(node *t,int x)
{
	if(t==NULL)
	{
		return NULL;
	}
	if(t->data==x)
	{
		return t;
	}
	else
	{
		node *p;
		p=rec_search(t->left,x);
		if(p==NULL)
		{
			p=rec_search(t->right,x);
		}
		return p;
	}
}
node *tree::find_leaf(node *p)
{
	while(p->left!=NULL || p->right!=NULL)
	{
		if(p->left!=NULL)
		{
			p=p->left;
		}
		else if(p->right!=NULL)
		{
			p=p->right;
		}
	}
	return p;
}
node *tree::delete_rec(node *t,node *p,int done)
{
	if(t==p)
	{
		delete t;
		done=1;
		return NULL;
	}
	if(t->left!=NULL && done==0)
	{
		t->left=delete_rec(t->left,p,done);
	}
	if(t->right!=NULL && done==0)
	{
		t->right=delete_rec(t->right,p,done);
	}
	return t;
}