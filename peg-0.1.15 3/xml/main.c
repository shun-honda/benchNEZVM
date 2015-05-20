#include <stdio.h>
#include <time.h>
#include "xml.h"

int main(int argc, char **argv) {
	FILE *fp = stdin;
	XML *xml;

  for (int i = 0; i < 10; i++) {
    if (argc >= 2) {
      if (!(fp = fopen(argv[1], "r"))) {
        fprintf(stderr, "File [%s] is not found!\n", argv[1]);
        return 1;
      }
    }
  
    clock_t start = clock();
    if ((xml = xml_parser(fp))) {
      clock_t end = clock();
      //xml_print(stdout, xml);
      printf("time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    } else {
      printf("XML error!\n");
    }
    fclose(fp);
    //clock_t end = clock();
  }

	return 0;
}
