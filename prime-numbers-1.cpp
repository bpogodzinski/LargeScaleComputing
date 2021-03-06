#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <algorithm>


using namespace std;

bool is_prime(int number){
    int end_to_search = ceil(sqrt(number));
    for(int j = 2; j<=end_to_search; ++j){
        if(number % j == 0) return false;
    }
    return true;
}

void print_vector(vector<int> data){
    for(int i = 0; i<data.size(); i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

clock_t time_start, time_stop;
double wall_time_start, wall_time_stop;
int num_threads = 8;

int main(int argc, char *argv[]){


    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    vector<int> primes;
    
    wall_time_start = omp_get_wtime();
    time_start = clock();

    for(int i = start; i <= end; ++i){
        if((i != 2 && i % 2 == 0) || i == 1){
            continue;
        }
        if(is_prime(i)){
                primes.push_back(i);
        }
    }
    
    time_stop = clock();
    wall_time_stop = omp_get_wtime();
    sort(primes.begin(), primes.end());
    cout << "Czas przetwarzania zegarowego: " << (wall_time_stop - wall_time_start) << endl;
    cout << "Czas przetwarzania procesora: " << (double(time_stop-time_start)/CLOCKS_PER_SEC) << endl;
    cout << "Czas przetwarzania jednego procesora: " << (double(time_stop-time_start)/CLOCKS_PER_SEC) / num_threads << endl;
    cout << "Size primes: " << primes.size() << endl;
    // print_vector(primes);

    return 0;
}