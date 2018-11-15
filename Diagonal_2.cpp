#include<iostream>
using namespace std;
#define Max 50
int arr[Max];
int n;
void SetD()
{
    cout<<"Enter the value of n:";
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cout<<"Enter the value at " <<i<<","<<i<<":";
        cin>>arr[i];
    }
}
void SetL()
{
    cout<<"Enter the value of n:";
    cin>>n;
    int k=0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<=i; ++j)
        {
            cout<<"Enter the value at " <<i<<","<<j<<":";
            cin>>arr[k++];
        }
}
void SetS()
{
    cout<<"Enter the value of n:";
    cin>>n;
    int k=0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<=i; ++j)
        {
            cout<<"Enter the value at " <<i<<","<<j<<":";
            cin>>arr[k++];
        }
}
void SetU()
{
    cout<<"Enter the value of n:";
    cin>>n;
    int k=0;
    for(int i=0; i<n; ++i)
        for(int j=i; j<n; ++j)
        {
            cout<<"Enter the value at " <<i<<","<<j<<":";
            cin>>arr[k++];
        }
}
void SetTD()
{
    cout<<"Enter the value of n:";
    cin>>n;
    int k=0;
    for(int i=2; i<=n; ++i)
    {
        cout<<"Enter the value at " <<i<<","<<i-1<<":";
        cin>>arr[k++];
    }
    for(int i=1; i<=n; ++i)
    {
        cout<<"Enter the value at " <<i<<","<<i<<":";
        cin>>arr[k++];
    }
    for(int i=2; i<=n; ++i)
    {
        cout<<"Enter the value at " <<i-1<<","<<i<<":";
        cin>>arr[k++];
    }
}

int GetD(int i,int j)
{


    if(i!=j)
        return 0;
    else
        return arr[i];

}
int GetL(int i,int j)
{
    if(j>i)
        return 0;
    else
    {
        return arr[i*(i+1)/2 +j];
    }
}
int GetS(int i,int j)
{
    if(j>i)
        return arr[j*(j+1)/2 +i];
    else
    {
        return arr[i*(i+1)/2 +j];
    }
}
int GetU(int i,int j)
{
    if(j<i)
        return 0;
    else
    {
        return arr[(n*(n+1)-(n-i)*(n-i+1))/2+j-i];
    }
}
int GetTD(int i,int j)
{

    switch(i-j)
    {
    case 1:
        return arr[i-2];
        break;
    case 0:
        return arr[n+i-2];
        break;
    case-1:
        return arr[2*n+i-2];
        break;
    default:
        return 0;
        break;



    }

}
void displayD()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cout<<GetD(i,j)<<" ";
        }
        cout<<endl;
    }
}
void displayS()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cout<<GetS(i,j)<<" ";
        }
        cout<<endl;
    }
}
void displayTD()
{
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            cout<<GetTD(i,j)<<" ";
        }
        cout<<endl;
    }
}
void displayL()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cout<<GetL(i,j)<<" ";
        }
        cout<<endl;
    }
}
void displayU()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cout<<GetU(i,j)<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int k;
    do
    {
        int i=0,j=0;
        k=0;
        cout<<"\n1-->Diagonal\n2-->Upper Diagonal\n3-->Lower Diagonal\n4-->Symmetric\n5-->Tridiagonal\n6-->Quit,\nEnter your choice::";
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            SetD();
            displayD();
            i=0;
            j=0;
            cout<<"\nEnter the index values,-1,-1 to stop";
            while(i!=-1&&j!=-1)
            {
                cout<<"\nEnter index i::";
                cin>>i;
                cout<<"\nEnter index j::";
                cin>>j;
                if(i>=0&&i<n&&j>=0&&j<n)
                    cout<<GetD(i,j);
                else if(i!=-1&&j!=-1)
                    cout<<"invalid input";
                else;
            }
            break;

        case 2:
            SetU();
            displayU();
            i=0;
            j=0;
            cout<<"\nEnter the index values,-1,-1 to stop";
            while(i!=-1&&j!=-1)
            {
                cout<<"\nEnter index i::";
                cin>>i;
                cout<<"\nEnter index j::";
                cin>>j;
                if(i>=0&&i<n&&j>=0&&j<n)
                    cout<<GetU(i,j);
                else if(i!=-1&&j!=-1)
                    cout<<"invalid input";
                else;
            }
            break;
        case 3:
            SetL();
            displayL();
            i=0;
            j=0;
            cout<<"\nEnter the index values,-1,-1 to stop";
            while(i!=-1&&j!=-1)
            {
                cout<<"\nEnter index i::";
                cin>>i;
                cout<<"\nEnter index j::";
                cin>>j;
                if(i>=0&&i<n&&j>=0&&j<n)
                    cout<<GetL(i,j);
                else if(i!=-1&&j!=-1)
                    cout<<"invalid input";
                else;
            }
            break;
        case 4:
            SetS();
            displayS();
            i=0;
            j=0;
            cout<<"\nEnter the index values,-1,-1 to stop";
            while(i!=-1&&j!=-1)
            {
                cout<<"\nEnter index i::";
                cin>>i;
                cout<<"\nEnter index j::";
                cin>>j;
                if(i>=0&&i<n&&j>=0&&j<n)
                    cout<<GetS(i,j);
                else if(i!=-1&&j!=-1)
                    cout<<"invalid input";
                else;
            }
            break;
        case 5:
            SetTD();
            displayTD();
            i=0;
            j=0;
            cout<<"\nEnter the index values,-1,-1 to stop";
            while(i!=-1&&j!=-1)
            {
                cout<<"\nEnter index i::";
                cin>>i;
                cout<<"\nEnter index j::";
                cin>>j;
                if(i>=1&&i<=n&&j>=1&&j<=n)
                    cout<<GetTD(i,j);
                else if(i!=-1&&j!=-1)
                    cout<<"invalid input";
                else;
            }
            break;
        case 6:
            k=1;
            break;
        }
    }
    while(k!=1);
}



