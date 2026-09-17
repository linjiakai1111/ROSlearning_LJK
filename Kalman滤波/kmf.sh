set -euo pipefail
cd /home/line/ROSlearning_LJK/Kalman滤波
cmake -S . -B build
cmake --build build
cd /home/line/ROSlearning_LJK/Kalman滤波/build
./Kalman_Filter
cd ..