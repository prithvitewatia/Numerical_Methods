//Gauss Elimination Numerical Method Code

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(float *a,float *b)
{
    float t;
    t=*a;
    *a=*b;
    *b=t;
}

void display_mat(int n,float **mat_ptr)
{
    printf("Matrix is\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("%.2f ", mat_ptr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n;
    float **mat_ptr, *out_matrix;
    printf("Enter N for Matrix ");
    scanf("%d",&n);
    mat_ptr=(float**)malloc(n*sizeof(float));
    printf("Enter Augmented matrix (Size N*(N+1))\n");
    for(int i=0;i<n;i++)
    {
        mat_ptr[i]=(float *)malloc(sizeof(float)*(n+1));
        for(int j=0;j<(n+1);j++)
        {
            scanf("%f",&mat_ptr[i][j]);
        }
    }


    //main code begins here
    for(int k=0;k<n-1;k++)
    {
        int j,m=k;
        for(int j=k+1;j<n;j++)
        {
            if (fabs(mat_ptr[m][k])<fabs(mat_ptr[j][k]))
                m=j;
        }
        if (mat_ptr[m][k]==0)
        {
            printf("No unique solution exists");
            exit(1);
        }
        //exchange row k and row m
        else
        {
            for(int i=0;i<n+1;i++)
                swap(&mat_ptr[k][i],&mat_ptr[m][i]);
            printf("\n");
        }

        if(mat_ptr[n-1][n-1]==0)
        {
            printf("No unique solution exists");
            exit(1);
        }

        //In this part matrix is being converted into upper triangular matrix
        //mul_fctr is the ratio of first term of row being reduced to the
        //first term of the row from which it is being converted
        //In line 82 actual reduction takes place.
        else
        {
            for(int j=k+1;j<n;j++)
            {
                float mul_fctr=mat_ptr[j][k]/mat_ptr[k][k];
                for(int p=k;p<n+1;p++)
                {
                    mat_ptr[j][p]=mat_ptr[j][p]-mul_fctr*mat_ptr[k][p];
                }
            }
        }

    }

    //back substitution
    out_matrix=(float*)malloc(sizeof(float)*n);

    out_matrix[n-1]=mat_ptr[n-1][n]/mat_ptr[n-1][n-1];
    for(int i=n-2;i>=0;i--)
    {
        float sigma_aij_xj=0;
        for(int j=i+1;j<n+1;j++)
        {
            sigma_aij_xj+=mat_ptr[i][j]*out_matrix[j];
        }
        out_matrix[i]=(mat_ptr[i][n]-sigma_aij_xj)/mat_ptr[i][i];
    }

    //displaying the output
    for(int i=0;i<n;i++)
    {
        printf("x%d= %f\n",i+1,out_matrix[i]);
    }

    return 0;
}
