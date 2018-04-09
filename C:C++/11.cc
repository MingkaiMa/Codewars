#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <cmath>
using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int Colour(int colour_number, int split_part) {

    int m = colour_number;
    int n = split_part;


    if(n == 1){
	return m;
    }
    else if(n == 2){
	return m*(m - 1);
    }

    return m* pow(m-1, n-1) - Colour (m, n-1);

}

int main()
{
    cout << Colour(3, 3) << "\n";
}