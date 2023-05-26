#include "MagicalContainer.h"
#include <algorithm>

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


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer container)
    : container(container), currentIndex(0) {
    
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
    return this->container.elements.at(currentIndex);
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    this->currentIndex = this->currentIndex+1;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    AscendingIterator iterator(container);
    iterator.currentIndex = 0;
    return iterator;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    AscendingIterator iterator(container);
    iterator.currentIndex = container.size();
    return iterator;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer container)
    : container(container), currentIndex(0) {
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), currentIndex(other.currentIndex) {
}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return this->currentIndex == other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return this->currentIndex != other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return this->currentIndex < other.currentIndex;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return this->currentIndex > other.currentIndex;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return this->container.elements.at(currentIndex);
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    this->currentIndex = this->currentIndex+1;
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator--() {
    this->currentIndex = this->currentIndex-1;
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    SideCrossIterator iterator(container);
    iterator.currentIndex = 0;
    return iterator;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    // end implementation
    return *this;
}

// Implement empty bodies for PrimeIterator

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer container)
    : container(container), currentIndex(0) {
    // constructor implementation
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), currentIndex(other.currentIndex) {
    // copy constructor implementation
}

MagicalContainer::PrimeIterator::~PrimeIterator() {
    // destructor implementation
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (this != &other) {
        container = other.container;
        currentIndex = other.currentIndex;
        // assignment operator implementation
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    // operator== implementation
    return true;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    // operator!= implementation
    return true;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    // operator< implementation
    return true;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    // operator> implementation
    return true;
}

int MagicalContainer::PrimeIterator::operator*() const {
    // operator* implementation
    return 0;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    // operator++ implementation
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    // begin implementation
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    // end implementation
    return *this;
}


