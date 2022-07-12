#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;
void maxSlidingWindow(vector<int> &nums, int k)
{

    vector<int> output;
    int i = 0;
    int j = 0;
    list<int> l;
    while (j < nums.size())
    {
        if (l.empty())
        {
            l.push_back(nums[j]);
        }
        else
        {
            // Removing small elements from the list
            while (!l.empty() && l.back() < nums[j])
                l.pop_back();
            l.push_back(nums[j]);
        }
        if (j - i + 1 < k)
            ++j;
        else if (j - i + 1 == k)
        {
            // filling only the largest element from the list
            output.push_back(l.front());
            if (nums[i] == l.front())
                l.pop_front();
            ++i;
            ++j;
        }
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    int e;
    for(int i = 0; i<n; i++)
    {
        cin >> e;
        a.push_back(e);
    }
    int k;
    cin >> k;

    maxSlidingWindow(a, k);
    
    
    return 0;
}