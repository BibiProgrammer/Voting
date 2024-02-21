echo 'Compiling...'
g++ -std=c++11 main.cpp -o voting.o

if [ $? -eq 0 ]; then
    echo "file compiled successful"
    ./voting.o
else
    echo "Error compiling"
fi