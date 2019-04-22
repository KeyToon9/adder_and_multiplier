//
// unsigned adder and multiplier implemented in digital cicuit way
// 2019/4/22 created by keytoon
//
#include <stdio.h>

int add(int, int);//+
int mult(int, int);//*

int main()
{
	int a = 4, b = 6;
	
	printf("%d\n%d\n", add(a, b), mult(a, b));
	
	getchar();
	return 0;
}

//i xor j get the non-carry
//i and j get the carry
//
//eg. 1001 + 0011 dec(9 + 3)
//-----first step-----
//    1001 xor 0011 = 1010
//    1001 and 0011 = 0001
//    shift left 0001 get 0010
//-----second step-----
//    1010 xor 0010 = 1000
//    1010 and 0010 = 0010
//    shift left 0010 get 0100
//----final step-----
//    1000 xor 0100 = 1100
//    1000 and 0100 = 0000 == 0
//--------------------
//now we get the result 1100 dec(12)
int add(int i, int j)
{
	return j == 0 ? i : add(i ^ j, (i & j) << 1);
}

//now we have a unsigned adder.let's creat a multiplier.
//
//eg. 1001 * 0011 dec(9 * 3)
//                   1 0 0 1
//*                  0 0 1 1
//--------------------------
// step 1            1 0 0 1
// step 2          1 0 0 1
// setp 3        0 0 0 0
//             0 0 0 0
//--------------------------
//             0 0 1 1 0 1 1  dec(27)
//
//every time we operate these number
//determine if multiplier and 1 is equal to 1, if true, we add a to a variable
//then shift left multiplicand(1001) and shift right multiplier(0011)
//repeat this operation
int mult(int i, int j)
{
	static int res = 0;
	if (j & 1) res = add(res, i);
	return j == 0 ? res : mult(i << 1, j >> 1);
}

