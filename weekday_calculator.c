#include <stdio.h>
#include <stdlib.h>

int day_calculator(int q, int m, int k, int j){                                               //
                                                                                             //This function calculate the weekday!
    int real_day = (q + (13 * ((m + 1)) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7;         //
    return real_day;


}


int main(){

    int q; //day
    int m; //month
    int k; //last two digits of century
    int j; //zero based century
    int x; //year
    int end_year;


    printf("Enter date [year month day]:");
    scanf("%d %d %d", &x, &m, &q);

    int constant_x = x;


    if (m > 12){                                                                   //lines between line 29 and 62 for handling the errors!
        fprintf(stderr,"Invalid date.\n");
        exit(EXIT_SUCCESS);
    }


    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){     //lines between line 29 and 62 for handling the errors!
        if(q > 31 || q < 1){
            fprintf(stderr,"Invalid date.\n");
            exit(EXIT_SUCCESS);
        }
    }

    else if ( m == 2){
        if((constant_x % 4) == 0){                                                  //lines between line 29 and 62 for handling the errors!
            if(q > 29 || q < 1){
                fprintf(stderr,"Invalid date.\n");
                exit(EXIT_SUCCESS);
            }
        }
        else{
            if(q > 28 || q < 1){
                fprintf(stderr,"Invalid date.\n");
                exit(EXIT_SUCCESS);
            }
        }
    }

    else{
        if(q > 30 || q < 1){
            fprintf(stderr,"Invalid date.\n");
            exit(EXIT_SUCCESS);                                                     //lines between line 29 and 62 for handling the errors!
        }
    }





    printf("Enter end year:");
    scanf("%d", &end_year);


    if (m == 1){
        m = m + 12;
        x = x - 1;
    }

    if (m == 2){
        m = m + 12;
        x = x - 1;
    }

    k = x % 100;
    j = x / 100;

    int real_day = day_calculator(q, m, k, j);





    if (real_day == 0){
        printf("It's a Saturday.\n");
    }
    else if (real_day == 1){
        printf("It's a Sunday.\n");
    }
    else if (real_day == 2){
        printf("It's a Monday.\n");
    }
    else if (real_day == 3){
        printf("It's a Tuesday.\n");
    }
    else if (real_day == 4){
        printf("It's a Wednesday.\n");
    }
    else if (real_day == 5){
        printf("It's a Thursday.\n");
    }
    else{
        printf("It's a Friday.\n");
    }

    int for_while_start_year = x + 1;

    int checking_days_between;
    int i = 0;
    int first_two;
    int last_two;

    while (for_while_start_year  <= end_year){                             //
        first_two = for_while_start_year / 100;                            //
        last_two = for_while_start_year % 100;                             //here the program calculates number of same same weekdays which are have same month and day

        checking_days_between = day_calculator(q, m, last_two, first_two); //
        if (checking_days_between == real_day){
            i = i + 1;
        }
        for_while_start_year++;

    }
    printf("Same day-and-month on same weekday between %d and %d: %d\n", constant_x, end_year, i);













    return 0;
}