//USING MERGE & INSERTION SORT

#include<iostream>
#include<stdbool.h>
using namespace std;

class data
{
private:
    string id,firstname,lastname;
    int credit;
    double cgpa;
public:
    data()
    {
        credit=0;
        cgpa=0.0;
    }
    void input();
    void showdata();
    bool operator > (data);
    void operator=(int);
};

bool data :: operator > (data dd)
{
    if(credit > dd.credit || (credit == dd.credit && cgpa > dd.cgpa))return true;
    return false;
}


void data :: operator=(int inf)
{
    credit=inf;
}

void data :: input()
{
    cin >> id >> firstname >> lastname >> credit >> cgpa;
}

void data :: showdata()
{
    cout << id << "  " << firstname << " " << lastname << "  " << credit << "  " << cgpa << endl;
}

void insertion(data ara[], int num)
{
    int i,j;
    data k;
    for(j=2; j <= num; j++)
    {
        i=j-1;
        k=ara[j];
        while(i > 0 && k > ara[i])
        {
            ara[i+1]=ara[i];
            i--;
        }
        ara[i+1]=k;
    }
}

void Merge(data ara[], int p, int q, int r)
{
    data L[300],R[300];
    int i,j,n1,n2;
    n1=q-p+1;
    n2=r-q;
    for(i=1; i <= n1; i++)
    {
        L[i]=ara[p+i-1];
    }
    for(i=1; i <= n2; i++)
    {
        R[i]=ara[q+i];
    }

    L[n1+1]=-1000000;
    R[n2+1]=-1000000;
    i=j=1;

    for(int k=p; k <= r; k++)
    {
        if(L[i] > R[j])
        {
            ara[k]=L[i];
            i++;
        }
        else
        {
            ara[k]=R[j];
            j++;
        }
    }
}

void mergesort(data ara[], int p, int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        mergesort(ara,p,q);
        mergesort(ara,q+1,r);
        Merge(ara,p,q,r);
    }
}

int main()
{
    data ara[500];

    int num,i,op;
    cin >> num;
    for(i=1; i <= num; i++)ara[i].input();
    cin >> op;

    if(op == 1)
    {
        insertion(ara,num);
        cout << "Using Insertion Sort:" << endl;
    }

    else
    {
        mergesort(ara,1,num);
        cout << "Using Merge Sort:" << endl;
    }

    for(i=1; i <= num; i++)ara[i].showdata();

    return 0;
}
