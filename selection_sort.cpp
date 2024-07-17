#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

#define inFileName "vectors/num.1000.1.in"
#define vector_size 1000

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
    for(int j, i = 0; i < nums.size(); i++)
    {
        aux = nums[i];
        for(j = i +1; j < nums.size()-1; j++)
        {
            if(nums[j] < aux)
            {
                aux = nums[j];
                index = j;
            }
        }
        aux = nums[i];
        nums[i] = nums[index];
        nums[index] = aux;
    }
    auto fim = chrono::high_resolution_clock::now();

    for (const int& num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    chrono::duration<double> duracao = fim - inicio;
    cout << "execution time: " << duracao.count() << " seconds" << endl;

    return 0;
}