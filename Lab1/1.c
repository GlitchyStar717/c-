#include <stdio.h>
#include <stdlib.h>

// // For Testing Automation
// void generateRandomExpenditure(int lower, int upper, int years, int expenditure[][12])
// {
//     int i,j, num;
//     for (i = 0; i < years; i++) {
//         for (j = 0; j < 12; j++){
//             num = (rand() % (upper - lower + 1)) + lower;
//             expenditure[i][j] = num;
//         }
//     }
// }

void inputExpenditure(int start, int years, int expenditure[2][12])
{
    int i,j;

    //Heading
    printf ("|  Year  |   Jan    |  Feb    |  Mar    |  Apr    |  May    |  Jun    |  Jul    |  Aug    |  Sep    |  Oct    |  Nov    |  Dec    |  Sum    |  Avg    |\n");

    for (i = 0; i < years; i++) {
        printf("|  %-4d|",(start+i));
        for (j = 0; j < 12; j++){
            scanf("%d", &expenditure[i][j]);
        }
        printf("\n");
    }
}

void displayExpenditure(int years, int expenditure[][12], int sum[], int average[])
{
    int i,j;

    //Print Headings
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf ("|  Year  |   Jan    |  Feb    |  Mar    |  Apr    |  May    |  Jun    |  Jul    |  Aug    |  Sep    |  Oct    |  Nov    |  Dec    |  Sum    |  Avg    |");
    
    //Remaining table printing
    for (i = 0; i < years; i++) {
        printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("|    %-4d| ",i+1);
        for (j = 0; j < 12; j++){
            printf(" %-7d |",expenditure[i][j]);
        }
        printf(" %-7d |",sum[i]);
        printf(" %-7d |",average[i]);
        
    }

    printf("\n-------------------------------------------------------------------------------------------------------------------------------------------------------");

}

// // Used for testing
// void displaySumAvg(int years, int sum[], int average[])
// {
//     int i;
//     for (i = 0; i < years; i++) {
//             printf(" %-7d |",sum[i]);
//     }
//     printf("\n");
//     for (i = 0; i < years; i++) {
//             printf(" %-7d |",average[i]);
//     }
// }


void initSumAvg(int years, int sum[], int average[])
{
    int i;

    for (i = 0; i < years; i++) {
        sum[i]=0;
    }
    for (i = 0; i < years; i++) {
        average[i]=0;
    }

}

void calcYearlyExpenditure(int years, int expenditure[][12], int sum[], int average[])
{
    int i,j;
    for (i = 0; i < years; i++) {
        for (j = 0; j < 12; j++){
            sum[i] += expenditure[i][j];
        }
        average[i]=sum[i]/12;
    }
}

int main()
{
    int start, end;
    // printf("Starting Year: ");
    // scanf("%d", &start);
    // printf("Ending year: ");
    // scanf("%d", &end);
    int years=2;
    int expenditure[years][12], sum[years], average[years];

    printf("Starting Year: ");
    scanf("%d", &start);
    printf("Ending year: ");
    scanf("%d", &end);
    years = end-start+1;



    // int lower = 100000, upper = 1000000;
    
    // For Testing Automation
    // generateRandomExpenditure(lower, upper, years, expenditure);

    inputExpenditure(start, years, expenditure);

    // // I forgot what I used this for
    // monthlyExpenditures(years, expenditure);

    initSumAvg(years, sum, average);

    calcYearlyExpenditure(years, expenditure, sum, average);

    // Testing Purpose
    // displaySumAvg(years, sum, average);

    printf("\n\n");

    displayExpenditure(years, expenditure, sum, average);


    return 0;
}