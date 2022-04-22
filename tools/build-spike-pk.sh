#/bin/sh

RISCV=~/BUILD_DIR

echo "Buildando o spike"
git clone https://github.com/riscv-software-src/riscv-isa-sim
cd "riscv-isa-sim"
sudo apt-get install device-tree-compiler
mkdir build
cd build
../configure --prefix=$RISCV
make
sudo cp spike /usr/bin/spike

echo "Buildando o pk"
git clone https://github.com/riscv-software-src/riscv-pk
cd "riscv-pk"
mkdir build
cd build
../configure --prefix=$RISCV --host=riscv64-linux-gnu
make
sudo cp pk /usr/bin/pk
