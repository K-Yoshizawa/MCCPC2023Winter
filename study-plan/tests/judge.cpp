#include "testlib.h"

using namespace std;

vector<int> readAns(InStream& is, int N)
{
    int first = is.readInt();
    if (first == -1) {
        return { first };
    }
    vector<int> ret(N);
    ret[0] = first;
    for (int i = 1; i < N; i++) {
        is.readSpace();
        ret[i] = is.readInt();
    }
    return ret;
}

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    int N = inf.readInt();
    inf.readEoln();
    int X = inf.readInt();
    inf.readSpace();
    int Y = inf.readInt();
    inf.readSpace();
    int Z = inf.readInt();
    inf.readEoln();
    vector<vector<int>> ABC(3, vector<int>(N));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            if (j)
                inf.readSpace();
            ABC[i][j] = inf.readInt();
        }
        inf.readEoln();
    }

    vector<int> pans = readAns(ouf, N), jans = readAns(ans, N);
    if (jans[0] == -1) {
        if (pans[0] == -1) {
            quitf(_ok, "Correct answer (-1)\n");
        } else {
            quitf(_wa, "Wrong answer (-1)\n");
        }
    } else {
        vector<int> S(3);
        for (int i = 0; i < N; i++) {
            S[pans[i]] += ABC[pans[i]][i];
        }
        if (S[0] >= X && S[1] >= Y && S[2] >= Z) {
            quitf(_ok, "Correct answer\n");
        } else {
            quitf(_wa, "Wrong answer\n");
        }
    }
}