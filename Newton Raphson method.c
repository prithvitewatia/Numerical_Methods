#include<stdio.h>
#include<math.h>

double func(double x)
{
    return (((x-2)*x+1)*x-3);      //write your function here in nested form for efficiency
}

double derivative_fx(double x)
{
    return ((3*x-4)*x+1);       //write your function derivative here
}

void Newton_Raphson(double x,int n_steps,float e,float delta)
{
    double fx,fp,d;
    fx=func(x);
    printf("0\t%f\t%f\n",x,fx);
    for(int i=0;i<n_steps;i++)
    {
        fp=derivative_fx(x);
        if(fabs(fp)<delta)
        {
            printf("Small derivative");
            break;
        }
        d=fx/fp;
        x-=d;
        fx=func(x);
        printf("%d\t%f\t%f\n",i+1,x,fx);
        if(fabs(d)<e)
        {
            printf("Convergence");
            break;
        }
    }
}

int main()
{
    double x;
    float delta,epsilon;
    int n;
    printf("Enter initial value Number of Steps Epsilon and Delta\n");
    scanf("%lf %d %f %f",&x,&n,&epsilon,&delta);
    Newton_Raphson(x,n,epsilon,delta);

    return 0;
}
