#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

const int ARRAY_SIZE = 50;

void sumArrays(double* A, double* B, double* MEDIA, int start, int end){
    for(int i = start; i < end; ++i){
            MEDIA[i] = ((A[i] * 3.5) + (B[i] * 7.5)/(3.5 + 7.5));
            std::cout << "MEDIA = " << MEDIA[i] << std::endl;
    }
}

int main(){
    double A[ARRAY_SIZE] = {1.5, 2.7, 3.2, 4.8, 5.1, 6.3, 7.9, 8.4, 9.6, 10.2, 11.7, 12.9, 13.4, 14.6, 15.3, 16.8, 17.2, 18.5, 19.1, 20.4, 21.9, 22.3, 23.7, 24.2, 25.6, 26.8, 27.5, 28.9, 29.4, 30.7, 31.2, 32.6, 33.8, 34.5, 35.9, 36.4, 37.7, 38.1, 39.4, 40.9, 41.3, 42.7, 43.2, 44.6, 45.8, 46.5, 47.9, 48.3, 49.7, 50.1};
    double B[ARRAY_SIZE] = {1.5, 2.7, 3.2, 4.8, 5.1, 6.3, 7.9, 8.4, 9.6, 10.2, 11.7, 12.9, 13.4, 14.6, 15.3, 16.8, 17.2, 18.5, 19.1, 20.4, 21.9, 22.3, 23.7, 24.2, 25.6, 26.8, 27.5, 28.9, 29.4, 30.7, 31.2, 32.6, 33.8, 34.5, 35.9, 36.4, 37.7, 38.1, 39.4, 40.9, 41.3, 42.7, 43.2, 44.6, 45.8, 46.5, 47.9, 48.3, 49.7, 50.1};
    double MEDIA[ARRAY_SIZE] = {0};

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

        threads[i] = std::thread(sumArrays, A, B, MEDIA, start, end);
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


