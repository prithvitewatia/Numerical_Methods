#include<stdio.h>
#include<stdlib.h>

void display_mat(double **mat,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%.2lf ",mat[i][j]);
        }
        printf("\n");
    }
}

void LU_fact(double **input_matrix,int n)
{

    double **lower_mat,**upper_mat;
     //creating lower triangular matrix
    lower_mat=(double**)malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++)
    {
        lower_mat[i]=(double*)malloc(sizeof(double)*n);
        for(int j=0;j<n;j++)
        {
            lower_mat[i][j]=0;
        }
    }


     //creating the upper triangular matrix
    upper_mat=(double**)malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++)
    {
        upper_mat[i]=(double*)malloc(sizeof(double)*n);
        for(int j=0;j<n;j++)
        {
            upper_mat[i][j]=0;
        }
    }

    for(int i=0;i<n;i++)
    {
        //upper triangular matrix
        for(int k=i;k<n;k++)
        {
            double sum1=0;
            for(int s=0;s<i;s++)
            {
                sum1+=(lower_mat[i][s]*upper_mat[s][k]);
            }
            upper_mat[i][k]=input_matrix[i][k]-sum1;
        }

        //lower triangular matrix;
        for(int k=i;k<n;k++)
        {
            if (i == k) 
				lower_mat[i][i] = 1; 
			else 
            { 
				double sum2 = 0; 
				for (int j = 0; j < i; j++) 
					sum2 += (lower_mat[k][j] * upper_mat[j][i]); 
				lower_mat[k][i] = (input_matrix[k][i] - sum2) / upper_mat[i][i]; 
			} 
		}
    }
    printf("Lower triangular matrix is\n\n");
    display_mat(lower_mat,n);
    printf("\n");
    printf("Upper triangular matrix is\n");
    display_mat(upper_mat,n);  
}

int main()
{
    double **input_matrix,**lower_mat,**upper_mat;
    int n;
    printf("Enter the size of matrix\n");
    scanf("%d",&n);
    printf("Enter the matrix\n");

    //taking the input matrix
    input_matrix=(double**)malloc(sizeof(double*)*n);
    for(int i=0;i<n;i++)
    {
        input_matrix[i]=(double*)malloc(sizeof(double)*n);
        for(int j=0;j<n;j++)
        {
            scanf("%lf",&input_matrix[i][j]);
        }
    }

    LU_fact(input_matrix,n);

    return 0;

}