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
    float fa,fb,c,fc,c_old;
    int i=0;
    fa=func(a);
    fb=func(b);
    if(same_sign(fa,fb))
    {
        printf("%f %f %f %f\n",a,b,fa,fb);
        printf("Function has same sign at a and b");
        exit(1);
    }
    printf("Iteration Solution\tValue\n");
    for(;i<n_steps;)
    {
        c=(a*fb-b*fa)/(fb-fa);
        if(i==0)
        {
            c_old=c;
        }
        else
        {
            if(c==c_old)
            {
                if(!(same_sign(fa,fb)))
                    c=(a*fb-2*b*fa)/(fb-2*fa);
                else
                    c=(2*fb*a-b*fa)/(2*fb-fa);
            }
        }

        fc=func(c);
        printf("%d\t%f\t%f\n",i+1,c,fc);
        if(fabs(fc)<tol)
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
        i+=1;
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
