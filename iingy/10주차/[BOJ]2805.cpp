//백준 2805 나무자르기
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

long long MAX;
int need_treeLen;
long long result;

long long binary_search(vector<long long>& tree,long long start, long long high) {
    long long mid = (start + high) / 2;
    long long cut_tree = 0;
    
    if (start > high) return result;

    for (size_t idx = 0; idx < tree.size(); idx++) 
        if (tree[idx] - mid < 0) break;
        else cut_tree += tree[idx] - mid;
     
    if (cut_tree >= need_treeLen)    //잘라서 나온 나무 길이가 필요로 하는 나무길이보다 크다면
        result = result < mid ? mid : result;    //M길이에 가까운 근사치를 구한다.

    if (cut_tree > need_treeLen) 
        return binary_search(tree, mid + 1, high);
    else
        return binary_search(tree, start, mid - 1);

}

int main() {
    int N = 0;
    long long temp = 0;
    cin >> N; cin >> need_treeLen;
    vector<long long>tree;
    tree.reserve(N + 1);
    
    for (int i = 0; i < N; i++) {
        cin >> temp;
        tree.emplace_back(temp);
    }
    
    sort(tree.rbegin(), tree.rend());  //내림차순 정렬로 최대 값이 앞으로 오게 한다.
    MAX = tree[0];

    printf("%lld\n", binary_search(tree, 0, MAX));
    return 0;
}