/**
 * struct Point {
 *	int x;
 *	int y;
 * };
 */

class Solution {
   public:
    /**
     *
     * @param points Point类vector
     * @return int整型
     */
    int maxPoints(vector<Point>& points) {
        int N = points.size();
        if (N < 3)
            return N;

        int i = 0, j, k;
        vector<int> a;  // 记录该位置的点数
        a.push_back(1);
        // 整合位置相同的点
        while (i != N - 1) {
            bool flag = true;
            for (j = i + 1; j < N; j++) {
                if ((points[i].x == points[j].x) &&
                    (points[i].y == points[j].y)) {
                    points[j] = points[N - 1];
                    a[i]++;
                    N = N - 1;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                i += 1;
                a.push_back(1);
            }
        }

        if (N == 1)
            return a[0];
        int max = 0, sum;
        for (i = 0; i < N - 1; i++) {
            for (j = i + 1; j < N; j++) {
                sum = a[i] + a[j];
                for (k = j + 1; k < N; k++) {
                    if ((points[i].y - points[j].y) *
                            (points[k].x - points[j].x) ==
                        (points[k].y - points[j].y) *
                            (points[i].x - points[j].x)) {
                        sum += a[k];
                    }
                }
                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }
};