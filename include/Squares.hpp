#pragma once

#include "ISquare.hpp"
#include "IPlayer.hpp"
#include <iostream>
#include <random>


class StartSquare : public ISquare
{
public:
    void onEntry([[maybe_unused]] IPlayer& p_player) override {}
    void onPass(IPlayer& p_player) override
    {
        p_player.addMoney(m_bonusMoney);
    }
private:
    Amount m_bonusMoney{200};
};

class PenaltySquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.subtractMoney(m_fineValue);
    }
    void onPass([[maybe_unused]] IPlayer& p_player) override {}

private:
    Amount m_fineValue{150};
};

class RewardSquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.addMoney(m_rewardValue);
    }
    void onPass([[maybe_unused]] IPlayer& p_player) override {}

private:
    Amount m_rewardValue{5};
};

class DepositSquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.addMoney(m_rewardValue);
        m_rewardValue = 0;
    }
    void onPass(IPlayer& p_player) override
    {
        p_player.subtractMoney(m_depositValue);
        m_rewardValue += m_depositValue;
    }

private:
    Amount m_rewardValue{0};
    Amount m_depositValue{50};
};

class EstateSquare : public ISquare
{
public:
    EstateSquare(Amount p_cost, Amount p_fine) : m_cost(p_cost), m_fine(p_fine) {}

    void onEntry(IPlayer& p_player) override
    {
        if(m_owner.expired())
        {
            m_owner = p_player.tryBuy(m_cost);
        }
        else if (p_player != *m_owner.lock())
        {
            std::cout << p_player.getName() << " was fined for stepping on " << m_owner.lock()->getName() << " field!" << std::endl;
            p_player.subtractMoney(m_fine);
            m_owner.lock()->addMoney(m_fine);
        }
    }
    void onPass([[maybe_unused]] IPlayer& p_player) override {}

private:
    std::weak_ptr<IPlayer> m_owner;
    Amount m_cost;
    Amount m_fine;
};

class PrisonSquare : public ISquare
{
public:
    void onEntry(IPlayer& p_player) override
    {
        p_player.goToJail(3);
    }
     void onPass([[maybe_unused]] IPlayer& p_player) override {}
};


class RandomSquare : public ISquare
{
public:
    RandomSquare(std::vector<std::shared_ptr<ISquare>> p_squares) : m_squares(std::move(p_squares)) {}

    void onEntry(IPlayer& p_player) override
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, m_squares.size() - 1);
        auto l_result = distrib(gen);

        std::cout << p_player.getName() << " stepped on Random Square " << l_result << '\n';
        m_squares[l_result]->onEntry(p_player);
    }
     void onPass([[maybe_unused]] IPlayer& p_player) override {}

private:
    std::vector<std::shared_ptr<ISquare>> m_squares;
};

class BlackholeSquare : public ISquare
{
public:
    BlackholeSquare(std::shared_ptr<ISquare> p_square) : m_square(std::move(p_square)) {}

    void onEntry(IPlayer& p_player) override
    {
        if(not wasSteppedPreviously)
        {
            m_square->onEntry(p_player);
            wasSteppedPreviously = true;
            return;
        }
        wasSteppedPreviously = false;
        std::cout << p_player.getName() << " stepped on Blackhole Square"  << '\n';
    }

    void onPass(IPlayer& p_player) override
    {
        onEntry(p_player);
    }

private:
    std::shared_ptr<ISquare> m_square;
    bool wasSteppedPreviously = false;
};