// bucket sort.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include<array>
#include<random>

using std::array;
using std::cout;
using std::endl;
using std::uniform_int_distribution;
using std::default_random_engine;


template<typename T,size_t size>
void bucketSort(array<T, size>& items) {
    
    //find max value
    T max{ items[0]};
    for (int i{ 1 }; i < items.size(); i++) {
        if (items[i] > max) {
            max = items[i];
        }
    }

    //find digits of max value
    int digit{ 0 };
    while (max != 0) {
        max /= 10;
        digit++;
    }

    int l{ 1 };

    for (int j{ 0 }; j < digit; j++) {
        //try using vector
        array<array<T, size>, 10> bucket{};

        int k{ 0 };

        for (int i{ 0 }; i < items.size(); i++) {
            T remainder = (items[i]/l) % 10;
            switch (remainder) {
            case 0:bucket[0][k] = items[i]; k++; break;
            case 1:bucket[1][k] = items[i]; k++; break;
            case 2:bucket[2][k] = items[i]; k++; break;
            case 3:bucket[3][k] = items[i]; k++; break;
            case 4:bucket[4][k] = items[i]; k++; break;
            case 5:bucket[5][k] = items[i]; k++; break;
            case 6:bucket[6][k] = items[i]; k++; break;
            case 7:bucket[7][k] = items[i]; k++; break;
            case 8:bucket[8][k] = items[i]; k++; break;
            case 9:bucket[9][k] = items[i]; k++; break;

            }
        }
        l *= 10;
        int index{ 0 };

        for (int i{ 0 }; i < bucket.size(); i++) {
            for (int j{ 0 }; j < items.size(); j++) {
                if (bucket[i][j] != 0) {
                    items[index++] = bucket[i][j];
                }
            }
        }
    }
    
}

int main()
{
    const size_t arraySize{ 9 };
    array<int, arraySize> data{ 12,5,7,8,24,2,3,6,900 };
    
    for (int i{ 0 }; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    
    cout << endl;

    bucketSort(data);

    for (int i{ 0 }; i < data.size(); i++) {
        cout << data[i] << " ";
    }

    cout << endl;
    
}

