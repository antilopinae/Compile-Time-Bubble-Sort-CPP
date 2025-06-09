#include <array>
#include <iostream>

template <int32_t... Args> struct bubbleSort {
private:
  template <int32_t Data> static void print_one() { std::cout << Data << " "; }

  template <int32_t... Values> static void print_all() {
    (print_one<Values>(), ...);
    std::cout << std::endl;
  }

  template <int32_t First, int32_t Second, int32_t... Rest>
  static constexpr std::array<int32_t, sizeof...(Rest) + 2> sort_impl() {
      if constexpr (sizeof...(Rest) == 0) {
          if (First <= Second) {
            return std::array<int32_t, 2>{First, Second};
          } else {
            return std::array<int32_t, 2>{Second, First};
          }
      } else if (First <= Second) {
        auto rest_array = sort_impl<Second, Rest...>();
        std::array<int32_t, sizeof...(Rest) + 2> result = {First};
          for (std::size_t i = 0; i < rest_array.size(); ++i) {
            result[i + 1] = rest_array[i];
              if (result[i] > result[i + 1]) {
                int32_t p = result[i];
                result[i] = result[i + 1];
                result[i + 1] = p;
            }
          }
        return result;
      } else {
        auto rest_array = sort_impl<First, Rest...>();
        std::array<int32_t, sizeof...(Rest) + 2> result = {Second};
          for (std::size_t i = 0; i < rest_array.size(); ++i) {
            result[i + 1] = rest_array[i];
              if (result[i] > result[i + 1]) {
                int32_t p = result[i];
                result[i] = result[i + 1];
                result[i + 1] = p;
            }
          }
        return result;
      }
  }

public:
  static constexpr void print() { print_all<Args...>(); }

  static constexpr auto print_sort() {
      for (const auto& elem : sort_impl<Args...>()) {
        std::cout << elem << " ";
      }
    std::cout << std::endl;
  }
};

int main() {
  bubbleSort<6072, 8321, 7570, 3728, 2776, 7365, 5541, 1644, 2956, 5636, 4857,
             9243, 7937, 2442, 1514, 3393, 6070, 7205, 9799, 1918, 4193, 3534,
             2955, 1334, 5009, 1329, 7076, 4392, 331, 4173, 5882, 5590, 5224,
             8168, 6754, 103, 4514, 9037, 5753, 8900, 2210, 89, 6735, 2140,
             8125, 6960, 2410, 6931, 1276, 6716, 2760, 1658, 697, 7897, 9569,
             855, 7153, 7168, 569, 374, 3027, 6298, 5783, 4946, 3894, 7332,
             7362, 7758, 2915, 4442, 590, 5429, 5672, 9368, 5712, 9387, 2072,
             6711, 9293, 5345, 9968, 4808, 8133, 8181, 3076, 2845, 2142, 6942,
             6153, 1980, 5572, 1048, 7227, 2343, 6494, 4652, 283, 950, 1894,
             8875, 6506, 5112, 8878, 2249, 4363, 4780, 5334, 7388,
             1182>::print();

  std::cout << "Sorted!" << std::endl;

  bubbleSort<6072, 8321, 7570, 3728, 2776, 7365, 5541, 1644, 2956, 5636, 4857,
             9243, 7937, 2442, 1514, 3393, 6070, 7205, 9799, 1918, 4193, 3534,
             2955, 1334, 5009, 1329, 7076, 4392, 331, 4173, 5882, 5590, 5224,
             8168, 6754, 103, 4514, 9037, 5753, 8900, 2210, 89, 6735, 2140,
             8125, 6960, 2410, 6931, 1276, 6716, 2760, 1658, 697, 7897, 9569,
             855, 7153, 7168, 569, 374, 3027, 6298, 5783, 4946, 3894, 7332,
             7362, 7758, 2915, 4442, 590, 5429, 5672, 9368, 5712, 9387, 2072,
             6711, 9293, 5345, 9968, 4808, 8133, 8181, 3076, 2845, 2142, 6942,
             6153, 1980, 5572, 1048, 7227, 2343, 6494, 4652, 283, 950, 1894,
             8875, 6506, 5112, 8878, 2249, 4363, 4780, 5334, 7388,
             1182>::print_sort();

  return 0;
}
