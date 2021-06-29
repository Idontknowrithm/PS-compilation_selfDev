#include<iostream>
#include<algorithm>

const int INF = 10000;
int pal[2505][2505], cache[2505];
std::string input;

void find_pal(){
    for(int i = input.size() - 1; i >= 0; --i){
        for(int u = i; u < input.size(); ++u){
            if(i == u)
                pal[i][u] = 1;
            else if(input[u] == input[u - 1])
                pal[i][u] = pal[i][u - 1];
            else if(input[i] == input[u])
                pal[i][u] = pal[i + 1][u - 1];
        }
    }
}
int pal_divider(int start, int end){
    if(start == end) return 0;

    int &ret = cache[start];
    if(ret) return ret;

    ret = INF;
    for(int i = start; i < end; ++i){
        if(pal[start][i] == 1)
            ret = std::min(ret, 1 + pal_divider(i + 1, end));
    }
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> input;

    find_pal();
    std::cout << pal_divider(0, input.size());
}
