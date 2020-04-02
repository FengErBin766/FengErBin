#include <iostream>

using namespace std;

int main()
{
    int N,*arr,sum=3;
    while (sum != 0)
    {
        cout << "请输入数组元素个数：" << endl;
        cin >> N;
        arr = new int[N];
        cout << endl << "请依次输入数组的各个元素：" << endl;
        int i, max1, max2, k;
        for (i = 0, k = -1; i < N; i++)
        {
            cin >> arr[i];
            if (arr[i] >= 0)
            {
                k = 1;
            }
        }
        if (k == 1)
        {
            for (i = 0, max1 = 0, max2 = 0; i < N; i++)
            {
                max1 += arr[i];
                if (max2 < max1)
                {
                    max2 = max1;
                }
                if (max1 < 0)
                {
                    max1 = 0;
                }
            }
            cout << endl << "该数组最大子序列和为：" << endl;
            cout << max2 << endl << endl << endl;
        }
        else
        {
            cout << endl << "该数组均为负数，最大子序列和定义为 0 " << endl;
        }
        delete[]arr;
        sum--;
    }
    return 0;
}
