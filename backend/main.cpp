#include <iostream>
#include "modelclassext.h"
#include "controller.h"


int main(int argc, char *argv[])
{
    Controller<ModelClassExt>::runServer(argc, argv);
    return 0;
}
