#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

// Merge two arrays only if they share ANY common string
vector<vector<string>> mergeIfCommon(vector<string> A, vector<string> B)
{
    vector<string> all = A;
    all.insert(all.end(), B.begin(), B.end());

    // Step 1: Assign ID to every unique string
    unordered_map<string, int> id;
    int idx = 0;
    for (auto &s : all)
    {
        if (!id.count(s))
            id[s] = idx++;
    }

    DSU dsu(idx);

    // Step 2: Check if A and B have ANY common string
    unordered_set<string> setA(A.begin(), A.end());
    bool hasCommon = false;

    for (string &s : B)
    {
        if (setA.count(s))
        {
            hasCommon = true;
            break;
        }
    }

    // Step 3: If common → union every element of A with every element of B
    if (hasCommon)
    {
        for (string &a : A)
        {
            for (string &b : B)
            {
                dsu.unite(id[a], id[b]);
            }
        }
    }

    // Step 4: Build groups based on DSU root
    unordered_map<int, vector<string>> groups;
    for (auto &p : id)
    {
        string s = p.first;
        int root = dsu.find(p.second);
        groups[root].push_back(s);
    }

    // Step 5: Convert map to result vector
    vector<vector<string>> result;
    for (auto &g : groups)
        result.push_back(g.second);

    return result;
}

int main()
{
    vector<string> A = {"cat", "dog", "lion"};
    vector<string> B = {"wolf", "dog", "tiger"};

    auto groups = mergeIfCommon(A, B);

    for (auto &grp : groups)
    {
        cout << "{ ";
        for (auto &s : grp)
            cout << s << " ";
        cout << "}\n";
    }
}
