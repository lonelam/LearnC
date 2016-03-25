#include"coordin.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	rect one= {3,4};
	polar two;
	two = trans_rect(one);
	show_pol(two);
	return 0;
}
