#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
#include <list>
#include <ctime>
#include <iomanip>


int verifyContent(std::string content);
void printDeque(std::deque<int> myDeque);
void printList(std::list<int> myList);
void goMergeDeque(std::deque<int> myDeque);
void goMergeList(std::list<int> myList);

#endif
