#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <algorithm>


using namespace std;

clock_t time_start, time_stop;
double wall_time_start, wall_time_stop;
int num_threads = 8;

void fill_tab_with_range(int tab[], int start, int end){
    int value = start;
    for(int i=0;i<(end-start);i++){
        tab[i]=value;
        value++;
    }
}

int main(int argc, char *argv[]){

    omp_set_num_threads(num_threads);

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int tab_numbers[end-start];
    fill_tab_with_range(tab_numbers, start, end);
    for(int i = 0; i<(end-start); i++){
        cout << tab_numbers[i] << endl;
    }

    wall_time_start = omp_get_wtime();
    time_start = clock();

    for(int i = start; i <= end; i++){
        if(i == 0){
            continue;
        }
        int max_divider = sqrt(i);

        
    }

    
    time_stop = clock();
    wall_time_stop = omp_get_wtime();
    
    cout << "Czas przetwarzania zegarowego: " << (wall_time_stop - wall_time_start) << endl;
    cout << "Czas przetwarzania procesora: " << (time_stop-time_start)/CLOCKS_PER_SEC << endl;
    cout << "Czas przetwarzania jednego procesora: " << ((time_stop-time_start)/CLOCKS_PER_SEC) / num_threads << endl;

    return 0;
}