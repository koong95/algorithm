#include <iostream>
#define _max(a,b) (a>b?a:b)
using namespace std;

int max_sum();

int main()
{
	//int A[10] = {-4,-1,0,-2,3,-7,-11,-9,-2,10};
	int A[8] = {-7, 4, -3, 6, 3, -8, 3, 4};
	cout << "A[]=" ;
	for (int i=0 ; i<8 ; i++)
	{
		cout << A[i] << "," ;
	}
	cout << endl;

	int dp = 0;
	int ret = -20;

	for (int i=0 ; i<8 ; i++)
	{
		//dp = _max(dp, -20) + A[i];
		dp = _max(dp, 0) + A[i];
		ret = _max(ret, dp);

		cout << "dp, ret, A[i]: " << dp << "," << ret << "," << A[i] << endl;
	}
	cout << "max:" << ret << endl;

	cout << "max2: "<< max_sum() << endl;
	return 1;
}

int max_sum()
{
    //int input [] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int input[] = {-7, 4, -3, 6, 3, -8, 3, 4};
    size_t size = sizeof(input)/sizeof(int);

    int max_so_far = input[0], max_ending_here = input[0];
    for (int i = 1; i < size; i++) {
        if (max_ending_here < 0) {
            max_ending_here = input[i];
            // begin_temp = i;
        }
        else {
            max_ending_here += input[i];
        }

        max_so_far = _max(max_ending_here, max_so_far);
        //if (max_ending_here > max_so_far) {
            // begin = begin_temp;
            // end = i;
        //}
    }

    //trace("%d\n", max_so_far);
    return max_so_far;
} 
