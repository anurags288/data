#include<iostream>
using namespace std;
template<class T>
class LinkList
{
    class Node
    {
    public:
        T item;
        Node*next;

    };
    Node* first=NULL;

public:
    void addNode(T item1)
    {

        if(first==NULL)
        {
            first=new Node;
            first->item=item1;
        }
        else
        {
            Node*temp=first;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=new Node;
            temp=temp->next;
            temp->item=item1;
        }


    }
    void addAfter(T target,T item1)
    {

        if(first==NULL)
        {
            first=new Node;
            first->item=item1;
        }
        else
        {
            Node*temp=first;
            while(temp!=NULL&&temp->item!=target)
                temp=temp->next;
            if(temp!=NULL)
            {
                Node*p=new Node;
                p->item=item1;
                p->next=temp->next;
                temp->next=p;
            }
            else
                cout<<"Target not found";

        }


    }
    void addBefore(T target,T item1)
    {

        if(first==NULL)
        {
            first=new Node;
            first->item=item1;
        }
        else
        {
            Node*temp=first;
            Node*save=first;
            while(temp!=NULL&&temp->item!=target)
            {
                save=temp;
                temp=temp->next;
            }
            if(temp!=NULL)
            {
                Node*p=new Node;
                p->item=item1;
                if(temp==save)
                {
                    p->next=first;
                    first=p;
                }
                else
                {
                    p->next=save->next;
                    save->next=p;
                }
            }
            else
                cout<<"Target not found";

        }


    }
    void operator +(LinkList<T> r)
    {

     Node * temp=first;
     while(temp->next!=NULL)
      temp=temp->next;
     temp->next=r.first;


    }

    void reverser()
    {
     Node* p=first;
     Node *q =first;
     Node *t =NULL;
     if(first!=NULL)
     {
      p=first->next;
      first->next=NULL;
     }
     while(p!=NULL)
     {
      t=p->next;
      p->next=q;
      q=p;
      p=t;
     }
     first=q;

    }
    void display()
    {
        Node* temp;
        for(temp=first; temp!=NULL; temp=temp->next)
        {
            cout<<temp->item;
            cout<<endl;
        }
    }
    void Ddelete(T target)//delete from first position
    {
        Node* temp,*save;
        temp=save=first;
        while(temp!=NULL&&temp->item!=target)
        {
            save=temp;
            temp=temp->next;
        }
        if(temp==first)
        {
            first=first->next;
            delete temp;
        }

        else if(temp==NULL)
        {
            cout<"\nTarget element not found:";
        }
        else
        {
            save->next=temp->next;
            delete temp;
        }
    }
    void Ddeletep(int p)
    {
        Node* temp,*save;
        temp=save=first;
        int k=-1;
        while(temp!=NULL&&k!=p)
        {
            save=temp;
            temp=temp->next;
            ++k;
        }
        if(temp==first)
        {
            first=first->next;
            delete temp;
        }

        else if(temp==NULL)
        {
            cout<"\nIndex out of bound:";
        }
        else
        {
            save->next=temp->next;
            delete temp;
        }
    }
    void Search(T x)
    {
     int p=0;
     Node * temp=first;
     while(temp!=NULL&&temp->item!=x)
     {
     temp=temp->next;
     ++p;
     }
     if(temp!=NULL)
     {
      cout<<"\nElement found at position:"<<p;

     }
     else
      cout<<"\nNot found";
    }

};
int main()
{
    int ko=0;
    int ki=0;
    LinkList<int> o1;

    do
    {
        cout<<"\nPress 1 to add elements to the list\nPress 2 to delete an element from the list\nPress 3 to display\nPress 4 to reverse the list\nPress 5 to concatenate two link lists\nPress 6 to search for an element\nPress 7 to exit\nEnter your choice ::";
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            do
            {
                cout<<"\nPress 1 to add element at the end\nPress 2 to add element after a target element\nPress 3 to add element before a target element\nPress 4 to display\nPress 5 to go to previous menu\nEnter your choice:";
                int subchoice;
                cin>>subchoice;


                switch(subchoice)
                {

                case 1:
                {
                    int n;
                    cout<<"\nEnter an element to insert::";
                    cin>>n;
                    o1.addNode(n);
                    break;
                }
                case 2:
                {
                    int n;
                    cout<<"\nEnter an element to insert::";
                    cin>>n;
                    int t;
                    cout<<"\nEnter target element::";
                    cin>>t;
                    o1.addAfter(t,n);
                    break;
                }
                case 3:
                {
                    int n;
                    cout<<"\nEnter an element to insert::";
                    cin>>n;
                    int t;
                    cout<<"\nEnter target element::";
                    cin>>t;
                    o1.addBefore(t,n);
                    break;

                }
                case 4:
                {
                    o1.display();
                    break;
                }
                case 5:
                {
                    ki=1;

                    break;
                }
                }
            }
            while(ki!=1);
            break;

        }
        case 2:
        {
            int k3=0;
            do
            {
                cout<<"\nPress 1 to delete a target element\nPress 2 to delete from a position\nPress 3 to go back to previous menu\nEnter your choice::";
                int ch;
                cin>>ch;
                switch(ch)
                {
                case 1:
                {

                    int t;
                    cout<<"\nEnter target element::";
                    cin>>t;
                    o1.Ddelete(t);
                    break;
                }
                case 2:
                {
                    int t;
                    cout<<"\nEnter position::";
                    cin>>t;
                    o1.Ddeletep(t);
                    break;
                }
                case 5:
                {
                    k3=1;

                    break;
                }
                case 3:
                {
                    o1.display();
                    break;
                }


                }
            }
            while(k3!=1);
            break;
        }
        case 3:
            o1.display();
            break;

        case 7:
            ko=1;
            break;
        case 5:
                {
                 LinkList<int> o2;
                 cout<<"\nEnter elements of the linked list, -1 to stop";
                 int p;
                 cin>>p;
                 while(p!=-1)
                 {
                 o2.addNode(p);
                 cin>>p;
                 }
                 o1+o2;
                break;

                }

         case 4:
                {
                 o1.reverser();
                 break;
                }
         case 6:{
                 cout<<"Enter an element to be searched::";
                 int k;
                 cin>>k;
                 o1.Search(k);
                 break;
                 }

        }
    }
    while(ko!=1);
    o1.display();

}



