#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Item{
  int weight;
  int value;
  double ratio;

  void calcRatio(){
    this->ratio = this->value/(double)this->weight;
  }

  void print(){
    std::cout << "v: " << this->value << " w: " << this->weight << " r: " << this->ratio << "\n";
  }
};

struct less_than_key
{
    inline bool operator() (const Item& struct1, const Item& struct2)
    {
        return (struct1.ratio < struct2.ratio);
    }
};


int stuff_it_in(int capacity, int weight){
  if(capacity >= weight)
    return weight;
  return capacity;
}

double get_optimal_value(int capacity, vector<Item> items) {
  double value = 0.0;
  int temp_capacity = 0;
  std::sort(items.rbegin(), items.rend(), less_than_key());
  for(vector<int>::size_type i = 0; i != items.size(); i++){
    temp_capacity = stuff_it_in(capacity, items[i].weight);
    capacity -= temp_capacity;
    value += ((double) temp_capacity) * items[i].ratio;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cout << (double)500/3 << "\n";
  std::cin >> n >> capacity;
  vector<Item> items(n);
  for (int i = 0; i < n; i++) {
    Item item;
    std::cin >> item.value >> item.weight;
    item.calcRatio();
    items[i] = item;
  }

  double optimal_value = get_optimal_value(capacity, items);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
