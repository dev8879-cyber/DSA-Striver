#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
    long long x, y;
};

long long dist(Point p1, Point p2)
{
    long long dx = p1.x - p2.x;
    long long dy = p1.y - p2.y;

    return dx * dx + dy * dy;
}

void rotatePoint(Point &p, Point center)
{
    long long x = p.x;
    long long y = p.y;

    p.x = center.x + center.y - y;
    p.y = center.y + x - center.x;
}

bool isSquare(Point p[])
{
    long long d[6];
    int k = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 4; j++)
        {
            d[k++] = dist(p[i], p[j]);
        }
    }

    sort(d, d + 6);

    // Four equal non-zero sides
    if(d[0] == 0)
        return false;

    if(d[0] != d[1] ||
       d[1] != d[2] ||
       d[2] != d[3])
        return false;

    // Two equal diagonals
    if(d[4] != d[5])
        return false;

    // diagonal² = 2 * side²
    if(d[4] != 2 * d[0])
        return false;

    return true;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        Point p[4], center[4];

        for(int i = 0; i < 4; i++)
        {
            cin >> p[i].x >> p[i].y
                >> center[i].x >> center[i].y;
        }

        int ans = 1000000;

        // Try all 4^4 rotation combinations
        for(int r0 = 0; r0 < 4; r0++)
        {
            for(int r1 = 0; r1 < 4; r1++)
            {
                for(int r2 = 0; r2 < 4; r2++)
                {
                    for(int r3 = 0; r3 < 4; r3++)
                    {
                        Point temp[4];

                        for(int i = 0; i < 4; i++)
                            temp[i] = p[i];

                        for(int i = 0; i < r0; i++)
                            rotatePoint(temp[0], center[0]);

                        for(int i = 0; i < r1; i++)
                            rotatePoint(temp[1], center[1]);

                        for(int i = 0; i < r2; i++)
                            rotatePoint(temp[2], center[2]);

                        for(int i = 0; i < r3; i++)
                            rotatePoint(temp[3], center[3]);

                        if(isSquare(temp))
                        {
                            int moves = r0 + r1 + r2 + r3;
                            ans = min(ans, moves);
                        }
                    }
                }
            }
        }

        if(ans == 1000000)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}