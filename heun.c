#include<stdio.h>
#define STEP_SIZE 0.001

double f(double x,double y)
{
    return x+y;
}

int main()
{
    double x0,y0;
    int n;
    printf("Enter the initial values x0,y0 and number of steps\n");
    scanf("%lf %lf %d",&x0,&y0,&n);

    double k1=0,k2=0;
    double x,y=y0;

    for(int i=0;i<n;i++)
    {
        x=x0+i*STEP_SIZE;
        k1=STEP_SIZE*f(x,y);
        k2=STEP_SIZE*f(x+STEP_SIZE,y+k1);
        printf("%lf\t%lf\n",x,y);
        y=y+(k1+k2)/2;
        
    }
    return 0;
}