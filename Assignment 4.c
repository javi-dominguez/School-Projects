//Javier Dominguez
//March 21st 2013
//This program will count the differences
//in a string array from its reverse.

#include <stdio.h>
#include <string.h>
#define MAXLEN 50

int main() {
    char word[MAXLEN+1];
    int i, j, n, k=-1, l=0;

    scanf("%d", &n);
    //Loop n number of times where n is the number of test cases
    for(i=0; i<n; i++){
        scanf("%s", word);
    //Loop j number of times to form the reverse string array
        for(j=strlen(word)-1; j>=0; j--){
            k+=1;
        if(word[k]==word[j])
            l+=1;
    //k and l are used as counters for the difference
    //if statement compares the word at the k'th space
    //versus the word's reverse at the j'th space.
        }
    //resets counters and prints statement
        printf("The word %s differs from its reverse in %d places.\n", word, strlen(word)-l);
        k=-1;
        l=0;

    }

    return 0;
}
