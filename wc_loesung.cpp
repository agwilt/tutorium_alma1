#include <iostream>
#include <cstdio>

int main()
{
	int lines, words, chars;
	bool in_word = false;
	char c = 0;

	lines = words = chars = 0;

	while ((c = std::cin.get()) != EOF) {
		chars++;
		if (c == '\n') {
			lines++;
		}

		if (c == ' ' || c == '\t' || c == '\n') {
			in_word = false;
		} else if (! in_word) {
			in_word = true;
			words++;
		}
	}

	std::cout << lines << ' ' << words << ' ' << chars << '\n';

	return 0;
}
