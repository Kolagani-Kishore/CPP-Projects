#include<iostream>

using namespace std;

void add_at_end(int x);
void add_at_start(int y);
void add_at_n(int n, int y);
void del_at_n(int n);
void del_x(int x);
void reverse();
void reverse_recur();
void del_start();
void del_end();
void swap(int x, int y);
void print();
void print_recursion();

struct linkedlist
{
    int data;
    linkedlist* next;
};

linkedlist *head, *recur, *prev1, *current1, *next1;
int list_size;

int main()
{ 
    int b,c,d,e,g;
    char f;
    cout<<"Please enter the number of elements: \n";
    cin>>b;

    for(c = 0; c < b; c++)
    {
        cout<<"Enter the number: \n";
        cin>>d;
        add_at_end(d);
        print();
    }

    cout<<"Do you want to modify the list? Y/N: \t";
    cin>>f;

    if((f == 'Y')||(f == 'y'))
    {
        cout<<"Do you want to add or delete elements? \n1.Add \n2.Delete \n";
        cin>>g;

        if(g ==1)
        {
            cout<<"Choose where to add data: \n"<<"1.Start \n2.End \n3.At nth position \n";
            cin>>c;

            if(c == 1)
            {
                cout<<"Enter the number: \n";
                cin>>d;
                add_at_start(d);
                print();
            }
            else if(c == 2)
            {
                cout<<"Enter the number: \n";
                cin>>d;
                add_at_end(d);
                print();
            }
            else if(c == 3)
            {
                cout<<"Enter the position: \n";
                cin>>e;
                cout<<"Enter the number: \n";
                cin>>d;
                add_at_n(e,d);
                print();
            }
            else
            {
                cout<<"Wrong selection \n";
            }
        }
        else if(g == 2)
        {
            cout<<"Choose where to delete data: \n"<<"1.Start \n2.End \n3.At nth position \n4.Datawise \n";
            cin>>c;

            if(c == 1)
            {
                del_start();
                print();
            }
            else if(c == 2)
            {
                del_end();
                print();
            }
            else if(c == 3)
            {
                cout<<"Enter the position: \n";
                cin>>e;
                del_at_n(e);
                print();
            }
            else if(c == 4)
            {
                cout<<"Enter the data to delete: \n";
                cin>>e;
                del_x(e);
                print(); 
            }
            else 
            {
                cout<<"Wrong selection \n";
            }
        }
    }
    else if((f == 'N')||(f == 'n'))
    {
        cout<<"Here is the list: \n";
        print();
        cout<<"Here is the reverse list: \n";
        current1 = head;
        reverse_recur();
        recur = head;
        print_recursion();
        reverse();
    }
    else
    {
        cout<<"Wrong selection \n";
        cout<<"Here is the list: \n";
        print();
        cout<<"Here is the reverse list: \n";
        reverse();
        print();
        reverse();
    }

    return 0;
}

void add_at_end(int x)
{
    linkedlist* temp = new(linkedlist);
    linkedlist* temp1;

    temp->data = x;
    temp->next = NULL;

    if(head != NULL)
    {
        temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    else
    {
        head = temp;
    }
    list_size++;
}

void add_at_start(int x)
{
    linkedlist* temp = new(linkedlist);

    temp->data = x;
    temp->next = head;
    head = temp;
    list_size++;
}

void add_at_n(int n, int y)
{
    if (n > (list_size + 1))
    {
        cout<<"Position "<<n<<" is greater than list size "<<list_size<<'\n';
    }
    else if (n == (list_size + 1))
    {
        add_at_end(y);
    }
    else if (n == 1)
    {
        add_at_start(y);
    }
    else
    {
        int x;
        linkedlist* temp = new(linkedlist);
        linkedlist* temp1;
        temp->data = y;
        temp1 = head;

        for(x = 0; x < n-2; x++)
        {
            temp1 = temp1->next;
        }
        
        temp->next = temp1->next;
        temp1->next = temp;
        list_size++;
    }
}

void del_start()
{
    linkedlist* temp = head;
    linkedlist* temp1 = new(linkedlist);

    temp1 = temp->next;
    head = temp1;

    delete(temp1);
    list_size--;
}

void del_end()
{
    linkedlist* temp  = head;
    
    for (int a = 0; a < list_size-2; a++)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    list_size--;
}

void del_x(int x)
{
    int b, d;
    linkedlist* temp = head;
    linkedlist* temp1 = head;

    while(temp->data != x)
    {
        temp = temp->next;
        b++;
        if(b == list_size)
        {
            break;
        }
    }

    if(b == list_size)
    {
        cout<<"Given number is not in the list \n";
    }
    else
    {
        for(int c = 0; c < b-1; c++)
        {
            temp1 = temp1->next;
        }

        temp1->next = temp->next;

        delete(temp);
        list_size--;
    }
}

void del_at_n(int x)
{
    linkedlist* temp = head;
    linkedlist* temp1 = head;

    if((x > 1)&&(x <= list_size))
    {
        for(int a = 0; a < x-2; a++)
        {
            temp = temp->next;
        }
        
        temp1 = temp->next;
        temp->next = temp1->next;
        delete(temp1);
        list_size--;
    }
    else if(x == 1)
    {
        del_start();
    }
    else
    {
        cout<<"Position is greater than list size "<<list_size<<'\n';
    }
}

void reverse()
{
    linkedlist *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

}

void reverse_recur()
{
    if(current1 != NULL)
    {
        next1 = current1->next;
        current1->next = prev1;
        prev1 = current1;
        current1 = next1;
        reverse_recur();
    }
    head = prev1;
}

void swap(int x, int y)
{
    linkedlist *temp, *temp1;
    int c;
    temp = head;
    temp1 = head;

    for(int a = 0; a < x-1; a++)
    {
        temp = temp->next;
    }
    
    for(int a = 0; a < y-1; a++)
    {
        temp1 = temp1->next;
    }
    
    c = temp->data;
    temp->data = temp1->data;
    temp1->data = c;
}

void print()
{
    linkedlist* temp;
    temp = head;
    
    while(temp != NULL)
    {
        cout<<temp->data<<'\t';
        temp = temp->next;
    }
    cout<<'\n';
}

void print_recursion()
{
    if(recur != NULL)
    {
        cout<<recur->data<<'\t';
        recur = recur->next;
        print_recursion();
    }
}