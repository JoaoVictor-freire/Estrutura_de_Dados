#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
#define inFileName "vectors/num.100000.1.in"

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

    auto inicio = chrono::high_resolution_clock::now();

    int aux = 0;
    for(int j, i = 0; i < nums.size(); i++)
    {
        j = i;
        while(j > 0 && nums[j] < nums[j-1])
        {
            aux = nums[j];
            nums[j] = nums[j -1];
            nums[j -1] = aux;
            j--;
        }
    }

    auto fim = chrono::high_resolution_clock::now();

    chrono::duration<double> duracao = fim - inicio;

    for (const int& num : nums) {
        cout << num << endl;
    }
    cout << endl;

    std::cout << "execution time: " << duracao.count() << " seconds" << endl;

    return 0;
}