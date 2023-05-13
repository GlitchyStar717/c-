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
    int i,j,k;
    char *string;
    //Heading
    string = "  Jan    |  Feb    |  Mar    |  Apr    |  May    |  Jun    |  Jul    |  Aug    |  Sep    |  Oct    |  Nov    |  Dec    |  Sum    |  Avg    |\n";

    printf("\nEnter your data for : \n");

    for (i = 0; i < years; i++) {
        for (j = 0; j < 12; j++){
            printf("| %-4d |",(start+i));
            for(k = 10*j; k < (10*j)+10; k++){
                printf("%c",string[k]);
            }
            printf("  ");
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
    printf("\nStarting Year: ");
    scanf(" %d", &start);
    printf("Ending year: ");
    scanf( "%d", &end);
    
    int years = end-start+1;

    int expenditure[years][12], sum[years], average[years];



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

    displayExpenditure(years, expenditure, sum, average);

    printf("\n");

    return 0;
}