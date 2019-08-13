#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float func(float x)
{
    return (pow(x,3)-3*x+1);   //write your function here
}

int same_sign(float v1,float v2)
{
    if((v1>=0&&v2>=0)||(v1<=0&&v2<=0))
        return 1;
    else
        return 0;
}

void bisection(float a,float b,int n_steps,float tol)
{
    float fa,fb,c,fc,error_val;
    fa=func(a);
    fb=func(b);
    if(same_sign(fa,fb))
    {
        printf("%f %f %f %f\n",a,b,fa,fb);
        printf("Function has same sign at a and b");
        exit(1);
    }
    error_val=b-a;
    printf("Iteration Solution\tValue\t\tError\n");
    for(int i=0;i<n_steps;i++)
    {
        error_val/=2;
        c=a+error_val;
        fc=func(c);
        printf("%d\t%f\t%f\t%f\n",i+1,c,fc,error_val);
        if(error_val<tol)
        {
            printf("Convergence\n");
            break;
        }
        if (!(same_sign(fa,fc)))
        {
            b=c;
            fb=fc;
        }
        else
        {
            a=c;
            fa=fc;
        }
    }

}

int main()
{
    float a,b,e;
    int n_steps;
    printf("Enter range [a,b] as a b number of iterations and tolerance\n");
    scanf("%f %f %d %f",&a,&b,&n_steps,&e);
    printf("\n");
    bisection(a,b,n_steps,e);

    return 0;
}
