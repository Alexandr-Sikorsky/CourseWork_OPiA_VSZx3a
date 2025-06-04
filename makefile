all: main

main: main.cpp Entity.cpp Wallet.cpp Client.cpp TypesClient.cpp Transact.cpp TransactNode.cpp TransactList.cpp
	g++ main.cpp Entity.cpp Wallet.cpp Client.cpp TypesClient.cpp Transact.cpp TransactNode.cpp TransactList.cpp -o main 

run: main
	main.exe

clean:
	rm -f main.exe	
