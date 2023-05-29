#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace ariel{};

class MagicalContainer
{
private:

public:
    std::vector<int> elements;
    std::vector<int> prime_elements;

    MagicalContainer();
    ~MagicalContainer();
    MagicalContainer(const MagicalContainer& other);
    MagicalContainer(MagicalContainer&& other) noexcept;

    bool isPrime(int number);
    void addElement(int element);
    void removeElement(int element);
    int size();
    MagicalContainer& operator=(const MagicalContainer& other);
    MagicalContainer& operator=(MagicalContainer&& other) noexcept;


    class AscendingIterator
    {
    private:
        MagicalContainer* container;
        size_t currentIndex;

    public:
        AscendingIterator(MagicalContainer& container);
        AscendingIterator(const AscendingIterator& other);
        AscendingIterator(AscendingIterator&& other) noexcept;
        ~AscendingIterator();
        AscendingIterator& operator=(const AscendingIterator& other);
        AscendingIterator& operator=(AscendingIterator&& other) noexcept;

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
        size_t currentIndexLeft;
        size_t currentIndexRight;
        bool flag;

    public:
        SideCrossIterator(MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        SideCrossIterator(SideCrossIterator&& other) noexcept;
        ~SideCrossIterator();
        SideCrossIterator& operator=(const SideCrossIterator& other);
        SideCrossIterator& operator=(SideCrossIterator&& other) noexcept;

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
        // vector<int> primes; // there is problem that after adding a new element to container this is not updating
        size_t currentIndex;

    public:
        PrimeIterator(MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        PrimeIterator(PrimeIterator&& other) noexcept;
        ~PrimeIterator();
        PrimeIterator& operator=(const PrimeIterator& other);
        PrimeIterator& operator=(PrimeIterator&& other) noexcept;

        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;

        int operator*() const;

        PrimeIterator& operator++();//preincrement
        PrimeIterator begin() const;
        PrimeIterator end() const;

    };
};