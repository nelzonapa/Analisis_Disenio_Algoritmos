#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& item1, const Item& item2) {
    // Comparar los elementos según la relación valor/peso de forma descendente
    double valuePerWeight1 = static_cast<double>(item1.value) / item1.weight;
    double valuePerWeight2 = static_cast<double>(item2.value) / item2.weight;
    return valuePerWeight1 > valuePerWeight2;
}

double knapsackGreedy(const std::vector<Item>& items, int capacity) {
    std::vector<Item> sortedItems = items;
    std::sort(sortedItems.begin(), sortedItems.end(), compareItems);

    double totalValue = 0.0;
    int currentCapacity = capacity;

    for (const Item& item : sortedItems) {
        if (currentCapacity >= item.weight) {
            // Se puede añadir el objeto completo a la mochila
            totalValue += item.value;
            currentCapacity -= item.weight;
        } else {
            // Solo se añade una fracción del objeto a la mochila para aprovechar el espacio disponible
            double fraction = static_cast<double>(currentCapacity) / item.weight;
            totalValue += fraction * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    std::vector<Item> items = {
        {2, 10},
        {5, 25},
        {10, 40},
        {3, 12},
        {7, 30}
    };

    int capacity = 15;

    double maxValue = knapsackGreedy(items, capacity);

    std::cout << "Valor máximo obtenido: " << maxValue << std::endl;

    return 0;
}
