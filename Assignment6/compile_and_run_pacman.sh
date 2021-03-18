# This file should be placed at the top level of your project
# i.e. it should be in the same folder as the "src" folder (containing .cpp files)
# and the "include" folder (containing .h files)

# Stop upon error
set -e

g++ src/*.cpp -Wall -Wextra -std=c++14 -I include -o pacman -lSDL2 -I /opt/local/include -L /opt/local/lib

./pacman
