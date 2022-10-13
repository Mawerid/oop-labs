#include "../include/word.hpp"
#include "../include/dialog.hpp"

int main(int argc, char *argv[])
{
    word::words mass;
    dialog::menu();
    dialog::cmd_loop(&mass);

    return 0;
}