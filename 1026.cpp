#include <iostream>
#include<stdio.h>
#include <thread>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>

const int ARRAY_SIZE = 50;

void sumArrays(int* x, int* y, int* r, int start, int end){
    for(int i = start; i < end; ++i){
            r[i] = x[i] ^ y[i];
            std::cout << r[i] << std::endl;
    }
}

int main(){
    int x[ARRAY_SIZE] = {1, 3, 4, 5, 7, 8, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95};
    int y[ARRAY_SIZE] = {2, 8, 12, 17, 20, 22, 26, 31, 34, 37, 41, 45, 48, 52, 55, 58, 62, 66, 69, 73, 76, 80, 83, 87, 90, 94, 97, 100, 104, 107, 111, 114, 118, 122, 125, 129, 132, 136, 140, 143, 147, 150, 154, 157, 161, 165, 168, 172, 175, 179};
    int r[ARRAY_SIZE] = {0};

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

        threads[i] = std::thread(sumArrays, x, y, r, start, end);
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
