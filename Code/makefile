all: main

main: main.cpp Entity.cpp Wallet.cpp Client.cpp TypesClient.cpp Transact.cpp
	g++ main.cpp Entity.cpp Wallet.cpp Client.cpp TypesClient.cpp Transact.cpp -o main 

run: main
	main.exe

clean:
	rm -f main.exe	
