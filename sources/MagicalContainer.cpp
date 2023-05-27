#include "MagicalContainer.h"
#include <algorithm>
#include <cmath>

using namespace std;

MagicalContainer::MagicalContainer()
{
    elements =  vector<int>();
}
// MagicalContainer::~MagicalContainer()
// {
//     //vector destructor will handle it.
// }

void MagicalContainer::addElement(int element)
{
    elements.emplace_back(element);
}
void MagicalContainer::removeElement(int element)
{
    auto to_remove = find(elements.begin(),elements.end(),element);
    if(to_remove != elements.end())
    {
        elements.erase(to_remove);
    }
    else {
        throw std::runtime_error("Element not found in the container");
    }
}
int MagicalContainer::size()
{
    return elements.size();
}

MagicalContainer& MagicalContainer::operator=(const MagicalContainer& other){
    if (this != &other) {
        elements = other.elements;
    }
    return *this;
}

//--------------------AscendingIterator-------------------------------------//

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container)
    : container(&container), currentIndex(0) {
    sort(this->container->elements.begin(),this->container->elements.end());
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
    : container(other.container), currentIndex(other.currentIndex) {
    
}

MagicalContainer::AscendingIterator::~AscendingIterator() {
    
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this != &other) {
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    
    return this->currentIndex == other.currentIndex;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return this->currentIndex < other.currentIndex;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return this->currentIndex > other.currentIndex;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return this->container->elements.at(currentIndex);
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(*this == this->end()){
        throw runtime_error ("beyond limits");
    }
    this->currentIndex = this->currentIndex+1;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    AscendingIterator iterator(*container);
    iterator.currentIndex = 0;
    return iterator;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    AscendingIterator iterator(*container);
    iterator.currentIndex = size_t(container->size());
    return iterator;
}

//--------------------SideCrossIterator-------------------------------------//

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : container(&container), currentIndexLeft(0),currentIndexRight(size_t(container.size()-1)), flag(true) {
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), currentIndexLeft(other.currentIndexLeft), currentIndexRight(other.currentIndexRight) {
}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        container = other.container;
        currentIndexLeft = other.currentIndexLeft;
        currentIndexRight = other.currentIndexRight;
        flag = other.flag;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return this->currentIndexLeft == other.currentIndexLeft && this->currentIndexRight == other.currentIndexRight;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return !(*this > other) && (*this != other); // only lower than without <=.
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    if(currentIndexLeft > other.currentIndexLeft){
        return true;
    }
    if(currentIndexLeft < other.currentIndexLeft){
        return false;
    }
    //currentIndexLeft == other.currentIndexLeft
    if(currentIndexRight < other.currentIndexRight){
        return true;
    }
    return false;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if(flag){
        return this->container->elements.at(currentIndexLeft);
    }
    return this->container->elements.at(currentIndexRight);
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(*this == this->end()){
        throw runtime_error ("beyond limits");
    }
    if(flag){
        this->currentIndexLeft++;
    }
    else{
        this->currentIndexRight--;
    }
    flag = !flag;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    SideCrossIterator iterator(*container);
    iterator.currentIndexLeft = 0;
    iterator.currentIndexRight = size_t(container->size()-1);
    return iterator;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    SideCrossIterator iterator(*container);
    if(container->size()%2 != 0){
        iterator.currentIndexLeft = size_t((container->size()/2)+1);
        iterator.currentIndexRight = iterator.currentIndexLeft-1;
    }
    else{
        iterator.currentIndexLeft = size_t((container->size()/2));
        iterator.currentIndexRight = iterator.currentIndexLeft-1;
    }
    return iterator;
}

//--------------------PrimeIterator-------------------------------------//

bool MagicalContainer::PrimeIterator::isPrime(int number) // this function taken from stack overflow
{
    if(number<2 || (!(number&1) && number!=2))
        return false;
    for(int i=3; i*i<=number; i+=2){
        if(!(number%i))
            return false;
    }
    return true;
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : container(&container), currentIndex(0), primes() {

    for(size_t i = 0; i<container.size(); i++){
        if(isPrime(container.elements.at(i))){
            primes.emplace_back(container.elements.at(i));
        }
    }
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), currentIndex(other.currentIndex), primes(other.primes) {

}

MagicalContainer::PrimeIterator::~PrimeIterator() {
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (this != &other) {
        container = other.container;
        currentIndex = other.currentIndex;
        primes = other.primes;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    
    return currentIndex == other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return currentIndex != other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return currentIndex < other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return currentIndex > other.currentIndex;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return primes.at(currentIndex);
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(*this == this->end()){
        throw runtime_error ("beyond limits");
    }
    currentIndex++;
    return *this;
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
    MagicalContainer::PrimeIterator it(*container);
    it.currentIndex = 0;
    it.primes = primes;
    return it;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    MagicalContainer::PrimeIterator it(*container);
    it.currentIndex = primes.size();
    it.primes = primes;
    return it;
}


