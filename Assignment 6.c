// Javier Dominguez
// March 31st 2013
// This program calculates the profitability of an employee
// in regards to the rules set by the company.

#include <stdio.h>
#define MAXLEN 100

// Prototypes set for the functions.
void increaseProfit(int arr[], int index, int increase);
int calculatePerformance(int arr[], int index, int size);

int main(){

int nArr[MAXLEN+1], n, i, j, q, change_amount, query_type, total;

    // Scanning for n number of employees. Storing into array.
    scanf("%d", &n);
        for(i=0;i<n;i++){
        scanf("%d", &nArr[i]);
        }

    // Scanning for q number of queries.
    scanf("%d", &q);
        for(i=0;i<q;i++){
            // Asking for user input for query type.
            scanf("%d", &query_type);
            if(query_type == 2){
                scanf("%d", &j);
                total = calculatePerformance(nArr, j, n);
                printf("Employee #%d's performance is %d.\n", j, total);
                total = 0;}
            if(query_type == 1){
                scanf("%d", &j);
                scanf("%d", &change_amount);
                increaseProfit(nArr, j, change_amount);
                printf("Employee #%d's profit increased by %d.\n", j, change_amount);
                change_amount = 0;}
            }

return 0;
}

// This function is used to change the array at the indexed
// place by the increase amount.
void increaseProfit(int arr[], int index, int increase){
    arr[index] += increase;
}

// This function is used to print out employee total given
// the index place of the employee and the sum of all other employees
// after that place.
int calculatePerformance(int arr[], int index, int size){

    int sum=0;

    for(index;index<size;index++){
        sum += arr[index];
    }
    return sum;

}
