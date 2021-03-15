#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct tutu{
    char* name;
    int number;
    char* departure;
    char* arrival;
    int departureminuts;
    int arrivalhours;
    int departurehours;
    int arrivalminuts;
};

struct tutu travel;
struct tutu* scan_d(struct tutu * , int);
struct tutu* rand_route(struct tutu * , int);
void print(struct tutu * , int );
void swap(struct tutu *, int, int);
void QckSort(struct tutu *, int);
void file_out(FILE*, struct tutu *, int);
//void print_(struct tutu *, int);
int main() {
    int n = 3;
    struct tutu * travel =  (struct tutu *)malloc(n  * sizeof(struct tutu));
    FILE* f = NULL;
    (*travel).name = "Sapsan";
    (*travel).number = 575;
    (*travel).departure = "Moscow";
    (*travel).arrival = "SpB";
    (*travel).departureminuts = 15;
    (*travel).arrivalhours = 12;
    (*travel).departurehours = 9;
    (*travel).arrivalminuts = 30;
    (*(travel + 1)).name = "Firmenniy";
    (*(travel + 1)).number = 578;
    (*(travel + 1)).departure = "Moscow";
    (*(travel + 1)).arrival = "Kiev";
    (*(travel + 1)).departureminuts = 23;
    (*(travel + 1)).arrivalhours = 12;
    (*(travel + 1)).departurehours = 9;
    (*(travel + 1)).arrivalminuts = 30;
    (*(travel + 2)).name = "Skoriy";
    (*(travel + 2)).number = 580;
    (*(travel + 2)).departure = "Moscow";
    (*(travel + 2)).arrival = "Kaliningrad";
    (*(travel + 2)).departureminuts = 10;
    (*(travel + 2)).arrivalhours = 12;
    (*(travel + 2)).departurehours = 22;
    (*(travel + 2)).arrivalminuts = 30;
    int c;
    
    do
    {
        printf("Enter 0, if you want print regular timetable, enter 1, if you want to fill in the timetable, enter 2, if you want to see an arbitraty (random) timetable \n");
        scanf("%d", &c);
    } while (c != 0 && c != 1 && c != 2 );
    
    switch (c)
    {
        case 0:
            QckSort(travel, n);
            print(travel, n);
            do
            {
                printf("Enter 3, if you want to fill in the timetable or if you want to close the prog, just enter 4 \n");
                scanf("%d", &c);
            } while (c != 3 && c != 4);
            switch (c)
            {
                case 3:
                    travel = scan_d(travel,n); n++;
                    print(travel, n);
                    break;
                case 4:
                    return 0;
                    break;
            }
        case 1:
            travel = scan_d(travel,n); n++;
            QckSort(travel, n);
            print(travel, n);
            break;
        case 2:
            travel = rand_route(travel, n); n++;
            QckSort(travel, n);
            print(travel, n);
            do
            {
                printf("Enter 3, if you want to fill in the timetable, or if you want to close the prog, just enter 4 \n");
                scanf("%d", &c);
            } while (c != 3 && c != 4);
            switch (c){
                case 3:
                    travel = scan_d(travel,n); n++;
                    print(travel, n);
                    break;
                case 4:
                    return 0;
                    break;
            }

            
    }file_out(f, travel, n);
    return 0;
}

void print(struct tutu * voyage, int n){
    if (n == 0)
        return;
    for(int i = 0; i < n; i++){
        printf("Train %s\t", (*(voyage + i)).name);
        printf("number %d\n", (*(voyage + i)).number);
        printf("%s\n", (*(voyage + i)).departure);
        printf("Departure time %d:%d\n", (*(voyage + i)).departurehours, (*(voyage + i)).departureminuts);
        printf("%s\n", (*(voyage + i)).arrival);
        printf("Arrival time %d:%d\n", (*(voyage + i)).arrivalhours, (*(voyage + i)).arrivalminuts);
    }
}

struct tutu* scan_d(struct tutu * voyage, int n){
    n++;
    voyage = (struct tutu *)realloc(voyage, n  * sizeof(struct tutu));
    (*(voyage + n - 1)).name = (char*)malloc(100 * sizeof(char));
    printf("Enter type of the train\n");
    scanf("%s", (*(voyage + n - 1)).name);
    printf("Enter numder\n");
    scanf("%d", &(*(voyage+ n - 1)).number);
    printf("Enter departure hours\n");
    scanf("%d", &(*(voyage + n - 1)).departurehours);
    printf("Enter departure minuts\n");
    scanf("%d", &(*(voyage + n - 1)).departureminuts);
    printf("Enter arrival hours\n");
    scanf("%d", &(*(voyage + n - 1)).arrivalhours);
    printf("Enter arrival minuts\n");
    scanf("%d", &(*(voyage+ n - 1)).arrivalminuts);
    (*(voyage + n - 1)).arrival = (char*)malloc(100 * sizeof(char));
    (*(voyage + n - 1)).departure = (char*)malloc(100 * sizeof(char));
    printf("Enter departure\n");
    scanf("%s", (*(voyage + n - 1)).departure); // здесь чары, поэтому работает &*
    printf("Enter destination \n");
    scanf("%s", (*(voyage + n - 1)).arrival); // здесь чары, поэтому работает &*
    return voyage;
}

struct tutu * rand_route(struct tutu * voyage, int n){
    int i, j, k;
    n++;
    voyage = (struct tutu *)realloc(voyage, n  * sizeof(struct tutu));
    do{
        i = rand()%10;
        j = rand()%10;
        k = rand()%3;
    }while(i == j);
    char* city_array[10] = {"Moscow", "Kiev", "Orel", "Leningrad", "Novosibirsk", "Kalinigrad", "Ryazan", "Samara", "Volgograd", "Ekaterininburg"};
    char* nom[3] = {"Sapsan", "Firmenniy", "Skoriy"};
    (*(voyage + n - 1)).departure = city_array[i];
    (*(voyage + n - 1)).arrival = city_array[j];
    (*(voyage + n - 1)).departureminuts = rand()%60;
    (*(voyage + n - 1)).arrivalhours = rand()%23;
    (*(voyage + n - 1)).departurehours= rand()%23;
    (*(voyage + n - 1)).arrivalminuts = rand()%60;
    (*(voyage + n - 1)).number = rand()%(500 - 1000 + 1);
    (*(voyage + n - 1)).name = nom[k];
    return voyage;
}
void QckSort(struct tutu * voyage, int n){
    if (n == 1 || n == 0){
        return;
    }
    int i = 0, j = 0;
    int x = (*(voyage + n - 1)).departurehours;
    i = 0; //start
    j = n - 2; //start
    while (i < j)
    {
        if (((*(voyage + i)).departurehours > x) && ((*(voyage + j)).departurehours >= x))
            j--;
        else if (((*(voyage + i)).departurehours > x) && ((*(voyage + j)).departurehours < x)){
            swap(voyage, i, j);
            i++;
            j--;
        }
        else if (((*(voyage + i)).departurehours < x) && ((*(voyage + j)).departurehours > x)){
            i++;
            j--;
        }
        else //if ((*(a + i) < x) && (*(a + j) < x))
            i++;
    }
    if ((*(voyage + j)).departurehours > x){
        swap(voyage, j, n - 1);
        QckSort(voyage, j);
        QckSort(voyage + j + 1, n - j - 1);
    }
    else{
        swap(voyage,  j + 1, n - 1);
        QckSort(voyage, j + 1);
        QckSort(voyage + j + 2, n - j - 2);
    }
}

void swap(struct tutu *voyage, int i, int j){
    struct tutu tmp = *(voyage + i);
    *(voyage + i) = *(voyage + j);
    *(voyage + j) = tmp;
}
void file_out(FILE* f, struct tutu *voyage, int n)
{
    int i;
    if ((f = fopen("/Users/kristinaTsulaya/Documents/file.txt", "w")) == NULL)
        printf("error");
    for (i = 0; i < n; i++)
    {
        fprintf(f,"Train %s\t", (*(voyage + i)).name);
        fprintf(f,"number %d\n", (*(voyage + i)).number);
        fprintf(f,"%s\n", (*(voyage + i)).departure);
        fprintf(f,"Departure time %d:%d\n", (*(voyage + i)).departurehours, (*(voyage + i)).departureminuts);
        fprintf(f,"%s\n", (*(voyage + i)).arrival);
        fprintf(f,"Arrival time %d:%d\n", (*(voyage + i)).arrivalhours, (*(voyage + i)).arrivalminuts);
    }
    fclose(f);
}


