#include <iostream>

int main()
{
	float f_eps = 1;
	double d_eps = 1;
	long double ld_eps = 1;

	while (1+f_eps > 1) {
		f_eps /= 2;
	}

	while (1+d_eps > 1) {
		d_eps /= 2;
	}

	while (1+ld_eps > 1) {
		ld_eps /= 2;
	}

	std::cout << "Maschinengenauigkeit von float ist " << f_eps*2 << ".\n";
	std::cout << "Maschinengenauigkeit von double ist " << d_eps*2 << ".\n";
	std::cout << "Maschinengenauigkeit von long double ist " << ld_eps*2 << ".\n";

	return 0;
}
