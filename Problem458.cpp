class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int times = minutesToTest / minutesToDie;
    int result = 0;
    while (pow(times + 1, result) < buckets) ++result;
    return result;
  }
};
