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
void printDeque(std::deque<int> &myDeque);
void printList(std::list<int> &myList);
void goMergeDeque(std::deque<int> &myDeque);
void insertionSortDeque(std::deque<int> &myDeque);
void mergeInsertSortDeque(std::deque<int> &myDeque, int left, int right);
void mergeDeque(std::deque<int> &myDeque, int left, int middle, int right);
void insertionSortList(std::list<int> &myList, std::list<int>::iterator left, std::list<int>::iterator right);
void mergeSortList(std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right);
void mergeInsertionSortList(std::list<int> &myList, std::list<int>::iterator left, std::list<int>::iterator right);
void goMergeList(std::list<int> &myList);

#endif
