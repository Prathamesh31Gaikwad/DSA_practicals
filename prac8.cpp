#include <iostream>
#include <queue>
using namespace std;
#define SIZE 10
class OBST
{
    int p[SIZE];
    int w[SIZE][SIZE];
    int c[SIZE][SIZE];
    int a[SIZE];
    int r[SIZE][SIZE];
    int q[SIZE];
    int n;

public:
    void get_data()
    {
        int i;
        cout << "\n Optimal Binary Search Tree \n";
        cout << "\n Enter the number of nodes";
        cin >> n;
        cout << "\n Enter the data as…\n";
        for (i = 1; i <= n; i++)
        {
            cout << "\n a[" << i << "]";
            cin >> a[i];
        }
        for (i = 1; i <= n; i++)
        {
            cout << "\n p[" << i << "]";
            cin >> p[i];
        }
        for (i = 0; i <= n; i++)
        {
            cout << "\n q[" << i << "]";
            cin >> q[i];
        }
    }


    int Min_Value(int i, int j)
    {
        int m, k;
        int minimum = 32000;
        for (m = r[i][j - 1]; m <= r[i + 1][j]; m++)
        {
            if ((c[i][m - 1] + c[m][j]) < minimum)
            {
                minimum = c[i][m - 1] + c[m][j];
                k = m;
            }
        }
        return k;
    }


    void build_OBST()
    {
        int i, j, k, l, m;
        for (i = 0; i < n; i++)
        {
            // initialize
            w[i][i] = q[i];
            r[i][i] = c[i][i] = 0;
            // Optimal trees with one node
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        }
        w[n][n] = q[n];
        r[n][n] = c[n][n] = 0;
        // Find optimal trees with ‘m’ nodes
        for (m = 2; m <= n; m++)
        {
            for (i = 0; i <= n - m; i++)
            {
                j = i + m;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                k = Min_Value(i, j);
                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
                r[i][j] = k;
            }
        }
    }



    void build_tree()
    {
        std::queue<int> queue;
        std::cout << "The Optimal Binary Search Tree For the Given Node Is…\n";
        std::cout << "\n The Root of this OBST is ::" << r[0][n];
        std::cout << "\nThe Cost of this OBST is::" << c[0][n];
        std::cout << "\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD \n";

        queue.push(0);
        queue.push(n);
        while (!queue.empty())
        {
            int i = queue.front();
            queue.pop();
            int j = queue.front();
            queue.pop();
            int k = r[i][j];
            std::cout << "\n\t" << k;
            if (r[i][k - 1])
            {
                std::cout << "\t\t" << r[i][k - 1];
                queue.push(i);
                queue.push(k - 1);
            }
            else
            {
                std::cout << "\t\t";
            }
            if (r[k][j])
            {
                std::cout << "\t" << r[k][j];
                queue.push(k);
                queue.push(j);
            }
            else
            {
                std::cout << "\t";
            }
        }
        std::cout << "\n";
    }
};



int main()
{
    OBST obj;
    obj.get_data();
    obj.build_OBST();
    obj.build_tree();
    return 0;
}