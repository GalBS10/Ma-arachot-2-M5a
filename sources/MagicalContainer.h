#include <iostream>
#include <vector>
#include <algorithm>

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


    class AscendingIterator
    {
    private:
        const MagicalContainer& container;
        size_t currentIndex;

    public:
        AscendingIterator(const MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        ~AscendingIterator();
        AscendingIterator& operator=(const AscendingIterator& other);

        bool operator==(const AscendingIterator& other) const;
        bool operator!=(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;

        int operator*() const;

        AscendingIterator& operator++();//preincrement
        AscendingIterator begin() const;
        AscendingIterator end() const;
    };

    class SideCrossIterator
    {
    private:
        const MagicalContainer& container;
        size_t currentIndex;

    public:
        SideCrossIterator(const MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator();
        SideCrossIterator& operator=(const SideCrossIterator& other);

        bool operator==(const SideCrossIterator& other) const;
        bool operator!=(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;

        int operator*() const;

        SideCrossIterator& operator++();//preincrement
        SideCrossIterator& operator--();
        SideCrossIterator begin() const;
        SideCrossIterator end() const;
    };

    class PrimeIterator
    {
    private:
        const MagicalContainer& container;
        size_t currentIndex;

    public:
        PrimeIterator(const MagicalContainer& container);
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
    };
    AscendingIterator beginAscending() const;
    AscendingIterator endAscending() const;
    SideCrossIterator beginSideCross() const;
    SideCrossIterator endSideCross() const;
    PrimeIterator beginPrime() const;
    PrimeIterator endPrime() const;
};