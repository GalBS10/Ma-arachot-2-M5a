#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MagicalContainer
{
private:

public:
    std::vector<int> elements;
    MagicalContainer();
    // ~MagicalContainer();

    void addElement(int element);
    void removeElement(int element);
    int size();
    MagicalContainer& operator=(const MagicalContainer& other);


    class AscendingIterator
    {
    private:
        MagicalContainer* container;
        size_t currentIndex;

    public:
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();
        AscendingIterator& operator=(const AscendingIterator& other);

        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;

        int operator*() const;

        AscendingIterator& operator++();//preincrement isn't void in order to allow chaining like ++(++it).
        AscendingIterator begin() const;
        AscendingIterator end() const;
    };

    class SideCrossIterator
    {
    private:
        MagicalContainer* container;

    public:
        size_t currentIndexLeft;
        size_t currentIndexRight;
        bool flag;
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();
        SideCrossIterator& operator=(const SideCrossIterator& other);

        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;

        int operator*() const;

        SideCrossIterator& operator++();//preincrement
        // SideCrossIterator& operator--();
        SideCrossIterator begin() const;
        SideCrossIterator end() const;
    };

    class PrimeIterator
    {
    private:
        MagicalContainer* container;
        vector<int> primes; // there is problem that after adding a new element to container this is not updating
        size_t currentIndex;

    public:
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator();
        PrimeIterator& operator=(const PrimeIterator& other);

        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;

        int operator*() const;

        PrimeIterator& operator++();//preincrement
        PrimeIterator begin() const;
        PrimeIterator end() const;

        bool isPrime(int number);
    };
};