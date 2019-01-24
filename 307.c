#include<stdio.h>
#include<string.h>
#define SIZE 3

struct employee
{
    char name[20];
    int id;
    float salary;
};

struct employee read_employee()
{
    struct employee emp;
    scanf("%s",emp.name);
    scanf("%d",&emp.id);

    while(1)
    {
        scanf("%f",&emp.salary);
        if(emp.salary>=0)break;
    }
    return emp;
}

void read_all_employee(struct employee employee[], int s)
{
    int i;
    for(i=0; i<s; i++)employee[i]=read_employee();
}

void print_employee(struct employee employee)
{
    printf("%s(%d): %f ",employee.name,employee.id,employee.salary);
    if(employee.salary<4000)printf("Level A");
    else if(employee.salary>5000)printf("Level B");
    printf("\n");
}

void print_all_employee(struct employee employee[], int s)
{
    int i;
    for(i=0; i<s; i++)print_employee(employee[i]);
}

float employee_total_salary(struct employee employee[], int s)
{
    int i;
    float total_salary=0;
    for(i=0; i<s; i++)total_salary+=employee[i].salary;
    return total_salary;
}

float search_largest_salary_index(struct employee employee[], int s)
{
    int i,lar;
    lar=0;
    for(i=1; i<s; i++)
    {
        if(employee[i].salary>employee[lar].salary)lar=i;
    }
    return lar;
}

int search_an_employee_salary(struct employee employee[], int s, char str[])
{
    int i;
    for(i=0; i<s; i++)if(strcmp(employee[i].name,str)==0)return i;
    return -1;
}

int main()
{

    int i;
    char str[20];
    struct employee employee[SIZE];
    read_all_employee(employee,SIZE);
    printf("\n_Employee details are\n\n");
    print_all_employee(employee,SIZE);
    printf("\nTotal : %.5f\n\n",employee_total_salary(employee,SIZE));

    printf("Employee with the largest salary is --\n\n");
    i=search_largest_salary_index(employee,SIZE);
    printf("NAME - %s  ID - %d  SALARY - %.5f\n\n\n",employee[i].name,employee[i].id,employee[i].salary);

    printf("_Enter employee name for the search -- ");
    scanf("%s",str);
    i=search_an_employee_salary(employee,SIZE,str);
    if(i==-1)printf("\nArray does not contain an employee named %s\n\n\n",str);
    else printf("\nThe salary of %s is %.5f\n\n\n",str,employee[i].salary);

    printf("_Employee details in reverse order are --\n\n");
    for(i=2; i>=0; i--)print_employee(employee[i]);
    return 0;
}
