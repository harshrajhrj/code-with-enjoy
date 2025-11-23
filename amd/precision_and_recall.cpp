#include <bits/stdc++.h>
using namespace std;

pair<double, double> calcMetrics(int TP, int FP, int FN)
{
    double precision = (TP + FP) == 0 ? 0.0 : (double)TP / (TP + FP);
    double recall = (TP + FN) == 0 ? 0.0 : (double)TP / (TP + FN);

    return {precision, recall};
}
int main()
{
    return 0;
}