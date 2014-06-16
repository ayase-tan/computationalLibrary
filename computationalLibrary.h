#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include<windows.h>
#include<cstdlib>
#include<string.h>

using namespace std;

typedef struct node
         { int data;
           struct node *kanan,*kiri;
           }*tree;

typedef struct stack_node
         { int data;
           struct stack_node *next;
           } *stack;

typedef struct queue_node
         { int data;
           struct queue_node *next;
           } *node_;

typedef struct
         { node_ front,rear;
           } queue;

typedef struct node
{
    struct node *next;
    int vertex, berat;
} node;

//1
void swap(int &a,int &b)
{
  int t;
  t=a;a=b;b=t;
}
//2
void printArray(int x[],int n)
{int i;
 for (i=0;i<n;i++) {
    cout<<x[i]<<" ";
   }
 cout<<endl;
 cout<<endl;
}
//3
void bubbleSort(int x[],int n)
{int i,j,t ;
 for (i=1;i<=n-1;i++)
  for (j=1;j<=n-i;j++) {
   if (x[j]>x[j+1]) swap(x[j],x[j+1]);
  }
}
//4
void insertionSort(int x[],int n)
{int i,j,a;
    for(int i=2;i<=n;i++){
      j=i-1; a=x[i];
      while (j>0 && x[j]>a)
       { x[j+1]=x[j];
         j--;
       }
       x[j+1]=a;
       cout<<endl;
     }
}
//5
void partisi(int x[],int first,int last,int &j)
{ int i,t,pivot;
  pivot=x[first];
  i=first;j=last;
  while (i<j){
    while ((i<last)&&(x[i]<=pivot)) i++;
    while ((j>first)&&(x[j]>pivot)) j--;
    if (i<j) {t=x[i];x[i]=x[j];x[j]=t;}
  }
  x[first]=x[j];x[j]=pivot;
}
//6
void quickSort(int x[],int first,int last)
{int j;
  if (first<last) {
     partisi(x,first,last,j);
     quickSort(x,first,j-1);
     quickSort(x,j+1,last);
  }
}
//7
void merge(int x[], int first,int mid,int last)
{int z[1000];
  int i,j,k,l;
  i=first; j=mid+1;  k=first;
  do {
    if(x[i]<=x[j]) {z[k]=x[i];i++;}
    else {z[k]=x[j];j++;}
    k++;}
  while ((i<=mid) && (j<=last));
  if (i>mid) for (l=j;l<=last;l++) {z[k]=x[l];k++;}
  else for (l=i;l<=mid;l++) {z[k]=x[l];k++;}
  for (k=first;k<=last;k++) x[k]=z[k];
}
//8
void mergeSort(int x[],int first,int last)
{int mid;
  if(first<last) {
    mid =(first+last)/2;
    mergesort(x,first,mid);
    mergesort(x,mid+1,last);
    merge(x,first,mid,last);
  }
}
//9
void initQueue(queue &Q)
{
  Q.front = NULL; Q.rear=NULL;
}
//10
void enqueue(queue &Q,int x)
{
 node_ b;
   b=new queue_node;
   b->next=NULL;
   b->data=x;
   if (Q.rear==NULL) {Q.front=b;Q.rear=b;}
   else { Q.rear->next=b;
          Q.rear = b;
   }
}
//11
void dequeue(queue &Q,int &x)
{node_ t;
  if (Q.front!=NULL) {
    x=Q.front->data;
    t=Q.front;
    Q.front=t->next;
    free(t);
    if(Q.front==NULL) Q.rear=NULL;
  } else cout<<"Empty\n";
}
//12
void printQueue(queue Q)
{ node_ t;
   if(Q.front!=NULL) {
      t=Q.front;
      while(t!=NULL) {
         cout<<t->data<<" ";
         t=t->next;
      }
   cout<<endl;
  }
}
//13
void initStack(stack &S)
{ S = NULL;
}
//14
void push(stack &S,int x)
{
 stack b;
   b=new stack_node;
   b->next=NULL;
   b->data=x;
   if (S==NULL) S=b;
   else {b->next=S;
         S=b;}
}
//15
void pop(stack &S,int &x)
{stack t;
  if (S!=NULL) {
    x=S->data;
    t=S;
    S=t->next;
    free(t);
   } else cout<<"Empty";
}
//16
void printStack(stack l)
{stack p;
  if (l!=NULL) {
    p=l;
    while (p!=NULL) {
      cout<<p->data<<" \n";
      p=p->next;
    }
    cout<<endl;
  }
}
//17
void initBst(tree &T){
  T = NULL;
}
//18
void inputBst(tree &T,int x)
{ tree b;
  if (T==NULL) {
     b=new node;b->data=x;b->kanan=NULL;b->kiri=NULL;
     T=b;}
  else if(x < T->data) bst(T->kiri,x);else
    if (x>T->data) bst(T->kanan,x);
}
//19
void removeNode(tree &T,tree &t,tree s)
{
    if(t->kiri==NULL&&t->kanan==NULL)
    {
        if(s==NULL){T=NULL; delete t; return;}
        if(s->kiri==t)
            s->kiri=NULL;
        if(s->kanan==t)
            s->kanan=NULL;
        delete t;
    }
    else if(t->kiri==NULL&&t->kanan!=NULL)
    {
      if(s==NULL){T=t->kanan; delete t; return;}
        if(s->kiri==t)
            s->kiri=t->kanan;
        if(s->kanan==t)
            s->kanan=t->kanan;
        delete t;
    }
    else if(t->kiri!=NULL&&t->kanan==NULL)
    {
        if(s==NULL){T=t->kiri; delete t; return;}
        if(s->kiri==t)
            s->kiri=t->kiri;
        if(s->kanan==t)
            s->kanan=t->kiri;
        delete t;
    }
    else if(t->kiri!=NULL&&t->kanan!=NULL)
    {
        tree ss;
        ss=t;
        s=t->kanan;
        while(s->kiri!=NULL)
        {
          ss=s;
          s=s->kiri;
        }
        t->data=s->data;
        removeNode(T,s,ss);
    }
}
//20
void remove(tree &T){
    tree s=NULL,t=T;
    int x; bool found;
    cout<<"Masukan nilai yang dihapus: "; cin>>x;
    if(T==NULL)
    {
        cout<<"Pohon kosong"<<endl;
        return;
    }
    while(t!=NULL)
    {
         if(t->data==x)
         {
            found=true;
            break;
         }
         else
         {
             s=t;
             if(x>t->data) t=t->kanan;
             else t=t->kiri;
         }
    }
    if(!found)
    {
        cout<<"Tidak ditemukan"<<endl;
        return;
    }
    removeNode(T,t,s);
}
//21
void preOrder(tree T)
{
  if (T!=NULL) {
     cout<<T->data<<" ";
     preOrder(T->kiri);
     preOrder(T->kanan);
  }
}
//22
void inOrder(tree T)
{
  if (T!=NULL) {
     inOrder(T->kiri);
     cout<<T->data<<" ";
     inOrder(T->kanan);
  }
}
//23
void postOrder(tree T)
{
  if (T!=NULL) {
     postOrder(T->kiri);
     postOrder(T->kanan);
     cout<<T->data<<" ";
}
}
//24
void goToXY(int x, int y)
{
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//25
void linearSearch(int n[], int x, int panjangArray)
{
     for(int i =0;i<panjangArray;i++)
             if(n[i]==x) cout<<"Data ditemukan di Array ke-"<<i<<endl;
     }
}
//26
void createEmptyGraph (int nodegraph)
{
    int i,j;
    for (i=1;i<=nodegraph;i++)
    {
        for (j=1;j<=nodegraph;j++)
        {
            adjlistgraph [i] [j] = 0;
        }
    }
}
//27
void insertEdge(int jmlinsert)
{
    int tujuan,awal,weight,k;
    for (k=1;k<=jmlinsert;k++)
    {
        cin >> awal;
        cin >> tujuan;
        cin >> weight;
        adjlistgraph [awal] [tujuan] = weight;
    }
}
//28
void detectEdge(int awal, int tujuan)
{
    int p = adjlistgraph [awal] [tujuan];
    if (p == 0) cout << "tidak terhubung";
    else cout << "terhubung";
}
//29
void deleteEdge(int awal, int tujuan)
{
    if (adjlistgraph [awal] [tujuan] != 0) adjlistgraph [awal] [tujuan] = 0;
    else cout << "vertex tidak terhubung";
}
//30
void printGraph (int nodegraph)
{
    for (int i=1;i<=nodegraph;i++)
    {
        for (int j=1;j<=nodegraph;j++)
        {
            cout << adjlistgraph [i] [j] << " ";
        }
        cout << endl;
    }
}
//31
void binarySearch(int n[], int x, int awal, int akhir)
{
     int tengah=(awal+akhir)/2;
     if (n[tengah]==x) cout<<"Data ditemukan di Array ke-"<<tengah<<endl; 
     else if (awal==akhir) <<"Data tidak ada"<<endl;
     else if(n[tengah]<x) binary(n, x,tengah+1, akhir); 
     else if(n[tengah]>x) binary(n, x,awal, tengah-1);     
}
//32
void hammingCode()
{
  int i,a[4],c[3],r[7],clk[3],n,sum=0;
    printf("Enter data bits\n");

    for(i=3;i>=0;i--)
        scanf("%d",&a[i]);
    printf("\n");

    c[0]=(a[0]+a[1]+a[2])%2;
    c[1]=(a[1]+a[2]+a[3])%2;
    c[2]=(a[1]+a[0]+a[3])%2;

    printf("data bits after hamming code is\n");

    for(i=3;i>=0;i--)
        printf("%d",a[i]);
    for(i=2;i>=0;i--)
        printf("%d",c[i]);

}

//33
void hammingDistance(int start, int k, string bit, int length)

{
  if(k==0){
    cout<<bit<<endl;
        return;
          }
  if(k>1 && start==length-1)
    return;
    if(start>length-1)
        return;
    ham(start+1,k,bit,length);  
    if(bit.at(start) =='0'){        
        bit.replace(start, 1, "1");
        ham(start+1, k-1, bit, length);
                           }
    else if(bit.at(start)=='1')
    {   
        bit.replace(start,1,"0");
        ham(start+1,k-1,bit,length);
    }
}

//34

void Dijkstra(int startnode,int n)
{
    int dist[100],pred[100],visit[100],min_dist,nextnode;
    int count=0;
    node *a;
    for(int i=0; i<n; i++)
    {
        dist[i]=inf;
        pred[i]=startnode;
        visit[i]=0;
    }
    dist[startnode]=0;
    while(count < n-1)
    {
        min_dist=inf;
        for(int i=0; i<n; i++)
        {
            if(dist[i] < min_dist && !visit[i])
            {
                min_dist=dist[i];
                nextnode=i;
            }
        }
        visit[nextnode]=1;
        a=g[nextnode];
        while(a!=NULL)
        {
            if(!visit[a->vertex])
            {
                if(min_dist+(a->berat) < dist[a->vertex])
                {
                    dist[a->vertex]=min_dist+(a->berat);
                    pred[a->vertex]=nextnode;
                }
            }
            a=a->next;
        }
        count++;
    }
    print(startnode,dist,pred,n);
}

//35
void printDijkstra(int startnode,int dist[],int pred[],int n)
{
    cout << "Jarak Terpendek";
    cout << "\t\t Jalan Terpendek" << endl;
    for(int i=0; i<n; i++)
    {
        if(i != startnode)
        {
            cout << "  " << startnode << " --> " << i << " = " << dist[i];
            if(dist[i]!=inf)
            {
                cout << "\t\t" << i;
                int j=i;
                do
                {
                    j=pred[j];
                    cout << "--" << j;
                }
                while(j!=startnode);
            }
            else
            {
                cout << "\t\tnone";
            }
            cout << endl;
        }
    }
}

//36
void insertDjikstra(int src,int dest,int berat,node *g[])
{
    node *a,*b,*x,*y;
    b=(node *)malloc(sizeof(node));
    b->vertex=dest;
    b->next=NULL;
    b->berat=berat;
    if(g[src]==NULL)
    {
        g[src]=b;
    }
    else
    {
        a=g[src];
        while(a->next!=NULL)
        {
            a=a->next;
        }
        a->next=b;
    }
    //supaya undirect g
    y=(node *)malloc(sizeof(node));
    y->vertex=src;
    y->next=NULL;
    y->berat=berat;
    if(g[dest]==NULL)
    {
        g[dest]=y;
    }
                else
                {
                    x=g[dest];
                    while(x->next!=NULL)
                    {
                        x=x->next;
                    }
                    x->next=y;
                }
}



