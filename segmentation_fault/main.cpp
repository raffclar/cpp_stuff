#include "csignal"

int main (int argc, char *argv[]) {
    raise(SIGSEGV);
}
