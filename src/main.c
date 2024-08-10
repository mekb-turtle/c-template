#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <getopt.h>
#include <stdbool.h>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

// simple program with argument handling

int main(int argc, char *argv[]) {
	bool invalid = false;
	int opt;

	// argument handling
	while ((opt = getopt_long(argc, argv, ":hVabc", (struct option[]){
	                {"help",    no_argument, 0, 'h'},
	                {"version", no_argument, 0, 'V'},
	                {"a",       no_argument, 0, 'a'},
	                {"b",       no_argument, 0, 'b'},
	                {"c",       no_argument, 0, 'c'},
	                {0,         0,           0, 0  }
    }, NULL)) != -1) {
			switch (opt) {
				case 'h':
					printf("Usage: %s [OPTION]...\n", PROJECT_NAME);
					printf("-h --help: Shows help text\n");
					printf("-V --version: Shows the version\n");
					printf("-a --a: Do something\n");
					printf("-b --b: Do something else\n");
					printf("-c --c: Do another thing\n");
					return 0;
				case 'V':
					printf("%s %s\n", PROJECT_NAME, PROJECT_VERSION);
#ifdef PROJECT_URL
					printf("See more at %s\n", PROJECT_URL);
#endif
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

	if (optind != argc || invalid) {
		// use `argc - 1` if you want to require one non-flag argument, such as a file name
		eprintf("Invalid usage, try --help\n");
		return 1;
	}

	printf("Hello World\n");
	return 0;
}
