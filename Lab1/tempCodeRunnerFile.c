// For Testing Automation
void generateRandomExpenditure(int lower, int upper, int years, int expenditure[][12])
{
    int i,j, num;
    for (i = 0; i < years; i++) {
        for (j = 0; j < 12; j++){
            num = (rand() % (upper - lower + 1)) + lower;
            expenditure[i][j] = num;
        }
    }
}