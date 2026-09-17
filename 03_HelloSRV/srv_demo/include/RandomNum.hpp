#include <random>
#include <cmath>
#include <type_traits>

class RandomNum
{
    public:
      template<typename T>
      int shift_floor_int(T floor){
        if constexpr (std::is_integral_v<T>){
          return floor;
        }else{
          return static_cast<int>(std::floor(floor));
        }
      }
      template<typename T>
      int shift_ceil_int(T ceilling){
        if constexpr (std::is_integral_v<T>){
          return ceilling;
        }else{
          return static_cast<int>(std::ceil(ceilling));
        }
      }
      template<typename T>
      int RandomInt(const T& floor,const T& ceilling)
      {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> int_dist(shift_floor_int(floor),shift_ceil_int(ceilling));
        return int_dist(gen);
      }
      private:
};