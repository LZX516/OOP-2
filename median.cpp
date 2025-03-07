#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::domain_error;
using std::sort;

double median(vector<double> vec)
{
    auto size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());
    auto mid = size/2;
    return (size % 2 == 0) ? (vec[mid] + vec[mid-1]) / 2.0 : vec[mid];
}

double average(const vector<double>& vec)
{
    if (vec.empty())
        throw domain_error("average of an empty vector");
    
    double sum = 0;
    for (auto it:vec)
        sum += it;
    return sum / vec.size();
}
