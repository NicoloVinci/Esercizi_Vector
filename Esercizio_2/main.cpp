#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution dis(1, 100);
    int random_number = dis(mt);
    vector<int> numbers;
    do
    {
        numbers.push_back(random_number);
        if ((random_number % 7) == 0)
        {
            numbers.pop_back();
            int size = numbers.size();
            for (int i1 = 0; i1 < size; i1++)
            {
                if ((numbers[i1] % 2) == 0)
                {
                    numbers.push_back(numbers[i1]);
                }
            }

        }
        random_number = dis(mt);
    } while (numbers.size() <= 50);
    for (int number : numbers)
    {
        cout << number << " ";
    }
    return 0;
}