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
// MagicalContainer.cpp

// ... include necessary headers ...

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
    : container(container), currentIndex(0) {
    // constructor implementation
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
    : container(other.container), currentIndex(other.currentIndex) {
    // copy constructor implementation
}

MagicalContainer::AscendingIterator::~AscendingIterator() {
    // destructor implementation
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this != &other) {
        // container = other.container;
        currentIndex = other.currentIndex;
        // assignment operator implementation
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    // operator== implementation
    return true;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    // operator!= implementation
    return true;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    // operator< implementation
    return true;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    // operator> implementation
    return true;
}

int MagicalContainer::AscendingIterator::operator*() const {
    // operator* implementation
    return true;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    // operator++ implementation
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    // begin implementation
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    // end implementation
    return *this;
}

// Implement empty bodies for SideCrossIterator

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
    : container(container), currentIndex(0) {
    // constructor implementation
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), currentIndex(other.currentIndex) {
    // copy constructor implementation
}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {
    // destructor implementation
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        // container = other.container;
        currentIndex = other.currentIndex;
        // assignment operator implementation
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    // operator== implementation
    return true;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    // operator!= implementation
    return true;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    // operator< implementation
    return true;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    // operator> implementation
    return true;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    // operator* implementation
    return 0;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    // operator++ implementation
    return *this;
}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator--() {
    // operator-- implementation
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    // begin implementation
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    // end implementation
    return *this;
}

// Implement empty bodies for PrimeIterator

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
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
        // container = other.container;
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


