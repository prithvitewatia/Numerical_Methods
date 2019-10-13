#include<stdio.h>

int pow_2(int c)
{
    int num=1;
    while(c--)
    {
        num*=2;
    }
    return num;
}

int len_int(char *b)
{
    int l=0;
    int i=0;
    while(b[i]!='.')
    {
        l++;
        i++;
    }
    return l;

}

int len_dec(char *b)
{
    int ld=0;
    int i=0;
    while(b[i]!='.')
    {
        i++;
    }
    i++;
    while(b[i]!='\0')
    {
        ld++;
        i++;
    }
    return ld;
}

int get_int_val(char *b,int p)
{
    int integer_part=0;
    int index=0;
    int num;
    for(int i=p-1;i>=0;i--)
    {
        num=b[index]-48;            //b[index] contains the ascii values therefore 48 is subtracted which is ascii for 0
        integer_part=num*pow_2(i)+integer_part;
        index++;
    }
    return integer_part;
}

double get_dec_val(char *b,int l)
{
    double dec_part=0;
    while(*b!='.')
    {
        b++;
    }
    b++;
    double num;
    for(int i=1;i<=l;i++)
    {
        num=*b-48;
        dec_part=num/pow_2(i)+dec_part;
        b++;
    }
    return dec_part;


}

int main()
{
    char bin_input[50];
    int l_int,l_dec;
    int base10_int;
    double base10_dec,base10_num;
    scanf("%s",bin_input);
    l_int=len_int(bin_input);
    l_dec=len_dec(bin_input);
    base10_int=get_int_val(bin_input,l_int);
    //printf("%d",base10_int);
    base10_dec=get_dec_val(bin_input,l_dec);
    //printf("%lf",base10_dec);
    base10_num=base10_int+base10_dec;
    printf("%lf",base10_num);
    return 0;



}