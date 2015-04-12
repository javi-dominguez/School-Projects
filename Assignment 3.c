// Javier Dominguez
// February 17th 2013
// This program will analyze a flight plan with a total number of flight
// minutes and total number layover minutes. It will print out whether
// the plan is efficient according to the total number of flight & layover
// minutes. Additionally, it will print the destination time.


#include <stdio.h>

int main() {

    int curCase, numFlights, totalFlight, flight, totalLayover, layover, hour, minute, totalMin, desHour, desMin, minOfDay;

    // Scans for the number of flights and the departure time.
    scanf("%d", &numFlights);
    scanf("%d %d", &hour, &minute);

    // Sets variables to 0 before loop. Minute of day is set.
    totalMin = 0;
    totalFlight = 0;
    totalLayover = 0;
    minOfDay = ((hour*60)+minute);


    // Loops n number of times, asking for flight/layover times up until
    // the max number of flights is reached.
    for(curCase = 1; curCase <= numFlights; curCase++){

        // Calculates and scans for both flight and layover if this isn't
        // the final flight.
        if(curCase < numFlights){
            scanf("%d %d", &flight, &layover);
            totalMin += flight + layover;
            totalFlight += flight;
            totalLayover += layover;
        }

        // Calculates and scans for just the flight if this is the final flight.
        else if(curCase = numFlights){
            scanf("%d", &flight);
            totalMin += flight;
            totalFlight += flight;
        }

    }

    // Sets the destination HH:MM time in regards to the total number of time
    // spent in the flight plan.
    desHour = ((minOfDay+totalMin)/60)%24;
    desMin = (minute+totalMin)%60;

    // Prints that the flight plan is efficient only if the total flight time
    // is greater than or equal to two times the total layover time.
        if(totalFlight >= 2*(totalLayover))
            printf("This flight plan is efficient, and will conclude at %02d:%02d.\n", desHour, desMin);
    // Prints that the flight plan is ineffcient if the previous terms were not met.
        else if(totalFlight < 2*(totalLayover))
            printf("This flight plan is inefficient, and will conclude at %02d:%02d.\n", desHour, desMin);

    return 0;
}
