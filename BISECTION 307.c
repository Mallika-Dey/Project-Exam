
//BISECTION METHOD

#include<stdio.h>
#include<math.h>
#define EPS .000001

float f(float x)
{
    return ((x*x)-(4*x)-10);
}

int main()
{
    float x1,x2,xo,flag;

    printf("x1=");
    scanf("%f",&x1);
    printf("\nx2=");
    scanf("%f",&x2);

    if(f(x1)*f(x2)>0)printf("No root\n");

    else
    {
        flag=0;
        while(flag!=1)
        {
            xo=(x1+x2)/2.0;
            if(f(xo)*f(x1)<0)x2=xo;
            else x1=xo;
            printf("x1=%.7f \tx2=%.7f\n",x1,x2);
            if(f(xo)==0)
            {
                printf("%.7f\n",xo);
                break;
            }
            if(fabs((x2-x1)/x2)<EPS)
            {
                printf("%.7f\n",(x1+x2)/2);
                flag=1;
            }
        }

    }
    return 0;
}
