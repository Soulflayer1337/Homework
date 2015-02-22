#pragma once

template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
};

template <typename T1, typename T2>
Pair<T1, T2> *makePair(T1 first, T2 second)
{
    Pair<T1, T2> *newPair = new Pair<T1, T2>;
    newPair->first = first;
    newPair->second = second;
    return newPair;
}

template <typename T1, typename T2>
Pair<T1, T2> *makePair(Pair<T1, T2> *oldPair)
{
    return makePair(oldPair->first, oldPair->second);
}

template <typename T1, typename T2>
void deletePair(Pair <T1, T2> *pair)
{
    delete pair;
    pair = nullptr;
}
