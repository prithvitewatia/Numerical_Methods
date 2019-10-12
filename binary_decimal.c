#include<stdio.h>
#define ACCURACY 8


int num_digits(int num)
{
    int count=0;
    while(num>0)
    {
        count++;
        num=num/10;
    }
    return count;
}

//returns powers of 10
long int pow_10(int c)
{
    long int num=1;
    if(c>=0)
    {
        for(int i=0;i<c;i++)
        {
            num*=10;
        }
    }
    return num;
}

int main()
{
    //to hold integral and decimal parts of a number
    typedef struct decimal
    {
        int integer_val;
        int dec_part;
        int digits_dp;
    }dec;

    //to hold integral and decimal parts of a binary number
    typedef struct binary
    {
        long int integer_val;
        char dec_part[ACCURACY+1];
    }bin;
    
    dec num_d;
    bin b_num;
    
    printf("Enter a number in base 10\n");
    printf("always write num.0 for integers\n ");
    scanf("%d.%d",&num_d.integer_val,&num_d.dec_part);

    num_d.digits_dp=num_digits(num_d.dec_part);

    b_num.integer_val=0;

    //to calculate the integer par of binary number
    int count=0;
    for(;num_d.integer_val!=1;count++)
    {
        int power=pow_10(count);
        b_num.integer_val=(num_d.integer_val%2)*power+b_num.integer_val;
        num_d.integer_val/=2;
    }
    b_num.integer_val=(num_d.integer_val%2)*pow_10(count)+b_num.integer_val;

    //to calculate decimal part of binary number
    b_num.dec_part[ACCURACY]='\0';
    int update=num_d.dec_part;
    long int precision_adjust=pow_10(num_d.digits_dp);
    for(int i=0;i<ACCURACY;i++)
    {
        b_num.dec_part[i]=update*2/precision_adjust>=1?'1':'0';
        update=(update*2)>=precision_adjust ? update*2%precision_adjust :update*2;
    }
    printf("%ld.%s\n\n",b_num.integer_val,b_num.dec_part);
    return 0;
}