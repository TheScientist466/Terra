#include <gtest/gtest.h>

#include <climits>

bool isPrime(int x) {
    if(x <= 1)
        return false;

    if(x == 2) 
        return true;

    if(x % 2 == 0)
        return false;

    for(int i = 3; i < x; i++) {
        if(x % i == 0)
            return false;
    }
    return true;
}

TEST(PrimeTest, NegativeNumber) {
    EXPECT_EQ(isPrime(-5), false);
    EXPECT_EQ(isPrime(-542), false);
    EXPECT_EQ(isPrime(INT_MIN), false);
}

TEST(PrimeTest, EdgeCases) {
    EXPECT_EQ(isPrime(0), false);
    EXPECT_EQ(isPrime(1), false);
    EXPECT_EQ(isPrime(2), true);
}

TEST(PrimeTest, OneToHundred) {
    int primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
    };
    for(int i = 1; i <= 100; i++) {
        bool flag = false;
        for(int p : primes) {
            if(p > i) break;
            else if(p < i) continue;
            else flag = true;
        }
        EXPECT_EQ(isPrime(i), flag) << "i = " << i;
    }
}

TEST(PrimeTest, LargePrimes) {
    EXPECT_EQ(isPrime(7919), true);
    EXPECT_EQ(isPrime(27397), true);
    EXPECT_EQ(isPrime(10799497), true);
}
