#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
#define inFileName "vectors/num.1000.1.in"

int main(){

    ifstream infile(inFileName);
    if (!infile)
    {
        cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    vector<int> nums;
    int numero;
    while (infile >> numero)
    {
        nums.push_back(numero);
    }

    infile.close();

    int aux = 0;
    int index;
    auto inicio = chrono::high_resolution_clock::now();
    for(int j, i = 0; i < nums.size() -1; i++)
    {
        aux = nums[i];
        for(j = i +1; j < nums.size(); j++)
        {
            if(nums[j] < aux)
            {
                aux = nums[j];
                index = j;
            }
        }
        swap(nums[i], nums[index]);
    }
    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = fim - inicio;

    for (const int& num : nums) {
         std::cout << num << endl;
    }
    std::cout << endl;

    std::cout << "execution time: " << duracao.count() << " seconds" << endl;

    return 0;
}