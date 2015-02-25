// Raspitemp
// by Philip Märksch<comradephilos@googlemail.com>
#include<cstdlib>
#include<stdio.h>
#include<time.h>

using namespace std;

const int NUM_SECONDS = 2;

int main(){
    int count = 1;
    double time_counter = 0;

    clock_t this_time = clock();
    clock_t last_time = this_time;

    while(true)
    {
        this_time = clock();

        time_counter += (double)(this_time - last_time);

        last_time = this_time;

        if(time_counter > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
        {
            time_counter -= (double)(NUM_SECONDS * CLOCKS_PER_SEC);
            std::system("vcgencmd measure_temp");
            count++;
        }
    }

    return 0;
}
