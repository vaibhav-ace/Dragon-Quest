#Testing with dependancies
main: main.cpp dragon.o knight.o mage.o hero.o enemy.o
	g++ main.cpp knightarc.cpp magearc.cpp dragonarc.cpp dragon.o knight.o mage.o hero.o enemy.o -o main
	./a.out

dragon.o: dragon.cpp dragon.h
	g++ dragon.cpp -c -o dragon.o

knight.o: knight.cpp knight.h
	g++ knight.cpp -c -o knight.o

mage.o: mage.cpp mage.h
	g++ mage.cpp -c -o mage.o

hero.o: hero.cpp hero.h
	g++ hero.cpp -c -o hero.o

enemy.o: enemy.cpp enemy.h
	g++ enemy.cpp -c -o enemy.o



#Unit testing for class and their methods
unitHero:
	clang++ dragon.cpp knight.cpp hero.cpp unitHero.cpp enemy.cpp
	./a.out < inputHero.txt | diff - outputHero.txt

dragon_test:
	clang++ dragon_test.cpp dragon.cpp enemy.cpp
	./a.out

mage_test:
	clang++ mage_test.cpp mage.cpp enemy.cpp
	./a.out

knight_test:
	clang++ knight_test.cpp knight.cpp enemy.cpp
	./a.out



# Automated tests
test:
	clang++ dragon.cpp knight.cpp mage.cpp hero.cpp enemy.cpp main.cpp knightarc.cpp magearc.cpp dragonarc.cpp
	./a.out



# Automated tests using specified input
test1:
	clang++ dragon.cpp knight.cpp mage.cpp hero.cpp enemy.cpp main.cpp knightarc.cpp magearc.cpp dragonarc.cpp
	./a.out < input1.txt

test2:
	clang++ dragon.cpp knight.cpp mage.cpp hero.cpp enemy.cpp main.cpp knightarc.cpp magearc.cpp dragonarc.cpp
	./a.out < input2.txt

test3:
	clang++ dragon.cpp knight.cpp mage.cpp hero.cpp enemy.cpp main.cpp knightarc.cpp magearc.cpp dragonarc.cpp
	./a.out < input3.txt

test4:
	clang++ dragon.cpp knight.cpp mage.cpp hero.cpp enemy.cpp main.cpp knightarc.cpp magearc.cpp dragonarc.cpp
	./a.out < input4.txt

test5:
	clang++ dragon.cpp knight.cpp mage.cpp hero.cpp enemy.cpp main.cpp knightarc.cpp magearc.cpp dragonarc.cpp
	./a.out < input5.txt

clean:
	rm -f *.o *.gch
