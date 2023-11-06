#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <getopt.h>
#include <stdbool.h>

// silence error highlighting
#ifndef TARGET
#define TARGET "example"
#endif
#ifndef VERSION
#define VERSION "unknown"
#endif

static struct option options_getopt[] = {
        {"help",    no_argument, NULL, 'h'},
        {"version", no_argument, NULL, 'V'},
        {"a",       no_argument, NULL, 'a'},
        {"b",       no_argument, NULL, 'b'},
        {"c",       no_argument, NULL, 'c'},
        {NULL,      0,           NULL, 0  }
};

int main(int argc, char *argv[]) {
	bool invalid = false;
	int opt;

	// argument handling
	while ((opt = getopt_long(argc, argv, ":hVabc", options_getopt, NULL)) != -1) {
		switch (opt) {
			case 'h':
				printf("Usage: %s [OPTION]...\n", TARGET);
				printf("-h --help: Shows help text\n");
				printf("-V --version: Shows the version\n");
				printf("-a --a: Do something\n");
				printf("-b --b: Do something else\n");
				printf("-c --c: Do another thing\n");
				return 0;
			case 'V':
				printf("%s %s\n", TARGET, VERSION);
				return 0;
			default:
				if (!invalid) {
					switch (opt) {
						case 'a':
							printf("A\n");
							break;
						case 'b':
							printf("B\n");
							break;
						case 'c':
							printf("C\n");
							break;
						default:
							invalid = true;
							break;
					}
				}
				break;
		}
	}

	if (optind != argc || invalid) // use `argc - 1` if you want to require one non-flag argument, such as a file name
		errx(1, "Invalid usage, try --help");

	printf("Hello World\n");
	return 0;
}
