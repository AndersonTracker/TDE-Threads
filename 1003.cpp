#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

const int ARRAY_SIZE = 50;

void sumArrays(int* a, int* b, int* x, int start, int end){
    for(int i = start; i < end; ++i){
            x[i] = a[i] + b[i];
            std::cout << "SOMA = " << x[i] << std::endl;
    }
}

int main(){
    int a[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    int b[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    int x[ARRAY_SIZE] = {0};

    //Define o Numero de threads desejado
    int numThreads;
    std::cout << "Digite o numero de threads a serem utilizadas: ";
    std::cin >> numThreads;

    // calcula o numero de elementos que cada thread deve processor
    int elementsPerThread = ARRAY_SIZE / numThreads;

    // vetor de armazenamento das threads
    std::thread threads[numThreads];

    // Start timing
    auto startTime = std::chrono::steady_clock::now();

    //cria as threads
    for(int i = 0; i < numThreads; ++i){
        int start = i * elementsPerThread;
        int end = ( i == numThreads - 1 ) ? ARRAY_SIZE : start + elementsPerThread;

        threads[i] = std::thread(sumArrays, a, b, x, start, end);
    }

    //aguarda todas as threads
    for (auto& thread : threads) {
        thread.join();
    }

    // Stop timing
    auto endTime = std::chrono::steady_clock::now();

    // Calculate execution time in microseconds and milliseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    std::cout << "Programa concluido." << std::endl;
    std::cout << "Tempo de execucao: " << duration << " microssegundos " << std::endl;
    std::cout << "Tempo de execucao: " << ms << " milissegundos " << std::endl;

    return 0;
}

