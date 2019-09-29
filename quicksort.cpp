//QUICKSORT

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class student
{
private:
    int id;
    string firstname, lastname,ph_number;
    double cgpa;

public:
    student()
    {
        id=0;
        cgpa=0.0;
    }
    void input()
    {
        cin>>id>>firstname>>lastname>>cgpa>>ph_number;
    }
    void showdata()
    {
        cout<<id<<"  "<<firstname<<" "<<lastname<<"  "<<cgpa<<"  "<<ph_number<<endl;
    }
    double getcg()
    {
        return cgpa;
    }
};

int last_Partition(student ara[], int p, int r)
{
    student x = ara[r],tmp;
    int i=p-1,j;
    for(j=p; j<r; j++)
    {
        if(ara[j].getcg()<=x.getcg())
        {
            i++;
            tmp=ara[j];
            ara[j]=ara[i];
            ara[i]=tmp;
        }
    }
    tmp=ara[i+1];
    ara[i+1]=ara[r];
    ara[r]=tmp;
    return i+1;
}

void last_quicksort(student ara[], int p, int r)
{
    int q;
    if(p<r)
    {
        q=last_Partition(ara,p,r);
        last_quicksort(ara,p,q-1);
        last_quicksort(ara,q+1,r);
    }
}

int first_Partition(student ara[], int p, int r)
{
    student x = ara[p],tmp;
    int i=r+1,j;
    for(j=r; j>p; j--)
    {
        if(ara[j].getcg()>=x.getcg())
        {
            i--;
            tmp=ara[j];
            ara[j]=ara[i];
            ara[i]=tmp;
        }
    }
    tmp=ara[i-1];
    ara[i-1]=ara[p];
    ara[p]=tmp;
    return i-1;
}

void first_quicksort(student ara[], int p, int r)
{
    int q;
    if(p<r)
    {
        q=first_Partition(ara,p,r);
        first_quicksort(ara,p,q-1);
        first_quicksort(ara,q+1,r);
    }
}

//Randomized Quicksort

void rand_quicksort(student ara[], int p, int r)
{
    int q;
    if(p<r)
    {
        srand(time(NULL));
        int k =p+rand()%(r-p);
        student tmp=ara[k];
        ara[k]=ara[r];
        ara[r]=tmp;
        q = last_Partition(ara,p,r);
        rand_quicksort(ara,p,q-1);
        rand_quicksort(ara,q+1,r);
    }
}

int main()
{
    student inf[100];
    int n,i,op;

    cin>>n;
    for(i=1; i<=n; i++)
        inf[i].input();
    cin>>op;

    if(op==2)
    {
        cout<<"Using Last Partition Quicksort:"<<endl;
        last_quicksort(inf,1,n);
    }
    else if(op==1)
    {
        cout<<"Using First Partition Quicksort:"<<endl;
        first_quicksort(inf,1,n);
    }
    else
    {
        rand_quicksort(inf,1,n);
        cout<<"Using Randomized QuickSort:"<<endl;
    }
    for(i=1; i<=n; i++)
        inf[i].showdata();
    return 0;
}

