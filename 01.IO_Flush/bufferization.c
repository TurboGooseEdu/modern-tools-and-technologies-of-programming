#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    bool flushEnabled = false;
    bool linebreaksEnabled = false;
    
    if (argc == 3) {
        flushEnabled = argv[1][0] == '1';
        linebreaksEnabled = argv[2][0] == '1';
    }

    fputs(linebreaksEnabled ? "STDOUT\n" : "STDOUT", stdout);
    if (flushEnabled) {
        fflush(stdout);        
    }

    fputs(linebreaksEnabled ? "STDERR\n" : "STDERR", stderr);
    if (flushEnabled) {
        fflush(stderr);
    }
    
    return 0;
}
