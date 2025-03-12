#include<stdio.h>
#include<stdlib.h>
int valid_date(int date, int mon, int year);
int main(void)
{
    int day1, mon1, year1;
    int day2, mon2, year2;
    int day_diff, mon_diff, year_diff;

    printf("Enter start date (DD/MM/YYYY) : ");
    scanf("%d/%d/%d",&day1, &mon1,  &year1);

    printf("Enter end date (DD/MM/YYYY) : ");
    scanf("%d/%d/%d", &day2, &mon2, &year2);

    if(!valid_date(day1, mon1, year1))
    {
        printf("First date is invalid.\n");
    }

    if(!valid_date(day2, mon2, year2))
    {
        printf("Second date is invalid.\n");
        exit(0);
    }

    if(day2 < day1)
    {
        if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12)
        {
           day2 += 30;
        }
        else
        {
           day2 += 30;
        }
        mon2 = mon2 - 1;
    }
    if (mon2 < mon1)
    {
        mon2 += 12;
        year2 -= 1;
    }

    day_diff = day2 - day1;
    mon_diff = mon2 - mon1;
    year_diff = year2 - year1;

    printf("\nDifference: %d years %02d months and %02d days.\n", year_diff, mon_diff, day_diff);
    float interest,no_of_hnrds,interest_amount,amount,per_day,per_dayx;
    printf("Enter the amount : ");
    scanf("%f",&amount);
    float amount1=amount;
    printf("Enter the interest per 100 : ");
    scanf("%f",&interest);
    for(int i=0;i<year_diff;i++)
    {
        no_of_hnrds=amount/(float)100;
        interest_amount=no_of_hnrds*interest*(float)12;
        amount=amount+interest_amount;
        printf("\nAmount after year %d is : %.2f.\t\t------------------(%d)\n",i+1,amount,i+1);
    }
    //for months
    if(mon_diff>=4)
    {
        no_of_hnrds=amount/(float)100;
        interest_amount=no_of_hnrds*interest*(float)mon_diff;
        amount=amount+interest_amount;
        per_day=interest_amount/((float)mon_diff*(float)30);
    }
    else if(mon_diff<4 && mon_diff!=0 && year_diff==0)
    {
        no_of_hnrds=amount/(float)100;
        interest_amount=no_of_hnrds*interest*(float)mon_diff;
        amount=amount+interest_amount;
        per_day=interest_amount/((float)mon_diff*(float)30);
    }
    else if(mon_diff==0)
    {
        per_day=interest_amount/((float)30*(float)12);
    }
    printf("\nAmount after %d years %d months is  :%.2f.\t\t-------------------(%d months)",year_diff,mon_diff,amount,mon_diff);

    per_dayx=per_day*(float)day_diff;
    amount=amount+per_dayx;
    printf("\nAmount after %d years %d months %d days is :%.2f.\t\t-------------------(%d days)",year_diff,mon_diff,day_diff,amount,day_diff);

    printf("\nfor THE AMOUNT of Rs.%f/-.\n",amount1);

    printf("\nThe INTEREST is Rs.%f/-.\n",amount-amount1);

    printf("\n*****************The TOTAL AMOUNT is Rs.%.2f/-.*******************\n",amount);

    return 0;
}
int valid_date(int day, int mon, int year)
{
    int is_valid = 1;
    if (year >= 1800 && year <= 9999)
    {
        if(mon >= 1 && mon <= 12)
        {
            is_valid = 1;
        }
        else
        {
            is_valid = 0;
        }
    }
    else
    {
        is_valid = 0;
    }
    return is_valid;
}
