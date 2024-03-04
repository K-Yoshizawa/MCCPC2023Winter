#include "testlib.h"
#include "constraints.hpp"
#include <bits/stdc++.h>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

	int sx = inf.readInt(MIN_SX, MAX_SX, "s_x"); inf.readSpace();
    int sy = inf.readInt(MIN_SY, MAX_SY, "s_y"); inf.readSpace();
    int gx = inf.readInt(MIN_GX, MAX_GX, "g_x"); inf.readSpace();
    int gy = inf.readInt(MIN_GY, MAX_GY, "g_y");
	inf.readEoln();
	inf.readEof();
	return 0;
}
