// normal wrong

#include<iostream>
#include<vector>
#include<cstring>

int main (){
    int num = 0, digit = 1;
    char str[51], temp;
    std::vector<int> numV;
    std::vector<char> opeV;
    scanf("%s", str);
    for(int i = strlen(str) - 1; i >= 0; --i)
        if(str[i] >= '0' && str[i] <= '9'){
            num += digit * (str[i] - '0');
            digit *= 10;
        }
        else {
            numV.push_back(num);
            num = 0; digit = 1;
            opeV.push_back(str[i]);
        }
    numV.push_back(num);
    for(int i = 0; i < numV.size() / 2; ++i){
        num = numV[i];
        numV[i] = numV[numV.size() - i - 1];
        numV[numV.size() - i - 1] = num;
    }
    for(int i = 0; i < opeV.size() / 2; ++i){
        temp = opeV[i];
        opeV[i] = opeV[opeV.size() - i - 1];
        opeV[opeV.size() - i - 1] = temp;
    }
    for(int i = 0; i < opeV.size(); ++i)
        if(opeV[i] == '+'){
            numV[i] += numV[i + 1];
            numV.erase(numV.begin() + i + 1);
            opeV.erase(opeV.begin() + i);
        }
    for(int i = 1; i < numV.size(); ++i)
        numV[0] -= numV[i];

    printf("%d", numV[0]);

    return 0;
}
