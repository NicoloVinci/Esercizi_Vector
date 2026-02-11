#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    int min = 1, max = 10;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    int num = dis(gen);
    vector<int> zombies;
    zombies.reserve(num);
    for (int i = 0; i < num; i++)
    {
        zombies.push_back(dis(gen));
    }
    do {
        for (int i = 0; i < zombies.size(); i++)
        {
            cout << "Zombie " << i + 1 << ": " << zombies[i] << " health" << endl;
        }
        for (int i = 0; i < zombies.size(); i++)
        {
            if (i == zombies.size() - 1)
            {
                zombies[0] -= zombies[i] / 2;
            }
            else
            {
                zombies[i + 1] -= zombies[i] / 2;
            }
        }
        auto remove = remove_if(zombies.begin(), zombies.end(), [](int health) { return health <= 0; });
        zombies.erase(remove, zombies.end());
    } while (zombies.size() > 1);
    if (!zombies.empty())
    {
        cout << "Zombie: " << zombies[0] << " health" << endl;
    } else
    {
        cout << "All zombies are dead." << endl;
    }
    return 0;
}