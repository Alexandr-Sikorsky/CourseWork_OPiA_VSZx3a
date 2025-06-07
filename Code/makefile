all: main

main: main.cpp Entity.cpp Wallet.cpp Client.cpp Transact.cpp TransactNode.cpp TransactList.cpp ClientBST.cpp Blockchain.cpp
	g++ main.cpp Entity.cpp Wallet.cpp Client.cpp Transact.cpp TransactNode.cpp TransactList.cpp ClientBST.cpp Blockchain.cpp -o main 

run: main
	main.exe

clean:
	rm -f main.exe	
