#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NEW(type,size) (type*)malloc(sizeof(type)*n)

double get_double(char *a,int l)
{
}

void split(char *s,double *x,double *y,int index)
{
    char str_x[20];
    char str_y[20];

    int i=0;
    while(*s!=' ')
    {
        str_x[i]=*s;
        i++;
        s++;
    }
    str_x[i++]='\0';
    s++;
    i=0;
    while(*s!='\0')
    {
        str_y[i]=*s;
        i++;
        s++;
    }
    str_y[i++]='\0';

    //printf("%s\n",str_x);
    //printf("%s\n",str_y);


}


int main(int argc,char *argv[])
{
    FILE *fp;
    const int n=4;

    double *x_arr=NEW(double,n);
    double *y_arr=NEW(double,n);

    char values[50];

    fp=fopen("xy_val.txt","r");
    if(fp==NULL)
    {
        puts("Cannot open file\n");
        exit(2);
    }
    int index=0;
    while(fgets(values,49,fp)!=NULL)
    {
        split(values,x_arr,y_arr,index);
        index++;
    }

    fclose(fp);

    return 0;
}

